#include "Config.h"
#include "TcpServer.h"
#include "TcpSocket.h"
#include "TcpAction.h"
#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/bufferevent.h>

namespace Network
{

Utils * TcpServerBase::utils = new Utils;

TcpDummyHandler dummyHandler;

bool TcpDummyHandler::onRead( TcpSocket *, struct evbuffer * evbuf )
{
	size_t len = evbuffer_get_length(evbuf);
	if(len > 0)
		evbuffer_drain(evbuf, len);
	return false;
}


TcpSimpleListenServer::TcpSimpleListenServer(struct event_base * eb): _evBase(eb), _running(true)
{
	_ownBase = (eb == NULL);
	if(eb == NULL)
	{
		_evBase = event_base_new();
		if(_evBase == NULL)
		{
			throw std::bad_alloc();
		}
	}
}

TcpSimpleListenServer::~TcpSimpleListenServer()
{
	for(auto it = _listenEvent.begin(); it != _listenEvent.end(); ++ it)
		event_free(*it);
	if(_ownBase)
		event_base_free(_evBase);
	for(auto it = _listener.begin(); it != _listener.end(); ++ it)
		delete *it;
}

bool TcpSimpleListenServer::listen( UInt16 port )
{
	try
	{
		TcpListener * listener = new TcpListener(port);
		_listener.push_back(listener);
		return doListen(listener);
	}
	catch(...)
	{
		return false;
	}
}

bool TcpSimpleListenServer::listen( const std::string& addr, UInt16 port )
{
	try
	{
		TcpListener * listener = new TcpListener(addr.c_str(), port);
		_listener.push_back(listener);
		return doListen(listener);
	}
	catch(...)
	{
		return false;
	}
}

void TcpSimpleListenServer::stop()
{
	_running = false;
}

void TcpSimpleListenServer::onAccept( TcpListener * l )
{
	while(1)
	{
		TcpSocket * s = l->accept();
		if(s == NULL)
			break;
		onNewAccepted(s);
	}
}

bool TcpSimpleListenServer::doListen( TcpListener * l )
{
	l->setData(this);
	l->makeLinger(true);
	l->makeBlock(false);
	l->makeNoDelay(true);
	struct event * ev = event_new(_evBase, *l, EV_READ | EV_WRITE | EV_PERSIST, _onListenerEvent, l);
	if(ev == NULL)
		return false;
	event_add(ev, NULL);
	_listenEvent.push_back(ev);
	return true;
}

void TcpSimpleListenServer::onError()
{
	event_base_loopbreak(_evBase);
}

void TcpSimpleListenServer::_onListenerEvent( socket_t, short ev, void * arg )
{
	TcpListener * l = static_cast<TcpListener *>(arg);
	TcpSimpleListenServer * svr = l->getData<TcpSimpleListenServer>();
	if(ev & EV_WRITE)
		svr->onError();
	else
		svr->onAccept(l);
}

void TcpSimpleListenServer::onNewAccepted( TcpSocket * s )
{
	delete s;
}

int TcpSimpleListenServer::loop()
{
	_running = true;

	int r = event_base_loop(_evBase, 0);

	_running = false;

	return r;
}

struct ClientData
{
	ClientData(TcpServerBase * sv, TcpEventHandler * eh): server(sv), bev(NULL), eventHandler(eh) {}
	~ClientData() { if(bev) bufferevent_free(bev); if(eventHandler) eventHandler->destroy(); }
	TcpServerBase * server;
	struct bufferevent * bev;
	TcpEventHandler * eventHandler;
};

void _onClientRead( struct bufferevent * bev, void * arg )
{
	printf("onreading......\n");
	TcpSocket * sock = static_cast<TcpSocket *>(arg);
	struct evbuffer * evbuf = bufferevent_get_input(bev);
	ClientData * cd = sock->getData<ClientData>();
	while(cd->eventHandler->onRead(sock, evbuf)) { }
}

void _onClientWrite( struct bufferevent * bev, void * arg )
{
	TcpSocket * sock = static_cast<TcpSocket *>(arg);
	if(sock->isPendClose())
	{
		struct evbuffer * evbuf = bufferevent_get_output(bev);
		if(evbuffer_get_length(evbuf) == 0)
			sock->shutdown(2);
	}
}

void TcpServerBase::_onClientEvent( struct bufferevent *, short wht, void * arg )
{
	if((wht & (BEV_EVENT_EOF | BEV_EVENT_ERROR | BEV_EVENT_TIMEOUT)) > 0)
	{
		TcpSocket * sock = static_cast<TcpSocket *>(arg);
		ClientData * data = sock->getData<ClientData>();
		bufferevent_disable(data->bev, EV_WRITE);
		data->eventHandler->onDisconnect(sock);
		TcpServerBase * ts = data->server;
		delete data;
		ts->remove(sock);
	}
}

TcpServerBase::TcpServerBase(struct event_base * eb, bool tsafe): _evBase(eb), _defHandler(&dummyHandler), _running(true), _threadSafe(tsafe), _clientUniqueId(0), _size(0)
{
	_ownBase = (eb == NULL);
	if(eb == NULL)
	{
		_evBase = event_base_new();
		if(_evBase == NULL)
		{
			throw std::bad_alloc();
		}
	}
}

TcpServerBase::~TcpServerBase()
{
	std::for_each(_clients.begin(), _clients.end(), [](TcpSocket * ts) {if(ts != NULL) { delete ts->getData<ClientData>(); delete ts; }});
	for(auto it = _listenEvent.begin(); it != _listenEvent.end(); ++ it)
		event_free(*it);
	if(_ownBase)
		event_base_free(_evBase);
	for(auto it = _listener.begin(); it != _listener.end(); ++ it)
		delete *it;
}

bool TcpServerBase::listen( UInt16 port )
{
	try
	{
		TcpListener * listener = new TcpListener(port);
		_listener.push_back(listener);
		return doListen(listener);
	}
	catch(...)
	{
		return false;
	}
}

bool TcpServerBase::listen( const std::string& addr, UInt16 port )
{
	try
	{
		TcpListener * listener = new TcpListener(addr.c_str(), port);
		_listener.push_back(listener);
		return doListen(listener);
	}
	catch(...)
	{
		return false;
	}
}

bool TcpServerBase::connect( const std::string& host, UInt16 port, UInt32& sid )
{
	struct bufferevent * bev = bufferevent_socket_new(_evBase, -1, _threadSafe ? BEV_OPT_THREADSAFE : 0);
	if(bev == NULL)
		return false;
	if(bufferevent_socket_connect_hostname(bev, NULL, AF_INET, host.c_str(), port) < 0)
		return false;
	TcpSocket * s = new(std::nothrow) TcpSocket(bufferevent_getfd(bev));
	if(s == NULL)
	{
		bufferevent_free(bev);
		return false;
	}
	ClientData * cd = new(std::nothrow) ClientData(this, _defHandler);
	if(cd == NULL)
	{
		bufferevent_free(bev);
		delete s;
		return false;
	}
	cd->bev = bev;
	bufferevent_setcb(bev, _onClientRead, _onClientWrite, _onClientEvent, s);
	bufferevent_enable(bev, EV_READ | EV_WRITE);
	s->setData(cd);

	if(_emptySlots.empty())
	{
		sid = static_cast<UInt32>(((++ _clientUniqueId) << 20) + _clients.size());
		_clients.push_back(s);
	}
	else
	{
		std::set<UInt32>::iterator it = _emptySlots.begin();
		UInt32 id = *it;
		_emptySlots.erase(it);
		sid = ((++ _clientUniqueId) << 20) + id;
		_clients[id] = s;
	}
	s->setId(sid);
	_size = static_cast<UInt32>(_clients.size() - _emptySlots.size());
	return true;
}

void TcpServerBase::_onListenerEvent( socket_t fd, short ev, void * arg )
{
	TcpListener * l = static_cast<TcpListener *>(arg);
	TcpServer * svr = l->getData<TcpServer>();
	if(ev & EV_WRITE)
		svr->onError();
	else
		svr->onAccept(l);
}

bool TcpServerBase::doListen(TcpListener * l)
{
	l->setData(this);
	l->makeLinger(true);
	l->makeBlock(false);
	l->makeNoDelay(true);
	struct event * ev = event_new(_evBase, *l, EV_READ | EV_WRITE | EV_PERSIST, _onListenerEvent, l);
	if(ev == NULL)
		return false;
	event_add(ev, NULL);
	_listenEvent.push_back(ev);
	return true;
}

void TcpServerBase::onError()
{
	event_base_loopbreak(_evBase);
}

void TcpServerBase::onAccept(TcpListener * l)
{
	while(1)
	{
		TcpSocket * s = l->accept();
		if(s == NULL)
			break;
		add(s);
	}
}

void TcpServerBase::add(TcpSocket * s)
{
	s->makeLinger(true);
	s->makeBlock(false);
	s->makeNoDelay(true);
	if(!_defHandler->onAccept(s))
	{
		delete s;
		return;
	}
	ClientData * cd = new(std::nothrow) ClientData(this, _defHandler);
	if(cd == NULL)
	{
		delete s;
		return;
	}
	cd->bev = bufferevent_socket_new(_evBase, *s, _threadSafe ? BEV_OPT_THREADSAFE : 0);
	if(!cd->bev)
	{
		delete cd;
		delete s;
		return;
	}
	bufferevent_setcb(cd->bev, _onClientRead, _onClientWrite, _onClientEvent, s);
	bufferevent_enable(cd->bev, EV_READ | EV_WRITE);
	s->setData(cd);

	if(_emptySlots.empty())
	{
		s->setId(((++ _clientUniqueId) << 20) + static_cast<UInt32>(_clients.size()));
		_clients.push_back(s);
	}
	else
	{
		std::set<UInt32>::iterator it = _emptySlots.begin();
		UInt32 id = *it;
		_emptySlots.erase(it);
		s->setId(((++ _clientUniqueId) << 20) + id);
		_clients[id] = s;
	}
	_size = _clients.size() - _emptySlots.size();
}

int TcpServerBase::loop()
{
	_running = true;

	int r = event_base_loop(_evBase, 0);

	_running = false;

	return r;
}

void TcpServerBase::remove( TcpSocket * ts )
{
	UInt32 index = static_cast<UInt32>(ts->id() & 0xFFFFF);
	if(index < _clients.size() && _clients[index] == ts)
	{
		_clients[index] = NULL;
		if(index == _clients.size() - 1)
		{
			int idx = static_cast<int>(index) - 1;
			while(idx >= 0)
			{
				if(_clients[idx] != NULL)
					break;
				_emptySlots.erase(idx);
				-- idx;
			}
			_clients.resize(idx + 1);
		}
		else
			_emptySlots.insert(index);
		_size = _clients.size() - _emptySlots.size();
	}
	delete ts;
}

void TcpServerBase::stop()
{
	_running = false;
}

void TcpServerBase::setHandler( UInt32 id, TcpEventHandler * eh )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
	{
		TcpEventHandler * old_eh = ts->getData<ClientData>()->eventHandler;
		if(old_eh != eh)
		{
			old_eh->destroy();
			ts->getData<ClientData>()->eventHandler = eh;
		}
	}
}

