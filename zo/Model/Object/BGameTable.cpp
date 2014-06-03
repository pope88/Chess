#include "Config.h"
#include "BGameTable.h"
#include "ZoGlobal.h"

namespace Object
{
	BGameTable::BGameTable(char cTableID, RoomPlayerManager* rpm):m_TableId(cTableID), pPlayerManager(rpm), m_MaxPlyNum(zoGlobal.playerNum()), m_cCurPlyNum(0), m_nTimerID(0), m_cMasterChairID(0), m_nBaseScore(0), m_nKickChairID(0), m_nKickTimerID(0), m_nStatus(0)
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

	bool BGameTable::isCanJoin(User *user, int &chairId, UInt8 &res, bool bVisitor = false)
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
			}
			else
			{

			}
		}
		else
		{
			if (isCanJoin(user, chairId, res))
			{
			}
			else
			{

			}
		}
	}


	bool BGameTable::canStartGame()
	{
		//CheckReadyStatus();
		if(zoGlobal.getReadyMode() == 0)//坐满且全举手
		{
			for(size_t i = 0; i < m_vecPlayers.size(); ++i)
			{
				if(m_vecPlayers[i] == NULL || m_vecPlayers[i]->GetStatus() != CUserSession::US_READY)
					return false;
			}
		}
		else if(CConfigManager::GetInstancePtr()->GetReadyMode() == 1)//2人以上且全举手
		{
			int nReadyNum = 0;
			for(size_t i = 0; i < m_vecPlayers.size(); ++i)
			{
				if(m_vecPlayers[i] != NULL)
				{ 
					if(!m_pTable->CanJoinGame() && !m_vecPlayers[i]->Is2ndRound())
						continue;
					if(m_vecPlayers[i]->GetStatus() != CUserSession::US_READY)
					{
						return false; //有人未举手
					}
					++nReadyNum;
				}
			}
			if(nReadyNum < 2)
				return false;
		}
		else if(CConfigManager::GetInstancePtr()->GetReadyMode() == 2)//对家有人且举手
		{
			int nReadyNum = 0;
			int nDouble = m_vecPlayers.size() / 2;

			for(int i = 0; i < nDouble; ++i)
			{
				if(m_vecPlayers[i] != NULL || m_vecPlayers[i + nDouble] != NULL)
				{
					if(!m_vecPlayers[i] || m_vecPlayers[i]->GetStatus() != CUserSession::US_READY)
					{
						return false;
					}
					if(!m_vecPlayers[i + nDouble] || m_vecPlayers[i + nDouble]->GetStatus() != CUserSession::US_READY)
					{
						return false;
					}
					nReadyNum++;
				}
			}
			if(nReadyNum < 1)
				return false;
		}
		else if(CConfigManager::GetInstancePtr()->GetReadyMode() == 3)//3人以上且全举手
		{
			int nReadyNum = 0;
			for(size_t i = 0; i < m_vecPlayers.size(); ++i)
			{
				if(m_vecPlayers[i] != NULL)
				{ 
					if(!m_pTable->CanJoinGame() && !m_vecPlayers[i]->Is2ndRound())
						continue;
					if(m_vecPlayers[i]->GetStatus() != CUserSession::US_READY)
					{
						return false; //有人未举手
					}
					++nReadyNum;
				}
			}
			if(nReadyNum < 3)
				return false;
		}
		else
			return false;

		//可以开始游戏了
		OnStartGame();
		return true;
	}
}