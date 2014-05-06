#include "Config.h"
#include "IdPool.h"
#include "Worker/DB.h"
#include "Database/MongoAction.h"

namespace Object
{
	void IdPool::addIdPoolRange(UInt32 start, bool writeDB)
	{
		System::Mutex::ScopedLock lk(_mutex);
		if (writeDB)
		{
			MONGO_PUSH_INSERT(_tableName.c_str(), set("id", start));
		}
		start *= 1024u;
		UInt32 e = start + 1024u;
		if (start == 0)
		{
			start = 1;
		}
		for (; start < e; ++start)
		{
			_idPool.insert(start);
		}
	}

	UInt32 IdPool::poolIdLeft()
	{
		System::Mutex::ScopedLock lk(_mutex);
		return static_cast<UInt32>(_idPool.size());
	}

	void IdPool::addPoolId( UInt32 id )
	{
		if (id == 0)
		{
			return;
		}
		System::Mutex::ScopedLock lk(_mutex);
		_idPool.insert(id);
	}

	UInt32 IdPool::uniquePoolID()
	{
		System::Mutex::ScopedLock lk(_mutex);
		auto it = _idPool.begin();
		if (it == _idPool.end())
		{
			return 0;
		}
		UInt32 r = *it;
		_idPool.erase(it);
		return r;
	}

	void IdPool::removePoolID(UInt32 id)
	{
		_idPool.erase(id);
	}
}

