#include "Config.h"
#include "ItemPack.h"
#include "Model/Data/ItemMgr.h"
#include "Equipment.h"
#include "Model/Object/User.h"
#include "Expendable.h"
#include "Model/Object/User.h"
#include "Packet/Builder.h"
#include "System/TimeUtil.h"

namespace Item
{
	ItemPack::OperationCache  ItemPack::operationCache;
	UInt32  ItemPack::operationReason; 
	ItemPack::ItemPack():_packUsed(0), _packuid(100000)
	{

	}
	ItemPack::~ItemPack()
	{
	}

	Item* ItemPack::loadItem(UInt32 playerid, UInt64 keyid, UInt32 id, UInt32 param)
	{
		UInt32 iid = id;
		if (!Data::itemMgr[iid].exists)
		{
			return NULL;
		}
		Expendable *pitem = new Expendable(keyid, id, playerid, param);
		_packItems[keyid] = pitem;
		_packUsed++;// Item::getBlockSize(iid, param);

		auto it = _idItems.find(id);
		if (it == _idItems.end())
		{
			std::vector<Item*> items;
			items.push_back(pitem);
			if (((UInt32)keyid & 0x80000000) > 0)
			{
				_idItems[id|0x100000] = items;
			}
			else
			{
				_idItems[id] = items;
			}
		}
		return NULL;
	}

	void ItemPack::insertItem(Item *pitem)
	{
		auto it = _idItems.find(pitem->getID());
		if (it == _idItems.end())
		{
			std::vector<Item*> items;
			items.push_back(pitem);
			if (((UInt32)pitem->getKeyID() & 0x80000000) > 0)
			{
				_idItems[pitem->getID()|0x100000] = items;
			}
			else
			{
				_idItems[pitem->getID()] = items;
			}
		}
	}


	Item* ItemPack::loadEquip(UInt32 playerid, UInt64 keyid, UInt32 id, UInt32 param, UInt32 position)
	{
		UInt32 iid = id;
		if (!Data::itemMgr[iid].exists)
		{
			return NULL;
		}
		if (iid > 10000)
		{
			Equipment *pitem = new Equipment(keyid, id, playerid, param);
			if (position == 0)
			{
				_packItems[keyid] = pitem;
				_packUsed++;

				auto it = _idItems.find(id);
				if (it == _idItems.end())
				{
					std::vector<Item*> items;
					items.push_back(pitem);
					if (((UInt32)keyid & 0x80000000) > 0)
					{
						_idItems[id|0x100000] = items;
					}
					else
					{
						_idItems[id] = items;
					}
				}
			}
			else//equip
			{
				Object::User* pplayer = static_cast<Object::User*>(this);
				UInt16 hid = position & 0xFFFF;
		    //	Object::Hero *phero = pplayer->getHero();
			//	if (phero)
			//	{
			//		UInt16 epart = pitem->getEquipPart();
			//	}
	        //	else
			//	{
				    //_packItems[keyid] = pitem;
				    //_packuid++;
			//	}

			}
			return pitem;
		}
		return NULL;
	}

	std::vector<Item*>& ItemPack::getItems(UInt32 id, bool isbound )
	{
		std::map<UInt32, std::vector<Item*> >::iterator miter;

		miter = _idItems.find(id | (isbound ? 0x1000000 : 0));

		if (miter == _idItems.end())
		{
			static std::vector<Item*> empty;
			return empty;
		}
		return miter->second;
	}

	Item* ItemPack::getItem(UInt64 keyid)
	{
		auto pItem = _packItems.find(keyid);
		if (pItem == _packItems.end())
		{
			return NULL;
		}
		else
		{
			return pItem->second;
		}

	}

	UInt32 ItemPack::getItemNum(UInt32 id, bool isbound)
	{
		std::map<UInt32, std::vector<Item*> >::iterator miter;

		miter = _idItems.find(id | (isbound ? 0x1000000 : 0));

		if (miter == _idItems.end())
		{
			return 0;
		}
		else
		{
			UInt32 count = 0;
			for (auto it = miter->second.begin(); it != miter->second.end(); ++it)
			{
				count = (*it)->getCount();
			}
		}
		return 0;
	}

