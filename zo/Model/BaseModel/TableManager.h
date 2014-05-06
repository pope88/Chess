#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_

class CTableManager
{
private:

public:
	CTableManager(int nRoomID, CPlayerManager* pPlayerManager);
	~CTableManager(void);
	CGameTable* FindTable(int nRoomID);
	void GetTableData(vector<st_tabledata>& vecTableData);
	CGameTable* SeacheTable(int& nChair, const string& strIP);
	void BreakAllGame();
	CGameTable* FindEmptyTable(int& nChair);
	CGameTable* FindWaitingTable(int& nChair);
private:
	int	m_nRoomID;
	//CGameTable*	m_arrGameTable[MAX_TABLE_NUM];
	int m_nMaxTableNum;
	vector<CGameTable*> m_arrGameTable;
};

class TableManager
{
public:
	TableManager(int roomid, RoomPlayerManager* pPlayerManager) {}
	~TableManager() {}
	GameTable* findTablById(int tableId) {}
	GameTable* findEmptyTable(int &nChair){}
	GameTable* findWaitingTable(int &nChair){}
	GameTable* findCouldEnterTable(int &nChair) {}
public
};
#endif