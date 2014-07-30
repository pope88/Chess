#include "Config.h"
#include "GameTable.h"


GameTable::GameTable():m_cCurOpChair(0), m_cCurOpcode(0), m_nPlyNum(0), m_bNewRound(false), m_baseChips(0), m_blittleBlind(false), m_bbigBlind(false), m_btimeOut(false), m_limitMoney(0), m_nCommonNum(0), m_nLastBigBlind(0)
{

}

GameTable::~GameTable()
{

}

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
	m_blittleBlind = false;
	m_bbigBlind = false;
	m_btimeOut = false;
	m_limitMoney = 0;
	m_nCommonNum = 0;
	m_nLastBigBlind = 0;

	int nChair = rand() % ePLYNUM;   //ѡׯ��
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
	pt_dz_clearstatus_not noti1;  //֪ͨ����������״̬������ˢ��
	noti1.opcode = dz_clearstatus_not;
	NotifyRoom(noti1);

	int nChair = -1;
	Player *p = getPlayer(m_Poke.m_nBanker);
	if (p && (p->getStatus() == Player::PS_PLAYER || p->getStatus() == Player::PS_GIVEUP))
	{	
		nChair = m_Poke.m_nBanker;
	}
	else //ׯ�Ҳ��ڣ���������
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
void GameTable::deaLing()
{

}

void GameTable::startTimer(int nEvent, char cChair)
{
	if (nEvent == eBET_EVENT)
	{
		this->addInterValTimer(eBET_EVENT, eBET_PERIOD);
	}
	else if (nEvent == ePICK_EVENT)
	{
		this->addInterValTimer(ePICK_EVENT, ePICK_PERIOD);
	}
	else if(nEvent == eDEALING_EVENT)
	{
		this->addInterValTimer(eDEALING_EVENT, eDEALING_PERIOD);
	}
	//timer
	
}

void GameTable::onTimer()
{
	switch (timerId())
	{
	case eBET_EVENT:
		{
			printf("eBET_EVENT");
		}
		break;
	case ePICK_EVENT:
		{
		}
		break;
	case eDEALING_EVENT:
		{

		}
		break;
	default:
		break;
	}
}

int GameTable::getBeforePlayerID(int nChairID)
{
	int nTemp = 0;
	for (int i = 1; i <= ePLYNUM+1; ++i)
	{
		nTemp = (nChairID - i + ePLYNUM)%ePLYNUM;
		Player* p = getPlayer(nTemp);
		if (p && (p->getStatus() == Player::PS_PLAYER || p->getStatus() == Player::PS_GIVEUP))
		{
			return p->getChairID();
		}
	}
	return nChairID;
}

Player* GameTable::getNextPlayer(UInt8 nChairID)
{
	UInt8 chairid = nChairID;
	for(int i = 0; i < ePLYNUM; ++i)
	{
		++chairid;
		UInt8 cNextChair = chairid % ePLYNUM;
		Player *p = getPlayer(cNextChair);
		if(p && p->getStatus() == Player::PS_PLAYER)
			return p;
	}
	return NULL;
}


void GameTable::SendCompleteData(Player* pPlayer)
{
	//pt_dz_completedata_not noti;
}

Player* GameTable::getPlayer(UInt8 nChairID)
{
	//ICorePlayer* pCorePlayer = m_pCoreTable->GetCorePlayer(nChairID);
	//if(pCorePlayer)
	//	return (CPlayer*)pCorePlayer->GetIPlayer();
	//return NULL;
}

