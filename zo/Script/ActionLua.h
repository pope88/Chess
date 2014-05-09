#ifndef _ACTIONLUA_H_
#define _ACTIONLUA_H_

#include "Script.h"
#include "../Model/Object/User.h"
//#include "Object/Guild.h"
#include "System/TimeUtil.h"

namespace Map
{
	class CityDungeon;
}

namespace Script
{
	using namespace Item;
	using namespace Object;

#define GetObj(BaseObj, DeriveObj)  BaseObj *Get##BaseObj(DeriveObj *dobj) { return dynamic_cast<BaseObj *>(dobj); }
	class ActionLua:
		public Script
	{
	public:
		ActionLua();
		~ActionLua();

	public:
		void init();
		void postInit();

	public:
		UInt32 getLoopQuestAward(User *pl);
		UInt32 getTowerAward(User *pl, UInt8 level);
		void playerLogin(User *pl);
		bool exchaneAward(User *pl, UInt8 id);
		bool getActivityAward(User *pl, UInt8 id, UInt8 typeId);
		void checkOption(User *pl);
		void calActivityState(UInt32 now);
		void attendBoss(User *pl);
		void towerWin(User *pl);
		void donate(User *pl);
		void loopQuest(User *pl); 
		void instituteBook(User *pl);
		void convoy(User *pl);
		void athleticChallenge(User *pl);
		void updateTimerPlayers(UInt8 type, User *pl);
		bool checkActivityAvalid(UInt8 type, User *pl);

	public:
		Table RunQuest(User *user, UInt32 questId);
		Table RunQuestStep(User *pl, UInt32 questId, UInt8 step);
		bool QuestCanAccept(User* user, UInt32 questId);
		bool AcceptQuest(User* user, UInt32 questId, UInt8 quality = 0);
		bool SubmitQuest(User* user, UInt32 questId);
		bool AbandonQuest(User* user, UInt32 questId);

		Table NpcAction(User *user, UInt32 npcId, UInt32 questId, UInt32 conveyId = 0);
		Table DefaultNpcAction(User *user, UInt32 npcId);
		void  MonsterKilled(User* user, UInt32 monsterId, UInt16 monsterNum = 1);
		void DungeonWin(User* user, UInt16 dungeonId);
		void DemonWin(User* user, UInt16 demonId);
		bool RunQuestItemUse(User *user, UInt32 itemId);
		bool RunConveyStep(User *pl, UInt32 questId, UInt32 monsterId, bool isWin);
		void PlotEnd(User *pl, UInt32 plotId);

	public:
		template<typename R>
		inline R Call(const std::string& name);
		template<typename R, typename T1>
		inline R Call(const std::string& name, const T1& t1);
		template<typename R, typename T1, typename T2>
		inline R Call(const std::string& name, const T1& t1, const T2& t2);
		template<typename R, typename T1, typename T2, typename T3>
		inline R Call(const std::string& name, const T1& t1, const T2& t2, const T3& t3);
		template<typename R, typename T1, typename T2, typename T3, typename T4>
		inline R Call(const std::string& name, const T1& t1, const T2& t2, const T3& t3, const T4& t4);
		template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
		inline R Call(const std::string& name, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5);

	public:
		template <typename R>
		inline R Run(User* user, const std::string& script);		
		template <typename R, typename T1>
		inline R Run(User* user, const std::string& script, const T1& t1);
		template <typename R, typename T1, typename T2>
		inline R Run(User* user, const std::string& script, const T1& t1,  const T2& t2);
		template <typename R, typename T1, typename T2, typename T3>
		inline R Run(User* user, const std::string& script, const T1& t1,  const T2& t2, const T3& t3);
		template <typename R, typename T1, typename T2, typename T3, typename T4>
		inline R Run(User* user, const std::string& script, const T1& t1,  const T2& t2, const T3& t3, const T4& t4);



	public:
		User* GetUser1() { return _user1; }
		User* GetUser2() { return _user2; } 
	public:

		/*GetObj(QuestMgr, User)
		GetObj(ItemPack, User)
		GetObj(Squad, User)
		GetObj(Fish, User)
		GetObj(Convoy, User)
		GetObj(HeroAvail, User)
		GetObj(BattlePrepare, User)
		GetObj(Demon, User)
		GetObj(Notification, User)
		GetObj(Clansman, User)
		GetObj(Activity, User)
		GetObj(GuildDungeon, Guild)*/

		//ItemPack* GetItemPack(User *pl){ return dynamic_cast<ItemPack *>(pl); }
		//QuestMgr* GetQuestMgr(User *pl){ return dynamic_cast<QuestMgr *>(pl); }
		//Squad* GetSquad(User *pl){ return dynamic_cast<Squad *>(pl); }
		//Fish* GetFish(User* pl){ return dynamic_cast<Fish *>(pl); }
		//Convoy* GetConvoy(User* pl){ return dynamic_cast<Convoy *>(pl); }
		//HeroAvail* GetHeroAvail(User *pl){ return dynamic_cast<HeroAvail *>(pl); }
		//BattlePrepare* GetBattlePrepare(User *pl){ return dynamic_cast<BattlePrepare *>(pl); }
		//Demon* GetDemon(User *pl){ return dynamic_cast<Demon *>(pl); }
		//Notification* GetNotification(User *pl){ return dynamic_cast<Notification* >(pl); }
		//Clansman* GetClansMan(User *pl){ return dynamic_cast<Clansman *>(pl); }
		//GuildDungeon* GetGuildDungeon(Guild* guild){ return dynamic_cast<GuildDungeon *>(guild); }
	
		//Map::CityDungeon* GetCityDungeon(Map::City *c);

	public:
		void openHelp(User *pl, UInt32 questId);

	protected:
		void regActionInterface();
	private:
		User* _user1;	//脚本动作行为主体1
		User* _user2;	//脚本动作行为主体2
	};

extern ActionLua gAction;

#include "ActionLuaImpl.inl"

}
#endif //_ACTIONLUA_H_
