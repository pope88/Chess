#include "Config.h"
#include "Gateway.h"
#include "Processor.h"
#include "Worker/Game.h"
#include "../Model/Object/User.h"

namespace Packet
{

	Gateway _gateway;

	void Gateway::remove( UInt32 id )
	{
		std::map<UInt32, std::unordered_set<Object::User *> >::iterator itt = _gateways.find(id);
		if(itt == _gateways.end())
			return;
		for(std::unordered_set<Object::User *>::iterator it = itt->second.begin(); it != itt->second.end(); ++ it)
		{
			Worker::game.processor()->pushDisconnect((*it)->sessionId(), *it);
		}
		_gateways.erase(itt);
	}

	void Gateway::add( Object::User * p )
	{
		_gateways[p->sessionId()].insert(p);
	}

	void Gateway::kick( Object::User * p )
	{
		_gateways[p->sessionId()].erase(p);
	}

}
