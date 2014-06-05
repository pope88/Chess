#include "Config.h"
#include "PlayerCreator.h"
#include "../Logic/Player.h"

IPlayer* PlayerCreator::CreatePlayer()
{
	return new(std::nothrow) Player();
}