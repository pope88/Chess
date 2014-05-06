#include "Config.h"
#include "GameTimer.h"
#include "System/TimeUtil.h"
#include "UserManager.h"
#include "TimerBase.h"

namespace Object
{
	using namespace ::Data::Define;
	GameTimer gameTimer;
	GameTimer::GameTimer()
	{
		_timers.resize(TimerMax);
		_month = TimeUtil::Month();
	}

	void GameTimer::init()
	{
		auto bt = Data::timerData.bootTimers();
		for (auto it = bt.begin(); it != bt.end(); ++it)
		{
			addPresetTimer(*it, 0, 0);
		}
	}

	void GameTimer::uninit()
	{
		userManager.foreachOnline([](User *user)->bool { user->shutdown(); return true;});
	}

	void GameTimer::addPresetTimer( const Data::TimerData::SingleTimer& st, void *key, UInt32 firstInterval)
	{
		if (st.param2 != 0)
		{
			key = reinterpret_cast<void*>(st.param2);
		}
		if (st.baseTime == 0)
		{
			if (st.addTime != 0)
			{
				firstInterval = st.addTime;
			}
			if (firstInterval)
			{
				addTimerWithFirst(st.id, key, st.interval, firstInterval, st.param1, st.weekdays);
			}
			else
			{
				addTimer(st.id, key, st.interval, st.once, st.param1, st.weekdays);
			}
			return ;
		}
		UInt32 nday;
		if(st.baseTime >= 86400)
			nday = TimeUtil::ThisDay();
		else
			nday = TimeUtil::Now() / st.baseTime * st.baseTime;
		nday += st.addTime;
		UInt32 now = TimeUtil::Now();
		if(nday < now)
			nday += st.baseTime;
		firstInterval = nday - now;
		if(st.once)
			addTimer(st.id, key, firstInterval, true, st.param1, st.weekdays);
		else
			addTimerWithFirst(st.id, key, st.interval, firstInterval, st.param1, st.weekdays);
	}

	bool GameTimer::addTimerWithFirst(int typeId, void *key, UInt32 interval, UInt32 firstInterval, UInt32 param, UInt8 wd)
	{
		if (_timers[typeId].find(key) != _timers[typeId].end())
		{
			return false;
		}
		TimerInfo& td = _timers[typeId][key];
		td.typeId = typeId;
		td.key = key;
		td.param = param;
		td.data = add(interval, firstInterval, &td);
		td.wd = wd;
		if (td.data == NULL)
		{
			_timers[typeId].erase(key);
			return false;
		}
		return true;
	}

	bool GameTimer::addTimer( int typeId, void * key, UInt32 interval, bool once, UInt32 param, UInt8 wd )
	{
		if(_timers[typeId].find(key) != _timers[typeId].end())
			return false;
		TimerInfo& td = _timers[typeId][key];
		td.typeId = typeId;
		td.key = key;
		td.param = param;
		td.wd = wd;
		if(once)
			td.data = add(interval, &td, 1);
		else
			td.data = add(interval, &td);
		if(td.data == NULL)
		{
			_timers[typeId].erase(key);
			return false;
		}
		return true;
	}

	void GameTimer::removeTimer(int typeId, void *key)
	{
		std::unordered_map<void *, TimerInfo>::iterator it = _timers[typeId].find(key);
		if(it == _timers[typeId].end())
			return;
		remove(it->second.data);
		_timers[typeId].erase(it);
	}

	void GameTimer::onDailyCheck()
	{
		//do daily things
	}

	void GameTimer::onTickCheck()
	{
		process();
	}

	void GameTimer::onTimer(const void *timer, void *data)
	{		
		TimerInfo * td = reinterpret_cast<TimerInfo *>(data);
		if(td->wd != 0 && !((1 << TimeUtil::WeekDay()) & td->wd))
			return;
		int typeId = td->typeId;
		switch(typeId)
		{
		case FiveSec:
			//gGroupBattle.process(TimeUtil::Now());
			//feast.check();
			//guildManager.checkAction();
			//gActivityMgr.process();
			break;
		case OnlineLog:
			//userManager.logOnline();
			break;
		case Chess:
			((TimerBase*)td->key)->onTimer();
			break;
		default:
			break;
		}
		if(getCount(timer) == 0)
			_timers[typeId].erase(td->key);
	}


}