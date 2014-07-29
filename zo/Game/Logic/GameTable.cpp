#include "Config.h"
#include "GameTable.h"


void GameTable::onGameStart()
{
	NewRound();

	m_Poke.NewRound();

	Dealing();

	SetBaseMoney();

	//DealingTask();

	SvrStartGameNot();
}

void GameTable::NewRound()
{
	m_Poke.NewRound();
	m_vecCommonCards.clear();
	m_vecPoker.clear();
	m_cCurOpChair = 0;
	m_cCurOpcode = 0;
	m_nPlyNum = 0;
	m_bNewRound = false;
	m_baseChips = 0;
	m_littleBlind = false;
	m_bigBlind = false;
	m_btimeOut = false;
	m_limitMoney = 0;
	m_nCommonNum = 0;
	m_nLastBigBlind = 0;

	int nChair = rand() % ePLYNUM;   //选庄家
	for(int i = 0; i < ePLYNUM; ++i)
	{
		int nOtherChair = (nChair + i) % ePLYNUM;
		Player* pPlayer = getPlayer(nOtherChair);
		Player* pBanker = getPlayer(m_Poke.m_nBanker);
		if(!pPlayer)
			continue;
		if(m_bNewRound || !pBanker)
		{
			m_Poke.m_nBanker = nOtherChair;
			m_bNewRound = false;
		}
		pPlayer->newRound();
		pPlayer->setStatus(Player::PS_PLAYER);
		++m_nPlyNum;
	}

	setGameScore();

	//notify

}

void GameTable::showPlayerStatus()
{
	pt_dz_clearstatus_not noti1;  //通知清空所有玩家状态，重新刷新
	noti1.opcode = dz_clearstatus_not;
	NotifyRoom(noti1);

	int nChair = -1;
	Player *p = getPlayer(m_Poke.m_nBanker);
	if (p && (p->getStatus() == Player::PS_PLAYER || p->getStatus() == Player::PS_GIVEUP))
	{	
		nChair = m_Poke.m_nBanker;
	}
	else //庄家不在，既已逃跑
	{
		Player* pp = getAfterPlayer(m_Poke.m_nBanker);
		if (pp)
		{
			nChair = pp->getChairID();
			m_Poke.m_nBanker = nChair;
		}
	}

	int nNum = 0;
	for (int i = 0; i < ePLYNUM; ++i)
	{
		Player *pp = getPlayer(i);
		if (pp && (pp->getStatus() == Player::PS_PLAYER || pp->getStatus() == Player::PS_GIVEUP))
		{
			++nNum; 
		}
	}

	for (int i = 0; i < ePLYNUM; ++i)
	{
		Player* pPlayer = getPlayer(nChair);
		if (!pPlayer)
		{
			++nChair;
			nChair = (nChair)%ePLYNUM;
			continue;
		}
		if (pPlayer->getStatus() == Player::PS_CANDIDATE || pPlayer->getStatus() == Player::PS_NONE)
		{
			++nChair;
			nChair = (nChair)%ePLYNUM;
			continue;
		}	

		pt_dz_status_not noti;
		noti.opcode = dz_status_not;
		noti.cChairID = nChair;
		if (nNum == 2)
		{
			if (nChair == m_Poke.m_nBanker)
			{
				pPlayer->setPlayStatus(BANKER|XIAOMANG);
				noti.nStatus = (BANKER|XIAOMANG);
			}
			else if (getBeforePlayerID(nChair) == m_Poke.m_nBanker)
			{
				pPlayer->setPlayStatus(DAMANG);
				noti.nStatus = DAMANG;
			}
		}
		else
		{
			if (nChair == m_Poke.m_nBanker)
			{
				pPlayer->setPlayStatus(BANKER);
				noti.nStatus = BANKER;
			}
			else if (getBeforePlayerID(nChair)== m_Poke.m_nBanker)
			{
				noti.nStatus = XIAOMANG;
				pPlayer->setPlayStatus(XIAOMANG);
			}
			else if (getBeforePlayerID(getBeforePlayerID(nChair)) == m_Poke.m_nBanker)
			{
				noti.nStatus = DAMANG;
				pPlayer->setPlayStatus(DAMANG);
			}
			else
			{
				noti.nStatus = COMMONPLAYER;
				pPlayer->setPlayStatus(COMMONPLAYER);
			}
		}
		NotifyRoom(noti);

		++nChair;
		nChair = (nChair)%ePLYNUM;
	}
}
void GameTable::Dealing()
{
	//timer
	this->addInterValTimer(eANIMATE_EVENT, 100);
}

void GameTable::onTimer()
{
	switch (timerId())
	{
	case eANIMATE_EVENT:
		{
			printf("eANIMATE_EVENT");
		}
		break;
	case eCALLSCORE_EVENT:
		{
		}
		break;
	default:
		break;
	}
}
