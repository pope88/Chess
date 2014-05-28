HANDLER_CLASS_INIT(UserLogin, 0x02)
{
	UInt32 now = TimeUtil::Now();
	std::string userId = pkt.Username();
	size_t pos = userId.find_last_of('@');
	UInt32 serverNo = 0;
	if (pos != std::string::npos)
	{
		std::string serverName = userId.substr(pos+1);
		userId.erase(pos);
		serverNo = Object::serverManager[serverName];
	}

	if(!zocfg.debugMode)
	{
		if(serverNo == 0)
			return;
		//if(pkt.Key().length() != 56)
		//{
		//	Worker::tcp.close(sessionId, gatewayId);
		//	return;
		//}
		//const std::string& key = pkt.Key();
		//char tmpstr[9];
		//tmpstr[8] = 0;
		//memcpy(tmpstr, key.c_str() + 40, 8);
		//UInt32 randomnum = static_cast<UInt32>(strtoul(tmpstr, NULL, 16));
		//memcpy(tmpstr, key.c_str() + 48, 8);
		//UInt32 tshift = static_cast<UInt32>(strtoul(tmpstr, NULL, 16));
		//UInt32 realtime = tshift ^ randomnum;
		//System::SHA1Engine sha1;
		//sha1.update(userId);
		//sha1.update(tmpstr);
		//sha1.update(zocfg.serverKey);
		//const std::vector<unsigned char>& result = sha1.digest();
		//for(int i = 0; i < 20; ++ i)
		//{
		//	UInt8 currentV = hextov(key[i * 2]) * 16 + hextov(key[i * 2 + 1]);
		//	if(result[i] != currentV)
		//	{
		//		Worker::tcp.close(sessionId, gatewayId);
		//		return;
		//	}
		//}
		//if(realtime < now - 5 * 60 || realtime > now + 5 * 60)
		//{
		//	Worker::tcp.close(sessionId, gatewayId);
		//	return;
		//}
	}

	Object::User *targetP = Object::userManager.findUserById(serverNo, userId);

	if(targetP == NULL)
	{
		UserLogin ul;
		ul.SetResult(1);
		System::Random& rnd = Randomizer();
		bool isMale = rnd.next(2) > 0;
		ul.SetUserName(pkt.Username());
		//std::string name = Data::nameGen.gen(isMale);
		//int i = 10;
		//while(i > 0 && Object::userManager.finduserByName(serverNo, name) != NULL)
		//{
		//	-- i;
		//	name = Data::nameGen.gen(isMale);
		//}
		//ul.SetName(name);
		ul.send(sessionId, gatewayId);
	}
	else if(targetP->lockend() > now)
	{
		targetP->setOnline(false);
		UserLogin ul;
		ul.SetResult(2);
		ul.SetBanTime(targetP->lockend() - now);
		ul.send(sessionId, gatewayId);
	}
	else
	{
		//if (pkt.HasWallow())
		//{
		//	targetP->setwallow(pkt.Wallow());
		//	if (pkt.Wallow() == 0)
		//	{
		//		targetP->setOnlineTime(0);
		//	}
		//}
		targetP->setOnline(false);
		UInt32 sid = targetP->sessionId();
		if (sid != 0xFFFFFFFF)
		{
			if (sid == sessionId && targetP->gatewayId() == gatewayId)
			{
				return;
			}

			//if (targetP->lastOp() != 0x01)  //when last cmd is register ,do not tick client
			//{
			//	targetP->kick();
			//}
			targetP->sessionId(sessionId, gatewayId);
		}
		else
		{
			targetP->sessionId(sessionId, gatewayId);
		}
		targetP->setRemoteAddr(remoteAddr);
		if (gatewayId == 0xFFFFFFFF)
		{
			Worker::tcp.setPlayer(sessionId, targetP);
		}
		else
		{
			Packet::_gateway.add(targetP);
		}

		UserLogin ul;
		ul.SetResult(0);
		ul.SetUserName(targetP->playerid());
		//ul.SetName("no name"); //targetP->name());
		//ul.SetVipLevel(targetP->vip());
		//ul.AddSteps(static_cast<UInt32>(targetP->guideStep() & 0xFFFFFFFFull));
		//ul.AddSteps(123);
		//if(targetP->guideStep() > 0xFFFFFFFFull)
		//{
		//	ul.AddSteps(static_cast<UInt32>(targetP->guideStep() >> 32));
		//}
		ul.send(sessionId, gatewayId);

		targetP->loginPlayer();
	}
}
HANDLER_END(UserLogin)
