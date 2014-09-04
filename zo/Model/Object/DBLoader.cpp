#include "Config.h"
#include "DBLoader.h"
#include "ZoCfg.h"
#include "Database/MongoExecutor.h"
#include "Database/MongoAction.h"
#include "Database/MongoMgr.h"
#include "Model/Object/User.h"
#include "Model/Object/UserManager.h"
#include "Worker/DB.h"
#include "UserManager.h"

namespace Database
{
	namespace
	{
		struct DBVersion
		{
			UInt32 version;
		};

		struct DBIdRange
		{
			UInt32 id;
		};

		struct DBUser
		{
			UInt32 id;
			std::string playerid;
			UInt32 regtime;
			UInt32 dailycp;
			UInt32 gold;
			UInt32 totaltopup;
			UInt64 totallosegold;
			UInt32 lastonline;
			UInt8 lockend;
			bool ismale;
			std::string name;
			UInt32 serverno;
			UInt8 level;
			UInt32 dailyprogress;
			UInt64 guidestep;
			UInt32 experience;
		};

		struct DBItem
		{
			UInt32 playerid ;
			UInt32 gid;
			UInt32 keyid ;
			UInt32 itemid;
			UInt32 param ;
			UInt32 position ;
			UInt32 level;
		};
	}

	MBINDBEGIN(DBVersion)
		MBIND(version);
	MBINDEND();

	MBINDBEGIN(DBIdRange)
		MBIND(id);
	MBINDEND();

	MBINDBEGIN(DBUser) 
		MBIND(id);
		MBIND(playerid);
		MBIND(regtime);
		MBIND(dailycp);
		MBIND(gold);
		MBIND(totaltopup);
		MBIND(totallosegold);
		MBIND(lastonline);
		MBIND(lockend);
		MBIND(ismale);
		MBIND(name);
		MBIND(serverno);
		MBIND(level);
		MBIND(dailyprogress);
		MBIND(guidestep);
		MBIND(experience);
	MBINDEND();

	MBINDBEGIN(DBItem)
		MBIND(playerid);
	    MBIND(gid);
	    MBIND(keyid);
		MBIND(itemid);
	    MBIND(param);
	    MBIND(position);
	    MBIND(level);
	MBINDEND();
}

namespace Object
{
	namespace 
	{
		class SinglePlayer
		{
		public:
			SinglePlayer():_obj(NULL), _lastId(0xFFFFFFFF) {}
			inline void update(UInt32 id)
			{
				if (id != _lastId)
				{
					_obj = userManager[id];
					_lastId = id;
				}
			}
			inline User* updateOld(UInt32 id)
			{
				if (id != _lastId)
				{
					User *r = _obj;
					_obj = userManager[id];
					_lastId = id;
					return r;
				}
				return NULL;
			}
			inline User* updateNew(UInt32 id)
			{
				if ( id != _lastId)
				{
					_obj = userManager[id];
					_lastId = id;
					return _obj;
				}
				return NULL;
			}
			inline User* operator->() { return _obj; }
			inline bool isNull() { return _obj == NULL; }
			inline User * getPointer() { return _obj ;}
		private:
			User *_obj;
			UInt32 _lastId;
		};
	}

	const UInt32 thisVersion = 10;

	UInt32 DBLoader::getOldVersion(Database::MongoFinder * finder)
	{
		finder->ensureIndex("version", "id", true);
		Database::DBVersion dbv;
		UInt32 oldVersion = thisVersion;
		if(finder->findOne(Database::MongoActionBson("version").finish(), dbv) == Database::OK)
		{
			oldVersion = dbv.version;
		}
		else
		{
			MONGO_PUSH_UPSERT("version", set("version", thisVersion).cond("id", 1));
		}
		return oldVersion;
	}

	void DBLoader::load()
	{
		Database::MongoMgr *connMgr = new Database::MongoMgr;
		connMgr->init(zocfg.mongoHost.c_str(), zocfg.mongoPort, zocfg.mongoDatabase.c_str());
		Database::MongoFinder *finder = connMgr->getFinder();
		if (finder == NULL)
		{
			delete connMgr;
			return;
		}
		//UInt32 ov = getOldVersion(finder);
		//checkVersionPre(finder, ov);
		loadUsers(finder);
	}

	void DBLoader::checkVersionPre(Database::MongoFinder *finder, UInt32 oldVersion)
	{
		switch (oldVersion)
		{
		case 0 :
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			finder->dropIndexes("players");
			break;
		}
	}

