#include "Config.h"
#include "Game.h"
#include "Packet/Processor.h"
#include "Model/Object/ServerManager.h"
#include "Model/Object/UserManager.h"
#include "Worker/Tcp.h"
#include "Worker/Game.h"
#include "Worker/DB.h"
#include "System/TimeUtil.h"
#include "Model/Object/GameTimer.h"
#include "Model/Object/DBLoader.h"
#include "Model/Data/CsvLoader.h"
#include "Model/Object/RoomManager.h"
#include "ZoGlobal.h"
#include "Block.h"

namespace Worker
{
	Game game;
	Game::~Game()
	{
		delete _processor;
	}

	void Game::loop()
	{
		Object::serverManager.init();
		Object::userManager.init();

		//Script::gAction.doFile((ktCfg.scriptPath + "main.lua").c_str());

		zoGlobal.init();

		Data::CsvLoader::load();

		//Object::market.initSorter();

		//Object::GameMaster::init();

		dbMongo.initPushLogger("push");

		Object::DBLoader::load();

		//dbMongo.start();

		//if(zoCfg.backendEnable)
		//{
		//	dbBackend.start();
		//	Object::DBLoader::setIndex();
		//}

		Object::gameTimer.init();

		//combat.start();  //battle datas

		//block.start();  //login

		tcp.start();

		Object::roomManager.init();

		UInt32 lastSec = 0;
		while(_running)
		{
			_processor->process();
			if(TimeUtil::Update())
			{
				Object::gameTimer.onDailyCheck();
			}
			UInt32 now = TimeUtil::Now();
			if(now != lastSec)
			{
				Object::gameTimer.onTickCheck();
				lastSec = now;
			}
		}
		tcp.stop();
		//block.stop();
		//combat.stop();
		//if(ktCfg.backendEnable)
		//	dbBackend.stop();
		Object::gameTimer.uninit();
		tcp.join();
		//block.join();
		//combat.join();
		//System::Sleep(2000);
		//dbMongo.stop();
		//dbMongo.join();
		//if(ktCfg.backendEnable)
		//	dbBackend.join();

		//Data::CsvLoader::unload();
	}

	Packet::Processor* Game::processor()
	{
		if (_processor == NULL)
		{
			_processor = new Packet::Processor;
		}
		return _processor;
	}


}