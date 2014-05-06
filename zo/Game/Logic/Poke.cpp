/*
 CopyRight(c)2006 by Banding,Shanghai, All Right Reserved.

 @Date:	        2009/4/15
 @Created:	    15:02
 @Filename: 	Poke.cpp
 @File path:	BDLeyoyoV2\DDZV2\Server 
 @Author:		leiliang
 @Description:	
*/

#include "Config.h"
#include "Poke.h"
#include "GameTable.h"

Poke::Poke()
{
}

Poke::~Poke()
{
}

void Poke::ShuffleCards()
{
	//3, 4, 5, .....K, A, 2, 
	for(int i = 3; i <= 15; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			Card Card;
			Card.m_nColor = j;
			Card.m_nValue = i;
			m_AllCards.push_back(Card);
		}
	}
	//小王,大王
	for(int i = 0; i <= 1; i++)
	{
		Card Card;
		Card.m_nColor = i;
		Card.m_nValue = 16;
		m_AllCards.push_back(Card);
	}

	//洗牌
	random_shuffle(m_AllCards.begin(), m_AllCards.end());
}

void Poke::NewRound()
{
	//成员初始化
	m_nNextPlayer = 0;
	m_nBombCounter = 0;
	m_nDecideLordRound = 0;
	memset(m_bSendCardOK, false, sizeof(m_bSendCardOK));
	m_AllCards.clear();
	m_cLordCard.clear();
	//洗牌
	ShuffleCards();
	//设置3张底牌
	for(int i = 0; i < 3; i++)
	{
		m_cLordCard.push_back(GetCard());
	}
	//设定地主
	SetDefaultLord();
}

void Poke::SetDefaultLord()
{
	//随机翻出的一张牌
	m_nRanCardPos = rand() % m_AllCards.size();
	m_nDefaultLord = m_nRanCardPos % 3;
	m_nCurrentLord = m_nDefaultLord;

	m_nRanCardPos = (int)m_AllCards.size() - m_nRanCardPos - 1;
	m_cRanCard = m_AllCards[m_nRanCardPos];

    //by me 百搭牌不可以是大小王
    while (m_cRanCard.m_nValue == 15 || m_cRanCard.m_nValue == 16)
    {
        m_nRanCardPos = rand() % m_AllCards.size();
        m_nDefaultLord = m_nRanCardPos % 3;
        m_nCurrentLord = m_nDefaultLord;

        m_nRanCardPos = (int)m_AllCards.size() - m_nRanCardPos - 1;
        m_cRanCard = m_AllCards[m_nRanCardPos];
    }
}

Card& Poke::GetCard(int nPos)
{
	if( (size_t)nPos >= 0 && (size_t)nPos < m_AllCards.size() )
	{
		return m_AllCards[nPos];
	}
	Card cCard;
	return cCard;
}

Card& Poke::GetCard()
{
	if( !m_AllCards.empty() )
	{
		Card& cCard = m_AllCards.back();
		m_AllCards.pop_back();
		return cCard;
	}
	Card cCard;
	return cCard;
}