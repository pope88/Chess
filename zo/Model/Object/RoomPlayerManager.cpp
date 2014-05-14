#include "Config.h"
#include "RoomPlayerManager.h"
#include "../Object/User.h"

namespace Object
{
	void RoomPlayerManager::onHeartBit()
	{
		User *user = NULL;
		for (auto it = _roomPlayers.begin(); it != _roomPlayers.end(); ++it)
		{
			user = it->second;
			user->heartBit();
		}
	}
}
