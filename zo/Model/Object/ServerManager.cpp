#include "Config.h"
#include "ServerManager.h"
#include "ZoCfg.h"

namespace Object
{
	ServerManager serverManager;
	void ServerManager::init()
	{
		size_t n = std::min(zocfg.serverNo.size(), zocfg.serverName.size());
		for (size_t i = 0; i < n; ++i)
		{
			add(zocfg.serverNo[i], zocfg.serverName[i]);
		}
	}

	void ServerManager::add(UInt32 id, std::string name)
	{
		std::string &s = _servers[id];
		if (s.empty())
		{
			s = name;
		}
		UInt32 &n = _serversByName[name];
		if (n == 0)
		{
			n = id;
		}
	}

	UInt32 ServerManager::operator[](std::string name) const
	{
		auto it = _serversByName.find(name);
		if (it == _serversByName.end())
		{
			return 0;
		}
		return it->second;
	}

	const std::string& ServerManager::operator[](UInt32 id) const
	{
		auto it = _servers.find(id);
		if(it == _servers.end())
		{
			static std::string empty;
			return empty;
		}
		return it->second;
	}


}