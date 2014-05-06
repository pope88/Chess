#ifndef _ITEMPACK_H_
#define _ITEMPACK_H_

#define REASON_NOERROR		0x1
#define REASON_LACK			0x2
#define REASON_PACK_FULL	0x3
#define REASON_NOT_EXIST	0x4
#define REASON_DUP_RIDE		0x5
#define REASON_BOUND_USED	0x10000
namespace Item
{
	class Item;

	class ItemPack
	{
	public:
		ItemPack();
		virtual ~ItemPack();
	public:
		Item* loadItem(UInt32 playerid, UInt64 keyid, UInt32 id, UInt32 param);
		Item* loadEquip(UInt32 playerid, UInt64 keyid, UInt32 id, UInt32 param, UInt32 position);
		void insertItem(Item *pitem);
		void insertEquip(UInt32 playerid, UInt64 keyid, UInt32 id, UInt32 param);
		std::vector<Item*>& getItems(UInt32 id, bool isbound = true);
		Item* getItem(UInt64 keyid);
		UInt32 getItemNum(UInt32 id, bool isbound = true);
		void sendItemList();
		Int32 getUsableSize();
		void beginItemOperation();
		bool addItem(UInt32 id, Int32 param, bool is_bound = true);
		
		bool removeItem(UInt32 id, Int32 param, bool is_bound = true);
		bool endItemOperation(bool operate , bool is_hint = true, bool is_send = true);
		bool tryAddItem(UInt32 id, UInt32 count, bool is_bound = true, bool is_hint = true, bool is_send = true);
	    bool tryRemoveItem(UInt32 id, UInt32 count, bool is_bound = true, bool is_hint = true, bool is_send = true);
		bool TryRemoveItemAny(UInt32 id, UInt32 count, bool& is_bound, bool is_hint = true, bool is_send = true);
	private:
		struct  OperationCache
		{
			std::unordered_map<UInt32, Int32> cacheItem;
			std::unordered_set<UInt32> addFromStock;
			std::unordered_set<UInt32> removeToStock;
			Int32 checkingVol;   //over
			Int32 chekingLack;  //less
			UInt32 playerid;  //the only role id
		}; 
		static OperationCache operationCache;
		static UInt32 operationReason;
	protected:
		UInt32 _packUsed;
		UInt32 _packuid;
		std::map<UInt64, Item*> _packItems;
		std::map<UInt32, std::vector<Item*> > _idItems;
	};
}
#endif  