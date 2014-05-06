#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include "Network/Utils.h"
#include "System/MsgQueue.h"

struct event_base;
struct event;
struct evbuffer;
struct bufferevent;

namespace Network
{

class TcpListener;
class TcpSocket;
class TcpAction;

struct SessionStruct
{
	UInt32 sid;
	UInt32 gid;
};

/* Tcp socket event handler */
class TcpEventHandler
{
public:
	virtual ~TcpEventHandler() {}
	/* Destroy self, which is used to avoid destruction on static objects by leaving it empty */
	virtual void destroy() {}
	/* Called when accept a new client connection (used by server socket) */
	virtual bool onAccept(TcpSocket *) { return false; }
	/* Called when data inputs (used by client socket) */
	virtual bool onRead(TcpSocket *, struct evbuffer *) { return false; }
	/* Called when client socket disconnects (used by client socket) */
	virtual void onDisconnect(TcpSocket *) {}
	/* Indicates that if this socket accepts global broadcasts */
	virtual bool acceptBroadcast(struct bufferevent *) { return false; }
};

class TcpDummyHandler: public TcpEventHandler
{
	virtual bool onRead(TcpSocket *, struct evbuffer *);
};

extern TcpDummyHandler dummyHandler;

/* Basic TCP Simple listen server class */
class TcpSimpleListenServer
{
public:
	/* Constructor
	 *   if evBase is NULL, the class will create a event base and release it on destruction
	 *   if evBase is not NULL, the class will use it to handle server and incoming sockets
	 *   threadSafe indicates wheather client sockets require thread safe functions in libevent2 */
	TcpSimpleListenServer(struct event_base * evBase);
	/* Destructor */
	virtual ~TcpSimpleListenServer();
	/* Listen on 0.0.0.0:port */
	bool listen(UInt16 port);
	/* Listen on host:port */
	bool listen(const std::string& host, UInt16 port);
	/* Start event loop, only used when event base is created by itself, Otherwise please run
	 * event loop in the caller procedure */
	virtual int loop();

	/* Stop running the event loop */
	void stop();

protected:
	virtual void onNewAccepted(TcpSocket * s) = 0;

protected:
	void onAccept(TcpListener *);
	bool doListen(TcpListener *);
	void onError();

protected:
	static void _onListenerEvent( socket_t, short, void * );

protected:
	std::vector<TcpListener *> _listener;
	struct event_base * _evBase;
	std::vector<struct event *> _listenEvent;
	bool _running;
	bool _ownBase;
};

/* Basic TCP-Server Class */
class TcpServerBase
{
public:
	/* Constructor
	 *   if evBase is NULL, the class will create a event base and release it on destruction
	 *   if evBase is not NULL, the class will use it to handle server and incoming sockets
	 *   threadSafe indicates wheather client sockets require thread safe functions in libevent2 */
	TcpServerBase(struct event_base * evBase, bool threadSafe);
	/* Destructor */
	virtual ~TcpServerBase();
	/* Listen on 0.0.0.0:port */
	bool listen(UInt16 port);
	/* Listen on host:port */
	bool listen(const std::string& host, UInt16 port);
	/* Connect to host:port */
	bool connect(const std::string& host, UInt16 port, UInt32& sid);
	/* Start event loop, only used when event base is created by itself, Otherwise please run
	 * event loop in the caller procedure */
	virtual int loop();

	/* Add an new accepted socket, the socket is released by this class on closing, so please
	   do not release it after adding it outside */
	void add(TcpSocket *);

	/* Stop running the event loop */
	void stop();

	/* Set the default handler which is used when a new connection is accepted */
	inline void setDefaultHandler(TcpEventHandler * eh) { _defHandler = eh; }
	/* Get the default handler */
	inline TcpEventHandler * getDefaultHandler() { return _defHandler; }
	/* Set a new handler for a connection */
	void setHandler(UInt32 id, TcpEventHandler * eh);
	/* Get current handler for the connection */
	TcpEventHandler * getHandler(UInt32 id);

