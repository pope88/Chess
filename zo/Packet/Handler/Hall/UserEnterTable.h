#include "../../Model/Object/GameRoom.h"
HANDLER_CLASS(UserEnterTable, 0x07)
{
	if (user->getInRoom() != NULL)
	{
		Object::GameRoom *gr = NULL;
		gr = user->getInRoom();
		user->getInRoom()->enterTable(user, pkt.Tableno());
	}
	else
	{	
		Object::_roomManager.playerEnterRoom(user); //
		if (user->getInRoom() == NULL)
		{
			bool bSuc = true;
			bSuc = user->getInRoom()->enterTable(user, pkt.Tableno());
			if (bSuc == false)
			{
				UserEnterTable uet;
				uet.SetRes(1);
				uet.send(user);
			}
		}
		else
		{
			UserEnterTable uet;
			uet.SetRes(1);
			uet.send(user);
		}
		
	}
}
HANDLER_END(UserEnterTable)
