#include "Config.h"
#include "TableCreator.h"
#include "../Logic/GameTable.h"

ITable* TableCreator::CreateTable()
{
	ITable *ptable = new(std::nothrow) GameTable();
	return ptable;
}