#include "Config.h"
#include "MongoMgr.h"
#include "MongoExecutor.h"

namespace Database
{

	MongoMgr::MongoMgr()
	{
	}

	MongoMgr::~MongoMgr()
	{
	}

	void MongoMgr::init( const char * host, UInt16 port, const char * db )
	{
		_host = host;
		_port = port;
		_db = db;
	}

	MongoExecutor * MongoMgr::getExecutor()
	{
		return new(std::nothrow) MongoExecutor(_host, _port, _db);
	}

	MongoFinder * MongoMgr::getFinder()
	{
		return new(std::nothrow) MongoFinder(_host, _port, _db);
	}

}
