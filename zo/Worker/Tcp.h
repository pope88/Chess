#ifndef _WORKER_TCP_H_
#define _WORKER_TCP_H_
#include "Base.h"

namespace Object
{
	class User;
	class GPlayer;
}

namespace Network
{
	class TcpServer;
}

namespace Worker
{

	class Tcp : public Base
	{
	public:
		Tcp():_server(NULL) {}
		void stop();
		void close(UInt32 id, UInt32 gid);
		void pendClose(UInt32 id);
		void send(UInt32 id, UInt32 gid, std::shared_ptr<std::string>& pkt);
		void sendMulti(void* multi, std::shared_ptr<std::string>& pkt);
		void sendNolock(UInt32 id, UInt32 gid, std::shared_ptr<std::string> &pkt);
		void sendLock();
		void sendUnlock();
		void broadcast(std::shared_ptr<std::string> &pkt);
		void setPlayer(UInt32 id, Object::User *user);
		void setFromGateway(UInt32 id);
	protected:
		virtual bool init();
		virtual void uninit();
		virtual const char* getLogFilename() { return "Tcp";}
		virtual void onTimer(int id, void*);
	private:
		bool _running;
		Network::TcpServer *_server;
	};
	extern Tcp tcp;

}
#endif