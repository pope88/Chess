#ifndef _PLAYERCREATOR_H_
#define _PLAYERCREATOR_H_
#include "System/Singleton.h"
#include "Model/BaseModel/Mplayer.h"
#include "Model/BaseModel/ServerModule.h"
#include "../Logic/Player.h"
class PlayerCreator : public IPlayerCreator
{
public:
	PlayerCreator(void) {}
	~PlayerCreator(void) {}
	virtual IPlayer* CreatePlayer();
};

typedef System::Singleton<PlayerCreator> _playerCreator;


#endif

