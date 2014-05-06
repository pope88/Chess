#include "Config.h"
#include "ActionLua.h"
//#include "Object/Athletics.h"
//#include "Map/CityDungeon.h"
//#include "Object/Feast.h"
//#include "Object/Boss.h"
//#include "Object/Activity.h"
//#include "Object/PlayerManager.h"


namespace Script
{

ActionLua gAction;

ActionLua::ActionLua() : _user1(NULL), _user2(NULL)
{
}

ActionLua::~ActionLua()
{
}

void ActionLua::init()
{
	regActionInterface();
}

void ActionLua::postInit()
{
	fprintf(stdout, "Scripts loaded.......\n");
	fflush(stdout);
	Call<bool>("calActivityState", TimeUtil::Now());	
}

void attackBoss(User *pl, UInt32 id)
{
	//Object::bossManager.attack(pl, id);
}

UInt8 getFeastStage()
{
	//return Object::feast.stage();
	return 0;
}

void ActionLua::regActionInterface()
{		
	/*
#define CLASS_ADD(klass)	\
	class_add<klass>(#klass)
#define CLASS_DEF(klass,member)	 \
	class_def<klass>(#member, &klass::member)
#define CLASS_STATIC_DEF(klass,member)	\
	class_def<klass>(#klass "_" #member, &klass::member)
#define CLASS_INH(child, base) \
	lua_tinker::class_inh<child, base>(_L);


	CLASS_ADD(ActionLua);
	CLASS_ADD(ActivityMgr);
	CLASS_ADD(PlayerManager);
	lua_tinker::set(_L, "_ActionLua", this);
	lua_tinker::set(_L, "gActivityMgr", &Object::gActivityMgr);
	lua_tinker::set(_L, "gPlayerManager", &playerManager);

	lua_tinker::def(_L, "attackBoss", attackBoss);
	lua_tinker::def(_L, "getFeastStage", getFeastStage);
	def("setConvoyRate", Convoy::setAddRate);

	CLASS_DEF(ActionLua, GetPlayer1);
	CLASS_DEF(ActionLua, GetPlayer2);
	CLASS_DEF(ActivityMgr, activityState);
	CLASS_DEF(ActivityMgr, setActivityState);
	CLASS_DEF(ActivityMgr, randomGameState);
	CLASS_DEF(PlayerManager, addTimerPlayers);

	CLASS_DEF(ActionLua, GetItemPack);
	CLASS_DEF(ActionLua, GetQuestMgr);
	CLASS_DEF(ActionLua, GetFish);
	CLASS_DEF(ActionLua, GetConvoy);
	CLASS_DEF(ActionLua, GetBattlePrepare);
	CLASS_DEF(ActionLua, GetHeroAvail);
	CLASS_DEF(ActionLua, GetSquad);
	CLASS_DEF(ActionLua, GetDemon);
	CLASS_DEF(ActionLua, GetNotification);
	CLASS_DEF(ActionLua, GetCityDungeon);
	CLASS_DEF(ActionLua, openHelp);
	CLASS_DEF(ActionLua, GetGuildDungeon);
	CLASS_DEF(ActionLua, GetClansman);
	CLASS_DEF(ActionLua, GetActivity);

	CLASS_ADD(User);
	CLASS_ADD(HeroAvail);
	CLASS_ADD(ItemPack);
	CLASS_ADD(QuestMgr);
	CLASS_ADD(Squad);
	CLASS_ADD(BattlePrepare);
	CLASS_ADD(Demon);
	CLASS_ADD(Notification);
	CLASS_ADD(Map::CityDungeon);
	CLASS_ADD(Map::City);
	CLASS_ADD(Fish);
	CLASS_ADD(Convoy);
	CLASS_ADD(Clansman);
	CLASS_ADD(Guild);
	CLASS_ADD(GuildDungeon);
	CLASS_ADD(Activity);

	
	CLASS_DEF(User, id);
	CLASS_DEF(User, getGold);
	CLASS_DEF(User, gold);
	CLASS_DEF(User, getGoldB);
	CLASS_DEF(User, goldB);
	CLASS_DEF(User, getSilver);
	CLASS_DEF(User, silver);
	CLASS_DEF(User, getEnergy);
	CLASS_DEF(User, energy);
	CLASS_DEF(User, setstatus);
	CLASS_DEF(User, status);
	CLASS_DEF(User, setoption);
	CLASS_DEF(User, option);
	CLASS_DEF(User, hasOption);
	CLASS_DEF(User, addOption);
	CLASS_DEF(User, getOptionBits);
	CLASS_DEF(User, setOptionBits);
	CLASS_DEF(User, settotalTopup);
	CLASS_DEF(User, settotalConsume);
	CLASS_DEF(User, totalConsume);
	CLASS_DEF(User, getProfExp);
	CLASS_DEF(User, level);
	CLASS_DEF(User, getCity);
	CLASS_DEF(User, setx);
	CLASS_DEF(User, x);
	CLASS_DEF(User, sety);
	CLASS_DEF(User, y);
	CLASS_DEF(User, openDungeon);
	CLASS_DEF(User, hasStatus);
	CLASS_DEF(User, miningCount);
	CLASS_DEF(User, hasRide);
	CLASS_DEF(User, sendSysMsg);
	CLASS_DEF(User, online);
	CLASS_DEF(User,  removeRide);

	CLASS_DEF(QuestMgr, hasQuestAccepted);
	CLASS_DEF(QuestMgr, hasQuestCompleted);
	CLASS_DEF(QuestMgr, hasQuestSubmited);
	CLASS_DEF(QuestMgr, questNotComplete);
	CLASS_DEF(QuestMgr, acceptQuest);
	CLASS_DEF(QuestMgr, submitQuest);
	CLASS_DEF(QuestMgr, abandonQuest);
	CLASS_DEF(QuestMgr, addQuestStep);
	CLASS_DEF(QuestMgr, addQuestStep1);
	CLASS_DEF(QuestMgr, addLastStep);
	CLASS_DEF(QuestMgr, getQuestStep);
	CLASS_DEF(QuestMgr, getQuestStatus);
	CLASS_DEF(QuestMgr, resetQuestStep);
	CLASS_DEF(QuestMgr, getQuestEndTm);
	CLASS_DEF(QuestMgr, getQuestSubmitNpc);
	CLASS_DEF(QuestMgr, getLQCount);
	CLASS_DEF(QuestMgr, addQuestObjects);
	CLASS_DEF(QuestMgr, delQuestObjects);
	CLASS_DEF(QuestMgr, beginPlot);
	CLASS_DEF(QuestMgr, failConvey);

 	CLASS_DEF(ItemPack, GetItemNum);
	CLASS_DEF(ItemPack, BeginItemOperation);
	CLASS_DEF(ItemPack, EndItemOperation);
	CLASS_DEF(ItemPack, AddItem);
	CLASS_DEF(ItemPack, RemoveItem);
	CLASS_DEF(ItemPack, TryAddItem);
	CLASS_DEF(ItemPack, GetUsableSize);

	CLASS_DEF(Squad, job);
	CLASS_DEF(Squad, job2);
	CLASS_DEF(Squad, potential);
	CLASS_DEF(Squad, getExp);
	CLASS_DEF(Squad, hasSummonedHero);

	CLASS_DEF(Fish, getFishCount);
	CLASS_DEF(Fish, isFishCancel);

	CLASS_DEF(Convoy, getConvoyNum);
	CLASS_DEF(Convoy, isConvoyInterupt);
	CLASS_DEF(Clansman, spinMoney);
	CLASS_DEF(Clansman, guild);
	CLASS_DEF(Guild, glevel);
	CLASS_DEF(Guild, getActionstate);
	CLASS_DEF(GuildDungeon, isDungeonBegin);
	CLASS_DEF(GuildDungeon, attack);


	CLASS_DEF(HeroAvail, setFinished);
	CLASS_DEF(BattlePrepare, attackNpc);
	CLASS_DEF(BattlePrepare, attackNpcExtra);

	CLASS_DEF(Demon, openDemon);
	CLASS_DEF(Demon, demonPassed);
	CLASS_DEF(Demon, eachDemonPassed);
	CLASS_DEF(Map::CityDungeon, attackMonster);
	CLASS_DEF(Notification, addNotifyLua);
	CLASS_DEF(Notification, addNotifyAwardLua);
	*/
}

Table ActionLua::RunQuest(User *user, UInt32 questId)
{
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "Quest_%08d", questId);
	return Run<Table>(user, buffer);
}

