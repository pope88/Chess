#include "Config.h"
#include "Tcp.h"
#include "Game.h"
#include "Model/Object/User.h"
#include "Network/TcpSocket.h"
#include "Network/TcpServer.h"
#include <event2/bufferevent.h>
#include "Packet/Processor.h"
#include "ZoCfg.h"


namespace Worker
{
	Tcp tcp;

	class InitHandler : public Network::TcpEventHandler
	{
	public:
		virtual bool onAccept(Network::TcpSocket *sock)
		{
			return true;
		}
		virtual bool onRead(Network::TcpSocket *ts, struct evbuffer *evbuf)
		{
			return game.processor()->parseInit(evbuf, ts->id(), ts->getRemoteAddr());
		}
		virtual void onDisconnect(Network::TcpSocket *)
		{
			return;
		}
	};

	class PlayerHandler: public Network::TcpEventHandler
	{
	public:
		PlayerHandler(Object::User *p): user(p) {};
		virtual ~PlayerHandler() {}
		virtual void destroy() { delete this; }
		virtual bool onRead(Network::TcpSocket *ts, struct evbuffer *evbuf)
		{
			return game.processor()->parsePlayer(evbuf, user);
		}
		virtual void onDisconnect(Network::TcpSocket *ts)
		{
			game.processor()->pushDisconnect(ts->id(), user);
		}
		virtual bool acceptBroadcast(struct bufferevent *)
		{
			return user->online();
		}
	private:
		Object::User *user;
	};


	class GatewayHandler:public Network::TcpEventHandler
	{
	public:
		virtual bool onRead(Network::TcpSocket *ts, struct evbuffer *evbuf)
		{
			return game.processor()->parseGateway(evbuf, ts->id());
		}
		virtual void onDisconnect(Network::TcpSocket *ts)
		{
			game.processor()->pushGatewayDisconnect(ts->id());
		}
		virtual bool acceptBroadcast(struct bufferevent *bev)
		{
			const UInt16 targetCnt = 0;
			bufferevent_write(bev, &targetCnt, 2);
			return true;
		}
	};


	bool Tcp::init()
	{
		_server = new (std::nothrow) Network::TcpServer(_evBase);
		if (_server == NULL)
		{
			return false;
		}
		
		//connect to web server to sign servers
		//...

		_running = true;
		static InitHandler initHandler;
		_server->setDefaultHandler(&initHandler);
		_server->listen(zocfg.tcpPort);
		addTimer(-1, 50);
		return true;
	}

	void Tcp::uninit()
	{
		_running = false;
		delete _server;
	}

	void Tcp::onTimer(int id, void*)
	{
		switch(id)
		{
		case -1:
			_server->onRunCheck();
			break;
		}
	}

	void Tcp::stop()
	{
		if (_running)
		{
			_server->stop();
		}
		Base::stop();
	}

	void Tcp::close(UInt32 id, UInt32 gid)
	{
		if (_running)
		{
			if (gid == 0xFFFFFFFF)
			{
				_server->close(id);
			}
			else // send close to gateway
			{

			}
		}
	}

	void Tcp::pendClose(UInt32 id)
	{
		if (_running)
		{
			_server->pendClose(id);
		}
	}

	void Tcp::send( UInt32 id, UInt32 gid, std::shared_ptr<std::string>& pkt )
	{
		if (_running)
		{
			_server->send(id, gid, pkt);
		}
	}

	void Tcp::sendMulti( void * multi, std::shared_ptr<std::string>& pkt)
	{
		if (_running)
		{
			_server->send(*reinterpret_cast<std::vector<Network::SessionStruct> *>(multi), pkt);
		}
	}

	void Tcp::sendNolock(UInt32 id, UInt32 gid, std::shared_ptr<std::string> &pkt)
	{
		if (_running)
		{
			_server->sendNoLock(id, gid, pkt);
		}
	}

	void Tcp::sendLock()
	{
		_server->sendLock();
	}

	void Tcp::sendUnlock()
	{
		_server->sendUnlock();
	}

	void Tcp::broadcast(std::shared_ptr<std::string> &pkt)
	{
		if ( _running)
		{
			_server->broadcast(pkt);
		}
	}


	void Tcp::setPlayer(UInt32 id, Object::User * user)
	{
		if (_running)
		{
			PlayerHandler *ph = new(std::nothrow) PlayerHandler(user);
			_server->setHandler(id, ph);
		}
		else
		{
			_server->close(id);
		}
	}

	void Tcp::setFromGateway(UInt32 id)
	{
		if (_running)
		{
			static GatewayHandler gatewayHandler;
			_server->setHandler(id, &gatewayHandler);
		}
		else
		{
			_server->close(id);
		}
	}

}