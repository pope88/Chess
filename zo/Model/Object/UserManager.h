#ifndef _PLAYERMANAGER_H_
#define _PLAYERMANAGER_H_
#include "User.h"
#include "IdPool.h"
namespace Object
{
	class UserManager : public IdPool
	{
	public:
		UserManager();
		~UserManager();
	public:
		User * operator[] (UInt32); 
		void init();
		void add(User *user);
		void setMaxID(UInt32 maxId);
		UInt32 uniqueID();
		User* findUserByName(UInt32 serverNo, const std::string &name);
		User* findUserById(UInt32 serverNo, const std::string &pid);

		template<typename F>
		void foreach(F func)
		{
			for (auto it = _users.begin(); it != _users.end(); ++it)
			{
				if (!func(it->second))
				{
					return;
				}
			}
		}

		template<typename F>
		void foreachOnline(F func)
		{
			for(auto it = _onlineUsers.begin(); it != _onlineUsers.end(); ++ it)
			{
				for(auto it2 = it->second.begin(); it2 != it->second.end(); ++ it2)
				{
					if(!func(*it2))
					{
						return;
					}
				}
			}
		}

	private:
		std::unordered_map< UInt32, User* > _users;                  // all roles players
		std::unordered_map<std::string, User* > _nameUsers;          // all named role players
		std::map< UInt32, std::unordered_set<User*> > _onlineUsers;   // all online role players of per server
		std::map< UInt32, std::unordered_map< std::string, User* > > _idUsersByServer;
		std::map< UInt32, std::unordered_map<std::string, User* > > _namedUsersByServer;
		UInt32 _maxID;
	};

	extern UserManager userManager;
}
#endif