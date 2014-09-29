HANDLER_CLASS(UserLogout, 0xFFFF)
{
	UInt32 sessionId = *(UInt32 *)((UInt8 *)hdr + sizeof(HandlerMsgPlayer));
	if(sessionId == user->sessionId())
		user->logOut();
}
HANDLER_END(UserLogout)
