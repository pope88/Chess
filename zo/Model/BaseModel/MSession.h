#ifndef _MSESSION_H_
#define _MSESSION_H_
class MSession
{
public:
	MSession() {}
	virtual ~MSession() {}
public:
	virtual void onConnnection() = 0;
	virtual void setConnection() = 0;
	virtual void onDisConnect() = 0;
	virtual void onDisConnection() = 0;
	virtual void onRecv(const UInt8 *pData, int nLen) = 0;
	virtual void release() = 0;
	virtual void onRecvFrom(struct sockaddr* remoteaddr, const UInt8 *pData, int nLen) = 0;
};
#endif