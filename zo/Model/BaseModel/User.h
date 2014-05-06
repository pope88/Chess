#ifndef _USER_H_
#define _USER_H_
#include "Mplayer.h"
#include "MSession.h"
#include "GameRoom.h"

class User :public MSession, public Mplayer
{
public:
	enum LOGIN_STATUS
	{
		LOAD_FAILD = (1 << 0),
		LOAD_INFO = (1 << 1),
		//		LOAD_PAY = (1 << 2),
		LOAD_GAME = (1 << 3),
		LOAD_NOLOGIN = (1 << 4),	//帐号被禁用
		LOAD_FROZEN = (1 << 5),		//游戏币被冻结
		LOAD_NOSIGN = (1 << 6),		//没有报名
		LOAD_VERIFYFAILD = (1 << 7),//检验错误
		LOAD_SUCCESS = (LOAD_INFO | LOAD_GAME),
	};
public:
	enum USER_STATUS
	{
		US_UNCONNECTED,		///< 0	未连接
		US_CONNECTED,		///< 1	连接成功
		US_LOBBY,			///< 2	登录成功
		US_TABLE,			///< 3	玩家进入房间
		US_VISITOR,			///< 4	旁观进入房间
		US_READY,			///< 5	举手
		US_RACING,			///< 6	比赛中
		US_BROKEN,			///< 7	断线中
	};
public:
	User();
	~User();
public:
	//session
	virtual void onConnnection() {}
	virtual void setConnection() {}
	virtual void onDisConnect() {}
	virtual void onDisConnection() {}
	virtual void onRecv(const UInt8 *pData, int nLen) {}
	virtual void release() {}
	virtual void onRecvFrom(struct sockaddr* remoteaddr, const UInt8 *pData, int nLen) {}

	//mplayer
	virtual int getTableId() { return 0; }
	virtual int getChairId() { return 0; }
	virtual int getGameMoney() { return 0; }
	virtual bool saveGameScore(int score) { return true; }
	virtual bool SaveGameMoney(int money) { return true; }
	virtual bool canWatch() { return true; }

	//db

	//base control
	const int getPid() { return 0; }
	void setTableInfo(BGameTable pTable, int chiarid) {}
	inline int getStatus() { return 0; }
	void setStaus(int status) {}
	inline int getRoomId() { return 0; }

	int changeMoney(int money) { return 0; }
	inline int getLimitScore() { return 0; }

	//logic 
	bool onStartGame() { return true; }
	GameRoom* getTableManager() { return NULL; }
	void onHeartBit() {}
	void getNetDelay() {}
	const std::string& getPlayerIp() { 	static std::string empty; return empty; }
	const BGameTable* getTheTable() { return NULL; }
	void setPlayerStatus(UInt16 status) {}

	//net

private:
	BGameTable *_mpTable;
	UInt8 _roomID;
	UInt32 _sessionId;
	UInt32 _gatewayId;
	UInt32 _remoteAddr;
	UInt32 _lastPacketTime;  // last receive packet time
	bool _bBroken;          // is now off line;
	UInt16  _vipTime;       // be vip total time
	UInt32 _onlineTime;     // online time point
	UInt32 _dayWindRound;   // today win round
	UInt32 _gameStartTime;  //the round game start time
	UInt16 _todayGameTime;
	UInt64 _loseGoldAmount;
};
#endif