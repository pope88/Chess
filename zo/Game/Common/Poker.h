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
	Poker():bfinishSendCard(false) {}
	~Poker() {}
public:
	void newRound();
	int getCardType() const;
	void setCards(const std::vector<CCard> &vecCards);
	void sortPlayerCards(std::vector<CCard> &vecSortCards);
	bool isStraight (std::vector<CCard> &vecSortCards) const;
	bool isFlush(std::vector<CCard> &vecSortCards);
	inline void setFinishCard(bool f) { bool bfinishSendCard = f; }
	inline bool getFinishCard() { return bfinishSendCard; }
	inline void setShowHand(bool s) { m_bShowHand = s; }
	inline bool getShowHand() { return m_bShowHand; }
	inline void setGiveUp(bool g) { m_bGiveUp = g; }
	inline bool getGiveUp() { return m_bGiveUp; }
	inline void setPickCard(bool p) { m_bPickCard = p; }
	inline bool getPickCard() { return m_bPickCard; }
	inline UInt32 getChips() { return m_nChips; }
	inline void setChips(UInt32 c) { m_nChips = c; }
	inline UInt32 getCurrentChips() { return m_nCurrentChips; }
	inline void setCurrentChips(UInt32 c) { m_nCurrentChips = c; }

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

	bool m_bShowHand;
	bool m_bGiveUp;
	bool m_bPickCard;
	int	m_nChips;
	int	m_nPlayerChips;
	int	m_nCurrentChips;
	bool bfinishSendCard;
};
#endif