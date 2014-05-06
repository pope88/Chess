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
	std::vector<Card> m_AllCards;			//ȫ����54��
	std::vector<Card> m_cLordCard;			//��������������
	int m_nRanCardPos;					//����Ƶ�λ��
	Card m_cRanCard;					//�����
	int m_nDefaultLord;					//Ĭ�ϵ���
	int m_nCurrentLord;					//��ǰ����
	int m_nBombCounter;					//����ը������
	int m_nNextPlayer;					//��һ���������
	int m_nDecideLordRound;				//������������
	bool m_bSendCardOK[3];				//��������Ƿ������
};

#endif // !

