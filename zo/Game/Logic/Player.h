#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/Object/DBObject.h"
#include "SsuObject.h"
//#include "../Common/PlayCard.h"
#include "../Common/Poker.h"
#include "../../Model/Object/User.h"
#include "../../Model/Object/BGameTable.h"

class Player : public IPlayer
{
public:
	enum PS_PLAYERSTATE
	{
		PS_NONE,
		PS_PLAYER,
		PS_CANDIDATE,
		PS_GIVEUP,
	};
	enum DZOP
	{
		COMMONPLAYER = (1 << 0),
		BANKER = (1 << 1),
		SMALLBLIND = (1 << 2),
		BIGBLIND = (1 << 3),
	};
public:
	Player();
	virtual ~Player();

	void release();
	
	void bindUser2Player(Object::User *user); 

	//��ʼ�µ�һ��
	void newRound();

	void setGameTable(Object::BGameTable *bt);

	//���úͻ�ȡ���״̬
	UInt8 getStatus(){ return m_nStatus; }
	void setStatus(UInt8 nStatus) { m_nStatus = nStatus; }

	//��Ϸ״̬
	UInt8 getPlayerStatus() { return mPlayerStatus; }
	void setPlayerStatus(UInt8 mStatus) { mPlayerStatus = mStatus; }

	bool isRacing() { return m_nStatus == PS_PLAYER; }

	//���������ϵ���
	void getPlayerCards(::ssu::Object &noti, bool bShow);

	//���ͻ��˷���
	//void getCard(Card& cCard);

	//��ȡ���������������Ϸ��
	int getMoney() { return m_pCorePlayer->getMoney(); }

	//��ȡ�����λ��
	int	getChairID() { return m_pCorePlayer->getChairId(); }

public:
	//������ϵͳ�ӿں���
	Mplayer* getCorePlayer() { return m_pCorePlayer; }

	void onPacketOperate(const ::ssu::Object &ack);
	void onPacketPickCard(const ::ssu::Object &ack) {}
	void onPacketFinishSendCard(const ::ssu::Object &ack) {}
public:
	//����������Э�鴦����
public:
	Poker mPoker;
private:
	Mplayer* m_pCorePlayer;		    //ϵͳ�ӿ�
	Mtable* m_pGameTable;		    //ϵͳ�ӿ�
	UInt8 m_nStatus;				//���״̬
	UInt8 mPlayerStatus;            //��Ϸ״̬


};

//namespace std
//{
//	template<>
//	struct less <Player>
//	{
//		bool operator()(const Player& lhs, const Player& rhs)
//		{
//			int nType = lhs.mPoker.getCardType();
//			int nRhsType = rhs.mPoker.getCardType();
//			std::vector<CCard> lhsSortVecCards;
//			std::vector<CCard> rhsSortVecCards;
//			lhs.mPoker.getSortVecCards(lhsSortVecCards);
//			rhs.mPoker.getSortVecCards(rhsSortVecCards);
//			if(nType == nRhsType)
//			{
//				if (nType == 9 || nType == 5 )
//				{
//					return lhsSortVecCards[0].m_nValue > rhsSortVecCards[0].m_nValue;
//				}
//				else
//				{
//					for (size_t i = 0; i < lhsSortVecCards.size(); ++i)
//					{
//						if (lhsSortVecCards[i].m_nValue != rhsSortVecCards[i].m_nValue)
//						{
//							return lhsSortVecCards[i].m_nValue > rhsSortVecCards[i].m_nValue;
//						}
//					}
//					return false;
//				}
//			}
//			return nType > nRhsType;
//		}
//	};
//}

#endif