#include "Config.h"
#include "GPlayerManager.h"
#include "ZoCfg.h"

namespace Object
{
	GPlayerManager gplayerManager;

	GPlayerManager::GPlayerManager():IdPool("player_id_range"), _gplayers(4096), _maxGID(0)
	{
	}

	GPlayerManager::~GPlayerManager()
	{
		for(std::unordered_map<UInt32, GPlayer *>::iterator it = _gplayers.begin(); it != _gplayers.end(); ++ it)
		{
			delete it->second;
		}
		_gplayers.clear();
	}

	GPlayer* GPlayerManager::operator[] (UInt32 id)
	{
		std::unordered_map<UInt32, GPlayer*>::iterator it = _gplayers.find(id);
		if (it == _gplayers.end())
		{
			return NULL;
		}
		return it->second;
	}

	void GPlayerManager::init()
	{
		for(auto it = zocfg.serverNoSet.begin(); it != zocfg.serverNoSet.end(); ++ it)
		{
			//gplayer
			_gplayersById[*it].clear();
			//_namedGPlayersByServer[*it].clear();
			_onlineGPlayers[*it].clear();
		}
	}

	void GPlayerManager::add(GPlayer *gplayer)
	{
		UInt32 sno = gplayer->serverNo();
		_gplayers[gplayer->gid()] = gplayer;
		_gplayersById[sno][gplayer->playerId()] = gplayer;
		//std::string name = gplayer->userName();
		//if (!name.empty())
		//{
		//	strlwr(&name[0]);
		//}
		//_namedGPlayersByServer[sno][name] = gplayer;
		//_nameGPlayers[name] = gplayer;
		//if (gplayer->level() >= 100)
		//{
		//	++_highLevelNum;
		//}
	}

	bool GPlayerManager::addPlayer(Player *player, UInt8 roleid)
	{
		std::unordered_map<UInt32, GPlayer*>::iterator it = _gplayers.find(player->id());
		if (it == _gplayers.end())
		{
			return false;
		}
		else
		{
			return it->second->addPlayer(player, roleid);
		}
		return true;
	}

	void GPlayerManager::addBpsPlayerLeft(GPlayer *gplayer)
	{
		_bpsGPlayersLeft.insert(gplayer);
	}

	UInt32 GPlayerManager::uniqueGID()
	{
		if (zocfg.useIdPool)
		{
			// return uniquePoolID();
		}
		return ++_maxGID;
	}

	void GPlayerManager::setMaxGID(UInt32 gmaxId)
	{
		_maxGID = gmaxId;
	}

	GPlayer* GPlayerManager::findGPlayerById(UInt32 serverNo, const std::string &pid)
	{
		auto it = _gplayersById.find(serverNo);
		if (it == _gplayersById.end())
		{
			return NULL;
		}
		std::string playerid = pid;
		auto it2 = it->second.find(pid);
		if (it2 == it->second.end())
		{
			return NULL;
		}
		return it2->second;
	}

	void GPlayerManager::addOnline(GPlayer *p)
	{
		if (p != NULL)
		{
			_onlineGPlayers[p->serverNo()].insert(p);
		}
	}
}