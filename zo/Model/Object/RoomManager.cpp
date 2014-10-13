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

	bool RoomManager::playerEnterRoom(User *user, UInt8 r)
	{
		if (user->getInRoom() != NULL)
		{
			playerLeaveRoom(user, user->getInRoom()->roomId());
		}
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

	bool RoomManager::playerLeaveRoom(User *user, UInt8 r)
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

	void RoomManager::playerQuikPlay(User *user)
	{
		UInt32 chips = user->gold();
		UInt32 roomId = 0;
		roomId = autoRoom(chips);
		if (roomId < zoGlobal.roomNum())
		{
			playerEnterRoom(user, roomId);
		}
		this->getGameRoom(roomId)->autoEnterTable(user);
	}

	UInt32 RoomManager::autoRoom(UInt32 chips)
	{
		if (chips < 1000)
		{
			return 0;
		}
		else if (chips < 2000)
		{
			return 1;
		}
		else if (chips < 5000)
		{
			return 2;
		}
		else if (chips < 10000)
		{
			return 3;
		}
		else if (chips < 50000)
		{
			return 4;
		}
		else if (chips < 100000)
		{
			return 5;
		}
		else if (chips < 500000)
		{
			return 6;
		}
		else if (chips < 1000000)
		{
			return 7;
		}
		else
		{
			return 8;
		}
	}
}
