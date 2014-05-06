/*
CopyRight(c)2006 by Banding,Shanghai, All Right Reserved.

@Date:	        2009/4/15
@Created:	    15:02
@Filename: 		Poke.cpp
@File path:		BDLeyoyoV2\DDZV2\Server 
@Author:		leiliang
@Description:	
*/
#ifndef _POKER_H_
#define _POKER_H_
#include "../Common/PlayCard.h"
class Poke
{
public:
	Poke();
	~Poke();
public:
	void ShuffleCards();
	void NewRound();
	void SetDefaultLord();
	Card& GetCard(int nPos);
	Card& GetCard();
public:
	std::vector<Card> m_AllCards;			//全副牌54张
	std::vector<Card> m_cLordCard;			//地主补的三张牌
	int m_nRanCardPos;					//随机牌的位置
	Card m_cRanCard;					//随机牌
	int m_nDefaultLord;					//默认地主
	int m_nCurrentLord;					//当前地主
	int m_nBombCounter;					//计算炸弹个数
	int m_nNextPlayer;					//下一个出牌玩家
	int m_nDecideLordRound;				//决定地主计数
	bool m_bSendCardOK[3];				//几个玩家是否发牌完毕
};

#endif // !

