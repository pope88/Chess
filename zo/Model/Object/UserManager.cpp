#include "Config.h"
#include "UserManager.h"
#include "ZoCfg.h"

namespace Object
{
	UserManager userManager;

#ifndef _WIN32
	inline static char* strlwr( char* str )
	{
		char* orig = str;
		for ( ; *str != '\0'; str++ )
			*str = tolower(*str);
		return orig;
	}
#endif

	UserManager::UserManager():IdPool("player_id_range"), _users(4096), _maxID(0)
	{
	}
	
	UserManager::~UserManager()
	{
		_users.clear();
	}
	 
	User* UserManager::operator[] (UInt32 id)
	{
		 std::unordered_map<UInt32, User*>::iterator it = _users.find(id);
		 if (it == _users.end())
		 {
			 return NULL;
		 }
		 return it->second;
	 }

	void UserManager::init()
	{
		for (auto it = zocfg.serverNoSet.begin(); it != zocfg.serverNoSet.end(); ++it)
		{
			//user
			_onlineUsers[*it].clear();
			_idUsersByServer[*it].clear();
			_namedUsersByServer[*it].clear();
		}
	}

	void UserManager::setMaxID(UInt32 maxId)
	{
		_maxID = maxId;
	}

	UInt32 UserManager::uniqueID()
	{
		if (zocfg.useIdPool)
		{
			// return uniquePoolID();
		}
		return ++_maxID;
	}

	void UserManager::add(User *user)
	{
		UInt32 sno = user->serverNo();
		_users[user->id()] = user;
		_idUsersByServer[sno][user->playerId()] = user;
		std::string name = user->name();
		if (!name.empty())
		{
			strlwr(&name[0]);
		}
		_namedUsersByServer[sno][name] = user;
		_nameUsers[name] = user;
	}

	User* UserManager::findUserByName(UInt32 serverNo,const std::string &name)
	{
		auto it = _namedUsersByServer.find(serverNo);
		if (it == _namedUsersByServer.end())
		{
			return NULL;
		}

		std::string _name = name;
		strlwr(&_name[0]);
		auto it2 = it->second.find(_name);
		if (it2 == it->second.end())
		{
			it2 = _nameUsers.find(_name);
			if (it2 == _nameUsers.end())
			{
				return NULL;
			}
		}
		return it2->second;
	}


	 //User* UserManager::findPlayerById(UInt32 serverNo,const std::string &pid)
	 //{
		// auto it = _idUsersByServer.find(serverNo);
		// if (it == _idUsersByServer.end())
		// {
		//	 return NULL;
		// }
		// std::string playerid = pid;
		// auto it2 = it->second.find(pid);
		// if (it2 == it->second.end())
		// {
		//	 return NULL;
		// }
		// return it2->second;
	 //}

}

