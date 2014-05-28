#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_
#include "BGameTable.h"
#include "RoomPlayerManager.h"

namespace Object
{
	class GameRoom
	{
	public:
		GameRoom(UInt8 id);
		~GameRoom() {}
		inline UInt8 roomId() { return _roomId; }
		UInt32 roomPlayerNum()  { return _roomPlayers->getPlayerNum(); }
		BGameTable* findTable(UInt32 tid) { return NULL; }
		BGameTable* searchTable(UInt8 &nChair, const std::string &strIp) { return NULL; }
		BGameTable* findEmptyTable(UInt32 &nChair) { return NULL; }
		BGameTable* findWaitingTable(UInt32 &nChair) { return NULL; }
		BGameTable* findCouldEnterTable(int &nChair) { return NULL;}
		bool enterUser(User *u) { return _roomPlayers->insertPlayer(u);}
		bool outUser(User *u) { return _roomPlayers->removePlayer(u); }
		void onHeartBit() { _roomPlayers->onHeartBit(); }
		void breakAllGame();
	private:
		UInt8  _roomId;
		UInt32 _maxTableNum;
		std::vector<BGameTable*> _arrGameTable;
		RoomPlayerManager *_roomPlayers;
	};
}
#endif