#include "Config.h"
#include "PlayerCreator.h"

Player* CPlayerCreator::CreatePlayer()
{
	return new Player();
}