	void ItemPack::sendItemList()
	{
		Packet::ItemList il;
		il.SetListType(0);  
		il.SetHint(0);
		for (auto iter = _packItems.begin(); iter != _packItems.end(); ++iter)
		{
			if (iter->first < 100000) //
			{
				Packet::SCItem *sci = il.AddItems();
				sci->SetItemId(iter->second->_itemId.id);
				sci->SetIcount(iter->second->_itemParam);
				sci->SetIsBand(iter->second->isBound());
				sci->SetPosition(1);
			}
			else
			{
				Packet::SCEquipAttribute *ea = il.AddEquipments();
				ea->SetEquipId(iter->second->_itemId.id);
				ea->SetPosition(1);
				ea->SetIsBand(iter->second->isBound());
			}
			il.send(static_cast<Object::User*>(this));
		}
	}

	Int32 ItemPack::getUsableSize()
	{
		return 0;
	}

	void ItemPack::beginItemOperation()
	{
		operationReason = REASON_NOERROR;
		operationCache.checkingVol = 0;
		operationCache.chekingLack = 0;
		operationCache.playerid = PThisPtr->id();
	}

	bool ItemPack::endItemOperation(bool operate , bool is_hint, bool is_send)
	{
		assert(PThisPtr->id() == operationCache.playerid);
		bool result;
		if (operationReason != REASON_NOERROR)
		{
			result = false;
		}
		else
		{
			result = true;
			if (operationCache.chekingLack > 0)
			{
				result = false;
				operationReason = REASON_LACK;
			}

			if (operationCache.checkingVol > getUsableSize())
			{
				result = false;
				operationReason = REASON_PACK_FULL;
			}

			if (result && operate)
			{
				_packUsed += operationCache.checkingVol;
				Packet::ItemList il; 
				il.SetHint(is_hint ? 1 : 0);
				il.SetListType(1);

				Packet::DeleteItems dit;

				for (auto caiter = operationCache.cacheItem.begin(); caiter != operationCache.cacheItem.end(); ++caiter)
				{
					bool bIsAdd = caiter->second >= 0 ? 1 : 0; 
					UInt32 keyid = caiter->first;
					bool isBand = keyid & 0x1000000 ? true : false;
					keyid &= 0x1FFFFFF;
					if (keyid >= 100000)
					{
						auto packIter = _packItems.find(keyid);
						if (bIsAdd)
						{
							Packet::SCItem *sci = il.AddItems();
							sci->SetItemId(keyid);
							sci->SetIcount(caiter->second);
							sci->SetPosition(1);
							sci->SetIsBand(isBand);
						}
						else
						{
							Packet::dlitems *dli = dit.AddDitems();
							dli->SetItemid(keyid);
						}
		
						packIter->second->removeObjectFromDB();
						delete packIter->second;
						_packItems.erase(packIter);
					}
					else
					{
						UInt32 id = keyid & 0xFFFFFF;
						bool isBand = (keyid & 0x1000000) != 0;
						switch(Item::getClass(id))
						{
						case Normal:
							{
									auto packIter = _packItems.find(keyid);
									if (packIter == _packItems.end())
									{
										if (caiter->second > 0)
										{
											Expendable *newItem = new Expendable(keyid,123456, PThisPtr->id(), caiter->second);
											newItem->newObjectToDB();
											_packItems[keyid] = newItem;
											if (is_send)
											{
												if (bIsAdd)
												{
													Packet::SCItem* sci = il.AddItems();
													sci->SetItemId(keyid);
													sci->SetPosition(1);
													sci->SetIsBand(isBand);
												}
											}
										}
										else
										{
											Int32 newCount = packIter->second->_itemParam + caiter->second;
											if (newCount == 0)
											{
												packIter->second->removeObjectFromDB();
												delete packIter->second;
												_packItems.erase(packIter);
											}
											else
											{
												static_cast<Expendable*>(packIter->second)->count(newCount);
											}
											if (is_send)
											{
												if (bIsAdd)
												{
													Packet::SCItem* sci = il.AddItems();
													sci->SetItemId(keyid);
													sci->SetIcount(caiter->second);
													sci->SetPosition(1);
													sci->SetIsBand(isBand);
												}
												else
												{
												}
												//il.AddItems((newCount << 16) | keyid);
											}
										}
									}
								}
							}
						}
					}
				}
			}

			return result;
			//return true;
	}
	

