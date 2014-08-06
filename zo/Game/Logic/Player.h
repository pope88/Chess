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

	//开始新的一轮
	void newRound();

	void setGameTable(Object::BGameTable *bt);

	//设置和获取玩家状态
	UInt8 getStatus(){ return m_nStatus; }
	void setStatus(UInt8 nStatus) { m_nStatus = nStatus; }

	//游戏状态
	UInt8 getPlayerStatus() { return mPlayerStatus; }
	void setPlayerStatus(UInt8 mStatus) { mPlayerStatus = mStatus; }

	bool isRacing() { return m_nStatus == PS_PLAYER; }

	//获得玩家手上的牌
	void getPlayerCards(::ssu::Object &noti, bool bShow);

	//给客户端发牌
	//void getCard(Card& cCard);

	//获取玩家身上所带的游戏币
	int getMoney() { return m_pCorePlayer->getMoney(); }

	//获取玩家座位号
	int	getChairID() { return m_pCorePlayer->getChairId(); }

public:
	//以下是系统接口函数
	Mplayer* getCorePlayer() { return m_pCorePlayer; }

	void onPacketOperate(const ::ssu::Object &ack);
	void onPacketPickCard(const ::ssu::Object &ack) {}
	void onPacketFinishSendCard(const ::ssu::Object &ack) {}
public:
	//以下是网络协议处理函数
public:
	Poker mPoker;
private:
	Mplayer* m_pCorePlayer;		    //系统接口
	Mtable* m_pGameTable;		    //系统接口
	UInt8 m_nStatus;				//玩家状态
	UInt8 mPlayerStatus;            //游戏状态


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