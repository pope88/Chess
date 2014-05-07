#include "Config.h"
#include "Processor.h"
#include "Packet/Handler/Handler.h"
#include "Model/Object/UserManager.h"
//#include "Object/GPlayerManager.h"
#include "Worker/Tcp.h"
#include "Worker/Game.h"
#include "PacketHead.h"

#include <event2/buffer.h>

namespace Packet
{

	void decryptPacket(UInt32 key, UInt16& op, UInt32 size, UInt8 * buf)
	{
		return;
	}

	bool Processor::parseInit(evbuffer *evbuf, UInt32 data, UInt32 addr)
	{
		printf("parseInit....\n");
		int len = static_cast<int>(evbuffer_get_length(evbuf));

		if(len < CLIENTHLEN)
			return false;
		UInt8 hdr[CLIENTHLEN] = {0};
		evbuffer_copyout(evbuf, hdr, CLIENTHLEN);
		packhead.Unpack(hdr, CLIENTHLEN);
		UInt32 sz = packhead.Getlen() & 0x00FFFFFF;
		if(static_cast<int>(sz) + CLIENTHLEN > len)
			return false;
		UInt32 key = packhead.Getlen() >> 24;
		HandlerMsgInit * msg = (HandlerMsgInit *)malloc(sz + sizeof(HandlerMsgInit));
		if(msg == NULL)
		{
			evbuffer_drain(evbuf, sz + CLIENTHLEN);
			return true;
		}
		msg->hdr.size = sz;
		msg->sessionId = data;
		msg->fromGateway = 0xFFFFFFFF;
		msg->remoteAddr = addr;
		evbuffer_drain(evbuf, CLIENTHLEN);
		UInt8 * buf = ((UInt8 *)msg) + sizeof(HandlerMsgInit);
		evbuffer_remove(evbuf, buf, sz);
		int op = packhead.Getop();
		//decryptPacket(key, op, sz, buf);
		if (op >= (int)_initHandlers.size())
		{
			free(msg);
			return false;
		}
		Handler * hdl = _initHandlers[op];
		if(hdl == NULL)
		{
			free(msg);
			return true;
		}
		msg->hdr.handler = hdl;
		pushMsg((HandlerMsgHeader *)msg);
		return true;
	}

	//bool Processor::parseGPlayer(evbuffer *evbuf, Object::GPlayer *gplayer)
	//{
	//	printf("prase gplayer...\n");
	//	int len = static_cast<int>(evbuffer_get_length(evbuf));
	//	if(len < CLIENTHLEN)
	//		return false;

	//	UInt8 hdr[CLIENTHLEN] = {0};
	//	evbuffer_copyout(evbuf, &hdr, CLIENTHLEN);
	//	packhead.Unpack((UInt8*)&hdr, CLIENTHLEN);
	//	UInt32 sz = packhead.Getlen() & 0x00FFFFFF;
	//	if(static_cast<int>(sz) + CLIENTHLEN > len)
	//		return false;
	//	UInt32 key = packhead.Getlen() >> 24;
	//	//if(!player->updateKey(key))
	//	//{
	//	//	Worker::tcp.close(player->sessionId(), player->gatewayId());
	//	//	return false;
	//	//}
	//	HandlerMsgGPlayer * msg = (HandlerMsgGPlayer *)malloc(sz + sizeof(HandlerMsgGPlayer));
	//	if(msg == NULL)
	//	{
	//		evbuffer_drain(evbuf, sz + CLIENTHLEN);
	//		return true;
	//	}
	//	msg->hdr.size = sz;
	//	msg->gplayer = gplayer;
	//	evbuffer_drain(evbuf, CLIENTHLEN);
	//	UInt8 * buf = ((UInt8 *)msg) + sizeof(HandlerMsgGPlayer);
	//	evbuffer_remove(evbuf, buf, sz);
	//	UInt16 op = packhead.Getop();
	//	decryptPacket(key, op, sz, buf);

	//	if (op >= (int)_gplayerHandlers.size())
	//	{
	//		free(msg);
	//		return false;
	//	}
	//	Handler * hdl = _gplayerHandlers[op];
	//	if(hdl == NULL)
	//	{
	//		free((void *)msg);
	//		return true;
	//	}
	//	msg->hdr.handler = hdl;
	//	pushMsg((HandlerMsgHeader *)msg);
	//	return true;
	//}

