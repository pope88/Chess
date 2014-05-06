#ifndef _MPLAYER_H_
#define _MPLAYER_H_

class Mplayer
{
public:
	Mplayer() {}	
	virtual ~Mplayer() {}
public:
	virtual int getTableId() = 0;
	virtual int getChairId() = 0;
	virtual int getMoney() = 0;
	virtual int getScore() = 0;
	virtual bool saveGameMoney(int money) = 0;
	virtual bool saveGameScore(int score) = 0;
	virtual bool canWatch() = 0;
};
#endif