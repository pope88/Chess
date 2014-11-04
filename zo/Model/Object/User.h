#ifndef _USER_H_
#define _USER_H_
#include "Model/Object/DBObject.h"
#include "System/Serialize.h"
#include "Model/Item/ItemPack.h"
#include "../BaseModel/Mplayer.h"
#include "../BaseModel/MSession.h"
#include "../BaseModel/Mtable.h"
#include "BGameTable.h"

namespace Object
{
	enum PlayerBuff
	{
		PlayerBuffNum = 1,
	};

class GameRoom;
class User;
#define PThisPtr static_cast< ::Object::User* >(this)

	class User : virtual protected DBObject,
		public Item::ItemPack,
		public MSession,
		public Mplayer
		//,
		//public System::Serializable
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
		User(UInt32 id, const std::string &pid);
		User(const std::string &pid);
		virtual ~User();
	private:
		virtual const char* getTableName() { return "user"; }
	public:
		void newObjectToDB();
		
		bool updateKey(UInt32 _key);
		void shutdown();
		void kick();
		void logOut();
		void doLogOut();
		bool loseGameGold(UInt32 g, UInt32 tipType = 0);
		//inline UInt8 heroId() { return _heroid; }
		//inline bool heroId( UInt8 hid) { if (hid > 2)  return false; _heroid = hid; }
		inline bool isUnderUse() { return _bUnderUse;}
		inline void setUnderUse(bool bUse) { _bUnderUse = bUse; }
	public:
		inline void sessionId(UInt32 s, UInt32 g) { _sessionId = s; _gatewayId = g; }
		inline UInt32 sessionId() { return _sessionId; }
		inline UInt32 gatewayId() { return _gatewayId; }
		inline UInt32 remoteAddr() { return _remoteAddr; }
		inline void setRemoteAddr(UInt32 addr) { _remoteAddr = addr; }
	    inline UInt8 getVip() { return 0; } 
		inline bool online() { return _roleOnline; }
		inline void setOnline(bool ol) { _roleOnline = ol; }
		void userInfo();
	public:
		void loginPlayer();
	public:
		// logic
		inline void setInTable(BGameTable *bt) { _pInTable = bt; }
		inline void setInRoom(GameRoom *gr) { _pInRoom = gr; }
		inline BGameTable* getInTable() { return _pInTable; }
		inline GameRoom* getInRoom() { return _pInRoom; }
	public:
		//session
		virtual void onConnnection() {}
		virtual void setConnection() {}
		virtual void onDisConnect() {}
		virtual void onDisConnection() {}
		virtual void onRecv(const UInt8 *pData, int nLen) {}
		virtual void release() {}
		virtual void onRecvFrom(struct sockaddr* remoteaddr, const UInt8 *pData, int nLen) {}
		virtual void heartBit() {}

		//mplayer
		virtual int getTableId() { return 0; }
		virtual int getChairId() { return _pInChair; }
		virtual void setChairId(int chairid) { _pInChair = chairid; }
		virtual int getMoney() { return 0; }
		virtual void setTableId(int tableid) {  }
		virtual bool saveGameMoney(int money) { return true; }
		virtual bool saveGameScore(int score) { return true; }
		virtual bool canWatch() { return true; }

		//db

		//base control
		void setTableInfo(BGameTable pTable, int chiarid) {}
		inline int getStatus() { return 0; }
		void setStaus(int status) {}
		inline int getRoomId() { return 0; }

		int changeMoney(int money) { return 0; }
		inline int getLimitScore() { return 0; }

		//logic 
		bool onGameStart() { return true; }
		GameRoom* getTableManager() { return NULL; }
		void onHeartBit() {}
		void getNetDelay() {}
	   // void getPlayerIp(std::string &empty) { 	std::string empty; }
		BGameTable* getTheTable() { return _pInTable; }
		IPlayer* getThePlayer() { return m_pPlayer; }
		void setPlayerStatus(UInt16 status) {}

		
	public:
		//id same to GPlayer
		DB_PROP_ADD(UInt32, id);  
		DB_PROP_ADD_REF(std::string, playerid);
		DB_PROP_ADD(UInt32, regtime);
		DB_PROP_ADD(UInt32, dailycp);
		DB_PROP_ADD(UInt32, gold);
		DB_PROP_ADD(UInt32, totaltopup);
		DB_PROP_ADD(UInt64, totallosegold);
		DB_PROP_ADD(UInt32, lastonline);
		DB_PROP_ADD(UInt8, lockend);
		DB_PROP_ADD(bool, ismale);
		DB_PROP_ADD_REF(std::string, name);
		DB_PROP_ADD(UInt32, serverno);
		DB_PROP_ADD(UInt8, level);
		DB_PROP_ADD(UInt32, dailyprogress);
		DB_PROP_ADD(UInt64, guidestep);
		DB_PROP_ADD(UInt32, experience);
		DB_MERGE_PROP2(UInt8, level, UInt32, experience);
	public:
		inline UInt8 vip() { return 0; }
	protected:
		DB_PROP_UPDATE_COND2(id, _id, playerid, _playerid);
	private:
		UInt8 _avatarVer;
		UInt8 _cloth;
		mutable UInt32 _buff[PlayerBuffNum];
		UInt32 _athleticsRank;
		//UInt32 _donationRank;
		UInt32 _lastbattleEnd;
		bool _bUnderUse;
		bool _roleOnline;
	private:
		UInt32 _sessionId;
		UInt32 _gatewayId;
		UInt32 _remoteAddr;
		UInt32 _lastPacketTime;  // last receive packet time
		bool _bBroken;
		UInt16 _onlineTime;       //online time point
		UInt16 _dayWinRound;      //today win round
		UInt32 _gameStartTime;    //the round game start time
		UInt16 _todayGameTime;    //the time count
	private:
		GameRoom *_pInRoom;
		BGameTable *_pInTable;
		IPlayer *m_pPlayer;
		UInt8 _pInChair;
	};
}

#endif
