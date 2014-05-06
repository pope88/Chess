#ifndef _DBLOADER_H_
#define _DBLOADER_H_

namespace Database
{
	class MongoFinder;
}
namespace Object
{
	class DBLoader
	{
	public:
		static void load();
		//static void setIndex();
	    static UInt32 getOldVersion(Database::MongoFinder *finder);
		static void checkVersionPre(Database::MongoFinder *finder, UInt32);
		static void checkVersionPost(Database::MongoFinder *finder, UInt32);
		static void loadUsers(Database::MongoFinder *finder);
		static void loadItems(Database::MongoFinder *finder);
	};



}
#endif