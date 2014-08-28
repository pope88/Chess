#include "Config.h"
#include "BGameTable.h"
#include "ZoGlobal.h"
#include "User.h"
#include "Model/BaseModel/ServerModule.h"

namespace Object
{

	BGameTable::BGameTable(char cTableID, RoomPlayerManager* rpm):m_TableId(cTableID), pPlayerManager(rpm), m_MaxPlyNum(zoGlobal.playerNum()), m_cCurPlyNum(0), m_nTimerID(0), m_cMasterChairID(0), m_nBaseScore(0), m_nKickChairID(0), m_nKickTimerID(0), m_nStatus(0)
	{
		m_MaxPlyNum = zoGlobal.playerNum();
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

		m_pTable = _serverModule::instance()->createTable();
	}

	int BGameTable::findEmptyChair()
	{
		for (size_t i = 0; i < m_vecPlayers.size(); ++i)
		{
			if (m_vecPlayers[i] == NULL)
			{
				return i;
			}
		}
		return -1;
	}

	bool BGameTable::isCanJoin(User *user, int &chairId, UInt8 &res, bool bVisitor)
	{
		return true;
	}

	//void CGameTable::StartClientFinished(CUserSession* pPlayer, char cChairID)
	//{
	//	CheckReadyStatus();
	//}
	int BGameTable::joinTable(User *user, int chairId, const std::string &strPassword)
	{

		UInt8 res = 0;
		if(m_vecPlayers[chairId] == NULL)
		{
			if (isCanJoin(user, chairId, res))
			{
				canStartGame();
			}
			else
			{
			}
		}
		else
		{
			if (isCanJoin(user, chairId, res))
			{
				canStartGame();
			}
			else
			{

			}
		}
		return 0;
	}


	bool BGameTable::canStartGame()
	{
		//CheckReadyStatus();
		UInt8 mPlayerNum = 0;
		UInt8 mReadyNum = 0;
		if(zoGlobal.getReadyMode() == 0)
		{
			for(size_t i = 0; i < m_vecPlayers.size(); ++i)
			{
				if (m_vecPlayers[i] != NULL)
				{
					++mPlayerNum;
				}
			}
			if (mPlayerNum < 1)
			{
				return false;
			}

		}

		//可以开始游戏了
		if (mPlayerNum == 2)
		{
			onGameStart();
		}
		return true;
	}

	void BGameTable::onGameStart()
	{
		User *pUser = NULL;
		for (size_t i = 0; i < m_vecPlayers.size(); ++i)
		{
			pUser = m_vecPlayers[i];
			pUser->onGameStart();	
		}
		m_pTable->onGameStart();
	}


	bool BGameTable::onUserEnter(User *u, UInt8 &nchair)
	{
		if (u == NULL)
		{
			return false;
		}

		if (isTableFull())
		{
			return false;
		}

		if (nchair < zoGlobal.tableNum() && m_vecPlayers[nchair] == NULL)
		{
			m_vecPlayers[nchair] = u;
			return true;
		}
		else if(nchair == 0xFF)
		{
			for (size_t i = 0; i < m_vecPlayers.size(); ++i)
			{
				if (m_vecPlayers[i] == NULL)
				{
					m_vecPlayers[i] = u;
					nchair = i;
					return true;
				}
			}
		}
		return false;
	}


	bool BGameTable::autoUserEnter(User *u)
	{
		UInt8 chairId = 0;
		return onUserEnter(u, chairId);
	}

	bool BGameTable::isTableFull()
	{
		bool bfull = true;
		if (m_vecPlayers.empty())
		{
			bfull = false;
			return bfull;
		}
		for (size_t i = 0; i < m_vecPlayers.size(); ++i)
		{
			if (m_vecPlayers[i] == NULL)
			{
				bfull = false;
				return bfull;
			}
		}
		return bfull;
	}
}