	inline UInt32 size() { return _size; }

protected:
	bool doListen(TcpListener *);
	void onError();
	void onAccept(TcpListener *);
	/* Remove a tcp socket from server */
	void remove(TcpSocket *);

protected:
	static void _onListenerEvent( socket_t, short, void * );
	static void _onClientEvent( struct bufferevent *, short, void * );

protected:
	std::vector<TcpListener *> _listener;
	struct event_base * _evBase;
	std::vector<struct event *> _listenEvent;
	std::vector<TcpSocket *> _clients;
	std::set<UInt32> _emptySlots;
	TcpEventHandler * _defHandler;
	bool _running;
	bool _ownBase;
	bool _threadSafe;
	UInt32 _clientUniqueId;
	UInt32 _size;

protected:
	/* Used by friend classes only */
	void close2(UInt32);
	void pendClose2(UInt32);
	void send2(UInt32, const void *, int);
	void send2(UInt32, const void *, int, const void *, int);
	void send2(UInt32, const void *, int, const void *, int, const void *, int);
	void broadcast2(const void *, int);
	void broadcast2(const void *, int, const void *, int);

protected:
	static Utils * utils;
};

/* TCP-Server class with thread support
 *   All packets/actions are pushed into queue from other thread.
 *   The event loop pulls packets out from queue by timer. */
class TcpServer: public TcpServerBase, public System::MsgQueue<TcpAction *>
{
	friend class TcpActionClose;
	friend class TcpActionSend;
	friend class TcpActionMultiSend;
	friend class TcpActionBroadcast;
public:
	inline TcpServer(struct event_base * eb = NULL): TcpServerBase(eb, true), _evRC(NULL) {}
	virtual ~TcpServer();
	/* Push close action to queue */
	void close(UInt32);
	/* Pend a close action to queue, which means the socket is closed after all packets have been sent */
	void pendClose(UInt32);
	/* Send a packet, this would lock the send queue, push packet into the queue and unlock it. */
	void send(UInt32, UInt32, std::shared_ptr<std::string>&);
	/* Send a packet to multiple targets, this would lock the send queue, push packet into the queue and unlock it. */
	void send(std::vector<SessionStruct>&, std::shared_ptr<std::string>&);
	/* Lock the send queue */
	void sendLock();
	/* Unlock the send queue */
	void sendUnlock();
	/* Send a packet without locking the queue */
	void sendNoLock(UInt32, UInt32, std::shared_ptr<std::string>&);
	/* Broadcast packet to all connections */
	void broadcast(std::shared_ptr<std::string>&);

	/* Start event loop, only used when event base is created by itself, Otherwise please run
	 * event loop in the caller procedure
	 * this virtual implementation adds timer to handle queued packets/actions */
	virtual int loop();

	void onRunCheck();

private:
	static void _eventRunCheck( socket_t, short, void * );

protected:
	struct event * _evRC;
};

/* Single-threaded TCP-Server class
 *   All packets are sent instantly when send function is called. */
class TcpServerST: public TcpServerBase
{
public:
	inline TcpServerST(struct event_base * eb = NULL): TcpServerBase(eb, false) {}
	/* Close a socket instantly */
	inline void close(UInt32 id)
	{
		TcpServerBase::close2(id);
	}
	/* Pend close a socket */
	inline void pendClose(UInt32 id)
	{
		TcpServerBase::pendClose2(id);
	}
	/* Send a packet instantly */
	inline void send(UInt32 id, const void * buf, int size)
	{
		TcpServerBase::send2(id, buf, size);
	}
	inline void send(UInt32 id, const void * buf1, int size1, const void * buf2, int size2)
	{
		TcpServerBase::send2(id, buf1, size1, buf2, size2);
	}
	inline void send(UInt32 id, std::string& packet)
	{
		TcpServerBase::send2(id, &packet[0], static_cast<int>(packet.size()));
	}
	/* Broadcast a packet instantly */
	inline void broadcast(const void * buf, int size)
	{
		TcpServerBase::broadcast2(buf, size);
	}
	inline void broadcast(const void * buf1, int size1, const void * buf2, int size2)
	{
		TcpServerBase::broadcast2(buf1, size1, buf2, size2);
	}
	inline void broadcast(std::string& packet)
	{
		TcpServerBase::broadcast2(&packet[0], static_cast<int>(packet.size()));
	}
};

}

#endif // _TCPSERVER_H_
