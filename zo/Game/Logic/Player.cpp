#include "Config.h"
#include "Player.h"


Player::Player() : m_pCorePlayer(NULL), /*m_pGameTable(NULL),*/ m_nStatus(PS_NONE)
{
}

Player::~Player()
{
}

void Player::newRound()
{
	mPoker.newRound();
	m_nStatus = PS_NONE;
}

void Player::getCard(Card& cCard)
{
	m_PlayCard.m_cCards.push_back(cCard);
}

void Player::getPlayerCards(::ssu::Object &noti, bool bShow)
{
	//noti.opcode = Svr_RefreshCard_Not;
	//noti.cChairID = m_pCorePlayer->GetChairID();
	//noti.vecCards = m_PlayCard.m_cCards;

	////显示牌面
	//if( !bShow && !m_bShowCard )
	//{
	//	for(size_t i = 0; i < noti.vecCards.size(); i++)
	//	{
	//		Card& cCard = noti.vecCards[i];
	//		cCard.m_nColor = 0;
	//		cCard.m_nValue = 0;
	//	}
	//}
}


bool Player::doPlayCard(Player* pPutPlayer)
{
	//此处避免bug
	if( pPutPlayer != this )	//非首家出牌
	{
		if(pPutPlayer->m_PlayCard.m_cDiscardingType.m_nTypeNum == 222)
		{
			m_PlayCard.lasttype = 222;
		}
		else if(pPutPlayer->m_PlayCard.m_cDiscardingType.m_nTypeNum == 2222)
		{
			m_PlayCard.lasttype = 2222;
		}
	}

	int nCompare = 0;
	if( m_PlayCard.CheckChoosing() == 1 )
	{
		//重新给lasttype赋值0
		m_PlayCard.lasttype = 0;
		if( pPutPlayer == this )	//首家出牌
		{
			nCompare = 1;
		}
		else if( pPutPlayer->m_PlayCard.m_cDiscardingType.m_nTypeNum != 0 )
		{
			nCompare = m_PlayCard.CompareCards(pPutPlayer->m_PlayCard.m_cDiscardingType);
			if( nCompare != 1 )
			{
				//glog.log("Put: Bomb=%d, num=%d, value=%d, Me: Bomb=%d, num=%d, value=%d",pPutPlayer->m_PlayCard.m_cDiscardingType.m_nTypeBomb,
				//	pPutPlayer->m_PlayCard.m_cDiscardingType.m_nTypeNum, pPutPlayer->m_PlayCard.m_cDiscardingType.m_nTypeValue,m_PlayCard.m_cDiscardingType.m_nTypeBomb,m_PlayCard.m_cDiscardingType.m_nTypeNum, m_PlayCard.m_cDiscardingType.m_nTypeValue);
			}
		}

		if( nCompare != 1 )
		{
			return false;
		}
	}
	else
	{ 
		return false;
	}


	//如果出的是炸弹
	if(m_PlayCard.m_cDiscardingType.m_nTypeNum == 4)
	{
		//m_pGameTable->m_Poke.m_nBombCounter++;
		//m_pGameTable->m_nDouble *= 2;
		//m_pGameTable->SendDoubleInfo();
	}

	//减去玩家出的牌
	if (m_PlayCard.trueCards.size() >0 )
	{
		m_PlayCard.EraseCards(m_PlayCard.trueCards);      //删除确实应该删除的牌
	}
	else
	{
		m_PlayCard.EraseCards(m_PlayCard.m_cChoosingCards);
	}


	return true;
}


void Player::release()
{
	//m_pGameTable = NULL;
	m_pCorePlayer = NULL;
	delete this;
}


/*
void Player::ProcessPacket(const char* pData, int nLen)
{
	CInputStream is(pData, nLen);
	short opcode;
	is >> opcode;
	is.Reset();

	switch(opcode)
	{
	case Cli_SendCardOK_Ack:	DISPATCH_MESSAGE(pt_Cli_SendCardOK_Ack);	break;
	case Cli_CallScore_Ack:		DISPATCH_MESSAGE(pt_Cli_CallScore_Ack);		break;
	case Cli_PlayCard_Ack:		DISPATCH_MESSAGE(pt_Cli_PlayCard_Ack);		break;
	case Cli_RobLord_Ack:		DISPATCH_MESSAGE(pt_Cli_RobLord_Ack);		break;
	case Cli_Auto_Req:			DISPATCH_MESSAGE(pt_Cli_Auto_Req);			break;
	case Cli_CompleteData_Req:	DISPATCH_MESSAGE(pt_Cli_CompleteData_Req);	break;
	case Cli_Voice_Req:			DISPATCH_MESSAGE(pt_Cli_Voice_Req);			break;
	case Cli_ShowCard_Ack:		DISPATCH_MESSAGE(pt_Cli_ShowCard_Ack);		break;
	default:
		g_pLogger->Log("Unknow Cmd %d", opcode);		
		break;
	}
}

void Player::OnPacket(const pt_Cli_SendCardOK_Ack& ack)
{
	if( m_pGameTable && m_pGameTable->m_bRacing )
	{
		m_pGameTable->CliSendCardAck(ack, this);
	}
}

void Player::OnPacket(const pt_Cli_CallScore_Ack& ack)
{
	if( m_pGameTable && m_pGameTable->m_bRacing )
	{
		m_pGameTable->CliCallScoreAck(ack, this);
	}
}

void Player::OnPacket(const pt_Cli_RobLord_Ack& ack)
{
	if( m_pGameTable && m_pGameTable->m_bRacing )
	{
		m_pGameTable->CliRobLordAck(ack, this);
	}
}

void Player::OnPacket(const pt_Cli_PlayCard_Ack& ack)
{
	if( m_pGameTable && m_pGameTable->m_bRacing )
	{
		m_pGameTable->CliPlayCardAck(ack, this);
	}
}

void Player::OnPacket(const pt_Cli_Auto_Req& req)
{
	if( m_pGameTable && m_pGameTable->m_bRacing )
	{
		m_bAuto = req.cAuto;

		pt_Svr_Auto_Not noti;
		noti.opcode = Svr_Auto_Not;
		noti.cChairID = GetChairID();
		noti.cAuto = req.cAuto;
		m_pGameTable->NotifyRoom(noti);
	}
}

void Player::OnPacket(const pt_Cli_CompleteData_Req& req)
{
	if( m_pGameTable )
	{
		m_pGameTable->GetCompleteData(this);
	}
}

void Player::OnPacket(const pt_Cli_Voice_Req& req)
{
	if( m_pGameTable )
	{
		m_pGameTable->NotifyRoom(req);
	}
}

void Player::OnPacket(const pt_Cli_ShowCard_Ack& ack)
{
	if( m_pGameTable && m_pGameTable->m_bRacing )
	{
		m_pGameTable->CliShowCardAck(ack, this);
	}
}
*/