#include "../../../Model/Object/RoomManager.h"
HANDLER_CLASS(UserPlayNow, 0x08)
{
	Object::_roomManager.playerQuikPlay(user);
}
HANDLER_END(UserPlayNow)
