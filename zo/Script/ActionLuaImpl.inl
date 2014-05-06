template <typename R>
R ActionLua::Run(User* user, const std::string& script)
{
	User* savePlayer1 = _user1;
	_user1 = user;

	R ret = lua_tinker::call<R>(_L, script.c_str());


	_user1 = savePlayer1;

	return ret;
}

template <typename R, typename T1>
inline R ActionLua::Run(User* user, const std::string& script, const T1& t1)
{
	User* savePlayer1 = _user1;
	_user1 = user;

	R ret = lua_tinker::call<R, T1>(_L, script.c_str(), t1);

	_user1 = savePlayer1;

	return ret;
}

template <typename R, typename T1, typename T2>
inline R ActionLua::Run(User* user, const std::string& script, const T1& t1,  const T2& t2)
{
	User* savePlayer1 = _user1;
	_user1 = user;

	R ret = lua_tinker::call<R, T1, T2>(_L, script.c_str(), t1, t2);

	_user1 = savePlayer1;

	return ret;
}

template <typename R, typename T1, typename T2, typename T3>
inline R ActionLua::Run(User* user, const std::string& script, const T1& t1,  const T2& t2, const T3& t3)
{
	User* savePlayer1 = _user1;
	_user1 = user;

	R ret = lua_tinker::call<R, T1, T2, T3>(_L, script.c_str(), t1, t2, t3);

	_user1 = savePlayer1;

	return ret;
}

template <typename R, typename T1, typename T2, typename T3, typename T4>
inline R ActionLua::Run(User* user, const std::string& script, const T1& t1,  const T2& t2, const T3& t3, const T4& t4)
{
	User* savePlayer1 = _user1;
	_user1 = user;

	R ret = lua_tinker::call<R, T1, T2, T3, T4>(_L, script.c_str(), t1, t2, t3, t4);

	_user1 = savePlayer1;

	return ret;
}

template<typename R>
inline R ActionLua::Call(const std::string& name)
{
	return lua_tinker::call<R>(_L, name.c_str());
}

template<typename R, typename T1>
inline R ActionLua::Call(const std::string& name, const T1& t1)
{
	return lua_tinker::call<R>(_L, name.c_str(), t1);
}

template<typename R, typename T1, typename T2>
inline R ActionLua::Call(const std::string& name, const T1& t1, const T2& t2)
{
	return lua_tinker::call<R>(_L, name.c_str(), t1, t2);
}

template<typename R, typename T1, typename T2, typename T3>
inline R ActionLua::Call(const std::string& name, const T1& t1, const T2& t2, const T3& t3)
{
	return lua_tinker::call<R>(_L, name.c_str(), t1, t2, t3);
}

template<typename R, typename T1, typename T2, typename T3, typename T4>
inline R ActionLua::Call(const std::string& name, const T1& t1, const T2& t2, const T3& t3, const T4& t4)
{
	return lua_tinker::call<R>(_L, name.c_str(), t1, t2, t3, t4);
}

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
inline R ActionLua::Call(const std::string& name, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5)
{
	return lua_tinker::call<R>(_L, name.c_str(), t1, t2, t3, t4, t5);
}