Table ActionLua::RunQuestStep(User *pl, UInt32 questId, UInt8 step)
{
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "Quest_%08d_Step", questId);
	return Run<Table>(pl, buffer, step);
}

bool ActionLua::QuestCanAccept(User* user, UInt32 questId)
{
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "Quest_Can_Accept_%08d", questId);
	return Run<bool>(user, buffer);
}

bool ActionLua::AcceptQuest(User* user, UInt32 questId, UInt8 quality)
{
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "Quest_%08d_accept", questId);
	return Run<bool>(user, buffer, quality);
}

bool ActionLua::AbandonQuest(User *user, UInt32 questId)
{
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "Quest_%08d_abandon", questId);
	return Run<bool>(user, buffer);
}

bool ActionLua::SubmitQuest(User* user, UInt32 questId)
{
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "Quest_%08d_submit", questId);
	return Run<bool>(user, buffer);
}

void ActionLua::MonsterKilled(User* user, UInt32 monsterId, UInt16 monsterNum)
{
	Run<bool>(user, "RunMonsterKilled", monsterId, monsterNum);
}

void ActionLua::DungeonWin(User* user, UInt16 dungeonId)
{
	Run<bool>(user, "DungeonWin", dungeonId);
}

void ActionLua::DemonWin(User* user, UInt16 demonId)
{
	Run<bool>(user, "DemonWin", demonId);
}