	void DBLoader::checkVersionPost(Database::MongoFinder *finder, UInt32 oldVersion)
	{
		if (oldVersion != thisVersion)
		{
			switch(oldVersion)
			{
			case 0:
				break;
			//case 0:
			//	{
			//		userManager.foreach([](User *pl)->bool {
			//			if (pl->level() >= 30)
			//			{
			//				pl->beginAddNotifyReward(102).add(2550, 3, true).end();
			//			}
			//			return true;
			//		});

			//	}
			//case 1:
			//	{
			//		userManager.foreach([](User *pl)->bool {
			//			pl->setLeftDays(Privilege::id2PrgType(1), 180, false);
			//			return true;
			//		});
			//		UInt32 endTime = TimeUtil::ThisDay() + (180-1)*86400;
			//		char cmd[256];
			//		sprintf(cmd, "db.user.find().forEach(function(obj) { db.privilege.update({playerId:obj.id, id:1}, {$set:{lastDay:%u}}, true, false);  })", endTime);
			//		MONGO_PUSH_COMMAND(cmd);
			//	}
			//case 3:
			//	 4:
			//	 {
			//		 char cmd[256];
			//		 char cmd[256];
			//		 sprintf(cmd, "db.demon.find({resetCount:{$exists:1}}).forEach( function(obj) { obj.resetCount = (obj.resetCount & 0xFF1F) | ((obj.resetCount & 0x60) << 1); db.demon.save(obj); } )");
			//		 MONGO_PUSH_COMMAND(cmd);
			//	 }
			}
			MONGO_PUSH_UPSERT("version", set("version", thisVersion).cond("id", 1));
		}
	}


	void DBLoader::loadUsers(Database::MongoFinder *finder)
	{
		bool buip = zocfg.useIdPool;
		if (buip)
		{
			//finder->ensureIndex("player_id_range", "id", true);
			//Database::DBIdRange dbir;
			//if (finder->findPrepare(Database::MongoActionBson("player_id_range").finish(), dbir) == Database::OK)
			//{
			//	while(finder->findNext() == Database::OK)
			//	{
			//		userManager.addIdPoolRange(dbir.id, false);
			//	}
			//}
		}

		finder->ensureIndex("user", "id", true);
		finder->ensureIndex("user", "serverNo", "name", true);
		finder->ensureIndex("user", "serverNo", "playerid", true);
		Database::DBUser dbpl;
		UInt32 maxId = 0;
		if (finder->findPrepare(Database::MongoActionBson("user").finish(), dbpl) == Database::OK)
		{
			while (finder->findNext() == Database::OK)
			{
				if (dbpl.id == 0)
				{
					continue;
				}
				if (!buip && dbpl.id > maxId)
				{
					maxId = dbpl.id;
				}

				User *user = new User(dbpl.id, dbpl.playerid);
				
				//user->setserverNo();
				user->setregtime(dbpl.regtime, false);
				user->setdailycp(dbpl.dailycp, false);
				user->setgold(dbpl.gold, false);
				user->settotaltopup(dbpl.totaltopup, false);
				user->settotallosegold(dbpl.totallosegold, false);
				user->setlastonline(dbpl.lastonline, false);
				user->setlockend(dbpl.lockend, false);
				user->setismale(dbpl.ismale, false);
				user->name(dbpl.name, false);
				user->setserverno(dbpl.serverno == 0 ? zocfg.serverNo[0] : dbpl.serverno, false);
				user->setlevel(dbpl.level, false);
				user->setdailyprogress(dbpl.dailyprogress, false);
				user->setguidestep(dbpl.guidestep, false);
				user->setexperience(dbpl.experience, false);
				userManager.add(user);
			}

			if (buip)
			{
				//userManager.removeAllIdFromPool();
			}
			else
			{
				userManager.setMaxID(maxId);
			}
		}
	}

	void DBLoader::loadItems(Database::MongoFinder *finder)
	{
		finder->ensureIndex("item", "playerid", "keyid", true);
		finder->ensureIndex("item", "keyid", false);
		finder->ensureIndex("item", "gid", false);
		Database::DBItem dbi;
		SinglePlayer sp;
		if (finder->findPrepare(Database::MongoActionBson("item").orderby().push("playerid"),dbi) == Database::OK )
		{
			while( finder->findNext() == Database::OK )
			{
				if( dbi.playerid == 0 )
				{
					//Item::stock.loadItem( dbi.keyid,dbi.param,dbi.enchant );
					continue;
				}
				sp.update(dbi.playerid);
				if(sp.isNull())
					continue;
				if(dbi.keyid < 100000)
					sp->loadItem(dbi.playerid, dbi.keyid, dbi.itemid, dbi.param);
				else
				{
					//sp->LoadEquip(dbi.playerid, dbi.keyid, dbi.param, dbi.position, dbi.enchant, dbi.refine, dbi.magictype, dbi.evolve, dbi.gems);
					//if(dbi.keyid >= sp->UID(0))
					//	sp->UID(dbi.keyid+1);
				}
			}
		}
	}
}