TcpEventHandler * TcpServerBase::getHandler( UInt32 id )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return NULL;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
		return ts->getData<ClientData>()->eventHandler;
	return NULL;
}

void TcpServerBase::close2( UInt32 id )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
		ts->shutdown(2);
}

void TcpServerBase::pendClose2( UInt32 id )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
	{
		struct evbuffer * evbuf = bufferevent_get_output(ts->getData<ClientData>()->bev);
		if(evbuffer_get_length(evbuf) == 0)
			ts->shutdown(2);
		else
			ts->pendClose();
	}
}

void TcpServerBase::send2( UInt32 id, const void * buf, int len )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
	{
		bufferevent_write(ts->getData<ClientData>()->bev, buf, len);
	}
}

void TcpServerBase::send2( UInt32 id, const void * buf1, int len1, const void * buf2, int len2 )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
	{
		struct bufferevent * bev = ts->getData<ClientData>()->bev;
		bufferevent_write(bev, buf1, len1);
		bufferevent_write(bev, buf2, len2);
	}
}

void TcpServerBase::send2( UInt32 id, const void * buf1, int len1, const void * buf2, int len2, const void * buf3, int len3 )
{
	UInt32 index = id & 0xFFFFF;
	if(index >= _clients.size())
		return;
	TcpSocket * ts = _clients[index];
	if(ts != NULL && ts->id() == id)
	{
		struct bufferevent * bev = ts->getData<ClientData>()->bev;
		bufferevent_write(bev, buf1, len1);
		bufferevent_write(bev, buf2, len2);
		bufferevent_write(bev, buf3, len3);
	}
}

