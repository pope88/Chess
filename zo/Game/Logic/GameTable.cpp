#include "Config.h"
#include "GameTable.h"
#include "../../Packet/Builder.h"
#include "../../Model/Object/User.h"


GameTable::GameTable():m_bRacing(false), m_cCurOpChair(0), m_cCurOpcode(0), m_nPlyNum(0), m_bNewRound(false), m_baseChips(0), m_blittleBlind(false), m_bbigBlind(false), m_btimeOut(false), m_limitMoney(0), m_nCommonNum(0), m_nLastBigBlind(0)
{

}

GameTable::~GameTable()
{

}

void GameTable::onGameStart()
{
	NewRound();

	showPlayerStatus();

	dealing();

	SetBaseMoney();

	//DealingTask();
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

	int nChair = rand() % ePLYNUM;   //选庄家
	for(int i = 0; i < ePLYNUM; ++i)
	{
		int nOtherChair = (nChair + i) % ePLYNUM;
		Player* pPlayer = getPlayer(nOtherChair);
		Player* pBanker = getPlayer(m_Poke.getBanker());
		if(!pPlayer)
			continue;
		if(m_bNewRound || !pBanker)
		{
			m_Poke.setBanker(nOtherChair);
			m_bNewRound = false;
		}
		pPlayer->newRound();
		pPlayer->setStatus(Player::PS_PLAYER);
		++m_nPlyNum;
	}

	setGameScore();

	SvrStartGameNot();

}

void GameTable::dealing()
{
	UInt8 beginChair = 0;
	if (m_nPlyNum == 2)
	{
		beginChair = m_Poke.getBanker();
	}
	else
	{
		beginChair = getNextPlayer(m_Poke.getBanker())->getChairID();
	}


	for(int i = 0; i < ePLYNUM; ++i)
	{
		int nOtherChair = (beginChair + i) % ePLYNUM;
		Player* pPlayer = getPlayer(nOtherChair);
		if(pPlayer != NULL && pPlayer->getStatus() == Player::PS_PLAYER)
		{
		
			Packet::PlayerHandCards ph;
			std::vector<CCard> initCards;

			CCard c = m_Poke.getCard();
			initCards.push_back(c);
			Packet::card *cd = ph.AddCards();
			cd->SetCardvalue(c.m_nValue);
			cd->SetCardcolor(c.m_nColor);

			c = m_Poke.getCard();
			initCards.push_back(c);
			cd = ph.AddCards();
			cd->SetCardvalue(c.m_nValue);
			cd->SetCardcolor(c.m_nColor);

			pPlayer->mPoker.setCards(initCards);
		//	ph.send(static_cast<Object::user*>(pPlayer->getCorePlayer()));
		}
	}
}

void GameTable::sendOperateReq(Player *prePlayer, UInt8 nPlayerNum)
{
	/*
	Player *player = NULL;
	if (prePlayer  == NULL)
	{
		return;
	}
	player  = prePlayer;
	if (nPlayerNum == 1) //处理小盲注
	{
		autoSendSmallBlind(player);
	}
	else if(m_nPlyNum == 2) //处理大盲注
	{
		autoSendBigBlind(player);
	}
	else if(m_nPlyNum == 3)
	{
		pt_dz_operator_req req;
		req.opcode = dz_operate_req;
		req.cChairID = player->getChairID();
		req.nOpcode = 0;
		req.nCurrentChips = m_Poke.getBaseChips() - player->mPoker.getCurrentChips();
		req.nBaseChip = m_Poke.getBaseChips();

		if (player->mPoker.isGiveUp())
		{
			return;
		}
		else if (req.nCurrentChips > player->getGameMoney() - player->mPoker.getChips())
		{
			pt_dz_operate_ack ack;
			ack.nOpcode = GIVEUP;
			ack.nSerialID = m_nSerialID;
			OnOperateAck(pPlayer, ack,true);
		}
		else 
		{
			if (player->getGameMoney() - player->mPoker.getChips() > req.nCurrentChips)
			{
				req.nOpcode |= ADDCHIPS;
			}
		}
		req.nOpcode |= FOLLOWCHIPS;
		req.nOpcode |= GIVEUP;
		req.send(player);

		m_cCurOpChair = player->getChairID();
		m_cCurOpcode = req.nOpcode;
		if (m_cCurOpcode & ADDCHIPS || m_cCurOpcode & FOLLOWCHIPS || m_cCurOpcode & GIVEUP )
		{
			m_cCurOpcode |= ADDCHIPS;
			m_cCurOpcode |= FOLLOWCHIPS;
			m_cCurOpcode |= GIVEUP;
		}
		m_pCoreTable->removeTimer();
		startTimer(eBET_EVENT, m_cCurOpChair);
	}
	*/
}

