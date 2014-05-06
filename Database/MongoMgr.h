#ifndef _MONGOMGR_H_
#define _MONGOMGR_H_

namespace Database
{

	class MongoExecutor;
	class MongoFinder;
	class MongoMgr
	{
	public:
		MongoMgr();
		~MongoMgr();
		void init(const char * host, UInt16 port, const char * db);
		MongoExecutor * getExecutor();
		MongoFinder * getFinder();
	private:
		std::string _host;
		UInt16 _port;
		const char * _db;
	};

}

#endif // _MONGOMGR_H_
