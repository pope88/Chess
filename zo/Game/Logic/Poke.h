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
	std::vector<Card> m_AllCards;	    //ȫ����54��
	UInt8 _bigBlind;                    //��äע
	UInt32 _totalChips;                 //�ܳ���
	UInt32 _baseChips;                  //��������
	UInt8 _finishNum;				//��������Ƿ������
};

#endif // !

