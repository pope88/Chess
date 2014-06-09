#ifndef _TABLECREATOR_H_
#define _TABLECREATOR_H_
#include "System/Singleton.h"
#include "Model/BaseModel/Mtable.h"
#include "Model/BaseModel/ServerModule.h"
class TableCreator : public ITableCreator
{
public:
	TableCreator(void) {}
	~TableCreator(void) {}
	virtual ITable* CreateTable();
};

typedef System::Singleton<TableCreator> _tableCreator;


#endif