void TcpServerBase::broadcast2( const void * buf, int len )
{
	size_t sz = _clients.size();
	for(size_t i = 0; i < sz; ++ i)
	{
		TcpSocket * ts = _clients[i];
		if(ts != NULL)
		{
			ClientData * cd = ts->getData<ClientData>();
			if(cd->eventHandler->acceptBroadcast(cd->bev))
				bufferevent_write(cd->bev, buf, len);
		}
	}
}

void TcpServerBase::broadcast2( const void * buf1, int len1, const void * buf2, int len2 )
{
	size_t sz = _clients.size();
	for(size_t i = 0; i < sz; ++ i)
	{
		TcpSocket * ts = _clients[i];
		if(ts != NULL)
		{
			ClientData * cd = ts->getData<ClientData>();
			if(cd->eventHandler->acceptBroadcast(cd->bev))
			{
				bufferevent_write(cd->bev, buf1, len1);
				bufferevent_write(cd->bev, buf2, len2);
			}
		}
	}
}

void TcpServer::_eventRunCheck( socket_t, short, void * arg )
{
	static_cast<TcpServer *>(arg)->onRunCheck();
}

void TcpServer::onRunCheck()
{
	if(_running)
	{
		std::vector<TcpAction *>* aq = fetchMsg();
		if(aq == NULL)
			return;
		for(std::vector<TcpAction *>::iterator it = aq->begin(); it != aq->end(); ++ it)
		{
			(*it)->run(this);
			delete *it;
		}
		fetchEnd(aq);
	}
	else
		event_base_loopbreak(_evBase);
}

