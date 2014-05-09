#ifndef _ROOMMANAGER_H_
#define _ROOMMANAGER_H_
#include "RoomPlayerManager.h"

namespace Object
{
	class GameRoom;
	class RoomManager
	{
	public:
		RoomManager(){}
		~RoomManager();
	public:
		void init();
		GameRoom* getGameRoom(int roomId);
		bool playerEnterRoom(UInt8 r, User *user);
		bool playerLeaveRoom(UInt8 r, User *user);
		void heartBit();
		void breakAllGame(){}
	private:
		std::vector<GameRoom*> _vecRooms;
		std::unordered_map<UInt32, UInt8> _userInRoomMap;
	};
	extern RoomManager roomManager;
}

#endif