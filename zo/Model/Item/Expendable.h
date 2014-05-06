#ifndef _EXPENDABLE_H_
#define _EXPENDABLE_H_
#include "Model/Object/DBObject.h"
#include "Item.h"
namespace Item
{
	class Expendable: public Item
	{
	public:
		Expendable(UInt64 keyid, UInt32 id, UInt32 playerId, UInt32 count):Item(keyid, id, playerId, count) {}
		virtual ~Expendable(void) {}
	public:
		virtual void newObjectToDB()
		{
			DB_PUSH_INSERT(getTableName(), set("playerid", _playerId, "keyid", _itemId.keyid, "itemid", _itemId.id, "param", _itemParam));
		}

		virtual void removeObjectFromDB()
		{
			DB_PUSH_DELETE(getTableName(), cond("playerid", _playerId).cond("keyid", _itemId.keyid) );
		}

		inline void count(UInt32 ct)
		{
			_itemParam = ct;
			writeData(getTableName(), "param", _itemParam);
		}

	public:
		virtual void Serialize(System::SerializeInfo& si);
		virtual void Deserialize(System::DeserializeInfo& di);

	protected:
		DB_PROP_UPDATE_COND2(playerid, _playerId, keyid, _itemId.keyid);
	};
}

#endif