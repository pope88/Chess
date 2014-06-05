#ifndef _SERVERMODULE_H_
#define _SERVERMODULE_H_
#include "System/Singleton.h"
#include "Model/BaseModel/Mplayer.h"
#include "Model/BaseModel/Mtable.h"


class IPlayerCreator
{
public:
	virtual ~IPlayerCreator(){}
	virtual IPlayer* CreatePlayer() = 0;
};
class ITableCreator
{
public:
	virtual ~ITableCreator(){}
	virtual ITable* CreateTable() = 0;
};
class ServerModule
{
public:
	void setPlayerCreator(IPlayerCreator *ipcreator);
	void setTableCreator(ITableCreator *itablecreator);
	IPlayer* createPlayer() { return playerCreator->CreatePlayer(); }
	ITable* createTable() { return tableCreator->CreateTable(); }
private:
	IPlayerCreator *playerCreator;
	ITableCreator *tableCreator;
};
typedef System::Singleton<ServerModule> _serverModule;

#endif // !_SERVERMODULE_H_
