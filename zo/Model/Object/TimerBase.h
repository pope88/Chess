#ifndef	_TIMERBASE_H_
#define _TIMERBASE_H_

//objects who want to trigger timer
class TimerBase
{
public:
	TimerBase();
	~TimerBase();
	virtual void onTimer() = 0;
};
#endif