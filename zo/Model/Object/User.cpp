#include "Config.h"
#include "User.h"
#include "System/TimeUtil.h"
#include "Worker/Tcp.h"
#include "UserManager.h"
#include "System/TimeUtil.h"
//#include "Packet/Gateway.h"

namespace Object
{
	User::User( UInt32 id, const std::string &pid ): _id(id), _playerId(pid),  _regTime(0), _dailyCP(0),
		_gold(0), _totalTopup(0), _totalLoseGold(0), _lastOnline(), _lockEnd(0),  _isMale(0), _serverNo(0),
		 _level(1), _dailyProgress(0),
		_guideStep(0), _experience(0), _avatarVer(0),_cloth(0), _athleticsRank(0), _lastbattleEnd(0), _bUnderUse(false),
		_roleOnline(false), _roleid(0), _key(0), _sessionId(0), _gatewayId(0), _remoteAddr(0)

	{
		memset(_buff, 0, sizeof(_buff));
	}

	User::User(const std::string &pid): _id(userManager.uniqueID()),_playerId(pid),  _regTime(0), _dailyCP(0), 
		 _gold(0), _totalTopup(0), _totalLoseGold(0), _lastOnline(), _lockEnd(0),  _isMale(0), _serverNo(0),
		  _level(1), _dailyProgress(0),
		_guideStep(0), _experience(0),  _avatarVer(0),_cloth(0), _athleticsRank(0), _lastbattleEnd(0), _bUnderUse(false),
		_roleOnline(false), _roleid(0), _key(0), _sessionId(0), _gatewayId(0), _remoteAddr(0)

	{
		memset(_buff, 0, sizeof(_buff));
	}

	User::~User()
	{

	}

	void User::newObjectToDB()
	{
		DB_PUSH_INSERT(getTableName(), set("id", _id, "playerId", _playerId, "name", _name, "serverNo", _serverNo, "isMale", _isMale));
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

		sendItemList();
	}

	void User::logOut()
	{
		doLogOut();
	}

	void User::doLogOut()
	{
		this->setlastOnline(TimeUtil::Now());

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

	void User::UserInfo()
	{
		/*Packet::UserInfo info;
		info.SetGold(this->gold());
		info.SetTotalTopup(this->totalTopup());
		info.SetTotalConsume(this->totalConsume());	
		for (auto it = _rolePlayers.begin(); it != _rolePlayers.end(); ++it)
		{
			if (it->second == NULL)
			{
				continue;
			}
			Packet::HeroInfo *hinfo = info.AddRoles();

			hinfo->SetIsMale(it->second->isMale());
			hinfo->SetLevel(it->second->level());
			hinfo->SetName(it->second->name());
			hinfo->SetJob(it->second->job());
			hinfo->SetRoleid(it->second->id());
		}
		info.send(this);
		return;*/
	}
}
