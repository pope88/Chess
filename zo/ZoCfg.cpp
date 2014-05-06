#include "Config.h"
#include "ZoCfg.h"
#include "System/IniFile.h"
#include "System/TimeUtil.h"
#include "System/StringTokenizer.h"
#include <sstream>
#include <hiredis/hiredis.h>

ZoCfg zocfg;

ZoCfg::ZoCfg():serverNo(0), tcpPort(0),  redisPort(0), mongoPort(0), backendEnable(false), backendPort(0), onlineLogInterval(0), openDay(0), debugMode(false), enableGM(false), postReg(false), useOldData(false)
{
}

ZoCfg::~ZoCfg()
{

}

void ZoCfg::loadString(const char *cfg)
{
	System::IniFileA iniFile;

	debugMode = true;
	enableGM = true;

	std::istringstream s(cfg);
	iniFile.Load(s);
	processIniFile(iniFile);
}

void ZoCfg::load(const std::string& filename)
{
	System::IniFileA iniFile;
	debugMode = true;
	enableGM = true;
	if (iniFile.Load(filename))
	{
		processIniFile(iniFile);
	}
}




void ZoCfg::processIniFile(System::IniFileA &iniFile)
{
	System::IniSection *sec = iniFile.GetSection("network");
	if (sec != NULL)
	{
		tcpHost = sec->GetKeyValue("tcpHost");
		tcpPort = (UInt16)atoi(sec->GetKeyValue("tcpPort").c_str());
	}

	sec = iniFile.GetSection("redis");
	if (sec != NULL)
	{
		redisHost = sec->GetKeyValue("host");
		redisPort = (UInt16)atoi(sec->GetKeyValue("port").c_str());
		redisPrefix = sec->GetKeyValue("prefix");
	}

	sec = iniFile.GetSection("mongo");
	if (sec != NULL)
	{
		mongoHost = sec->GetKeyValue("host");
		mongoPort = (UInt16)atoi(sec->GetKeyValue("port").c_str());
		mongoDatabase = sec->GetKeyValue("database");
	}

	sec = iniFile.GetSection("backend");
	if (sec != NULL)
	{
		backendEnable = atoi(sec->GetKeyValue("disable").c_str()) == 1;
		backendHost = sec->GetKeyValue("host");
		backendPort = (UInt16)atoi(sec->GetKeyValue("port").c_str());
		backendDatabase = sec->GetKeyValue("database");
		onlineLogInterval = (UInt32)atoi(sec->GetKeyValue("onlineLogInterval").c_str());
	}

	sec = iniFile.GetSection("main");
	if (sec != NULL)
	{
		{
			System::StringTokenizer tok(sec->GetKeyValue("serverNo"), ",");
			for (auto it = tok.begin(); it != tok.end(); ++it)
			{
				UInt32 id = (UInt32)atoi(it->c_str());
				serverNo.push_back(id);
				serverNoSet.insert(id);
			}
		}

		{
			System::StringTokenizer tok(sec->GetKeyValue("serverName"), ",");
			for (auto it = tok.begin(); it != tok.end(); ++it)
			{
				serverName.push_back(*it);
			}
		}
		openDay = TimeUtil::SharpDay(0, atoi(sec->GetKeyValue("openTime").c_str()));
		serverKey = sec->GetKeyValue("serverKey");
		dataPath = sec->GetKeyValue("dataPath");
		logPath = sec->GetKeyValue("logPath");
		sqlPath = sec->GetKeyValue("sqlPath");
		scriptPath = sec->GetKeyValue("scriptPath");
		postReg = atoi(sec->GetKeyValue("postReg").c_str()) > 0;
		useOldData = atoi(sec->GetKeyValue("useOldData").c_str()) > 0;
	}
	
	sec = iniFile.GetSection("idPool");
	if (sec != NULL)
	{
		useIdPool = atoi(sec->GetKeyValue("enable").c_str()) > 0;
		idPoolHost = sec->GetKeyValue("host");
		idPoolPort = (UInt16)atoi(sec->GetKeyValue("port").c_str());
	}

	sec = iniFile.GetSection("admin");
	if (sec != NULL)
	{
		debugMode = atoi(sec->GetKeyValue("debugMode").c_str()) > 0;
		enableGM = atoi(sec->GetKeyValue("enableGM").c_str()) > 0;
	}

	//tcpHost
	if (tcpHost.empty())
	{
		tcpHost = "0.0.0.0";
	}
	if (tcpPort == 0)
	{
		tcpPort = 8880;
	}

	//redis
	if (redisHost.empty())
	{
		redisHost = "localhost";
	}
	if (redisPort == 0)
	{
		redisPort = 6379;
	}

	//mongo
	if (mongoHost.empty())
	{
		mongoHost = "localhost";
	}
	if (mongoPort == 0)
	{
		mongoPort = 27017;
	}
	if (mongoDatabase.empty())
	{
		mongoDatabase = "zo_test";
	}

	//backend
	if (backendHost.empty())
	{
		backendHost = mongoHost;
	}
	if (backendPort )
	{
		backendPort = mongoPort;
	} 
	if (backendDatabase.empty())
	{
		backendDatabase = "zo_backend";
	}
	if (onlineLogInterval == 0)
	{
		onlineLogInterval = 60;
	}

	if (serverKey.empty())
	{
		serverKey = "zerotest";
	}
	if (serverNo.empty())
	{
		serverNo.push_back(0);
	}
	if (serverName.empty())
	{
		serverName.push_back("zerotest");
	}

	if(dataPath.empty())
	{
		dataPath = "conf/data/";
	}
	if(logPath.empty())
	{
		logPath = "log/";
	}
	if(sqlPath.empty())
	{
		sqlPath = "sql/";
	}
	if(scriptPath.empty())
	{
		scriptPath = "Scripts/";
	}

	//Battle::battlereplay.init();

	//channelName.clear();
	if(!serverName.empty())
	{
		//for(auto it = serverName.begin(); it != serverName.end(); ++ it)
		//{
		//	std::string::size_type pos = it->find("_s");
		//	channelName.push_back(it->substr(0, pos));
		//}
		struct timeval tv = {1, 0};
		redisContext * conn = redisConnectWithTimeout(redisHost.c_str(), redisPort, tv);
		if(conn == NULL || !(conn->flags & REDIS_CONNECTED))
		{
			redisFree(conn);
			return;
		}
		for(auto it = serverName.begin(); it != serverName.end(); ++ it)
		{
			void * reply = redisCommand(conn, "SET %s%s|info %s:%d", redisPrefix.c_str(), it->c_str(), tcpHost.c_str(), tcpPort);
			//void * reply = redisCommand(conn, "SET foo %d", tcpPort);
			if(reply != NULL) freeReplyObject(reply);
		}
		redisFree(conn);
	}
}