	bool Processor::parsePlayer(evbuffer *evbuf, Object::User *user)
	{
		int len = static_cast<int>(evbuffer_get_length(evbuf));
		if(len < CLIENTHLEN)
			return false;

		UInt8 hdr[CLIENTHLEN] = {0};
		evbuffer_copyout(evbuf, &hdr, CLIENTHLEN);
		packhead.Unpack((UInt8*)&hdr, CLIENTHLEN);
		UInt32 sz = packhead.Getlen() & 0x00FFFFFF;
		if(static_cast<int>(sz) + CLIENTHLEN > len)
			return false;
		UInt32 key = packhead.Getlen() >> 24;
		//if(!player->updateKey(key))
		//{
		//	Worker::tcp.close(player->sessionId(), player->gatewayId());
		//	return false;
		//}
		HandlerMsgPlayer * msg = (HandlerMsgPlayer *)malloc(sz + sizeof(HandlerMsgPlayer));
		if(msg == NULL)
		{
			evbuffer_drain(evbuf, sz + CLIENTHLEN);
			return true;
		}
		msg->hdr.size = sz;
		msg->user = user;
		evbuffer_drain(evbuf, CLIENTHLEN);
		UInt8 * buf = ((UInt8 *)msg) + sizeof(HandlerMsgPlayer);
		evbuffer_remove(evbuf, buf, sz);
		UInt16 op = packhead.Getop();
		decryptPacket(key, op, sz, buf);
		
		if (op >= (int)_playerHandlers.size())
		{
			free(msg);
			return false;
		}
		Handler * hdl = _playerHandlers[op];
		if(hdl == NULL)
		{
			free((void *)msg);
			return true;
		}
		msg->hdr.handler = hdl;
		pushMsg((HandlerMsgHeader *)msg);
		return true;
	}


	class HandlerGGateway: public Handler
	{
	public:
		virtual void handle(HandlerMsgHeader * hdr)
		{
			Worker::game.processor()->processGatewayMsg(hdr);
		}
	};

	class HandlerGateway: public Handler
	{
	public:
		virtual void handle(HandlerMsgHeader * hdr)
		{
			Worker::game.processor()->processGatewayMsg(hdr);
		}
	};


