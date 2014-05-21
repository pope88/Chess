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
}