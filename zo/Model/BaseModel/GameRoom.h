#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_
#include "BGameTable.h"
#include "RoomPlayerManager.h"


class GameRoom
{
public:
	GameRoom(UInt8) {}
	~GameRoom() {}
	BGameTable* findTable(UInt32 tid) { return NULL; }
	BGameTable* searchTable(UInt8 &nChair, const std::string &strIp) { return NULL; }
	void breakAllGame() {}
	BGameTable* findEmptyTable(UInt32 &nChair) { return NULL; }
	BGameTable* findWaitingTable(UInt32 &nChair) { return NULL; }
	BGameTable* findCouldEnterTable(int &nChair) { return NULL;}
private:
	UInt8  _roomId;
	UInt32 _maxTableNum;
	std::vector<BGameTable*> _arrGameTable;
};
#endif