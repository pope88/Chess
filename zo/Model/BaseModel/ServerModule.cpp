#include "Config.h"
#include "ServerModule.h"

void ServerModule::setPlayerCreator(IPlayerCreator *ipcreator)
{
	playerCreator = ipcreator;
	
}

void ServerModule::setTableCreator(ITableCreator *itablecreator)
{
	tableCreator = itablecreator;
}