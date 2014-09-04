#ifndef _MPLAYER_H_
#define _MPLAYER_H_
namespace Object
{
	class User;
}
class Mplayer
{
public:
	Mplayer() {}	
	virtual ~Mplayer() {}
public:
	virtual int getTableId() = 0;
	virtual void setTableId(int tableid) = 0;
	virtual int getChairId() = 0;
	virtual void setChairId(int chairid) = 0;
	virtual int getMoney() = 0;
	virtual bool saveGameMoney(int money) = 0;
	virtual bool saveGameScore(int score) = 0;
	virtual bool canWatch() = 0;
};


class IPlayer
{
public:
	virtual ~IPlayer(){}
	virtual void bindUser2Player(Object::User *user) = 0;
};

#endif