Table ActionLua::NpcAction(User *user, UInt32 npcId, UInt32 questId, UInt32 conveyId)
{
	return Run<Table>(user, "RunNpcAction", npcId, questId, conveyId);
}

Table ActionLua::DefaultNpcAction( User *user, UInt32 npcId )
{
	return Run<Table>(user, "NpcDefaultAction", npcId);
}

bool ActionLua::RunQuestItemUse(User *user, UInt32 itemId)
{
	return Run<bool>(user, "RunQuestItemUse", itemId);
}

bool ActionLua::RunConveyStep(User *pl, UInt32 questId, UInt32 monsterId, bool isWin)
{
	return Run<bool>(pl, "RunConveyStep", questId, monsterId, isWin);
}

void ActionLua::PlotEnd(User *pl, UInt32 plotId)
{
	Run<bool>(pl, "RunPlotEnd", plotId); 
}

UInt32 ActionLua::getLoopQuestAward(User *pl)
{
	return Call<UInt32>("getLoopQuestAward", pl);
}

UInt32 ActionLua::getTowerAward(User *pl, UInt8 level)
{
	return Call<UInt32>("getTowerAward", level);
}

void ActionLua::playerLogin(User *pl)
{
	Call<bool>("login", pl);
}

bool ActionLua::exchaneAward(User *pl, UInt8 id)
{
	return Call<bool>("exchangeAward", pl, id);
}

bool ActionLua::getActivityAward(User *pl, UInt8 id, UInt8 typeId)
{
	return Call<bool>("getActivityAward", pl, id, typeId);
}

void ActionLua::checkOption(User *pl)
{
	Call<bool>("checkOption", pl);
}

void ActionLua::calActivityState(UInt32 now)
{
	Call<bool>("calActivityState", now);
}

void ActionLua::attendBoss(User *pl)
{
	Call<bool>("attendBoss", pl);
}

void ActionLua::towerWin(User *pl)
{
	Call<bool>("towerWin", pl);
}

void ActionLua::donate(User *pl)
{
	Call<bool>("donate", pl);
}

void ActionLua::loopQuest(User *pl)
{
	Call<bool>("loopQuest", pl);
}

void ActionLua::updateTimerPlayers(UInt8 type, User *pl)
{
	Call<bool>("updateTimerPlayers", type, pl);
}

bool ActionLua::checkActivityAvalid(UInt8 type, User *pl)
{
	return Call<bool>("checkActivityAvalid", type, pl);
}

void ActionLua::openHelp(User *user, UInt32 questId)
{
	switch(questId)
	{
		case 101076:
			//athletics.enter(user);
			break;
		case 101251:
			//user->newConvoy();//for main city convoy
			//user->newFishing();
			//user->newLoopQuest();
			break;
		default:
			break;			
	}
}

//Map::CityDungeon* ActionLua::GetCityDungeon( Map::City *c )
//{
//	return dynamic_cast<Map::CityDungeon* >(c);
//}

void ActionLua::instituteBook( User *pl )
{
	Call<void>("instituteBook", pl);
}

void ActionLua::convoy( User *pl )
{
	Call<void>("convoy", pl);
}

void ActionLua::athleticChallenge( User *pl )
{
	Call<void>("athleticChallenge", pl);
}


}