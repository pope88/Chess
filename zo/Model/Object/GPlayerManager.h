#ifndef _GPLAYERMANAGER_H_
#define _GPLAYERMANAGER_H_
#include "GPlayer.h"
#include "Player.h"
#include "IdPool.h"

namespace Object
{
	class GPlayerManager : public IdPool
	{
	public:
		GPlayerManager();
		~GPlayerManager();
	public:
		GPlayer * operator[] (UInt32); 
		void init();
		void add(GPlayer *gplayer);
		bool addPlayer(Player *player, UInt8 roleid);
		void addBpsPlayerLeft(GPlayer *gplayer);
		UInt32 uniqueGID();
		void setMaxGID(UInt32 maxId);
		GPlayer* findGPlayerById(UInt32 serverNo, const std::string &pid);
		void addOnline(GPlayer *p);

		template<typename F>
		void foreach(F func)
		{
			for (auto it = _gplayers.begin(); it != _gplayers.end(); ++it)
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
			for(auto it = _onlineGPlayers.begin(); it != _onlineGPlayers.end(); ++ it)
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
		std::unordered_map< UInt32, GPlayer* > _gplayers;                  // all players
		//std::unordered_map<std::string, GPlayer* > _nameGPlayers;
		std::map< UInt32, std::unordered_map< std::string, GPlayer* > > _gplayersById;
		//std::map< UInt32, std::unordered_map< std::string, GPlayer* > >_namedGPlayersByServer;
		std::map< UInt32, std::unordered_set<GPlayer*> > _onlineGPlayers;  // all online players
		std::unordered_set<GPlayer *>_bpsGPlayersLeft;                    //pay users              
		UInt32 _maxGID;
	};
	extern GPlayerManager gplayerManager;
}
#endif