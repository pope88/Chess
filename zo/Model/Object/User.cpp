#include "Config.h"
#include "User.h"
#include "System/TimeUtil.h"
#include "Worker/Tcp.h"
#include "UserManager.h"
#include "System/TimeUtil.h"
//#include "Packet/Gateway.h"
#include "RoomManager.h"
#include "Packet/Builder.h"
#include "GameRoom.h"

namespace Object
{
	User::User( UInt32 id, const std::string &pid ): _id(id), _playerid(pid),  _regtime(0), _dailycp(0),
		_gold(0), _totaltopup(0), _totallosegold(0), _lastonline(), _lockend(0),  _ismale(0), _serverno(0),
		 _level(1), _dailyprogress(0),
		_guidestep(0), _experience(0), _avatarVer(0),_cloth(0), _athleticsRank(0), _lastbattleEnd(0), _bUnderUse(false),
		_roleOnline(false),  _sessionId(0), _gatewayId(0), _remoteAddr(0), _pInRoom(NULL), _pInTable(NULL), _pInChair(0)

	{
		memset(_buff, 0, sizeof(_buff));
	}

	User::User(const std::string &pid): _id(userManager.uniqueID()),_playerid(pid),  _regtime(0), _dailycp(0), 
		 _gold(0), _totaltopup(0), _totallosegold(0), _lastonline(), _lockend(0),  _ismale(0), _serverno(0),
		  _level(1), _dailyprogress(0),
		_guidestep(0), _experience(0),  _avatarVer(0),_cloth(0), _athleticsRank(0), _lastbattleEnd(0), _bUnderUse(false),
		_roleOnline(false), _sessionId(0), _gatewayId(0), _remoteAddr(0), _pInRoom(NULL), _pInTable(NULL), _pInChair(0)

	{
		memset(_buff, 0, sizeof(_buff));
	}

	User::~User()
	{

	}

	void User::newObjectToDB()
	{
		DB_PUSH_INSERT(getTableName(), set("id", _id, "playerid", _playerid, "name", _name, "serverno", _serverno, "ismale", _ismale));
	}

	bool User::updateKey(UInt32 _key)
	{
		return true;
	}

	void User::shutdown()  // set the player offline and push the player position to db
	{
		//shut down
		this->setOnline(false);
	}

	void User::kick()
	{
		UInt32 oSessionid;
		UInt32 oGatewayid;
		oSessionid = sessionId();
		oGatewayid = gatewayId();
		doLogOut();
		Worker::tcp.close(oSessionid, oGatewayid);
	}

	void User::loginPlayer()
	{
		if (!_roleOnline)
		{
			_roleOnline = true;
		}

		userInfo();
		sendItemList();
		_roomManager.sendRoomList(this);
	}

	void User::logOut()
	{
		doLogOut();
	}

	void User::doLogOut()
	{
		this->setlastonline(TimeUtil::Now());

		if (_roleOnline)
		{
			_roleOnline = false;
		}
	}

	bool User::loseGameGold(UInt32 g, UInt32 tipType)
	{
		if (g == 0)
		{
			return true;
		}


		//packet
		return true;
	}

	void User::userInfo()
	{
		Packet::UserInfo info;
		info.SetGold(this->gold());
		info.SetTotalTopup(this->totaltopup());
		info.SetTotalConsume(this->totallosegold());	
		info.send(this);
		return;
	}
}
