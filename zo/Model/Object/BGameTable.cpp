#include "Config.h"
#include "BGameTable.h"
#include "ZoGlobal.h"
#include "User.h"
#include "Model/BaseModel/ServerModule.h"
#include "../../Packet/Builder.h"

namespace Object
{

	BGameTable::BGameTable(char cTableID, RoomPlayerManager* rpm):m_TableId(cTableID), pPlayerManager(rpm), m_MaxPlyNum(zoGlobal.playerNum()), m_cCurPlyNum(0), m_PlyNum(0), m_nTimerID(0), m_cMasterChairID(0), m_nBaseScore(0), m_nKickChairID(0), m_nKickTimerID(0), m_nStatus(0)
	{
		m_MaxPlyNum = zoGlobal.playerNum();
		m_vecUsers.resize(m_MaxPlyNum);
		m_vecVisitors.resize(m_MaxPlyNum);
		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			m_vecUsers[i] = NULL;
		}

		for (size_t i = 0; i < m_vecVisitors.size(); ++i)
		{
			m_vecVisitors[i] = NULL;
		}

		m_pTable = _serverModule::instance()->createTable();
		m_pTable->bindCoreTable2Table(this);
	}


	bool BGameTable::leaveTable(User* pPlayer)
	{
		if(pPlayer != NULL) 
		{
			pPlayer->setInTable( NULL);
			return true;
		}
		return false;
	}

	int BGameTable::findEmptyChair()
	{
		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			if (m_vecUsers[i] == NULL)
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
		if(m_vecUsers[chairId] == NULL)
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
			for(size_t i = 0; i < m_vecUsers.size(); ++i)
			{
				if (m_vecUsers[i] != NULL)
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
		if (mPlayerNum >= 2 && (m_nStatus == TS_WATING || m_nStatus == TS_EMPTY)) 
		{
			onGameStart();
		}
		return true;
	}

	void BGameTable::onGameStart()
	{
		User *pUser = NULL;
		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			pUser = static_cast<User*>(m_vecUsers[i]);
			if (pUser != NULL)
			{
				pUser->onGameStart();	
			}
		}
		m_pTable->onGameStart();

		m_nStatus = TS_RACING;
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

		if (nchair < zoGlobal.tableNum() && m_vecUsers[nchair] == NULL)
		{
			m_vecUsers[nchair] = u;
			u->setChairId(nchair);
			u->setInTable(this);
			if (m_nStatus == TS_EMPTY)
			{
				m_nStatus = TS_WATING;
			}
			return true;
		}
		else if(nchair == 0xFF)
		{
			for (size_t i = 0; i < m_vecUsers.size(); ++i)
			{
				if (m_vecUsers[i] == NULL)
				{
					m_vecUsers[i] = u;
					nchair = i;
					++m_PlyNum;
					u->setChairId(nchair);
					u->setInTable(this);
					if (m_nStatus == TS_EMPTY)
					{
						m_nStatus = TS_WATING;
					}
					return true;
				}
			}
		}
		return false;
	}

	void BGameTable::onUserOut(User *u)
	{
		if (u == NULL)
		{
			return;
		}

		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			if (m_vecUsers[i] == u)
			{
				m_vecUsers[i] = NULL;
				u->setChairId(-1);
                u->setInTable(NULL);
				return;
			}
		}
	}


	bool BGameTable::autoUserEnter(User *u)
	{
		if (this->isTableFull())
		{
			return false;
		}
		UInt8 chairId = 0;
		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			if (m_vecUsers[i] == NULL)
			{
				chairId = i;
				break;
			}
		}
		if(onUserEnter(u, chairId))
		{
			Packet::UserEnterTable  ue;
			ue.SetRes(0);
			Packet::PlayerBaseInfo *pbi = NULL;
			pbi = ue.AddPlayerinfos();
			pbi->SetChairid(chairId);
			pbi->SetNickname(u->name());
			pbi->SetAllchips(u->getMoney());
			notifyTable(ue, u);

			Packet::UserEnterTable  ueo;
			Packet::PlayerBaseInfo *pbio = NULL;
			pbio = ueo.AddPlayerinfos(); //me
			pbio->SetChairid(u->getChairId());
			pbio->SetNickname(u->name());
			pbio->SetAllchips(u->getMoney());

			for (size_t i = 0; i < m_vecUsers.size(); ++i)
			{
				User *pUser = static_cast<User*>(m_vecUsers[i]);
				if (pUser == NULL || pUser == u)
				{
					continue;
				}

				pbio = ueo.AddPlayerinfos();
				pbio->SetChairid(pUser->getChairId());
				pbio->SetNickname(pUser->name());
				pbio->SetAllchips(pUser->getMoney());
			}
			ueo.send(u);
			return true;
		}
		else 
		{
			Packet::UserEnterTable  ue;
			ue.SetRes(1);
			ue.send(u);
			return false;
		}
		return false;
	}

	bool BGameTable::isTableFull()
	{
		bool bfull = true;
		if (m_vecUsers.empty())
		{
			bfull = false;
			return bfull;
		}
		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			if (m_vecUsers[i] == NULL)
			{
				bfull = false;
				return bfull;
			}
		}
		return bfull;
	}

	void BGameTable::startClientTimer(char cChairID, int nPeriod)
	{
		if(cChairID == -1)
		{
			Packet::UserTimerStart ut;
			ut.SetTimer(nPeriod);
			notifyTable(ut);
		}
		else
		{
			Packet::UserTimerStart ut;
			ut.SetTimer(nPeriod);
			ut.SetChairid(cChairID);
			notifyTable(ut);
		}
	}
}