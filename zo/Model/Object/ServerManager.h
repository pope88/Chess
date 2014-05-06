#ifndef _SERVERMANAGER_H_
#define _SERVERMANAGER_H_

namespace Object
{
	class ServerManager
	{
	public:
		void init();
		void add(UInt32 id, std::string name);
		UInt32 operator[](std::string name) const;
		const std::string& operator[](UInt32 id) const;
	private:
		std::unordered_map< std::string, UInt32 > _serversByName;
		std::unordered_map< UInt32, std::string > _servers;
	};
	extern ServerManager serverManager;
}

#endif