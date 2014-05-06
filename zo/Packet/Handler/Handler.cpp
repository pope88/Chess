
#include "Config.h"
#include "Handler.h"
#include "../Processor.h"
#include "Worker/Game.h"
namespace Packet
{
Handler::Handler(UInt16 op, UInt8 type)
{
	Worker::game.processor()->addHandler(op, type, this);
}

}