	bool Processor::parseGateway(evbuffer *evbuf, UInt32 sid)
	{
		int len = static_cast<int>(evbuffer_get_length(evbuf));
		if(len < 10)
			return false;
#pragma pack(push, 1)
		struct PktHdr
		{
			UInt32 pid;
			UInt32 size;
			UInt16 op;
		} ATTR_PACKED();
#pragma pack(pop)
		PktHdr hdr;
		evbuffer_copyout(evbuf, &hdr, 10);
		// UInt8 crc = static_cast<UInt8>(hdr->size >> 24);
		UInt32 sz = hdr.size & 0x00FFFFFF;
		if(static_cast<int>(sz) + 10 > len)
			return false;
		UInt16 op = hdr.op;

		if(op == 0xFFFF)
		{
			//HandlerMsgPlayer * msg = (HandlerMsgPlayer *)malloc(sizeof(HandlerMsgPlayer) + sizeof(UInt32));
			//if(msg == NULL)
			//{
			//	evbuffer_drain(evbuf, sz + 10);
			//	return true;
			//}
			//static HandlerGateway hdlGate;
			//msg->hdr.handler = &hdlGate;
			//msg->hdr.size = sz;
			//msg->gateway.pId = hdr.pid;
			//msg->gateway.op = op;
			//evbuffer_drain(evbuf, sz + 10);
			//memcpy(((UInt8 *)msg) + sizeof(HandlerMsgPlayer), &sid, 4);
			//pushMsg((HandlerMsgHeader *)msg);
		}
		else if((op & 0x8000) > 0)
		{
			op &= 0x7FFF;
			Handler * hdl = _initHandlers[op];
			if(hdl == NULL)
			{
				evbuffer_drain(evbuf, sz + 10);
				return false;
			}
			HandlerMsgInit * msg = (HandlerMsgInit *)malloc(sz + sizeof(HandlerMsgInit));
			if(msg == NULL)
			{
				evbuffer_drain(evbuf, sz + 10);
				return true;
			}
			msg->hdr.handler = hdl;
			msg->hdr.size = sz;
			msg->sessionId = hdr.pid;
			msg->fromGateway = sid;
			msg->remoteAddr = 0;
			evbuffer_drain(evbuf, 10);
			evbuffer_remove(evbuf, ((UInt8 *)msg) + sizeof(HandlerMsgInit), sz);
			pushMsg((HandlerMsgHeader *)msg);
		}
		else
		{
			if(op <= 2)
			{
				HandlerMsgPlayer * msg = (HandlerMsgPlayer *)malloc(sz + sizeof(HandlerMsgPlayer));
				if(msg == NULL)
				{
					evbuffer_drain(evbuf, sz + 10);
					return true;
				}
				static HandlerGateway hdlGate;
				msg->hdr.handler = &hdlGate;
				msg->hdr.size = sz;
				msg->gateway.playerId = hdr.pid;
				msg->gateway.op = op;
				evbuffer_drain(evbuf, 10);
				evbuffer_remove(evbuf, ((UInt8 *)msg) + sizeof(HandlerMsgPlayer), sz);
				pushMsg((HandlerMsgHeader *)msg);
			}
			else
			{
				HandlerMsgPlayer * msg = (HandlerMsgPlayer *)malloc(sz + sizeof(HandlerMsgPlayer));
				if(msg == NULL)
				{
					evbuffer_drain(evbuf, sz + 10);
					return true;
				}
				static HandlerGateway hdlGate;
				msg->hdr.handler = &hdlGate;
				msg->hdr.size = sz;
				msg->gateway.playerId = hdr.pid;
				msg->gateway.op = op;
				evbuffer_drain(evbuf, 10);
				evbuffer_remove(evbuf, ((UInt8 *)msg) + sizeof(HandlerMsgPlayer), sz);
				pushMsg((HandlerMsgHeader *)msg);
			}
		}
		return true;
	}

	void Processor::pushDisconnect(UInt32 data, Object::User *user)
	{
		HandlerMsgPlayer *msg = (HandlerMsgPlayer*)malloc(sizeof(HandlerMsgPlayer) + sizeof(UInt32));
		if (msg == NULL)
		{
			return;
		}
		msg->hdr.handler = _playerHandlers[0xFFFF];
		msg->hdr.size = sizeof(UInt32);
		msg->user = user;
		memcpy((UInt8 *)msg + sizeof(HandlerMsgPlayer), &data, sizeof(UInt32));
		pushMsg((HandlerMsgHeader *)msg);
	}

	void Processor::pushGatewayDisconnect( UInt32 sid )
	{
		//gateway.remove(sid);
	}

	void Processor::process()
	{
		std::vector<HandlerMsgHeader *>* queue = fetchMsg(1000);
		if (queue == NULL)
		{
			return;
		}
		for (std::vector<HandlerMsgHeader *>::iterator it = queue->begin(); it != queue->end(); ++it)
		{
			(*it)->handler->handle(*it);
			free(*it);
		}
		fetchEnd(queue);
	}

	void Processor::processGatewayMsg(HandlerMsgHeader *hdr)
	{
		HandlerMsgPlayer *msg = (HandlerMsgPlayer *)hdr;
		Handler *hdl = _playerHandlers[msg->gateway.op];
		if (hdl == NULL)
		{
			return;
		}
		Object::User *user = Object::userManager[msg->gateway.playerId];
		if (user == NULL)
		{
			return;
		}
		msg->user = user;
		hdl->handle(hdr);
	}

	void Processor::addHandler(UInt16 op, UInt8 type, Handler *handler)
	{
		if (type ==  1 || type == 2)
		{
			if (_playerHandlers.size() <= op)
			{
				_playerHandlers.resize((size_t)op + 1);
			}
			_playerHandlers[op] = handler;
		}

		if (type == 3)
		{
			if (_initHandlers.size() <= op)
			{
				_initHandlers.resize((size_t)op + 1);
			}
			_initHandlers[op] = handler;
		}
	}
}
