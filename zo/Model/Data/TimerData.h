#ifndef _TIMERDATA_H_
#define _TIMERDATA_H_

namespace Data
{
	namespace Define
	{
		enum
		{
			Reserved = 0,
			FiveSec,
			OnlineLog,
			Chess,
			TimerMax
		};

	}
	class TimerData
	{
		friend class CsvLoader;
	public:
		struct SingleTimer
		{
			UInt32 id;
			UInt32 baseTime;
			UInt32 addTime;
			UInt32 interval;
			UInt32 param1;
			UInt32 param2;
			UInt32 weekdays;
			bool once;
		};
	public:
		inline const SingleTimer& operator[](size_t idx) const { return _timers[idx]; }
		void clear();
		inline const std::vector<SingleTimer>& bootTimers() const { return _bootTimers; }
		static UInt32 idFromStr(const std::string&);
		static UInt32 timeFromStr(const std::string&);
		UInt32 getBootTimersBeginTime(UInt32 id) const
		{
			for (UInt32 i = 0; i < _bootTimers.size(); ++i)
			{
				if (_bootTimers[i].id == id)
				{
					return _bootTimers[i].addTime;
				}
				return 0;
			}
		}

		UInt32 getBootTimersWeekDays(UInt32 id) const
		{
			for (UInt32 i = 0; i < _bootTimers.size(); ++i)
			{
				if (_bootTimers[i].id == id)
				{
					return _bootTimers[i].weekdays;
				}
			}
			return 0;
		}
		inline SingleTimer& getPrivate(size_t idx, bool isBoot)
		{
			if (isBoot)
			{
				_bootTimers.resize(_bootTimers.size() + 1);
				SingleTimer& st = _bootTimers.back();
				st.id = static_cast<UInt32>(idx);
				return st;
			}
			else
			{
				SingleTimer& st = _timers[idx];
				st.id = static_cast<UInt32>(idx);
				return st;
			}
		}
	private:
	private:
		std::vector<SingleTimer> _timers;
		std::vector<SingleTimer> _bootTimers;

	};

	extern TimerData timerData;
}

#endif