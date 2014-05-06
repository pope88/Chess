#include "Config.h"
#include "Item.h"

namespace Item
{
	Item::Item(UInt64 keyid, UInt32 id, UInt32 playerid, UInt32 param): _playerId(playerid), _itemParam(param)
	{
		_itemId.keyid = keyid;
		_itemId.id = id;
	}
	
	Item::~Item()
	{
	}
}