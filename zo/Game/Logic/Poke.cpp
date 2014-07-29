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
	//Ï´ÅÆ
	random_shuffle(m_AllCards.begin(), m_AllCards.end());
}

void Poke::NewRound()
{
	_bigBlind = 0;
	_totalChips = 0;            
	_baseChips = 0;    
	_finishNum = 0;
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