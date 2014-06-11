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
		bool playerEnterRoom( User *user, UInt8 r = 0);
		bool playerLeaveRoom( User *user, UInt8 r = 0);
		void heartBit();
		void breakAllGame();
		void sendRoomList(User *user);
	private:
		std::vector<GameRoom*> _vecRooms;
		std::unordered_map<UInt32, UInt8> _userInRoomMap;
	};
	extern RoomManager _roomManager;
}

#endif