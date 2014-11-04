#ifndef _MTABLE_H_
#define _MTABLE_H_
#include "Mplayer.h"

class Mtable
{
	public:
	virtual ~Mtable(){}
	/**
	   @brief	ȡ����Ϸ��������
	   @ret		0��Ϸ�ҳ� 1���ֳ� 2������
	*/
	virtual int getGameType() = 0;
	/**
	   @brief ȡ�����ڵ�ǰ������������Թ�
	*/
	virtual int getCurPlyNum() = 0;
	/**
	   @brief ȡ��ָ����λ�ŵ����ָ��
	*/
	virtual Mplayer* getCorePlayer(int nChairID) = 0;
	/**
	   @brief ����������Ϸ״̬����������ó�δ����״̬
	*/
	virtual void endGame() = 0;
	/**
	   @brief	���÷��䶨ʱ����ÿ������ͬʱֻ����һ����ʱ��,
				�ص��ɹ���,��ʱ���Զ���ɾ��
	   @param	nPeriod �ص�����
	   @pParam	��ʱ������
	*/
	virtual void setTimer(int nPeriod, void* pParam) = 0;
	/**
		@brief	ɾ�������ڶ�ʱ��
	*/
	virtual void removeTimer() = 0;
	/**
	   @brief	���Թ���ҷ�����Ϣ
	   @param	cChairID	> 0 ָ����cChairIDλ�õ��Թ����, Ϊ-1ʱָ��ȫ���Թ����
	   @param	pData		��Ϣ����
	   @param	nLength		��Ϣ����
	   @param	bExclude	Ϊ��true��cChairID >0 ʱָ����cChairIDλ�������������Թ����
	*/
	virtual void notifyVisitor(char cChairID, const char* pData, int nLength, bool bExclude = false) = 0;
	/**
	   @brief	�����з�������ҷ���һ��������ʱ������Ϣ
	   @param	cChairID >= 0�ȴ����в�������� -1ȫ�����
	*/
	virtual void startClientTimer(char cChairID, int nPeriod) = 0;
	/**
	@brief ��ȡƽ̨��Ϸ�ҳ�˰�� (0 - 100)
	@note �ú����ѷ���
	*/
	//virtual int GetTaxRate() = 0;

	/**
	   @brief ���û�pid ��ȡ�û���Ϸ��
	   @return ���ؽ�����û�����Ϸ��
	*/
	virtual int changePlayerMoney(int nPID, int nVarMoney) = 0;

	/**
	    @brief ���ñ�����Ϸ��ע,������OnStartGame�ص�����������
	**/
	virtual void setBaseScore(int nScore) = 0;
	
};

class ITable
{
public:
	virtual ~ITable(){}

	virtual void bindCoreTable2Table(Mtable* pTable) = 0;
	virtual void release() = 0;
	virtual void onGameStart() = 0;
	virtual void onEndGame() = 0;
	virtual void onUserJoinVisitor(Mplayer* pPlayer) = 0;
	/**
	   @brief ����Ҿ�Э��ͨ�����뿪��Ϸ
	*/
	virtual void onUserArrangeLeave(Mplayer* pPlayer) = 0;
	/**
	   @brief �����ǿ���뿪��Ϸ
	*/
	virtual void onUserForceLeave(Mplayer* pPlayer) = 0;
	/**
		@brief	�������Ϸ�����ж���
	*/
	virtual void onUserDisconnection(Mplayer* pPlayer) = 0;
	/**
		@brief	����ڶ��ߺ�30�����ٴν�����Ϸ
	*/
	virtual void onUserReconnection(Mplayer* pPlayer) = 0;
	/**
	   @brief �������(�Ƕ���,�Թ����)���뷿��ʱ�ص�
	*/
	virtual void onPlayerJoin(IPlayer* pPlayer) = 0;
	/**
	   @brief ������뿪����ʱ�ص�
	*/
	virtual void onPlayerLeave(IPlayer* pPlayer) = 0;
	
	/**
	   @brief �Ƿ������½��뷿����Ҽ�����һ����Ϸ
	*/
	virtual bool canJoinGame(){ return true; }

	virtual void onOperateAck(IPlayer *player, UInt8 opcode, int mchips = 0) = 0;
};

#endif