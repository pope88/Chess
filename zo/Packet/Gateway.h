#ifndef _GATEWAY_H_
#define _GATEWAY_H_

namespace Object
{
	class User;
}

namespace Packet
{

	class Gateway
	{
	public:
		void remove(UInt32);
		void add(Object::User *);
		void kick(Object::User *);
	private:
		std::map<UInt32, std::unordered_set<Object::User *> > _gateways;
	};

	extern Gateway _gateway;

}

#endif // _GATEWAY_H_
