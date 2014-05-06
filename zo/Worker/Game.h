#ifndef _WOEKER_GAME_H_
#define _WOEKER_GAME_H_
#include "Base.h"

namespace Packet
{
	class Processor;
}

namespace Worker
{
	class Game : public SimpleBase
	{ 
	public:
		virtual ~Game();
		Packet::Processor* processor();
	public:
		virtual void loop();
		virtual const char* getLogFilename() { return "game"; }
	private:
		Packet::Processor *_processor;
	};
	extern Game game;
}

#endif