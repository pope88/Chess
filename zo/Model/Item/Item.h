#ifndef _ITEM_H_
#define _ITEM_H_
#include "Model/Object/DBObject.h"
#include "System/Serialize.h"
#include "Model/Data/ItemMgr.h"
namespace Item
{
	enum ItemClass
	{
		Invalid = 0,
		Normal = 1,
		SilverCheque = 2, 
		Equip = 3,
		Quest = 4,
		Currency = 5,
		Weapon = 6,
		UniqueIdItem = 7
	};

	enum  //game coin
	{
		ItemGold = 25001,
		ItemGoldB = 25002,
		ItemSilver = 25003,
		ItemExp = 25004,
		ItemExpMinute = 25005,
		ItemTenSilver = 25006,
		ItemCurrency,
	};
	
	struct ItemID
	{
		UInt64 keyid; //flag(++) + isband(1bit) + time(31bit)
		UInt32 id;
	};

	class Item : virtual protected Object::DBObject,
		public System::Serializable
	{
	public:
		Item(UInt64 keyid, UInt32 id, UInt32 playerid, UInt32 param);
		virtual ~Item();
	public:
		virtual void newObjectToDB() = 0;
		virtual void removeObjectFromDB() = 0;
	public:
		inline const char* getTableName() { return "item"; }
		static inline int getClass(UInt32 id)
		{
			if(id <= 9000)
			{
				if(id == 8000)  //specail
					return SilverCheque;
				return Normal;
			}
			if(id <= 15000)
				return Equip;
			if(id <= 25000)
				return ItemCurrency;
			if(id <= ItemCurrency)
				return Currency;
			if(id == 0x7FFF)
				return Equip;
			if(id >= 100000)
				return UniqueIdItem;
			return Invalid;
		}
		inline bool isBound() { return ((UInt32)(_itemId.keyid) & 0x80000000) > 0; }
		inline bool isEquipable() { return isEquipable(_itemId.id); }
		inline  int getClass() { return getClass(_itemId.id); }
		inline void setPlayerId(UInt32 pl) { _playerId = pl; }
		inline UInt32 getID() { return _itemId.id; }
		inline UInt64 getKeyID() { return _itemId.keyid; }
		inline UInt32 getCount() { return isEquipable()?1:_itemParam; }
		inline UInt16 getType() { return Data::itemMgr[_itemId.id].type; }
		inline UInt8 getQuality() { return Data::itemMgr[_itemId.id].quality; }
		inline UInt16 getLevel() { return Data::itemMgr[_itemId.id].level; }
		static inline bool isEquipable(UInt32 id) {return id==0x7FFF || (id>=9000 && id<=15000);}
		static inline UInt16 getStackSize(UInt32 rid) { return Data::itemMgr[rid].stack; }
		static inline UInt16 getBlockSize(UInt32 rid, int count) { return count > 0 ? (count-1)/getStackSize(rid)+1 : 0; }
		static inline UInt16 getPrice(UInt32 rid) { return Data::itemMgr[rid].price; }
	protected:
		friend class ItemPack;
	protected:
		UInt32 _playerId;
		ItemID _itemId;
		UInt32 _itemParam;
	};
}
#endif