void GameTable::sendPlayerCard()
{
	std::vector<CCard> vecCards;
	//pt_dz_sendcard_not noti;
	//noti.opcode = dz_sendcard_not;
	if (m_nPlyNum == 2)
	{
		//noti.cBeginChair = m_Poke.m_nBanker;
	}
	else
	{
		Player* pp = getNextPlayer(m_Poke.m_nBanker);
		if (pp)
		{
			//noti.cBeginChair = pp->getChairID();
		}
	}

	int nBegin = noti.cBeginChair;
	for(int i = 0; i < ePLYNUM; ++i)   //�Ȼ��������Ϸ�����λ��
	{
		Player* player = getPlayer((i+ nBegin)%ePLYNUM);
		if(player && player->getStatus() == Player::PS_PLAYER)
		{
			noti.vecChairs.push_back((i+nBegin)%ePLYNUM);
			vecCards.clear();
			for (int j = 0; j < 2; ++j)
			{
				vecCards.push_back(m_Poke.getPokeCard());
			}
			player->mPoker.setCards(vecCards);
		}
	}

	int nChair = m_stMJTable.m_nBanker;
	--nChair;
	nChair = (ePLYNUM + nChair)%ePLYNUM;
	for (int i = 0; i < ePLYNUM; ++i)  //����
	{
		CPlayer* pPlayer = GetPlayer(nChair);
		if(pPlayer && pPlayer->GetStatus() == CPlayer::PS_PLAYER)
		{
			noti.vecCards = pPlayer->m_stMJUser.m_vecCards;
			pPlayer->SendPacket(noti);
			if (pPlayer->CanWatch())
			{
				NotifyVistor(nChair, noti);
			}
			else
			{
				st_card EmptyCard;
				vector<st_card> temp;
				temp.push_back(EmptyCard);
				temp.push_back(EmptyCard);
				noti.vecCards  = temp;
				NotifyVistor(nChair, noti);
			}

		}
		--nChair;
		nChair = (ePLYNUM + nChair)% ePLYNUM;
	}
	m_pCoreTable->RemoveTimer();
	StartTimer(eDEALING_EVENT,-1);
}

void GameTable::onFinishSendAck(Player* p)
{
	if (!p)
	{
		return;
	}

	if (!p->mPoker.getFinishCard())
	{
		p->mPoker.setFinishCard(true);
		++m_Poke._finishNum++;
	}
	else
	{
		return;
	}

	bool bBegin = true;
	for (int i = 0; i < ePLYNUM; ++i)
	{
		Player *p = getPlayer(i);
		if (p && (p->getStatus() == Player::PS_PLAYER) && !p->mPoker.getFinishCard())
		{
			bBegin = false;
			break;
		}
	}
	if (bBegin)
	{
		Player *player  = NULL;
		if (m_nPlyNum == 2)
		{
			player  = getPlayer(m_Poke.m_nBanker);
		}
		else
		{
			player = getNextPlayer(m_Poke.m_nBanker);
		}
		if (!player)
		{
			return;
		}
		sendOperateReq(player, 1);
	}
}


void GameTable::autoSendSmallBlind(Player *player)
{
	if (!player)
	{
		return;
	}
	bool bhaveSmallBlind = false;
	if (!m_blittleBlind)
	{
		if ((player->getStatus() & Player::SMALLBLIND) == Player::SMALLBLIND)
		{
			bhaveSmallBlind = true;
		}
		else
		{
			showPlayerStatus();
			for (int i = 0; i < ePLYNUM; ++i)
			{
				Player *p = getPlayer(i);
				if (p && (p->getStatus() == Player::PS_PLAYER) && (p->getStatus() & Player::SMALLBLIND) == Player::SMALLBLIND )
				{
					player = p;
					bhaveSmallBlind = true;
				}
			}
		}
	}
	else
	{

	}

	if (bhaveSmallBlind)
	{
		player->mPoker.setChips(getBaseChips()/2);
		player->mPoker.setCurrentChips(getBaseChips()/2);
		m_Poke.setTotalChips(m_Poke.getTotalChips() + getBaseChips()/2);
		m_Poke.setBaseChips(getBaseChips()/2);

		Player *p = getNextPlayer(player->getChairID());
		if (p != NULL)
		{
			sendOperateReq(p, 2);
		}
	}

}
