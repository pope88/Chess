#ifndef _GAMETABLE_H_
#define _GAMETABLE_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/BaseModel/Mtable.h"
#include "SsuObject.h"
#include "Poke.h"
#include "../../Model/Object/TimerBase.h"
#include "../../Packet/Builder.h"
#include "../Common/CCard.h"
#include "Player.h"
class GameTable : public ITable, public TimerBase
{
	public:
	enum TIMER_ID
	{
		eBET_EVENT = 1,
		ePICK_EVENT = 2,
		eDEALING_EVENT = 3,
		eCOMMONCARD_EVENT = 4,
		eCARDFACE_EVENT = 5,
		ePICK_PERIOD = 30,
		eBET_PERIOD = 30,
		eDEALING_PERIOD = 5,
		eCARDFACE_PERIOD = 2,
	};

	enum 
	{
		eALLUSER = 0,
		eONLYPLAYER = 1,
		ePLYNUM = 7,
	};

	enum DZPKOP
	{
		GIVEUP =     (1 << 0),
		CALL =       (1 << 1),
		CHECK =      (1 << 2),
		ADDCHIPS =   (1 << 3),
		SMALLBLIND = (1 << 4),
		BIGBLIND =   (1 << 5),
	};

public:
	GameTable();
	~GameTable();
	virtual void bindCoreTable2Table(Mtable* pTable) { m_pCoreTable = pTable; }
	virtual void release() { delete this; }
	virtual void onTimer();
	virtual void onGameStart();
	//void onPacketOperate(const ::ssu::Object &ack) {}
	void onPacketPickCard(const ::ssu::Object &ack ) {}
	void onPacketFinishSendCard(const ::ssu::Object &ack) {}
	/**
	   @brief 房间内广播消息
	   @param packet 数据包 
	   @param nType 0全房间广播, 1玩家广播, 2全体旁观广播
	   @param pExceptPlayer 排除不发玩家
	*/
	
	void NotifyTable(Packet::Builder& pb, int nType = 0, Player* pExceptPlayer = NULL)
	{
		for (UInt8 i = 0; i < ePLYNUM; ++i)
		{
			Mplayer *player = m_pCoreTable->getCorePlayer(i);
			if ( player == NULL || (pExceptPlayer != NULL && pExceptPlayer->getCorePlayer() == player))
			{
				continue;
			}
			pb.send((Object::User*)player);
		}
	}	
public:
	//开始游戏
	void NewRound(); 
	//创建一个定时器
	void startTimer(int nEvent, char cChair);
	void showPlayerStatus();
	void dealing();
	inline UInt32 getBaseChips() { return m_baseChips; }
	UInt8 getBeforePlayerID(UInt8 nChairID);
	Player* getNextPlayer(UInt8 nChairID);
	Player* getPlayer(UInt8 nChairID);
	Player* getAfterPlayer(UInt8 nChairID);
	bool isBossGiveUp();
	bool isCanSendCommonCard();
	void SendCompleteData(Player* pPlayer);
	void sendPlayerCard();

	void onFinishSendAck(Player* p);
	void sendOperateReq(Player *player);

	void onOperateAck(IPlayer *iplayer, UInt8 opcode, int mchips = 0);

	void autoOperateBlind();
	//游戏结束
	void roundEnd();
	void sendCommonCards();

	void onPlayerJoin(IPlayer* pPlayer);
	void onPlayerLeave(IPlayer* pPlayer);

public:
	void setGameScore() { m_baseChips = 100; m_lowestChips = 10000; m_Poke.setCallChips(m_baseChips * 2 ); }

	//客户端回应发牌完毕
	void cliSendCardAck(const ::ssu::Object &ack, Player* pPlayer) {}


	void cliPickCardAck(const ::ssu::Object &ack, Player* pPlayer) {}

	void CliOperatorAck(const ::ssu::Object &ack, Player* pPlayer) {}


	//获取游戏数据，旁观、断线重连用
	void GetCompleteData(Player *pPlayer) {}

	//发送通用消息
	void SendCommonCmd(int nOp, int nChairID = -1) {}

	virtual void onUserArrangeLeave(Mplayer* pPlayer) {}
	virtual void onUserForceLeave(Mplayer* pPlayer) {}
	virtual void onEndGame() {}
	virtual void onUserDisconnection(Mplayer* pPlayer) {}
	virtual void onUserReconnection(Mplayer* pPlayer) {}
	virtual void onUserJoinVisitor(Mplayer* pPlayer) {}

	
	//开始游戏广播
	void SvrStartGameNot();

	//设置底注
	void SetBaseMoney() {}

	/**
	@brief 异常结束游戏
	@param nType 0协议退出 1强制退出
	@param pPlayer 强制退出玩家
	*/
	void AbnormalEndGame(int nType, Mplayer *pPlayer) {}

	/**
	@brief	向客户端刷新某玩家牌面信息
	@param	pPalyer 牌面发生变化的玩家
	@param	pExceptPlayer 排除该玩家不发
	@param	bPlyShow 是否向游戏者发送明牌	
	@param	bShowAll 是否向旁观者发送明牌	
	*/
	void RefreshCards(Player* pPlayer, Player* pExceptPlayer = NULL, bool bPlyShow = false, bool bShowAll = false) {}

private:
	Mtable* m_pCoreTable;					//系统接口
	Poke m_Poke;								//牌
	bool m_bRacing;                             //比赛状态
	std::vector<CCard> m_vecCommonCards;        //公共牌
	std::vector<Player*> m_vecPoker;            //players
	UInt8 m_cCurOpChair;         //当前等待操作的位置
	UInt8 m_cCurOpcode;          //当前等待的操作
	UInt8 m_nPlyNum;             //开局时玩家总人数
	bool m_bNewRound;            //是否需要选庄
	UInt32 m_baseChips;          //游戏底注
	bool m_bSmallBlind;         //小盲注已下
	bool m_bbigBlind;            //大盲注已下
	bool m_btimeOut;             //已经超时
	UInt32 m_lowestChips;         //最低筹码限制
	UInt8 m_nCommonStage;          //公共牌发牌步骤
	UInt8 m_nLastBigBlind;       //上一次大盲注chairid
	Player *playerSmall;
	Player *playerBig;

};

#endif