void TcpServer::close( UInt32 id )
{
	TcpActionClose * ac = new(std::nothrow) TcpActionClose(id);
	if(ac == NULL)
		return;
	pushMsg(ac);
}

void TcpServer::pendClose( UInt32 id )
{
	TcpActionClose * ac = new(std::nothrow) TcpActionClose(id, true);
	if(ac == NULL)
		return;
	pushMsg(ac);
}

void TcpServer::send( UInt32 id, UInt32 gid, std::shared_ptr<std::string>& pkt )
{
	TcpActionSend * as = new(std::nothrow) TcpActionSend(pkt, id, gid);
	if(as == NULL)
		return;
	pushMsg(as);
}

void TcpServer::send( std::vector<SessionStruct>& ss, std::shared_ptr<std::string>& pkt )
{
	TcpActionMultiSend * as = new(std::nothrow) TcpActionMultiSend(pkt, ss);
	if(as == NULL)
		return;
	pushMsg(as);
}

void TcpServer::sendLock()
{
	pushLock();
}

void TcpServer::sendUnlock()
{
	pushUnlock();
}

void TcpServer::sendNoLock( UInt32 id, UInt32 gid, std::shared_ptr<std::string>& pkt )
{
	TcpActionSend * as = new(std::nothrow) TcpActionSend(pkt, id, gid);
	if(as == NULL)
		return;
	pushMsgNoLock(as);
}

void TcpServer::broadcast( std::shared_ptr<std::string>& pkt )
{
	TcpActionBroadcast * ab = new(std::nothrow) TcpActionBroadcast(pkt);
	if(ab == NULL)
		return;
	pushMsg(ab);
}

int TcpServer::loop()
{
	_evRC = event_new(_evBase, -1, EV_PERSIST, _eventRunCheck, this);
	if(_evRC == NULL)
		return -1;
	struct timeval tv = {0, 50};
	event_add(_evRC, &tv);
	return TcpServerBase::loop();
}

TcpServer::~TcpServer()
{
	if(_evRC != NULL)
	{
		event_del(_evRC);
		event_free(_evRC);
	}
}

}
