HANDLER_CLASS_INIT(UserRegister, 0x01)
{
	UInt32 nothing = 0;
	for (int i = 0; i < 5; i++)
	{
		UserRegister ur;
		ur.SetUserId(2048);
		ur.SetResult(9);
		ur.send(sessionId, gatewayId);
	}
}
HANDLER_END(UserRegister)
