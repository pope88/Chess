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
	//ͨ��ָ�������Ӻ�ȡ�õ�ǰ��������ϵ����ָ��
	Player* getPlayer(int nChairID);

	//���ͳ�ʼ17����
	void Dealing();

	//�з�����
	void callScore();

	//������������
	void robLord();

	//��������õ���
	void dealingLord();

	//���������ͳ�������
	void svrPlayCardReq(int nChairID);

	//�ͻ��˻�Ӧ�������
	void cliSendCardAck(const ::ssu::Object &ack, Player* pPlayer);

	//�ͻ��˻�Ӧ�зֽ��
	void cliCallScoreAck(const ::ssu::Object &ack, Player* pPlayer);

	//�ͻ��˻�Ӧ��������Ӧ
	void cliRobLordAck(const ::ssu::Object &ack, Player* pPlayer);

	//�ͻ��˻�Ӧ����
	void CliShowCardAck(const ::ssu::Object &ack, Player* pPlayer);

	//�ͻ��˻�Ӧ����
	void CliPlayCardAck(const ::ssu::Object &ack, Player* pPlayer);

	//����ͨ����Ϣ
	void SendCommonCmd(int nOp, int nChairID = -1);

	//���ͱ�����Ϣ
	void SendDoubleInfo();

	//��Ϸ����
	void RoundEnd(Player* pPlayer);
	
	//��ʼ��Ϸ
	void NewRound();

	//��ȡ��Ϸ���ݣ��Թۡ�����������
	void GetCompleteData(Player *pPlayer);

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
private:
	//����һ����ʱ��
	void StartTimer(char cChair,int nEvent);

	//��ʼ��Ϸ�㲥
	void SvrStartGameNot();

	//���õ�ע
	void SetBaseMoney();

	//�����һ���������
	int GetNextPlayer();

	/**
	@brief �쳣������Ϸ
	@param nType 0Э���˳� 1ǿ���˳�
	@param pPlayer ǿ���˳����
	*/
	void AbnormalEndGame(int nType, Mplayer *pPlayer);

	/**
	@brief	��ͻ���ˢ��ĳ���������Ϣ
	@param	pPalyer ���淢���仯�����
	@param	pExceptPlayer �ų�����Ҳ���
	@param	bPlyShow �Ƿ�����Ϸ�߷�������	
	@param	bShowAll �Ƿ����Թ��߷�������	
	*/
	void RefreshCards(Player* pPlayer, Player* pExceptPlayer = NULL, bool bPlyShow = false, bool bShowAll = false);

	//��ҳ�����
	void SendPutCards(Player* pPlayer, bool bAll = false);
private:
	void NotifyRoom(const char* pData, int nLength, int nType, Player* pExceptPlayer);
public:
	//ICoreTable* m_pCoreTable;					//ϵͳ�ӿ�
	Poke m_Poke;								//��
	int m_nBaseScore;							//�׷�
	int m_nWaitOpChairID;						//�ȴ��������û�λ�ú�
	int m_nSerialID;							//��Ϣ���У�ȷ����������ͻ�����Ϣͬ��
	bool m_bRacing;								//�����Ƿ��Ǳ���״̬
	bool m_bShowCard;							//�жϵ����Ƿ����ƴ�
	int m_nPutCardsPlayerID;					//��ǰ�����ϳ����������
	int m_nCallScore;							//��ҽе�������
	int m_nRobDouble;							//����������
	int m_nDouble;								//��ǰ����
};

#endif