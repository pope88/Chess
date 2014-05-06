#include "Config.h"
#include "TimerData.h"

namespace Data
{
	using namespace Define;
	TimerData timerData;

	void TimerData::clear()
	{
		_timers.clear();
		_timers.resize(TimerMax);
	}

	UInt32 TimerData::idFromStr(const std::string& s)
	{
#define DOCHECKIF(n) \
	if(s == #n) \
	    return n;
		DOCHECKIF(FiveSec);
		DOCHECKIF(OnlineLog);
		DOCHECKIF(TimerMax);
#undef DOCHECKIF
		return 0;
	}

	UInt32 TimerData::timeFromStr( const std::string& str )
	{
		size_t pos = str.find(':');
		if(pos != std::string::npos)
		{
			int p1 = atoi(str.c_str());
			int p2 = atoi(str.c_str() + pos + 1);
			if(p2 < 0 || p2 > 59)
				return 0xFFFFFFFF;
			size_t pos2 = str.find(':', pos + 1);
			if(pos2 != std::string::npos)
			{
				int p3 = atoi(str.c_str() + pos2 + 1);
				if(p3 < 0 || p3 > 59)
					return 0xFFFFFFFF;
				return static_cast<UInt32>(p1 * 3600 + p2 * 60 + p3);
			}
			else
			{
				return static_cast<UInt32>(p1 * 60 + p2);
			}
		}
		size_t idx = 0;
		UInt32 currn = 0, resultn = 0;
		while(idx < str.length())
		{
			char c = str[idx];
			if(c == ' ' || c == '\t')
				continue;
			if(c >= '0' && c <= '9')
			{
				currn = currn * 10 + (str[idx] - '0');
			}
			else if(c == 'N')
			{
				if(str[idx + 1] == 'O' && str[idx + 2] == 'W')
					idx += 2;
				resultn = 0;
				currn = 0;
			}
			else if(c == 'D')
			{
				if(currn == 0) currn = 1;
				resultn += currn * 86400;
				currn = 0;
				if(str[idx + 1] == 'A' && str[idx + 2] == 'Y')
					idx += 2;
			}
			else if(c == 'H')
			{
				if(currn == 0) currn = 1;
				resultn += currn * 3600;
				currn = 0;
				if(str[idx + 1] == 'O' && str[idx + 2] == 'U' && str[idx + 3] == 'R')
					idx += 3;
				else if(str[idx + 1] == 'R')
					idx += 1;
			}
			else if(c == 'M')
			{
				if(currn == 0) currn = 1;
				resultn += currn * 60;
				currn = 0;
				if(str[idx + 1] == 'I' && str[idx + 2] == 'N')
				{
					if(str[idx + 3] == 'U' && str[idx + 4] == 'T' && str[idx + 5] == 'E')
						idx += 5;
					else
						idx += 2;
				}
			}
			else if(c == 'S')
			{
				if(currn == 0) currn = 1;
				resultn += currn;
				currn = 0;
				if(str[idx + 1] == 'E' && str[idx + 2] == 'C')
				{
					if(str[idx + 3] == 'O' && str[idx + 4] == 'N' && str[idx + 5] == 'D')
						idx += 5;
					else
						idx += 2;
				}
			}
			else
				return 0xFFFFFFFF;
			++ idx;
		}
		return resultn + currn;
	}

}