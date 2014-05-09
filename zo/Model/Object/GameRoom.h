#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_
#include "BGameTable.h"
#include "RoomPlayerManager.h"

namespace Object
{
	class GameRoom
	{
	public:
		GameRoom(UInt8 id):_roomId(0), _maxTableNum(0) {}
		~GameRoom() {}
		BGameTable* findTable(UInt32 tid) { return NULL; }
		BGameTable* searchTable(UInt8 &nChair, const std::string &strIp) { return NULL; }
		void breakAllGame() {}
		BGameTable* findEmptyTable(UInt32 &nChair) { return NULL; }
		BGameTable* findWaitingTable(UInt32 &nChair) { return NULL; }
		BGameTable* findCouldEnterTable(int &nChair) { return NULL;}
		bool enterUser(User *u) { return _roomPlayers.insertPlayer(u);}
		bool outUser(User *u) { return _roomPlayers.removePlayer(u); }
	private:
		UInt8  _roomId;
		UInt32 _maxTableNum;
		std::vector<BGameTable*> _arrGameTable;
		RoomPlayerManager _roomPlayers;
	};
}
#endif