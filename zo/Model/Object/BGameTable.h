#ifndef _BGAMETABLE_H_
#define _BGAMETABLE_H_
#include "../BaseModel/Mplayer.h"
#include "../BaseModel/Mtable.h"
#include "RoomManager.h"


namespace Object
{
class User;
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
	BGameTable(char cTableID, RoomPlayerManager* rpm);
	~BGameTable(void) {}

public:
	//0xFF random chair
	bool onUserEnter(User *u, UInt8 &nchair);
	void onUserOut(User *u);
	bool autoUserEnter(User *u);
	bool isTableFull();


	//**********************
	//IBDTimerModule
	virtual void onTimer(void* pParam) {}


	//ICoreTable
	virtual int getGameType() { return 0;}
	virtual Mplayer* getCorePlayer(int nChairID) 
	{
		if (nChairID < m_vecUsers.size())
			return m_vecUsers[nChairID];
		else 
			return NULL;
	}

	virtual void endGame()
	{
		m_nStatus = TS_WATING;
	}
	virtual int getCurPlyNum() { return m_cCurPlyNum; }
	virtual void setTimer(int nPeriod, void* pParam) {}
	virtual void removeTimer() {}
	virtual void notifyVisitor(char cChairID, const char* pData, int nLength, bool bExclude) {}
	virtual void startClientTimer(char cChairID, int nPeriod) {}
	virtual int getTaxRate(){ return 0; }
	virtual int getTableID() { return 0; }
	virtual int changePlayerMoney(int nPID, int nVarMoney) { return 0; }
	virtual void setBaseScore(int nScore) {}
//	void StartClientFinished(CUserSession* pPlayer, char cChairID);
	/**
	   @brief 重新进入桌子，用于断线重连
	*/
//	bool ReJoinTable(CUserSession* pPlayer, char cChairID);
	/**
	   @brief 离开桌子
	   @param pPlayer 离开玩家指针
	*/
	bool leaveTable(User* pPlayer) {}
	int findEmptyChair();
	bool canStartGame();
	void onGameStart();
	void getCompleteData() {}
	bool isCanJoin(User *user, int &chairId, UInt8 &res, bool bVisitor = false);
	int joinTable(User *user, int nChairID, const std::string &strPassword = "");
	template<class T>
	void notifyPlayer(const T& packet, User* pExceptPlayer = NULL)
	{

	}
	template<class T>
	void notifyTable(T& packet, User* pExceptPlayer = NULL)
	{
		User *pUser = NULL;
		for (size_t i = 0; i < m_vecUsers.size(); ++i)
		{
			pUser = static_cast<User*>(m_vecUsers[i]);
			if (pUser == NULL || pUser == pExceptPlayer)
			{
				continue;
			}
			packet.send(pUser);
		}
	}
//	const st_tabledata& GetTableData() { return m_stTableData; }
	int	getStatus() { return m_nStatus; }
	//void setStatus(int nStatus) { m_stTableData.cStatus = (char)nStatus; }
	ITable* getTable() { return m_pTable; }
	int	getBaseScore() { return m_nBaseScore; }

	void reqLeaveGame(User* pSession, const std::string& strReason) {}
	void reqLeaveGameAck(int nPID, char cRet) {}
	void GMBreakGame(int nPID) {}
private:
	void notifyPlayer(const char* pData, int nLength, User* pExceptPlayer) {}
	void notifyTable(const char* pData, int nLength, User* pExceptPlayer) {}
	void checkReadyStatus() {}
	void setKickTimer(int nChairID) {}
	void removeKickTimer() {}
private:
	//st_tabledata	m_stTableData;
	UInt8     m_TableId;
	RoomPlayerManager* pPlayerManager;
	ITable      *m_pTable;
	UInt8		m_MaxPlyNum;
	UInt8		m_cCurPlyNum;
	UInt8       m_PlyNum;
	std::vector<Mplayer*>	m_vecUsers;
	std::vector<Mplayer*>	m_vecVisitors;
	UInt32		m_nTimerID;
	UInt8		m_cMasterChairID;
	UInt32		m_nBaseScore;

	std::map<int, st_vote> m_mapArrangeLeave;
	int		m_nKickChairID;
	int		m_nKickTimerID;
	int     m_nStatus;
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
}

#endif