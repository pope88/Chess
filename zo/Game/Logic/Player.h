#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/Object/DBObject.h"
#include "SsuObject.h"
//#include "../Common/PlayCard.h"
#include "../Common/Poker.h"
#include "../../Model/Object/User.h"
#include "../../Model/Object/BGameTable.h"
class GameTable;

class Player : public IPlayer
{
public:
	enum PS_PLAYERSTATE
	{
		PS_NONE,
		PS_PLAYER,
		PS_CANDIDATE, //候选
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

	void setGameTable(GameTable *bt);

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
	int	getChairID()
	{
		m_pCorePlayer;
		return m_pCorePlayer->getChairId(); 
	}

	bool operator > (const Player *pb)
	{
		return this->mPoker > pb->mPoker;
	}
	bool operator == (const Player *pb)
	{
		return this->mPoker == this->mPoker;
	}

public:
	//以下是系统接口函数
	Mplayer* getCorePlayer() { return m_pCorePlayer; }

	virtual void onOperateAck(UInt8 opcode, int mchips = 0);
	void onPacketPickCard(const ::ssu::Object &ack) {}
	void onPacketFinishSendCard(const ::ssu::Object &ack) {}
public:
	//以下是网络协议处理函数
public:
	Poker mPoker;
private:
	Mplayer* m_pCorePlayer;		    //系统接口
	ITable* m_pGameTable;		    //系统接口
	UInt8 m_nStatus;				//玩家状态
	UInt8 mPlayerStatus;            //游戏状态


};

struct lessPlayer 
{
	bool operator()(const Player *lhs, const Player *rhs)
	{
		return lhs > rhs;
	}
};

#endif