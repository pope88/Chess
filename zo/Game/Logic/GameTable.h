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
	//ͨ��ָ�������Ӻ�ȡ�õ�ǰ��������ϵ����ָ��
	Player* getPlayer(int nChairID) {}

	//���ͳ�ʼ17����
	void Dealing();

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
	
	//��ʼ��Ϸ
	void NewRound();

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
	void showPlayerStatus();
private:
	//����һ����ʱ��
	void StartTimer(char cChair,int nEvent) {}

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
	bool m_littleBlind;          //Сäע
	bool m_bigBlind;             //��äע
	bool m_btimeOut;             //�Ѿ���ʱ
	UInt32 m_limitMoney;         //��ͳ�������
	UInt8 m_nCommonNum;          //�����Ʒ��Ʋ���
	UInt8 m_nLastBigBlind;       //��һ�δ�äע

};

#endif