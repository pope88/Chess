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

	bool RoomPlayerManager::insertPlayer(User *user)
	{
		_roomPlayers[user->id()] = user;
		return true;
	}

	bool RoomPlayerManager::removePlayer(User *user)
	{
		auto iter = _roomPlayers.find(user->id());
		if ( iter != _roomPlayers.end())
		{
			_roomPlayers.erase(iter);
			return true;
		}
		return false;
	}

	void RoomPlayerManager::broadcastRoom(Packet::Builder& builder, User *pExceptPlayer)
	{
		if (pExceptPlayer == NULL)
		{
			for ( auto iter = _roomPlayers.begin(); iter != _roomPlayers.end(); ++iter)
			{
				builder.send(iter->second);
			}
		}
		else
		{
			for ( auto iter = _roomPlayers.begin(); iter != _roomPlayers.end(); ++iter)
			{
				if (pExceptPlayer != iter->second)
				{
					builder.send(iter->second);
				}
			}
		}
	}
}
