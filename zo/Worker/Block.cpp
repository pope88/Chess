#include "Config.h"
#include "Block.h"
#include "System/TimeUtil.h"
#include "Model/Object/UserManager.h"
#include "ZoCfg.h"
#include "Network/TcpSocket.h"

namespace Worker
{
	Block block;
	void Block::loop()
	{
		UInt32 nextCheck = 0;
		while (_running)
		{
			UInt32 now = TimeUtil::Now();
			if (now >= nextCheck)
			{
				nextCheck = now + 10;
			}
			if (Object::userManager.poolIdLeft() < 256)
			{
				Network::TcpSocket s;
				s.makeBlock(true);
				if(s.connect(zocfg.idPoolHost.c_str(), zocfg.idPoolPort))
				{
					const UInt8 op = 1;
					s.write(&op, 1);
					s.write(&zocfg.serverNo, 4);
					UInt32 data;
					s.read(&data, 4);
					s.close();
					Object::userManager.addIdPoolRange(data);
				}
			}
		}
	}
}