#include "Config.h"
#include "Poke.h"
#include "GameTable.h"

Poke::Poke(): _m_nBanker(0), _bigBlind(0), _totalChips(0), _baseChips(0), _finishNum(0)
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
			CCard Card;
			Card.m_nValue = i;
			Card.m_nColor = j;
			m_AllCards.push_back(Card);
		}
	}
	//ϴ��
	random_shuffle(m_AllCards.begin(), m_AllCards.end());
}

void Poke::NewRound()
{
	_m_nBanker = 0;
	_bigBlind = 0;
	_totalChips = 0;            
	_baseChips = 0;    
	_finishNum = 0;
}



CCard& Poke::GetCard(int nPos)
{
	if( (size_t)nPos >= 0 && (size_t)nPos < m_AllCards.size() )
	{
		return m_AllCards[nPos];
	}
	CCard cCard;
	return cCard;
}

CCard& Poke::GetCard()
{
	if( !m_AllCards.empty() )
	{
		CCard& cCard = m_AllCards.back();
		m_AllCards.pop_back();
		return cCard;
	}
	CCard cCard;
	return cCard;
}