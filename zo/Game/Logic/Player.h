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
	CPlayCards m_PlayCard;			//牌类规则
	int m_nStatus;					//比赛状态
	int m_nCallScore;				//叫分情况,0:没叫,不能抢地主
	bool m_bGiveUp;					//是否过牌
	bool m_bShowCard;				//是否亮牌打
	bool m_bAuto;					//是否托管
	int m_nPutCount;				//出牌次数
	int m_nTimeOut;					//超时出牌次数
	std::vector<CCardsType> m_vecPutCard;//打出的牌型
	std::vector<Card> m_vecHandCard;	//初始化的手牌
};
#endif