void GameTable::showPlayerStatus()
{
	int nChair = -1;
	Player *p = getPlayer(m_Poke.getBanker());
	if (p && (p->getStatus() == Player::PS_PLAYER || p->getStatus() == Player::PS_GIVEUP))
	{	
		nChair = m_Poke.getBanker();
	}
	else //庄家不在，既已逃跑
	{
		Player* pp = getAfterPlayer(m_Poke.getBanker());
		if (pp)
		{
			nChair = pp->getChairID();
			m_Poke.setBanker(nChair);
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
	
	Packet::PlayerGameStatus pgs;
	Packet::PGStatus *ps = pgs.AddPlayerstatus();
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

		
		ps->SetChairid(nChair);
		if (nNum == 2)
		{
			if (nChair == m_Poke.getBanker())
			{
				pPlayer->setPlayerStatus(Player::BANKER|SMALLBLIND);
			    ps->SetStatus(Player::BANKER|Player::SMALLBLIND);
			}
			else if (getBeforePlayerID(nChair) == m_Poke.getBanker())
			{
				pPlayer->setPlayerStatus(BIGBLIND);
			    ps->SetStatus(BIGBLIND);
			}
		}
		else
		{
			if (nChair == m_Poke.getBanker())
			{
				pPlayer->setPlayerStatus(Player::BANKER);
				ps->SetStatus(Player::BANKER);
			}
			else if (getBeforePlayerID(nChair) == m_Poke.getBanker())
			{
				pPlayer->setPlayerStatus(SMALLBLIND);
				ps->SetStatus(Player::SMALLBLIND);
			}
			else if (getBeforePlayerID(getBeforePlayerID(nChair)) == m_Poke.getBanker())
			{
				pPlayer->setPlayerStatus(BIGBLIND);
				ps->SetStatus(Player::BIGBLIND);
			}
			else
			{
				//noti.nStatus = COMMONPLAYER;
				pPlayer->setPlayerStatus(Player::COMMONPLAYER);
				ps->SetStatus(Player::BIGBLIND);
			}
		}

		++nChair;
		nChair = (nChair)%ePLYNUM;
	}
	NotifyRoom(pgs);
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

UInt8 GameTable::getBeforePlayerID(UInt8 nChairID)
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


Player* GameTable::getAfterPlayer(UInt8 nChairID)
{
	UInt8 chairid  = nChairID;
	for (UInt8 i = 0; i < ePLYNUM; ++i)
	{
		++chairid;
		UInt8 nNextChair = chairid % ePLYNUM;
		Player *player = getPlayer(nNextChair);
		if (player && (player->getStatus() == Player::PS_PLAYER || player->getStatus() == Player::PS_GIVEUP ) )
			return player;
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
	return NULL;
}

void GameTable::sendPlayerCard()
{
	/*
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

	int nBegin = 0;
	//int nBegin = noti.cBeginChair;
	for(int i = 0; i < ePLYNUM; ++i)   //先获得所有游戏玩家座位号
	{
		Player* player = getPlayer((i+ nBegin)%ePLYNUM);
		if(player && player->getStatus() == Player::PS_PLAYER)
		{
			//noti.vecChairs.push_back((i+nBegin)%ePLYNUM);
			vecCards.clear();
			for (int j = 0; j < 2; ++j)
			{
				vecCards.push_back(m_Poke.GetCard());
			}
			player->mPoker.setCards(vecCards);
		}
	}
	
	int nChair = 0;
	//int nChair = m_Poke.m_nBanker;
	--nChair;
	nChair = (ePLYNUM + nChair)%ePLYNUM;
	for (int i = 0; i < ePLYNUM; ++i)  //发牌
	{
		Player* pPlayer = getPlayer(nChair);
		if(pPlayer && pPlayer->getStatus() == Player::PS_PLAYER)
		{
			pPlayer->mPoker.getVecCards(noti.vecCards);
			pPlayer->sendPacket(noti);
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
	StartTimer(eDEALING_EVENT,-1);*/
}

void GameTable::onFinishSendAck(Player* p)
{
	/*
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
			player  = getPlayer(m_Poke.getBanker());
		}
		else
		{
			player = getNextPlayer(m_Poke.getBanker());
		}
		if (!player)
		{
			return;
		}
		sendOperateReq(player, 1);
	}
	*/
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

	void GameTable::autoSendBigBlind(Player *player)
	{
		if(player == NULL)
			return;
		bool bHavebigBlind = false;
		if (m_bbigBlind == false)
		{
			if ((player->getPlayerStatus() & BIGBLIND) == BIGBLIND)
			{
				bHavebigBlind = true;
			}
			else
			{
				showPlayerStatus();
				for (UInt8 i = 0; i < ePLYNUM; ++i)
				{
					Player *pp = getPlayer(i);
					if (pp && (pp->getStatus() == Player::PS_PLAYER) && ((pp->getPlayerStatus() & BIGBLIND) == BIGBLIND))
					{
						player = pp;
						bHavebigBlind = true;
					}
				}
			}
		}
		else
		{
			player->mPoker.setChips(getBaseChips());
			player->mPoker.setCurrentChips(player->mPoker.getChips());
			m_Poke.setTotalChips(player->mPoker.getChips());
			m_Poke.setBaseChips(player->mPoker.getChips());
			player->mPoker.setPlayerChips(player->mPoker.getPlayerChips() + player->mPoker.getChips());
			m_bbigBlind = player->mPoker.getChips();

			//pt_dz_operate_not noti;
			//noti.opcode = dz_operate_not;
			//noti.nChairID = player->getChairID();
			//noti.nOpcode = BIGBLIND;
			//noti.nChip = player->mPoker.getChips();
			//noti.nUserAmount = player->mPoker.getPlayerChips();
			//noti.nTableAmount = m_Poke.getTotalChips();
			//noti.mLeaveAmount = player->getGameMoney() - player->mPoker.getPlayerChips();
			//NotifyRoom(noti);
			m_bbigBlind = true;

			m_nLastBigBlind = getBaseChips();
			
			Player *pp  = getNextPlayer(player->getChairID());
			if (pp != NULL)
			{
				sendOperateReq(pp, 3);
			}
		}
	}