	bool ItemPack::addItem(UInt32 id, Int32 param, bool is_bound)
	{
		if (id == 0 || param <= 0)
		{
			return true;
		}
		assert(PThisPtr->id() == operationCache.playerid);
		switch(Item::getClass(id))
		{
		case Normal:
			{
				if (!Data::itemMgr[id].exists)
				{
					return false;
					switch(Data::itemMgr[id].bound_policy)
					{
					case 0:
						is_bound = false;
						break;
					case 1:
						is_bound = true;
						break;
					}
				}
				UInt32 keyid = id | (is_bound ? 0x8000 : 0);
				auto packIter = _packItems.find(keyid);
				auto cacheIter = operationCache.cacheItem.find(keyid);
				Int32 packCount = (packIter == _packItems.end() ? 0 : packIter->second->_itemParam);
				if (cacheIter == operationCache.cacheItem.end())
				{
					operationCache.checkingVol += Item::getBlockSize(id, packCount + param) - Item::getBlockSize(id, packCount);
			        operationCache.cacheItem.insert(std::make_pair(keyid, param));
				}
				else
				{
					if ((packCount + cacheIter->second < 0) && (packCount + cacheIter->second + param ) > 0)
					{
						operationCache.chekingLack--;
					}
					operationCache.checkingVol += Item::getBlockSize(id, packCount + cacheIter->second + param) - Item::getBlockSize(id, packCount + cacheIter->second);
				}
			}
			break;
		}
		return true;
	}


	bool ItemPack::removeItem(UInt32 id, Int32 param, bool is_bound)
	{
		if(param <= 0)
			return false;
		assert(PThisPtr->id() == operationCache.playerid);
		UInt32 keyid = id | (is_bound? 0x8000 : 0);
		switch(Item::getClass(id))
		{
		case Normal:
			{
				if(!Data::itemMgr[id].exists)
					return false;
				auto pack_iter = _packItems.find(keyid);
				auto cache_iter = operationCache.cacheItem.find(keyid);
				Int32 pack_count = (pack_iter == _packItems.end()) ? 0 : pack_iter->second->_itemParam;
				if(cache_iter == operationCache.cacheItem.end())
				{
					operationCache.checkingVol += Item::getBlockSize(id, pack_count - param) - Item::getBlockSize(id, pack_count);
					operationCache.cacheItem.insert(std::make_pair(keyid, -param));
					if(pack_count < param)
						operationCache.chekingLack++;
				}
				else
				{
					if((pack_count + cache_iter->second >= 0) && (pack_count + cache_iter->second - param < 0))
						operationCache.chekingLack++;
					operationCache.checkingVol += Item::getBlockSize(id, pack_count + cache_iter->second - param) - Item::getBlockSize(id, pack_count + cache_iter->second);
					cache_iter->second -= param;
				}
				break;
			}
		}
		return true;
	}

