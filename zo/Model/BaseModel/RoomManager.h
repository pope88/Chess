#ifndef _ROOMMANAGER_H_
#define _ROOMMANAGER_H_
#include "RoomPlayerManager.h"

class GameRoom;
class RoomManager
{
public:
	RoomManager();
	~RoomManager();
public:
	bool Init();
	RoomPlayerManager* getRoomPlayerManager(int roomId) {}
	GameRoom* getGameRoom(int roomId) {}
	bool playerEnterRoom() {}
	bool playerLeaveRoom() {}
	User* findUser(int nPid){}
	void heartBit(){}
	void breakAllGame(){}


private:
	std::vector<RoomPlayerManager*> _vecPlayers;
	std::vector<GameRoom*> _vecTableManager;
	int mMaxRoomNum;
};
#endif