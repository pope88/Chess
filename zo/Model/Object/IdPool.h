#ifndef _IDPOOL_H_
#define _IDPOOL_H_
#include "System/Mutex.h"

namespace Object
{
	class IdPool
	{
	public:
		inline IdPool(const char *tn): _tableName(tn) {}
		void addIdPoolRange(UInt32, bool = true);
		UInt32 poolIdLeft();
		void addPoolId(UInt32);
		UInt32 uniquePoolID();
	protected:
		void removePoolID(UInt32);
		inline void lock() { _mutex.Lock();}
		inline void unlock() { _mutex.Unlock(); }
	private:
		const std::string _tableName;
		std::unordered_set<UInt32> _idPool;
		System::Mutex _mutex;
	};
}
#endif

