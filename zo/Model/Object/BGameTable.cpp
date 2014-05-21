#include "Config.h"
#include "BGameTable.h"
#include "ZoGlobal.h"

namespace Object
{
	BGameTable::BGameTable(char cTableID, RoomPlayerManager* rpm):m_TableId(cTableID), pPlayerManager(rpm), m_MaxPlyNum(zoGlobal.playerNum()), m_cCurPlyNum(0), m_nTimerID(0), m_cMasterChairID(0), m_nBaseScore(0), m_nKickChairID(0), m_nKickTimerID(0)
	{
		m_vecPlayers.resize(m_MaxPlyNum);
		m_vecVisitors.resize(m_MaxPlyNum);
		for (size_t i = 0; i < m_vecPlayers.size(); ++i)
		{
			m_vecPlayers[i] = NULL;
		}

		for (size_t i = 0; i < m_vecVisitors.size(); ++i)
		{
			m_vecVisitors[i] = NULL;
		}
	}

}