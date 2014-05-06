#include "Config.h"
#include "Builder.h"
#include "Model/Object/User.h"
#include "Model/Object/GPlayer.h"
#include "Worker/Tcp.h"
#include "PacketHead.h"

namespace Packet
{
	void Builder::send(Object::User *user, int cliid, int svrid)
	{
		_cliid = cliid;
		_svrid = svrid;
		if (user->online())
		{
			send(user->sessionId(), user->gatewayId());
		}
	}

	void Builder::send(UInt32 sid, UInt32 gid, int cliid, int svrid)
	{
		_cliid = cliid;
		_svrid = svrid;
		if (stream.get() != NULL || pack())
		{
			Worker::tcp.send(sid, gid, stream);
		}
	}

	void Builder::sendMulti(void *multi, int cliid, int svrid)
	{
		_cliid = cliid;
		_svrid = svrid;
		if(stream.get() != NULL || pack())
			Worker::tcp.sendMulti(multi, stream);
	}


	void Builder::sendNolock(Object::User *user, int cliid, int svrid)
	{
		_cliid = cliid;
		_svrid = svrid;
		if (user->online())
		{
			sendNolock(user->sessionId(), user->gatewayId());
		}
	}


	void Builder::sendNolock(UInt32 sid, UInt32 gid, int cliid, int svrid)
	{
		_cliid = cliid;
		_svrid = svrid;
		if (stream.get() != NULL || pack())
		{
			Worker::tcp.sendNolock(sid, gid, stream);
		}
	}

	void Builder::sendLock()
	{
		Worker::tcp.sendLock();
	}

	void Builder::sendUnlock()
	{
		Worker::tcp.sendLock();
	}

	void Builder::broadcast(int cliid, int svrid)
	{
		if (stream.get() != NULL || pack())
		{
			Worker::tcp.broadcast(stream);
		}
	}

	void Builder::broadcast(broadcastFilter, int cliid, int svrid)
	{
		if (stream.get() != NULL || pack())
		{
			Worker::tcp.broadcast(stream);
		}
	}

	//void Builder::broadcastCity(UInt16 cid, Object::User *user)
	//{

	//}

	bool Builder::repack()
	{
		return pack();
	}

	bool Builder::pack()
	{
		std::string *s = new(std::nothrow) std::string(20, 0);
		if (s == NULL)
		{
			return false;
		}
		stream.reset(s);
		//*((UInt16*)&((*s)[4])) =  op;
		packContent();
		size_t sz = s->size() - 20;
		packhead.Setop(op);
		packhead.Setlen(sz);
		packhead.SetCliid(_cliid);
		packhead.SetSvrid(_svrid);
		packhead.PackBuffer(reinterpret_cast<uint8_t*>(&((*s)[0])) );
		return true;
	}

	const std::string& Builder::data()
	{
		static std::string empty;
		if (stream.get() != NULL || pack())
		{
			return *stream.get();
		}
		return empty;
	}
}