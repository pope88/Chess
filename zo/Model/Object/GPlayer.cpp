#include "Config.h"
#include "GPlayer.h"
#include "System/TimeUtil.h"
#include "GPlayerManager.h"
#include "Worker/Tcp.h"
#include "Packet/Builder.h"


namespace Object
{
	GPlayer::GPlayer(UInt32 gid, std::string &pid):_gid(gid), _playerId(pid), _serverNo(0), _regTime(0), _dailyCP(0), _gold(0),
		_totalTopup(0), _totalConsume(0), _lastOnline(0), _wallow(0), _lockEnd(0), _vip(0), _sessionId(0), _gatewayId(0),
		_remoteAddr(0), _onlineTime(0), _online(false), _onlineRoleId(0xFF)
	{
	}

	GPlayer::GPlayer(std::string &pid):_gid(gplayerManager.uniqueGID()), _playerId(pid), _serverNo(0), _regTime(0), _dailyCP(0), _gold(0),
		_totalTopup(0), _totalConsume(0), _lastOnline(0), _wallow(0), _lockEnd(0), _vip(0), _sessionId(0), _gatewayId(0),
		_remoteAddr(0), _onlineTime(0), _online(false), _onlineRoleId(0xFF)
	{
	}

	GPlayer::~GPlayer()
	{
		for ( auto it = _rolePlayers.begin(); it != _rolePlayers.end(); ++it)
		{
			delete it->second;
		}
	}

	//if the player is not repeated
	bool GPlayer::enSureOnlyPlayer(Player *player)
	{
		for (auto it = _rolePlayers.begin(); it != _rolePlayers.end(); ++it)
		{
			if (it->second == player)
			{
				return false;
			}
			else
			{
				if (it->second->name() == player->name())
				{
					return false;
				}
			}
		}
		return true;
	}

	//called when build a new role
	bool GPlayer::addPlayer(Player *player, UInt8 roleid)
	{
		if(!enSureOnlyPlayer(player))
		{
			return false;
		}
		if (roleid == 0xFF)
		{
			roleid = static_cast<UInt8>(_rolePlayers.size());
		}

		if (roleid >= 0 && roleid < ROLENUM)
		{
			auto it = _rolePlayers.find(roleid);
			if (it == _rolePlayers.end())
			{
				if (_rolePlayers.size() <= ROLENUM)
				{
					_rolePlayers[roleid] = player;
					return true;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return false;
	}

	Player* GPlayer::operator[](UInt8 rid)
	{
		auto it = _rolePlayers.find(rid);
		if (it == _rolePlayers.end())
		{
			return NULL;
		}
		else
		{
			return it->second;
		}
	}

	Player* GPlayer::getPlayer(UInt8 roleid)
	{
		auto it = _rolePlayers.find(roleid);
		if (it == _rolePlayers.end())
		{
			return NULL;
		}
		else
		{
			return it->second;
		}
	}

	void GPlayer::newObjectToDB()
	{
		_regTime = TimeUtil::Now();
		if(_wallow == 1)
		{
			DB_PUSH_INSERT(getTableName(), set("gid", _gid, "playerId", _playerId, "serverNo", _serverNo, "regTime", _regTime));
		}
		else
		{
			DB_PUSH_INSERT(getTableName(), set("gid", _gid, "playerId", _playerId, "serverNo", _serverNo, "regTime", _regTime, "wallow", _wallow));
		}
	}

	void GPlayer::kick()
	{
		UInt32 oSessionid;
		UInt32 oGatewayid;
		oSessionid = _sessionId;
		oGatewayid = _gatewayId;
		doLogOutGPlayer();
		Worker::tcp.close(oSessionid, oGatewayid);
	}

	void GPlayer::logOut()
	{
		doLogOutGPlayer();
	}

	void GPlayer::doLogOutGPlayer()
	{
		setlastOnline(TimeUtil::Now());
		onlineRoleId(0xFF);
		if (_online	)
		{
			_online = false;
		}
	}


	void GPlayer::loginGPlayer()
	{
		if (!_online)
		{
			_online = true;
			gplayerManager.addOnline(this);
		}
	}


	void GPlayer::UserInfo()
	{
		Packet::UserInfo info;
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
			hinfo->SetJob(0);
			hinfo->SetRoleid(it->second->id());
		}
		info.send(this);
		return;
	}

	void GPlayer::GPlayerLogin()
	{
		if (_online == false)
		{
			_online = true;
		}
	}

	bool GPlayer::isRoleOnline()
	{
		if (_onlineRoleId == 0xFF)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}