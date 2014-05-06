#ifndef _PLAYERCREATOR_H_
#define _PLAYERCREATOR_H_
#include "System/Singleton.h"
#include "Model/BaseModel/Mplayer.h"
#include "../Logic/Player.h"
class CPlayerCreator
{
public:
	CPlayerCreator(void);
	~CPlayerCreator(void);
	virtual Player* CreatePlayer();
};

typedef System::Singleton<CPlayerCreator> _gamemanager;


#endif

