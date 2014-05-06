#include "Config.h"
#include "Script.h"
#include "ZoCfg.h"

namespace Script
{

	Script::Script()
	{
		_L = luaL_newstate();
		luaL_openlibs(_L);
	}

	Script::~Script()
	{
		lua_close(_L);
	}

	void Script::doFile(const char *path)
	{
		addPackagePath();
		init();
		_scriptName = path;
		lua_tinker::dofile(_L, _scriptName.c_str());
		postInit();
	}

	void Script::runScript(const char * str)
	{
		addPackagePath();
		init();
		lua_tinker::dostring(_L, str);
		postInit();
	}

	Table Script::getTable()
	{
		return Table(_L);
	}

	Table Script::getTable( int index )
	{
		return Table(_L, index);
	}

	Table Script::getTable( const char * name )
	{
		return Table(_L, name);
	}

	bool Script::reload()
	{
		lua_close(_L);
		_L = luaL_newstate();
		luaL_openlibs(_L);
		addPackagePath();

		init();
		lua_tinker::dofile(_L, _scriptName.c_str());
		postInit();

		return true;
	}

	void Script::addPackagePath()
	{
		lua_tinker::table pkg = lua_tinker::get<lua_tinker::table>(_L, "package");
		const char * path = pkg.get<const char *>("path");
		std::string newpath = path;
		newpath = newpath + ";" + zocfg.scriptPath + "?.lua" + ";" + zocfg.scriptPath + "?/init.lua";
		pkg.set("path", newpath.c_str());
	}

}
