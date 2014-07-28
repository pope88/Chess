#ifndef _POKER_H_
#define _POKER_H_
#include "CCard.h"

class Poker
{
public:
	Poker();
	~Poker();
public:
	void newRound();
	int getCardType() const;
	void sortPlayerCards(std::vector<CCard> &vecSortCrads);
	bool isStraight (std::vector<CCard> &vecSortCards);
	bool isFlush(std::vector<CCard> &vecSortCards);
	int getCardType();
private:
	std::vector<CCard> mVecCards;
	std::vector<CCard> mVecSortCards;
	std::vector<CCard> mVecPicCards;
	std::vector<CCard> mVecTotalCards;
};
#endif