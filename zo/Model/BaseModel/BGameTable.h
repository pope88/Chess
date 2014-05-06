#ifndef _GAMETABLE_H_
#define _GAMETABLE_H_
#include "Mplayer.h"
#include "Mtable.h"
#include "RoomManager.h"

class BGameTable : public Mtable
{
public:
	enum
	{
		TS_EMPTY,		    //空房间
		TS_WATING,			//等待状态
		TS_RACING,			//比赛状态
		TS_VIPWATING,		//有密码等待状态
		TS_VIPRACING,		//有密码比赛状态
	};
	enum 
	{
		eVOTE_EVENT = 9999,
		eVOTE_PEROID = 1000 * 10,
		eKICK_EVENT = 9998,
		eKICK_PEROID = 20 * 1000,
	};
	class st_vote
	{
	public:
		int				nAnswerNum;
		int				m_nTimer;
		st_vote()
		{
			nAnswerNum = 0;
			m_nTimer = 0;
		}
	};
public:
	BGameTable(char cTableID, RoomPlayerManager* pPlayerManager);
	~BGameTable(void);

	//IBDTimerModule
	virtual void onTimer(void* pParam);

	//ICoreTable
	virtual int getGameType();
	virtual Mplayer* getCorePlayer(int nChairID);
	virtual void endGame();
	virtual int getCurPlyNum() { return m_cCurPlyNum; }
	virtual void setTimer(int nPeriod, void* pParam);
	virtual void removeTimer();
	virtual void notifyVisitor(char cChairID, const char* pData, int nLength, bool bExclude);
	virtual void startClientTimer(char cChairID, int nPeriod);
	virtual int getTaxRate();
	virtual int getTableID();
	virtual int changePlayerMoney(int nPID, int nVarMoney);
	virtual void setBaseScore(int nScore);
	int joinTable(User* pPlayer, int nChairID, const std::string& strPassword);
//	void StartClientFinished(CUserSession* pPlayer, char cChairID);
	/**
	   @brief 重新进入桌子，用于断线重连
	*/
//	bool ReJoinTable(CUserSession* pPlayer, char cChairID);
	/**
	   @brief 离开桌子
	   @param pPlayer 离开玩家指针
	*/
	bool leaveTable(User* pPlayer);
	int findEmptyChair();
	bool canStartGame();
	void onStartGame();
	void getCompleteData();
	int isCanJoin(User* pPlayer, const std::string& strPassword, int& nPID, bool bVisitor = false);
	template<class T>
		void notifyPlayer(const T& packet, User* pExceptPlayer = NULL)
	{
		//COutputStream os;
		//os << packet;
		//NotifyPlayer(os.GetData(), os.GetLength(), pExceptPlayer);
	}
	template<class T>
		void notifyTable(const T& packet, User* pExceptPlayer = NULL)
	{
		//COutputStream os;
		//os << packet;
		//NotifyTable(os.GetData(), os.GetLength(), pExceptPlayer);
	}
//	const st_tabledata& GetTableData() { return m_stTableData; }
	//int	getStatus() { return m_stTableData.cStatus; }
	//void setStatus(int nStatus) { m_stTableData.cStatus = (char)nStatus; }
	//ITable* getTable() { return m_pTable; }
	int	getBaseScore() { return m_nBaseScore; }

	void reqLeaveGame(User* pSession, const std::string& strReason);
	void reqLeaveGameAck(int nPID, char cRet);
	void GMBreakGame(int nPID);
	User* getPlayer(int nChair);
private:
	void notifyPlayer(const char* pData, int nLength, User* pExceptPlayer);
	void notifyTable(const char* pData, int nLength, User* pExceptPlayer);
	void checkReadyStatus();
	void setKickTimer(int nChairID);
	void removeKickTimer();
private:
	//st_tabledata	m_stTableData;
	RoomPlayerManager* m_pPlayerManager;
	//ITable*	m_pTable;
	int		m_cMaxPlyNum;
	int		m_cCurPlyNum;
	std::vector<User*>	m_vecPlayers;
	std::vector<User*>	m_vecVisitors;
	int		m_nTimerID;
	int		m_cMasterChairID;
	int		m_nBaseScore;

	std::map<int, st_vote> m_mapArrangeLeave;
	int		m_nKickChairID;
	int		m_nKickTimerID;
	//int g_nSetTimerNum;
	//int g_nRemoveTimerNum;
	//int g_nOnTimerNum;
};


//class GameTable: public Mtable
//{
//public:
//	enum
//	{
//		T_EMPTY,
//		T_WATING,
//		T_RACING,
//	};
//public:
//	//GameTable(UInt8 tableId, PlayerMananger* userManager) {}
//	GameTable(UInt8 tableId) {}
//	virtual ~GameTable() {}
//public:
//	virtual void onTimer() {}
//	virtual void onGameStart() {}
//	virtual void onGameEnd() {}
//	virtual void onUserForceLeave(Mplayer *p) {}
//	virtual void onUserDisconnection(Mplayer *p) {}
//	virtual void onUserverReconnection(Mplayer *p) {}
//	virtual void onUserJoinTable(Mplayer *p) {}
//	virtual void onUserLeaveTable(Mplayer *p) {}
//	virtual bool canJoinGame(Mplayer *p) { return true; }
//public:
//	virtual int getGameType() { return 0;}
//	virtual int getCurPlayerNum() { return 0;}
//	virtual Mplayer* getTablePlayer(int nChairId) { return NULL; }
//	virtual void setTimer() {}
//	virtual void removeTimer() {}
//	virtual void changePlayerMoney(Mplayer *p, int nMoney) {}
//	virtual void setBaseSore(int nBaseCore) {}
//
//private:
//	std::vector<User*>  _vecPlayers;   //players
//	UInt8 _maxPlayNum;
//	UInt8 _curPlayNum;
//	UInt32 _tableId;
//
//};
#endif