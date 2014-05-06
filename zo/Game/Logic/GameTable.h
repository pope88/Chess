#ifndef _GAMETABLE_H_
#define _GAMETABLE_H_
#include "Model/BaseModel/Mplayer.h"
#include "Model/BaseModel/Mtable.h"
#include "Player.h"
#include "SsuObject.h"
#include "Poke.h"
class GameTable : public Ptable
{
	public:
	enum TIMER_EVENT
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
	GameTable();
	~GameTable();
	//virtual void BindCoreTable2Table(ICoreTable* pTable);
	virtual void release();
	virtual void onTimer(void* pParam);
	virtual void onStartGame();
	virtual void onEndGame();
	virtual void onUserArrangeLeave(Mplayer* pPlayer);
	virtual void onUserForceLeave(Mplayer* pPlayer);
	virtual void onUserDisconnection(Mplayer* pPlayer);
	virtual void onUserReconnection(Mplayer* pPlayer);
	virtual void onUserJoinVisitor(Mplayer* pPlayer);
	virtual void onUserJoin(Mplayer* pPlayer);
	virtual void onUserLeave(Mplayer* pPlayer);
public:
	//通过指定的椅子号取得当前这个椅子上的玩家指针
	Player* getPlayer(int nChairID);

	//发送初始17张牌
	void Dealing();

	//叫分流程
	void callScore();

	//抢地主的流程
	void robLord();

	//处理地主拿底牌
	void dealingLord();

	//服务器发送出牌请求
	void svrPlayCardReq(int nChairID);

	//客户端回应发牌完毕
	void cliSendCardAck(const ::ssu::Object &ack, Player* pPlayer);

	//客户端回应叫分结果
	void cliCallScoreAck(const ::ssu::Object &ack, Player* pPlayer);

	//客户端回应抢地主回应
	void cliRobLordAck(const ::ssu::Object &ack, Player* pPlayer);

	//客户端回应亮牌
	void CliShowCardAck(const ::ssu::Object &ack, Player* pPlayer);

	//客户端回应出牌
	void CliPlayCardAck(const ::ssu::Object &ack, Player* pPlayer);

	//发送通用消息
	void SendCommonCmd(int nOp, int nChairID = -1);

	//发送倍数信息
	void SendDoubleInfo();

	//游戏结束
	void RoundEnd(Player* pPlayer);
	
	//开始游戏
	void NewRound();

	//获取游戏数据，旁观、断线重连用
	void GetCompleteData(Player *pPlayer);

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
private:
	//创建一个定时器
	void StartTimer(char cChair,int nEvent);

	//开始游戏广播
	void SvrStartGameNot();

	//设置底注
	void SetBaseMoney();

	//获得下一个出牌玩家
	int GetNextPlayer();

	/**
	@brief 异常结束游戏
	@param nType 0协议退出 1强制退出
	@param pPlayer 强制退出玩家
	*/
	void AbnormalEndGame(int nType, Mplayer *pPlayer);

	/**
	@brief	向客户端刷新某玩家牌面信息
	@param	pPalyer 牌面发生变化的玩家
	@param	pExceptPlayer 排除该玩家不发
	@param	bPlyShow 是否向游戏者发送明牌	
	@param	bShowAll 是否向旁观者发送明牌	
	*/
	void RefreshCards(Player* pPlayer, Player* pExceptPlayer = NULL, bool bPlyShow = false, bool bShowAll = false);

	//玩家出的牌
	void SendPutCards(Player* pPlayer, bool bAll = false);
private:
	void NotifyRoom(const char* pData, int nLength, int nType, Player* pExceptPlayer);
public:
	//ICoreTable* m_pCoreTable;					//系统接口
	Poke m_Poke;								//牌
	int m_nBaseScore;							//底分
	int m_nWaitOpChairID;						//等待操作的用户位置号
	int m_nSerialID;							//消息序列，确保服务器与客户端消息同步
	bool m_bRacing;								//桌子是否是比赛状态
	bool m_bShowCard;							//判断地主是否亮牌打
	int m_nPutCardsPlayerID;					//当前桌面上出牌最大的玩家
	int m_nCallScore;							//玩家叫的最大分数
	int m_nRobDouble;							//抢地主倍数
	int m_nDouble;								//当前倍数
};

#endif