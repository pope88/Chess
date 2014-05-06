#ifndef _GPLAYER_H_
#define _GPLAYER_H_
#include "Model/Object/DBObject.h"

namespace Object
{
#define  ROLENUM 3
	class Player;
	class GPlayer : public DBObject
	{
	public:
		GPlayer(UInt32 id, std::string &pid);
		GPlayer(std::string &pid);
		virtual ~GPlayer();
	private:
		virtual const char* getTableName() { return "gplayer"; }
	public:
		void newObjectToDB();
		void shutdown();
		void kick();
		void logOut();
		void doLogOutGPlayer();
		void loginGPlayer();
	public:
		std::map<UInt8, Player* >& getRolePlayers() { return _rolePlayers; }
	    UInt8 getRoleNum() { return static_cast<UInt8>(_rolePlayers.size()); }
		inline void sessionId(UInt32 s, UInt32 g) { _sessionId = s; _gatewayId = g; }
		inline UInt32 sessionId() { return _sessionId; }
		inline UInt32 gatewayId() { return _gatewayId; }
		inline UInt32 remoteAddr() { return _remoteAddr; }
		inline void setRemoteAddr(UInt32 addr) { _remoteAddr = addr; }
		inline bool online() { return _online; }
		inline void setOnlineTime(UInt32 ot) { _onlineTime = ot; }
		inline void setOnline(bool b) { _online =b; }
		inline void onlineRoleId(UInt8 rid) { _onlineRoleId = rid; }
		inline UInt8 onlineRoleId() { return _onlineRoleId; }
	    bool isRoleOnline();
	public:
		inline UInt8 vip() { return _vip; }
		void UserInfo();
		void GPlayerLogin();
	public:
		bool enSureOnlyPlayer(Player *player);
		bool addPlayer(Player *player, UInt8 roleid = 0xFF);
		Player* getPlayer(UInt8 roleid);
		Player* operator[](UInt8 rid);
	protected:
		DB_PROP_UPDATE_COND(gid, _gid);

	public:
		DB_PROP_ADD(UInt32, gid);
		DB_PROP_ADD_REF(std::string, playerId);
		//DB_PROP_ADD_REF(std::string, userName);
		//DB_PROP_ADD_REF(std::string, passWord);
		DB_PROP_ADD(UInt32, serverNo);
		DB_PROP_ADD(UInt32, regTime);
		DB_PROP_ADD(UInt32, dailyCP);
		DB_PROP_ADD(UInt32, gold);
		DB_PROP_ADD(UInt32, totalTopup);     // top up
		DB_PROP_ADD(UInt32, totalConsume);   // consume
		DB_PROP_ADD(UInt32, lastOnline);
		DB_PROP_ADD(UInt8, wallow);
		DB_PROP_ADD(UInt32, lockEnd);
	private:
		std::map<UInt8, Player* > _rolePlayers;
		UInt8 _vip;
		UInt32 _key;
		UInt32 _sessionId;
		UInt32 _gatewayId;
		UInt32 _remoteAddr;
	private:
		UInt32 _onlineTime;
		bool _online;
		UInt8 _onlineRoleId;

	};
}

#endif