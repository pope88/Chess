#ifndef _POKE_H_
#define _POKE_H_
#include "../Common/CCard.h"
class Poke
{
public:
	Poke();
	~Poke();
public:
	void ShuffleCards();
	void NewRound();
	void SetDefaultLord();
	CCard& getCard(int nPos);
	void getCard(CCard&);
	inline UInt32 getTotalChips() { return _totalChips; }
	inline void setTotalChips(UInt32 c) {_totalChips = c;}
	inline UInt32 getBaseChips() { return _baseChips; }
	inline void setBaseChips(UInt32 c) { _baseChips = c; }
	inline void setBanker(UInt8 b) { _m_nBanker = b; }
	inline UInt8 getBanker() { return _m_nBanker; }
	inline void setSmallBlinder(UInt8 c) { _smallBlinder = c; }
	inline UInt8 getSmallBlinder() { return _smallBlinder; }
	inline void setBigBlinder(UInt8 c) { _bigBlinder = c; }
	inline UInt8 getBigBlinder() { return _bigBlinder;  }
public:
	std::vector<CCard> m_AllCards;	    //全副牌54张
	UInt8  _m_nBanker;			        //庄家
	UInt8 _smallBlinder;                //小盲注
	UInt8 _bigBlinder;                  //大盲注
	UInt32 _totalChips;                 //总筹码
	UInt32 _baseChips;                  //盲注
	UInt8 _finishNum;				    //几个玩家是否发牌完毕
};

#endif // !

