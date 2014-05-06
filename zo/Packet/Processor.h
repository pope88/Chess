#ifndef _PROCESSOR_H_	
#define _PROCESSOR_H_
#include "System/MsgQueue.h"
#include "System/Event.h"

struct evbuffer;
namespace Object
{
	class User;
	class UserManager;
}

namespace Packet
{
	class Handler;
	struct HandlerMsgHeader;

	class Processor : public System::MsgQueue<HandlerMsgHeader *>
	{
	public:
		Processor() {}
	public:
		bool parseInit(evbuffer *evbuf, UInt32 data, UInt32 addr);
		bool parsePlayer(evbuffer *, Object::User *user);
		bool parseGateway(evbuffer*, UInt32);
		void pushDisconnect(UInt32, Object::User *gplayer);
		void pushGatewayDisconnect(UInt32);
		void process();
		void processGatewayMsg(HandlerMsgHeader *);
		void addHandler(UInt16, UInt8, Handler*);
	private:
		std::vector<Handler *> _initHandlers;
		std::vector<Handler*> _playerHandlers;
		std::vector<Handler*> _gplayerHandlers;
	};
}
#endif