#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/Object/DBObject.h"
#include "SsuObject.h"
#include "../Common/PlayCard.h"
class Player
{
public:
	enum PS_GAMESTATE
	{
		PS_NONE,
		PS_PLAYER,
		PS_VISTOR,
	};
public:
	Player();
	~Player();

	//��ʼ�µ�һ��
	void newRound();

	//���������ϵ���
	void getPlayerCards(::ssu::Object &noti, bool bShow);

	//���ͻ��˷���
	void getCard(Card& cCard);
	
	//��ҳ���
	bool doPlayCard(Player* pPutPlayer);


	//��ȡ���������������Ϸ��
	int getMoney() { return m_pCorePlayer->getMoney(); }

	//���úͻ�ȡ���״̬
	int	getStatus(){ return m_nStatus; }
	void setStatus(int nStatus) { m_nStatus = nStatus; }

	//��ȡ�����λ��
	int	getChairID() { return m_pCorePlayer->getChairId(); }

	//�Ƿ������Թ�
	bool canWatch() { return m_pCorePlayer->canWatch(); }
public:
	//������ϵͳ�ӿں���
	Mplayer* getCorePlayer() { return m_pCorePlayer; }
	//void setGameTable(BGameTable* pTable) { m_pGameTable = pTable; }
	virtual void release();
	//virtual void bindCorePlayer2Player(Mplayer* pCorePlayer);
	//virtual void ProcessPacket(const char* pData, int nLength);
	//template<class T>
	//void SendPacket(const T& packet)
	//{
	//	if(m_pCorePlayer)
	//	{
	//		COutputStream os;
	//		os << packet;
	//		m_pCorePlayer->Send(os.GetData(), os.GetLength());
	//	}
	//}
	//void Send(const char* pData, int nLength)
	//{
	//	if(m_pCorePlayer)
	//		m_pCorePlayer->Send(pData, nLength);
	//}
public:
	//����������Э�鴦����
public:
	Mplayer* m_pCorePlayer;		//ϵͳ�ӿ�
	//BGameTable* m_pGameTable;		//ϵͳ�ӿ�
	CPlayCards m_PlayCard;			//�������
	int m_nStatus;					//����״̬
	int m_nCallScore;				//�з����,0:û��,����������
	bool m_bGiveUp;					//�Ƿ����
	bool m_bShowCard;				//�Ƿ����ƴ�
	bool m_bAuto;					//�Ƿ��й�
	int m_nPutCount;				//���ƴ���
	int m_nTimeOut;					//��ʱ���ƴ���
	std::vector<CCardsType> m_vecPutCard;//���������
	std::vector<Card> m_vecHandCard;	//��ʼ��������
};
#endif