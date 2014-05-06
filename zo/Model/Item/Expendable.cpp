#include "Config.h"
#include "Expendable.h"

namespace Item
{
	void Expendable::Serialize(System::SerializeInfo& si)
	{
		si << _playerId << _itemId.keyid << _itemId.id << _itemParam;
	}

	void Expendable::Deserialize(System::DeserializeInfo& di)
	{
		switch(di.GetVersion())
		{
		case 1:
			{
				di >> _playerId >> _itemId.keyid >> _itemId.id >> _itemParam;
				break;
			}
		}
	}
}
