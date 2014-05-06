#ifndef _PUPPET_H_
#define _PUPPET_H_
//#include "User.h"
#include "DBObject.h"

namespace Object
{
	class Puppet : protected DBObject
	{
	public:
		Puppet() {}
		virtual ~Puppet() {}
	private:

	};
}
#endif