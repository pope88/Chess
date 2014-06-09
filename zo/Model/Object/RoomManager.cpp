#include "Config.h"
#include "RoomManager.h"
#include "GameRoom.h"
#include "ZoGlobal.h"
#include "User.h"
#include "../../Packet/Builder.h"

namespace Object
{
	RoomManager _roomManager;

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
		for (auto it = _vecRooms.begin(); it != _vecRooms.end(); ++it)
		{
			(*it)->onHeartBit();
		}
	}

	void  RoomManager::breakAllGame()
	{
		for (auto it = _vecRooms.begin(); it != _vecRooms.end(); ++it)
		{
			(*it)->breakAllGame();
		}
	}

	void RoomManager::sendRoomList(User *user)
	{
		Packet::UserRoomList url;

		for (size_t i = 0; i < _vecRooms.size(); ++i)
		{
			Packet::RoomInfo *pRinfo = url.AddRmlist();
			pRinfo->SetRoomId(_vecRooms[i]->roomId());
			pRinfo->SetPalyerNum(_vecRooms[i]->roomPlayerNum());
		}
		url.send(user);
	}
}