	bool ItemPack::tryAddItem(UInt32 id, UInt32 count, bool is_bound, bool is_hint, bool is_send )
	{
		operationReason = REASON_NOERROR;
		switch(Item::getClass(id))
		{
		case Normal:
			{
				if(count == 0 || !Data::itemMgr[id].exists)
					return false;
				switch(Data::itemMgr[id].bound_policy)
				{
				case 1:
					is_bound = true;
					break;
				case 2:
					is_bound = false;
					break;
				}
				UInt32 bid = id | (is_bound? 0x1000000 : 0);
				UInt32 ucount = getUsableSize();
				UInt32 stackSize = Item::getStackSize(id);
				auto pack_iter = _idItems.find(bid);
				if(pack_iter == _idItems.end())
				{
					UInt32 extra_size = Item::getBlockSize(id, count);
					if(extra_size > ucount)
					{
						operationReason = REASON_PACK_FULL;
						return false;
					}
					_packUsed += extra_size;
					UInt32 itemFlag =0;
					for (size_t i = 0;i < extra_size; ++i)
					{
						UInt64 keyid = 0;
						UInt64 keyida = 0;
						UInt64 keyidb = 0;
						UInt32 rcount = 0;
						++itemFlag;
						keyida = (UInt64)itemFlag;
						keyidb = is_bound ? ((TimeUtil::Now() & 0x7FFFFFFF) | 0x80000000) : (TimeUtil::Now() & 0x7FFFFFFF);
						keyid = (keyida << 32) | keyidb;
						if (i == extra_size-1)
						{
							rcount = count - (extra_size-1)*stackSize;
						}
						else
						{
							rcount = stackSize;
						}
						Expendable* newItem = new Expendable(keyid, id, PThisPtr->id(), rcount);
						_packItems[keyid] = newItem; 
						insertItem(newItem);
						newItem->newObjectToDB();
					}
					
					if (is_send)
					{
						//	UInt32 packCount = pack_iter->second->_itemParam;
						//	UInt32 extra_size = Item::getBlockSize(id, packCount + count) - Item::getBlockSize(id, packCount);
						//	if(extra_size > ucount)
						//	{
						//		operationReason = REASON_PACK_FULL;
						//		return false;
						//	}
					}
				}
				else
				{
					UInt32 packCount = pack_iter->second.size(); //now pack count
					UInt32 spareSize = 0;
					for (size_t i = 0; i < pack_iter->second.size(); ++i)
					{
						spareSize += stackSize - pack_iter->second[i]->_itemParam;
					}
					UInt32 extra_size = Item::getBlockSize(id, count - packCount);
					if(extra_size > ucount)
					{
						operationReason = REASON_PACK_FULL;
						return false;
					}



				}
				//	newItem->newObjectToDB();
				//	_packItems[keyid] = newItem;
				//	if(is_send)
				//	{
				//		Packet::ItemList il;
				//		il.SetHint(is_hint? 1 : 0);
				//		il.SetListType(1);
				//		Packet::SCItem *sci = il.AddItems();
				//		sci->SetItemId(id);
				//		sci->SetIcount(count);
				//		sci->SetIsBand(is_bound);
				//		sci->SetPosition(1);
				//		il.send(PThisPtr);
				//	}
				//}
				//else
				//{
				//	UInt32 packCount = pack_iter->second->_itemParam;
				//	UInt32 extra_size = Item::getBlockSize(id, packCount + count) - Item::getBlockSize(id, packCount);
				//	if(extra_size > ucount)
				//	{
				//		operationReason = REASON_PACK_FULL;
				//		return false;
				//	}
				//	_packUsed += extra_size;
				//	static_cast<Expendable*>(pack_iter->second)->count(packCount + count);
				//	if(is_send)
				//	{
				//		Packet::ItemList il;
				//		il.SetHint(is_hint? 1 : 0);
				//		il.SetListType(1);
				//		Packet::SCItem *sci = il.AddItems();
				//		sci->SetItemId(id);
				//		sci->SetIcount(count);
				//		sci->SetIsBand(is_bound);
				//		sci->SetPosition(1);
				//		il.send(PThisPtr);
				//	}
				//}
				//return true;
			
		}
		return false;
	}
}
	
	bool ItemPack::tryRemoveItem(UInt32 id, UInt32 count, bool is_bound, bool is_hint, bool is_send)
	{
		if(id >= 100000)
		{
			auto pack_iter = _packItems.find(id);
			if(pack_iter == _packItems.end())
			{
				operationReason = REASON_NOT_EXIST;
				return false;
			}
			if(is_send)
			{
				Packet::ItemList il;
				il.SetHint(is_hint? 1 : 0);
				il.SetListType(1);
				Packet::SCItem *sci = il.AddItems();
				sci->SetItemId(id);
				sci->SetIcount(count);
				sci->SetIsBand(is_bound);
				sci->SetPosition(1);
				il.send(PThisPtr);
			}
			pack_iter->second->removeObjectFromDB();
			delete pack_iter->second;
			_packItems.erase(pack_iter);
			_packUsed--;
			return true;
		}
		else
		{
			assert(count > 0);
			switch (Item::getClass(id))
			{
			case Normal:
				{
					UInt32 keyid = id | (is_bound? 0x8000 : 0);
					auto pack_iter = _packItems.find(keyid);
					if(pack_iter == _packItems.end())
					{
						operationReason = REASON_LACK;
						return false;
					}
					Int32 new_count = pack_iter->second->_itemParam - count;
					if(new_count < 0)
					{
						operationReason = REASON_LACK;
						return false;
					}
					_packUsed -= Item::getBlockSize(id, pack_iter->second->_itemParam) - Item::getBlockSize(id, new_count);
					if(new_count == 0)
					{
						pack_iter->second->removeObjectFromDB();
						delete pack_iter->second;
						_packItems.erase(pack_iter);
					}
					else
					{
						static_cast<Expendable*>(pack_iter->second)->count(new_count);
					}
					if(is_send)
					{
						Packet::ItemList il;
						il.SetHint(is_hint? 1 : 0);
						il.SetListType(1);
						Packet::SCItem *sci = il.AddItems();
						sci->SetItemId(id);
						sci->SetIcount(count);
						sci->SetIsBand(is_bound);
						sci->SetPosition(1);
						il.send(PThisPtr);
					}
					return true;
				}
			case Currency:
				{
					//PThisPtr->loseCurrency(id - ItemGold, count, is_hint? 18U: 0x8000);
					return true;
				}
			}
			return false;
		}
		return false;
	}

