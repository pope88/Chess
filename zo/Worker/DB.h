#ifndef _WORKER_DB_H_
#define _WORKER_DB_H_

#include "Base.h"
#include "System/MsgQueue.h"

namespace Database
{

	class MongoMgr;
	class MongoExecutor;
	class MongoAction;

}

namespace Worker
{
	class DB : public SimpleBase, public System::MsgQueue<Database::MongoAction *>
	{
	public:
		DB(bool isBackEnd);
		virtual ~DB();
		void push(Database::MongoAction *ma);
		void initPushLogger(const char* log);
	protected:
		virtual bool init();
		virtual void uninit();
		virtual void loop();
		virtual const char* getLogFilename() { return "db"; }
	private:
		bool query(Database::MongoAction *ma);
	private:
		bool _isBackend;
		Database::MongoMgr *_connMgr;
		Database::MongoExecutor *_executor;
		System::Logger* _pushLogger;
	};

	extern DB dbMongo;
	extern DB dbBackend;

#define MONGO_PUSH_COMMAND(cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(NULL, 15); if(ma != NULL) { ma->push("$eval", cmd); Worker::dbMongo.push(ma); } }

#define MONGO_PUSH_INSERT(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 0); if(ma != NULL) { ma->cmd; Worker::dbMongo.push(ma); } }
#define MONGO_PUSH_DELETE(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 1); if(ma != NULL) { ma->cmd; Worker::dbMongo.push(ma); } }
#define MONGO_PUSH_UPDATE(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 2); if(ma != NULL) { ma->cmd; Worker::dbMongo.push(ma); } }
#define MONGO_PUSH_UPSERT(db, cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 3); if(ma != NULL) { ma->cmd; Worker::dbMongo.push(ma); } }
#define MONGO_PUSH_COMMAND(cmd) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(NULL, 15); if(ma != NULL) { ma->push("$eval", cmd); Worker::dbMongo.push(ma); } }

#define BACKEND_PUSH_INSERT(pl, db, cmd) { if(zocfg.backendEnale) { Database::MongoActionBson *ma = NULL; if(pl->bTest()) {ma = new(std::nothrow) Database::MongoActionBson("dbTest", 0);} else { ma = new (std::nothrow) Database::MongoActionBson(db, 0);}} if(ma != NULL) { ma->set("serverNo", pl->serverNo()).cmd; Worker::dbBackend.push(ma); } } }
#define	BACKEND_PUSH_INSERT2(sno, db, cmd) {if(zocfg.backendEnale) { Database::MongoActionBson *ma = new (std::nothrow) Database::MongoActionBson(db, 1); if(ma != NULL){ ma->set("serverNo", sno).cmd; Worker::dbBackend.push(ma); } } }
#define BACKEND_PUSH_DELETE(db, cmd) { if(ktCfg.backendEnable) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 1); if(ma != NULL) { ma->cmd; Worker::dbBackend.push(ma); } } }
#define BACKEND_PUSH_UPDATE(db, cmd) { if(ktCfg.backendEnable) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 2); if(ma != NULL) { ma->cmd; Worker::dbBackend.push(ma); } } }
#define BACKEND_PUSH_UPSERT(db, cmd) { if(ktCfg.backendEnable) { Database::MongoActionBson * ma = new(std::nothrow) Database::MongoActionBson(db, 3); if(ma != NULL) { ma->cmd; Worker::dbBackend.push(ma); } } }

}

#endif