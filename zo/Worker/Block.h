#ifndef _WORKER_BLOCK_H_
#define _WORKER_BLOCK_H_
#include "Base.h"
#include "System/Event.h"
#include "System/MsgQueue.h"

namespace Worker
{
	class Block: public SimpleBase, public System::MsgQueue<void *>
	{
	public:
		void pushReg(const std::string &id, const std::string &name, UInt32 serverId, UInt32 t, bool add = true);
	protected:
		virtual void loop();
		virtual const char* getLogFilename() { return "block"; }
	};

	extern Block block;
}
#endif