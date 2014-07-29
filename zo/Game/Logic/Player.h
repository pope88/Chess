#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/Object/DBObject.h"
#include "SsuObject.h"
#include "../Common/PlayCard.h"
#include "../Common/Poker.h"

class Player : public IPlayer
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

	//开始新的一轮
	void newRound();

	//获得玩家手上的牌
	void getPlayerCards(::ssu::Object &noti, bool bShow);

	//给客户端发牌
	void getCard(Card& cCard);
	
	//玩家出牌
	bool doPlayCard(Player* pPutPlayer);


	//获取玩家身上所带的游戏币
	int getMoney() { return m_pCorePlayer->getMoney(); }

	//设置和获取玩家状态
	int	getStatus(){ return m_nStatus; }
	void setStatus(int nStatus) { m_nStatus = nStatus; }

	//获取玩家座位号
	int	getChairID() { return m_pCorePlayer->getChairId(); }

	//是否允许旁观
	bool canWatch() { return m_pCorePlayer->canWatch(); }
public:
	//以下是系统接口函数
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
	//以下是网络协议处理函数
public:
	Mplayer* m_pCorePlayer;		//系统接口
	//BGameTable* m_pGameTable;		//系统接口
	UInt8 m_nStatus;				//比赛状态
	UInt8 mPlayerStatus;            //玩家状态
public:
	Poker mPoker;

};

namespace std
{
	template<>
	struct less <Player>
	{
		bool operator()(const Player& lhs, const Player& rhs)
		{
			int nType = lhs.mPoker.getCardType();
			int nRhsType = rhs.mPoker.getCardType();
			std::vector<CCard> lhsSortVecCards;
			std::vector<CCard> rhsSortVecCards;
			lhs.mPoker.getSortVecCards(lhsSortVecCards);
			rhs.mPoker.getSortVecCards(rhsSortVecCards);
			if(nType == nRhsType)
			{
				if (nType == 9 || nType == 5 )
				{
					return lhsSortVecCards[0].m_nValue > rhsSortVecCards[0].m_nValue;
				}
				else
				{
					for (size_t i = 0; i < lhsSortVecCards.size(); ++i)
					{
						if (lhsSortVecCards[i].m_nValue != rhsSortVecCards[i].m_nValue)
						{
							return lhsSortVecCards[i].m_nValue > rhsSortVecCards[i].m_nValue;
						}
					}
					return false;
				}
			}
			return nType > nRhsType;
		}
	};
}

#endif