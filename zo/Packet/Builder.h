#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "PacketsStoC.h"

namespace Object
{
	class User;
}

namespace Packet
{
	using namespace game::net::data::StoC;

	class Builder
	{
	public:
		typedef bool (*broadcastFilter)(Object::User *user);
	public:
		inline Builder(int o): op(o), _cliid(0), _svrid(0) {}
		virtual ~Builder() {}
		void send(Object::User *user, int cliid = 0, int svrid = 0);
		void send(UInt32 sid, UInt32 gid, int cliid = 0, int svrid = 0);
		void sendMulti(void *multi, int cliid = 0, int svrid = 0);
		void sendNolock(Object::User *user, int cliid = 0, int svrid = 0);
		void sendNolock(UInt32 sid, UInt32 gid, int cliid = 0, int svrid = 0);
		void sendLock();
		void sendUnlock();
		void broadcast(int cliid = 0, int svrid = 0);
		void broadcast(broadcastFilter, int cliid = 0, int svrid = 0);
		//void broadcastCity(UInt16 cid, Object::User *user = NULL);
		const std::string& data();
		bool repack();
	protected:
		virtual void packContent() = 0;
	private:
		bool pack();

	protected:
		std::shared_ptr<std::string> stream;
	private:
		int op;
		int _cliid;
		int _svrid;
	};

	template <class T, UInt16 OP>
	class BuilderT: public Builder, public T
	{
	public:
		BuilderT<T, OP>(): Builder(OP) {}
		virtual void packContent()
		{
			T::Pack(*stream.get());
		}
	};

#define DefBuilder(t, o) typedef BuilderT<SC##t##_##o, o> t
#include "Builder.inl"

}

#endif