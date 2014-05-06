#include "Config.h"
#include "DB.h"
#include "Database/MongoMgr.h"
#include "Database/MongoExecutor.h"
#include "Database/MongoAction.h"
#include "System/File.h"
#include "ZoCfg.h"
#include "System/Sleep.h"



namespace Worker
{
	DB dbMongo(false);
	DB dbBackend(true);
	DB::DB(bool isBackEnd):_isBackend(isBackEnd), _connMgr(NULL), _executor(NULL), _pushLogger(NULL)
	{
	}

	DB::~DB()
	{
		if (_pushLogger != NULL)
		{
			delete _pushLogger;
		}
	}

	bool DB::init()
	{
		System::File f(zocfg.logPath);
		f.createDirectories();
		_connMgr = new Database::MongoMgr;
		if (_isBackend)
		{
			_connMgr->init(zocfg.backendHost.c_str(), zocfg.backendPort, zocfg.backendDatabase.c_str());
		}
		else
		{
			_connMgr->init(zocfg.mongoHost.c_str(), zocfg.mongoPort, zocfg.mongoDatabase.c_str());
		}
		_executor = _connMgr->getExecutor();
		return true;
	}

	void DB::uninit()
	{
		delete _executor;
		delete _connMgr;
	}

	bool DB::query(Database::MongoAction *ma)
	{
		Database::MongoResult r;
		while ((r = _executor->run(*ma)) == Database::ConnLost)
		{
			//Lost connection to dataBase, retrying....
			System::Sleep(500);
		}
		return r == Database::OK;
	}

	void DB::push(Database::MongoAction *ma)
	{
		if (ma->type() < 0x10)
		{
			Database::MongoActionBson *mab = static_cast<Database::MongoActionBson *>(ma);
			mab->finish();
			if (_pushLogger != NULL)
			{
				std::ostringstream oss;
				if (mab->dump(oss))
				{
					_pushLogger->prolog(System::LogInfo)<< oss.str();
				}
			}
		}
		pushMsg(ma);
	}

	void DB::loop()
	{
		init();
		while (_running)
		{
			std::vector<Database::MongoAction* > *mq = fetchMsg();
			if (mq != NULL)
			{
				for (std::vector<Database::MongoAction*>::iterator it = mq->begin(); it != mq->end(); ++it)
				{
					query(*it);
					delete *it;
				}
				fetchEnd(mq);
			}
			System::Sleep(500);
		}
		uninit();
	}

	void DB::initPushLogger(const char* prefix)
	{
		_pushLogger = new System::Logger((zocfg.logPath + "/" + prefix).c_str());
	}
}