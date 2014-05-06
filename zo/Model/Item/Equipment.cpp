#include "Config.h"
#include "Equipment.h"

namespace Item
{
	Equipment::Equipment(UInt64 keyid, UInt32 id, UInt32 playerid, UInt32 param ):Item(keyid, id, playerid, param)
	{
	}

	void Equipment::newObjectToDB()
	{
		DB_PUSH_INSERT(getTableName(), set("playerid", _playerId, "keyid", _itemId.keyid, "itemid", _itemId.id, "param", _itemParam));
	}

	void Equipment::newObjectToDBWithPosition(UInt32 pos)
	{
		DB_PUSH_INSERT(getTableName(), set("playerid", _playerId, "keyid", _itemId.keyid, "itemid", _itemId.id, "param", _itemParam));
	}

	void Equipment::removeObjectFromDB()
	{
		DB_PUSH_DELETE(getTableName(), cond("playerid", _playerId).cond("keyid", _itemId.keyid));
	}

	void Equipment::Serialize(System::SerializeInfo &si)
	{
		si << _playerId << _itemId.keyid << _itemId.id << _itemParam;
	}
	
	void Equipment::Deserialize(System::DeserializeInfo& di)
	{
		switch(di.GetVersion())
		{
		case 1 : 
			{
				di >> _playerId >> _itemId.keyid >> _itemId.id >> _itemParam;
				break;
			}
		}
	}

}