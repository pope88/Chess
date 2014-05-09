#include "Config.h"
#include "RoomManager.h"
#include "GameRoom.h"
#include "ZoGlobal.h"
#include "User.h"

namespace Object
{
	RoomManager roomManager;

	RoomManager::~RoomManager()
	{
		_vecRooms.clear();
	}

	GameRoom* RoomManager::getGameRoom(int roomId)
	{
		if ((size_t)roomId >= _vecRooms.size())
		{
			return NULL;
		}
		else
		{
			return _vecRooms[roomId];
		}
	}

	void RoomManager::init()
	{
		UInt8 roomNum = 0;
		roomNum = zoGlobal.roomNum();
		_vecRooms.resize(roomNum);
		for (int i = 0;i < roomNum; ++i)
		{
			GameRoom *gr = new GameRoom(i);
			_vecRooms.push_back(gr);
		}
	}

	bool RoomManager::playerEnterRoom(UInt8 r, User *user)
	{
		if ((size_t)r < _vecRooms.size())
		{
			UInt32 userId = 0;
			userId = user->id();
			_userInRoomMap[userId] = r;
			GameRoom *pRoom = NULL;
			pRoom = _vecRooms[r];
			return pRoom->enterUser(user);
		}
		return false;
	}

	bool RoomManager::playerLeaveRoom(UInt8 r, User *user)
	{
		if ((size_t)r < _vecRooms.size())
		{
			UInt32 userId = 0;
			userId = user->id();
			auto it = _userInRoomMap.find(userId);
			if (it == _userInRoomMap.end())
			{
				return false;
			}
			_userInRoomMap.erase(it);
			GameRoom *pRoom = NULL;
			pRoom = _vecRooms[r];
			return pRoom->outUser(user);
		}
		return false;
	}

	void RoomManager::heartBit()
	{
		for
	}
}
