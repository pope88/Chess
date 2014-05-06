#ifndef _EQUIPEMNT_H_
#define _EQUIPEMNT_H_
#include "Item.h"
namespace Item
{
	class Equipment : public Item
	{
	public:
		Equipment(UInt64 keyid, UInt32 id, UInt32 playerId, UInt32 param = 0);
		virtual ~Equipment() {}
	public:
		void newObjectToDB();
		void newObjectToDBWithPosition(UInt32 pos);
		void removeObjectFromDB();
	public:
		UInt16 getEquipPart() { return 0; }
	private:
	protected:
		DB_PROP_UPDATE_COND2(playerid, _playerId, keyid, _itemId.keyid);

	public:
		virtual void Serialize(System::SerializeInfo& si);
		virtual void Deserialize(System::DeserializeInfo& di);

	};
}
#endif