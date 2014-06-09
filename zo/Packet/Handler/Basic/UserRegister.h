HANDLER_CLASS_INIT(UserRegister, 0x01)
{
	std::string userid = pkt.Username();
	size_t pos = userid.find_last_of('@');
	UInt32 serverNo = 0;
	std::string serverName;
	if (pos != std::string::npos)
	{
		serverName = userid.substr(pos+1, std::string::npos);
		serverNo = Object::serverManager[serverName];
		userid.erase(pos, std::string::npos);
	}

	if (userid.empty())
	{
		//std::string randName;
		//Packet::RandomName  rn;
		//randName = "dongfangbubai"; //Data::nameGen.gen(pkt.IsMale());
		//int i = 10; 
		//while (i < 10 && Object::playerManager.findPlayerByName(serverNo, randName) != NULL )
		//{
		//	randName = "dongfangbubai"; //Data::nameGen.gen(pkt.IsMale());
		//	++i;
		//}

		//rn.SetName(randName);
		//rn.send(sessionId, gatewayId);
		return;
	}

	if (serverNo == 0 && !zocfg.debugMode)
	{
		return;
	}
	if( Object::userManager.findUserById(serverNo, userid) != NULL )
	{
		LOG(Trace) << "receive from client2";

		UserRegister ur;
		ur.SetResult(1);
		ur.send(sessionId, gatewayId);
		return;
	}

	Object::User *targetP = new (std::nothrow) Object::User(userid);
	if (targetP == NULL)
	{
		Worker::tcp.close(sessionId, gatewayId);
	}
	if (targetP->id() == 0)
	{
		delete targetP;
		Worker::tcp.close(sessionId, gatewayId);
		return;
	}
	//Object::Hero *targetH;

	targetP->sessionId(sessionId, gatewayId);
	targetP->setRemoteAddr(remoteAddr);
	//targetP->setdailyCP(TimeUtil::ThisDay(), false);
	//if (pkt.HasWallow())
	//{
	//	targetP->setwallow(pkt.Wallow(), false);
	//	if (pkt.Wallow() == 0)
	//	{
	//		targetP->setOnlineTime(0);
	//	}
	//}
	targetP->newObjectToDB();

	////hero

	//////
	Object::userManager.add(targetP);
	//if (gatewayId == 0xFFFFFFFF)
	//{
	//	Worker::tcp.setPlayer(sessionId, targetP);
	//}
	//else
	//{
	//	//Packet::gateway.add(targetP);
	//}

}
HANDLER_END(UserRegister)
