#include "Config.h"
#include "GameRoom.h"
#include "ZoGlobal.h"
#include "BGameTable.h"

#include <cassert>
namespace Object
{
	GameRoom::GameRoom(UInt8 id):_roomId(0), _maxTableNum(zoGlobal.tableNum())
	{
		_arrGameTable.resize(_maxTableNum);
		_roomPlayers = new(std::nothrow)RoomPlayerManager();
		assert(_roomPlayers != NULL);
		
		for(size_t i = 0; i < _maxTableNum; ++i)
		{
			_arrGameTable[i] = new BGameTable(i, _roomPlayers);
		}
	}

	void GameRoom::breakAllGame()
	{
		for(auto it = _arrGameTable.begin(); it != _arrGameTable.end(); ++it)
		{
			(*it)->GMBreakGame(0);
		}
	}

	BGameTable* GameRoom::findTable(UInt32 tid)
	{
		for (auto it = _arrGameTable.begin(); it != _arrGameTable.end(); ++it)
		{
			if (tid == (*it)->getTableID())
			{
				return *it;
			}
		}
		return NULL;
	}

	BGameTable* GameRoom::findEmptyTable(Int8 &nChair)
	{
		for (size_t i = 0; i < _arrGameTable.size(); ++i)
		{
			if(((BGameTable*)_arrGameTable[i])->getStatus() == BGameTable::TS_EMPTY)
			{
				nChair = _arrGameTable[i]->findEmptyChair();
				return _arrGameTable[i];
			}
		}
		return NULL;
	}

	BGameTable* GameRoom::findWaitingTable(UInt32 &nChair)
	{
		for (size_t i = 0; i < _arrGameTable.size(); ++i)
		{
			if(((BGameTable*)_arrGameTable[i])->getStatus() == BGameTable::TS_WATING)
			{
				nChair = _arrGameTable[i]->findEmptyChair();
				return _arrGameTable[i];
			}
		}
		return NULL;
	}

	bool GameRoom::enterTable(User *u, UInt32 tableNo, UInt8 nchair)
	{
		if (u == NULL)
		{
			return false;
		}
		BGameTable *pt = NULL;
		if (tableNo < _arrGameTable.size())
		{
			 pt = _arrGameTable[tableNo];
		}
		if (pt == NULL)
		{
			return false;
		}
		if (pt->onUserEnter(u, nchair))
		{
			pt->canStartGame();
		}
		
		return true;
	}

	bool GameRoom::enterUser(User *u)
	{ 
		u->setInRoom(this);
		return _roomPlayers->insertPlayer(u);	
	}

	bool GameRoom::outUser(User *u)
	{ 
		return _roomPlayers->removePlayer(u); 
		u->setInRoom(NULL);
	}

}