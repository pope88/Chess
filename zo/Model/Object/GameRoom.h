#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_
#include "BGameTable.h"
#include "RoomPlayerManager.h"
#include "User.h"

namespace Object
{
	class GameRoom
	{
	public:
		GameRoom(UInt8 id);
		~GameRoom() {}
		inline UInt8 roomId() { return _roomId; }
		inline UInt32 roomPlayerNum()  { return _roomPlayers->getPlayerNum(); }
		BGameTable* findTable(UInt32 tid);
		BGameTable* findEmptyTable(Int8 &nChair);
		BGameTable* findWaitingTable(UInt32 &nChair);
		BGameTable* findCouldEnterTable(int &nChair) { return NULL;}
		bool enterUser(User *u) { return _roomPlayers->insertPlayer(u);}
		bool outUser(User *u) { return _roomPlayers->removePlayer(u); }
		bool enterTable(User *u, UInt32 tableNo = 0xFFFFFFFF, UInt8 nchair = 0xFF);
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