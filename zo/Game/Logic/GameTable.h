#ifndef _GAMETABLE_H_
#define _GAMETABLE_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/BaseModel/Mtable.h"
#include "Player.h"
#include "SsuObject.h"
#include "Poke.h"
#include "../../Model/Object/TimerBase.h"
class GameTable : public ITable, public TimerBase
{
	public:
	enum TIMER_ID
	{
		eANIMATE_EVENT = 1,
		eCALLSCORE_EVENT,
		eROBLORD_EVENT,
		ePLAYCARD_EVENT,
		eSHOWCARD_EVENT,

		eANI_PERIOD = 10 * 1000,
		eCALL_PERIOD = 10 * 1000,
		eROB_PERIOD = 10 * 1000,
		ePLAY_PERIOD = 20 * 1000,
		eSHOW_PERIOD = 10 * 1000,
	};

	enum 
	{
		ePLY_NUM = 3,
		eALLUSER = 0,
		eONLYPLAYER = 1,
	};
public:
	GameTable() {}
	~GameTable() {}
	//virtual void BindCoreTable2Table(ICoreTable* pTable);
	virtual void release() {}
	virtual void onTimer();
	virtual void onGameStart();



	virtual void onEndGame() {}
	virtual void onUserArrangeLeave(Mplayer* pPlayer) {}
	virtual void onUserForceLeave(Mplayer* pPlayer) {}
	virtual void onUserDisconnection(Mplayer* pPlayer) {}
	virtual void onUserReconnection(Mplayer* pPlayer) {}
	virtual void onUserJoinVisitor(Mplayer* pPlayer) {}
	virtual void onUserJoin(Mplayer* pPlayer) {}
	virtual void onUserLeave(Mplayer* pPlayer) {}
public:
	//通过指定的椅子号取得当前这个椅子上的玩家指针
	Player* getPlayer(int nChairID) {}

	//发送初始17张牌
	void Dealing();

	//叫分流程
	void callScore() {}

	//抢地主的流程
	void robLord() {}

	//处理地主拿底牌
	void dealingLord() {}

	//服务器发送出牌请求
	void svrPlayCardReq(int nChairID) {}

	//客户端回应发牌完毕
	void cliSendCardAck(const ::ssu::Object &ack, Player* pPlayer) {}


	void cliPickCardAck(const ::ssu::Object &ack, Player* pPlayer) {}

	void CliOperatorAck(const ::ssu::Object &ack, Player* pPlayer) {}

	//发送通用消息
	void SendCommonCmd(int nOp, int nChairID = -1) {}

	//游戏结束
	void RoundEnd(Player* pPlayer) {}
	
	//开始游戏
	void NewRound();

	//获取游戏数据，旁观、断线重连用
	void GetCompleteData(Player *pPlayer) {}

	/**
	   @brief 房间内广播消息
	   @param packet 数据包 
	   @param nType 0全房间广播, 1玩家广播, 2全体旁观广播
	   @param pExceptPlayer 排除不发玩家
	*/
	template<class T>
	void NotifyRoom(const T& packet, int nType = 0, Player* pExceptPlayer = NULL)
	{
		COutputStream os;
		os << packet;
		NotifyRoom(os.GetData(), os.GetLength(), nType, pExceptPlayer);
	}	
public:
	void showPlayerStatus();
private:
	//创建一个定时器
	void StartTimer(char cChair,int nEvent) {}

	//开始游戏广播
	void SvrStartGameNot() {}

	//设置底注
	void SetBaseMoney() {}

	//获得下一个出牌玩家
	int GetNextPlayer() {}

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

	//玩家出的牌
	void SendPutCards(Player* pPlayer, bool bAll = false) {}
private:
	void NotifyRoom(const char* pData, int nLength, int nType, Player* pExceptPlayer) {}
public:
	//ICoreTable* m_pCoreTable;					//系统接口
	Poke m_Poke;								//牌
	std::vector<CCard> m_vecCommonCards;
	std::vector<Player> m_vecPoker;
	UInt8 m_cCurOpChair;         //当前等待操作的位置
	UInt8 m_cCurOpcode;          //当前等待的操作
	UInt8 m_nPlyNum;             //开局时玩家总人数
	bool m_bNewRound;            //是否需要选庄
	UInt32 m_baseChips;          //游戏底注
	bool m_littleBlind;          //小盲注
	bool m_bigBlind;             //大盲注
	bool m_btimeOut;             //已经超时
	UInt32 m_limitMoney;         //最低筹码限制
	UInt8 m_nCommonNum;          //公共牌发牌步骤
	UInt8 m_nLastBigBlind;       //上一次大盲注

};

#endif