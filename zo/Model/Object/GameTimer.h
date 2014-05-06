#ifndef _GAMETIMER_H_
#define _GAMETIMER_H_
#include "Model/Data/TimerData.h"
#include "System/Timer.h"

namespace Object
{
	class GameTimer : protected System::Timer 
	{
	public:
	private:
		struct TimerInfo
		{
			int typeId;
			UInt32 param;
			void *key;
			void *data;
			UInt8 wd;
		};
	public:
		inline GameTimer();
		void init();
		void uninit();
		void onDailyCheck();
		void onTickCheck();
		void addPresetTimer(int typeId, void * key = NULL, UInt32 = 0);
		void addPresetTimer(const Data::TimerData::SingleTimer&, void * key = NULL, UInt32 = 0);
	protected:
		virtual void onTimer(const void *timer, void *data);
	private:
		bool addTimerWithFirst(int typeId, void *key, UInt32 interval, UInt32 firstInterval, UInt32 param, UInt8 wd);
		bool addTimer(int typeId, void *key, UInt32 interval, bool once = false, UInt32 param = 0, UInt8 wd = 0);
		void removeTimer(int typeId, void *key);
	
	private:
		std::vector<std::unordered_map<void*, TimerInfo> >_timers;
		UInt8 _month;
		UInt8 _monthday;
	};

	extern GameTimer gameTimer;
}

#endif