HANDLER_CLASS(UserEnterRoom, 0x06)
{
	Object::_roomManager.playerEnterRoom(pkt.Roomid(), user);
}
HANDLER_END(UserEnterRoom)
