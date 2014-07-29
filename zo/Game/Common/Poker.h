#ifndef _POKER_H_
#define _POKER_H_
#include "CCard.h"

class cardCompare
{
public:
	bool operator()(const CCard &as, const CCard &bs)
	{
		return as.m_nValue < bs.m_nValue;
	}
};

class dcardCompare
{
public:
	bool operator()(const CCard &as, const CCard &bs)
	{
		return as.m_nValue > bs.m_nValue;
	}
};
class Poker
{
public:
	Poker();
	~Poker();
public:
	void newRound();
	int getCardType() const;
	void setCards(const std::vector<CCard> &vecCards);
	void sortPlayerCards(std::vector<CCard> &vecSortCards);
	bool isStraight (std::vector<CCard> &vecSortCards) const;
	bool isFlush(std::vector<CCard> &vecSortCards);
	int getCardType();
	inline void getSortVecCards(std::vector<CCard> &cards)
	{
		cards = mVecSortCards;
	}
private:
	std::vector<CCard> mVecCards;
	std::vector<CCard> mVecSortCards;
	std::vector<CCard> mVecPicCards;
	std::vector<CCard> mVecTotalCards;
};
#endif