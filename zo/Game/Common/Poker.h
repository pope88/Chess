#ifndef _POKER_H_
#define _POKER_H_
#include "CCard.h"

struct CardType //when they type is same,wich bigger is compare by the keyvalue
{
	//10-0
	UInt8 type;
	//key value
	UInt8 keyvalue;
	CardType():type(0), keyvalue(0)
	{
	}
	void clear()
	{
		type = 0;
		keyvalue = 0;
	}
	bool operator>(const CardType &b)
	{
		if(type > b.type)
			return true;
		else if((type == b.type) && (keyvalue > b.keyvalue))
			return true;
		else 
			return false;
	}
	bool operator==(const CardType &b)
	{
		return (type == b.type) && (keyvalue == b.keyvalue);
	}
};

class cardCompare
{
public:
	bool operator()(const CCard &as,const CCard &bs)
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

class typeCompare
{
public:
	bool operator()(const CardType &at, const CardType &bt)
	{
		if (at.type != bt.type)
		{
			return at.type < bt.type;
		}
		else
		{
			return at.keyvalue < bt.keyvalue;
		}
	}
};

class dtypeCompare
{
public:
	bool operator()(const CardType &at, const CardType &bt)
	{
		if (at.type != bt.type)
		{
			return at.type > bt.type;
		}
		else
		{
			return at.keyvalue > bt.keyvalue;
		}
	}
};

class Poker
{
public:
	Poker():bfinishSendCard(false) {}
	~Poker() {}
public:
	void newRound();
	void setCards(const std::vector<CCard> &vecCards);
	void setCommonCards(const std::vector<CCard> &vecCards);
	void sortPlayerCards(std::vector<CCard> &vecSortCards);
	bool isStraight (std::vector<CCard> &vecSortCards) const;
	bool isFlush(std::vector<CCard> &vecSortCards);
	inline void setFinishCard(bool f) { bool bfinishSendCard = f; }
	inline bool isFinishCard() { return bfinishSendCard; }
	inline void setGiveUp(bool g) { m_bGiveUp = g; }
	inline bool isGiveUp() { return m_bGiveUp; }
	inline void setPickCard(bool p) { m_bPickCard = p; }
	inline bool isPickCard() { return m_bPickCard; }
	inline UInt32 getChips() { return m_nChips; }
	inline void setChips(UInt32 c) { m_nChips = c; }
	inline UInt32 getCurrentChips() { return m_nCurrentChips; }
	inline void setCurrentChips(UInt32 c) { m_nCurrentChips = c; }
	inline UInt32 getPlayerChips() { return m_nPlayerChips; }
	inline void setPlayerChips(UInt32 c) { m_nPlayerChips = c; } 

	void getCardType(std::vector<CCard> &mVecSortCards, CardType &ct);

	inline void getVecCards(std::vector<CCard> &cards)
	{
		cards = mVecCards;
	}
	bool getBiggestCards();
	bool operator>(const Poker &b) { return m_ctype > b.m_ctype; }
	bool operator==(const Poker &b) { return m_ctype == b.m_ctype;}
private:
	std::vector<CCard> mVecCards;      //2 cards init in hands
	std::vector<CCard> mVecCommonCards; //5 common cards
	CardType m_ctype;
	bool m_bGiveUp;
	bool m_bPickCard;
	int	m_nChips;        //此局下注
	int	m_nPlayerChips;  //带入桌子筹码
	int	m_nCurrentChips; //此回合下注
	bool bfinishSendCard;
};
#endif