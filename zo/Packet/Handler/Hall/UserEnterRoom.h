HANDLER_CLASS(UserEnterRoom, 0x06)
{
	Object::_roomManager.playerEnterRoom(user, pkt.Roomid());
}
HANDLER_END(UserEnterRoom)