	bool ItemPack::TryRemoveItemAny(UInt32 id, UInt32 count, bool& is_bound, bool is_hint, bool is_send)
	{
		if(id >= 100000)
		{
			auto pack_iter = _packItems.find(id);
			if(pack_iter == _packItems.end())
			{
				operationReason = REASON_NOT_EXIST;
				return false;
			}
			if(is_send)
			{
				//Packet::ItemList il;
				//il.SetHint(is_hint? 1 : 0);
				//Packet::EquipAttribute* ea=il.addEquipments();
				//ea->setTypeID(pack_iter->second->getID() | (is_bound?0x8000:0));
				//ea->setUniqueID(id);
				//il.send(PThisPtr);
			}
			pack_iter->second->removeObjectFromDB();
			delete pack_iter->second;
			_packItems.erase(pack_iter);
			_packUsed--;
			return true;
		}
		else
		{
			assert(count > 0);
			switch (Item::getClass(id))
			{
			case Normal:
				{
					UInt32 keyid1 = id | (is_bound? 0x8000 : 0);
					UInt32 keyid2 = id | (is_bound? 0 : 0x8000);
					auto pack_iter1 = _packItems.find(keyid1);
					auto pack_iter2 = _packItems.find(keyid2);
					UInt32 count1 = 0, count2 = 0;
					if(pack_iter1 != _packItems.end())
						count1 = pack_iter1->second->_itemParam;
					if(pack_iter2 != _packItems.end())
						count2 = pack_iter2->second->_itemParam;
					if(count > count1 + count2)
					{
						operationReason = REASON_LACK;
						return false;
					}
					Packet::ItemList il;
					il.SetHint(is_hint? 1 : 0);
					if(count1 > 0)
					{
						if(count1 >= count)
						{
							if(count1 == count)
							{
								pack_iter1->second->removeObjectFromDB();
								delete pack_iter1->second;
								_packItems.erase(pack_iter1);
								if(is_send);
									//il(keyid1);
							}
							else
							{
								static_cast<Expendable*>(pack_iter1->second)->count(count1 - count);
								if(is_send);
									//il.addItems(((count1 - count) << 16) | keyid1);
							}
							_packUsed -= Item::getBlockSize(id, count1) - Item::getBlockSize(id, count1 - count);
						}
						else
						{
							pack_iter1->second->removeObjectFromDB();
							delete pack_iter1->second;
							_packItems.erase(pack_iter1);
							if(is_send);
								//il.addItems(keyid1);
							if(count2 == count - count1)
							{
								pack_iter2->second->removeObjectFromDB();
								delete pack_iter2->second;
								_packItems.erase(pack_iter2);
								if(is_send);
									//il.addItems(keyid2);
							}
							else
							{
								static_cast<Expendable*>(pack_iter2->second)->count(count1 + count2 - count);
								if(is_send);
									//il.addItems(((count1 + count2 - count) << 16) | keyid2);
							}
							_packUsed -= Item::getBlockSize(id, count1);
							_packUsed -= Item::getBlockSize(id, count2) - Item::getBlockSize(id, count1 + count2 - count);
							is_bound = true;
						}
					}
					else
					{
						if(count2 == count)
						{
							pack_iter2->second->removeObjectFromDB();
							delete pack_iter2->second;
							_packItems.erase(pack_iter2);
							if(is_send);
								//il.addItems(keyid2);
						}
						else
						{
							static_cast<Expendable*>(pack_iter2->second)->count(count1 + count2 - count);
							if(is_send);
								//il.addItems(((count2 - count) << 16) | keyid2);
						}
						_packUsed -= Item::getBlockSize(id, count2) - Item::getBlockSize(id, count2 - count);
						is_bound = !is_bound;
					}
					if(is_send);
						//il.send(PThisPtr);
					return true;
				}
			case Currency:
				{
					//PThisPtr->loseCurrency(id - ItemGold, count, is_hint? 18U: 0x8000);
					return true;
				}
			}
		}
		return false;
	}
}