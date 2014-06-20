#ifndef	_TIMERBASE_H_
#define _TIMERBASE_H_
#include "../../Model/Object/GameTimer.h"
//objects who want to trigger timer
class TimerBase
{
public:
	TimerBase(): _timeId(0) {}
	~TimerBase() {}
	virtual void onTimer() {}
	inline UInt32 timerId() { return _timeId; } 
	virtual void addInterValTimer(int timeId, UInt32 interval, bool once = false, UInt32 param = 0, UInt8 wd = 0 )
	{
		GAMETIMER.removeInterValTimer(Data::Define::Chess, this);
		_timeId = timeId;
		GAMETIMER.addInterValTimer(Data::Define::Chess, this, interval, once, param, wd);
	}
private:
	UInt32 _timeId;
};
#endif