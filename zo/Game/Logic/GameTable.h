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
		eBET_EVENT = 1,
		ePICK_EVENT = 2,
		eDEALING_EVENT = 3,
		eCOMMONCARD_EVENT = 4,
		eCARDFACE_EVENT = 5,
		ePICK_PERIOD = 30 * 1000,
		eBET_PERIOD = 15 * 1000,
		eDEALING_PERIOD = 5 * 1000,
		eCARDFACE_PERIOD = 2 * 1000,
	};

	enum 
	{
		eALLUSER = 0,
		eONLYPLAYER = 1,
		ePLYNUM = 7,
	};

public:
	GameTable() {}
	~GameTable() {}
	//virtual void BindCoreTable2Table(ICoreTable* pTable);
	virtual void release() {}
	virtual void onTimer();
	virtual void onGameStart();
protected:
	//��ʼ��Ϸ
	void NewRound(); 
	//����һ����ʱ��
	void startTimer(int nEvent, char cChair);
	void showPlayerStatus();
	void deaLing();
	inline UInt32 getBaseChips() { return m_baseChips; }
	Player* getBeforePlayerID(UInt8 nChairID);
	Player* getNextPlayer(UInt8 nChairID);
	Player* getPlayer(UInt8 nChairID);
	void SendCompleteData(Player* pPlayer);
	//ͨ��ָ�������Ӻ�ȡ�õ�ǰ��������ϵ����ָ��
	void sendPlayerCard();
	void onFinishSendAck(Player* p);
	void sendOperateReq(Player *player, UInt8 playrNum);
	void autoSendSmallBlind(Player *player);


	virtual void onUserArrangeLeave(Mplayer* pPlayer) {}
	virtual void onUserForceLeave(Mplayer* pPlayer) {}
	virtual void onEndGame() {}
	virtual void onUserDisconnection(Mplayer* pPlayer) {}
	virtual void onUserReconnection(Mplayer* pPlayer) {}
	virtual void onUserJoinVisitor(Mplayer* pPlayer) {}
	virtual void onUserJoin(Mplayer* pPlayer) {}
	virtual void onUserLeave(Mplayer* pPlayer) {}


public:

	//���ͳ�ʼ17����


	//�з�����
	void callScore() {}

	//������������
	void robLord() {}

	//��������õ���
	void dealingLord() {}

	//���������ͳ�������
	void svrPlayCardReq(int nChairID) {}

	//�ͻ��˻�Ӧ�������
	void cliSendCardAck(const ::ssu::Object &ack, Player* pPlayer) {}


	void cliPickCardAck(const ::ssu::Object &ack, Player* pPlayer) {}

	void CliOperatorAck(const ::ssu::Object &ack, Player* pPlayer) {}

	//����ͨ����Ϣ
	void SendCommonCmd(int nOp, int nChairID = -1) {}

	//��Ϸ����
	void RoundEnd(Player* pPlayer) {}

	//��ȡ��Ϸ���ݣ��Թۡ�����������
	void GetCompleteData(Player *pPlayer) {}

	/**
	   @brief �����ڹ㲥��Ϣ
	   @param packet ���ݰ� 
	   @param nType 0ȫ����㲥, 1��ҹ㲥, 2ȫ���Թ۹㲥
	   @param pExceptPlayer �ų��������
	*/
	template<class T>
	void NotifyRoom(const T& packet, int nType = 0, Player* pExceptPlayer = NULL)
	{
		COutputStream os;
		os << packet;
		NotifyRoom(os.GetData(), os.GetLength(), nType, pExceptPlayer);
	}	
public:
	
private:


	//��ʼ��Ϸ�㲥
	void SvrStartGameNot() {}

	//���õ�ע
	void SetBaseMoney() {}

	//�����һ���������
	int GetNextPlayer() {}

	/**
	@brief �쳣������Ϸ
	@param nType 0Э���˳� 1ǿ���˳�
	@param pPlayer ǿ���˳����
	*/
	void AbnormalEndGame(int nType, Mplayer *pPlayer) {}

	/**
	@brief	��ͻ���ˢ��ĳ���������Ϣ
	@param	pPalyer ���淢���仯�����
	@param	pExceptPlayer �ų�����Ҳ���
	@param	bPlyShow �Ƿ�����Ϸ�߷�������	
	@param	bShowAll �Ƿ����Թ��߷�������	
	*/
	void RefreshCards(Player* pPlayer, Player* pExceptPlayer = NULL, bool bPlyShow = false, bool bShowAll = false) {}

	//��ҳ�����
	void SendPutCards(Player* pPlayer, bool bAll = false) {}
private:
	void NotifyRoom(const char* pData, int nLength, int nType, Player* pExceptPlayer) {}
public:
	//ICoreTable* m_pCoreTable;					//ϵͳ�ӿ�
	Poke m_Poke;								//��
	std::vector<CCard> m_vecCommonCards;
	std::vector<Player> m_vecPoker;
	UInt8 m_cCurOpChair;         //��ǰ�ȴ�������λ��
	UInt8 m_cCurOpcode;          //��ǰ�ȴ��Ĳ���
	UInt8 m_nPlyNum;             //����ʱ���������
	bool m_bNewRound;            //�Ƿ���Ҫѡׯ
	UInt32 m_baseChips;          //��Ϸ��ע
	bool m_blittleBlind;          //Сäע
	bool m_bbigBlind;             //��äע
	bool m_btimeOut;             //�Ѿ���ʱ
	UInt32 m_limitMoney;         //��ͳ�������
	UInt8 m_nCommonNum;          //�����Ʒ��Ʋ���
	UInt8 m_nLastBigBlind;       //��һ�δ�äע

};

#endif