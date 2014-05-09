#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Model/Object/DBObject.h"
#include "System/Serialize.h"
#include "Model/Item/ItemPack.h"
#include "../BaseModel/Mplayer.h"
#include "../BaseModel/MSession.h"
#include "BGameTable.h"


namespace Object
{
	enum PlayerBuff
	{
		PlayerBuffNum = 1,
	};

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
			LOAD_NOLOGIN = (1 << 4),	//�ʺű�����
			LOAD_FROZEN = (1 << 5),		//��Ϸ�ұ�����
			LOAD_NOSIGN = (1 << 6),		//û�б���
			LOAD_VERIFYFAILD = (1 << 7),//�������
			LOAD_SUCCESS = (LOAD_INFO | LOAD_GAME),
		};
	public:
		enum USER_STATUS
		{
			US_UNCONNECTED,		///< 0	δ����
			US_CONNECTED,		///< 1	���ӳɹ�
			US_LOBBY,			///< 2	��¼�ɹ�
			US_TABLE,			///< 3	��ҽ��뷿��
			US_VISITOR,			///< 4	�Թ۽��뷿��
			US_READY,			///< 5	����
			US_RACING,			///< 6	������
			US_BROKEN,			///< 7	������
		};
	public:
		User(UInt32 id, const std::string &pid);
		User(const std::string &pid);
		virtual ~User();
	private:
		virtual const char* getTableName() { return "player"; }
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
		void UserInfo();
	public:
		void loginPlayer();
	public:
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
		virtual int getMoney() { return 0; }
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
		bool onStartGame() { return true; }
		GameRoom* getTableManager() { return NULL; }
		void onHeartBit() {}
		void getNetDelay() {}
		const std::string& getPlayerIp() { 	static std::string empty; return empty; }
		const BGameTable* getTheTable() { return NULL; }
		void setPlayerStatus(UInt16 status) {}
		
	public:
		//id same to GPlayer
		DB_PROP_ADD(UInt32, id);  
		DB_PROP_ADD_REF(std::string, playerId);
		DB_PROP_ADD(UInt32, regTime);
		DB_PROP_ADD(UInt32, dailyCP);
		DB_PROP_ADD(UInt32, gold);
		DB_PROP_ADD(UInt32, totalTopup);
		DB_PROP_ADD(UInt64, totalLoseGold);
		DB_PROP_ADD(UInt8, lastOnline);
		DB_PROP_ADD(UInt8, lockEnd);
		//DB_PROP_ADD(UInt8, roleId);
		DB_PROP_ADD(bool, isMale);
		DB_PROP_ADD_REF(std::string, name);
		DB_PROP_ADD(UInt32, serverNo);
		DB_PROP_ADD(UInt8, level);
		DB_PROP_ADD(UInt32, dailyProgress);
		DB_PROP_ADD(UInt64, guideStep);
		DB_PROP_ADD(UInt32, experience);
		DB_MERGE_PROP2(UInt8, level, UInt32, experience);
	public:
		inline void setRoleId(UInt8 rid) { _roleid = rid; }
		inline  UInt8 getRoleId() { return _roleid; }
	public:
		inline UInt8 vip() { return 0; }
	protected:
		DB_PROP_UPDATE_COND(id, _id);
	private:
		UInt8 _avatarVer;
		UInt8 _cloth;
		mutable UInt32 _buff[PlayerBuffNum];
		UInt32 _athleticsRank;
		//UInt32 _donationRank;
		UInt32 _lastbattleEnd;
		bool _bUnderUse;
		bool _roleOnline;
		UInt8 _roleid;
	private:
		UInt32 _key;
		UInt32 _sessionId;
		UInt32 _gatewayId;
		UInt32 _remoteAddr;
		UInt32 _lastPacketTime;  // last receive packet time
		bool _bBroken;
		UInt16 _onlineTime;      //online time point
		UInt16 _dayWinRound;      //today win round
		UInt32 _gameStartTime;   //the round game start time
		UInt16 _todayGameTime;   //the time count
	};
}

#endif