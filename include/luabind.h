#include <iostream>
#include <string>
#include <stdexcept>

#include <lua5.3/lua.hpp>
#include <lua5.3/lauxlib.h>
#include <lua5.3/lualib.h>

#pragma once

namespace lbind {

// Lua state wraper
class LuaState {
private:
private:
	void error() const {
		std::cerr << "LUA: Error!" << std::endl;
	}

	void clear_stack() const {
		lua_settop(L, 0);
	}
public:
	lua_State* const L; // public for testing only

	LuaState(): L(luaL_newstate()) {
		if(!L) { throw std::runtime_error(":P"); }
	}

	~LuaState() { lua_close(L); }

	lua_State* get_lstate() const { return L; }

	void open_libs() const { luaL_openlibs(L); }

	void load_config(const char* const fname,
		 	int* const w,
		 	int* const h,
			int* c_size) const {
		if(luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
			error();

		// scan for window dimensions
		lua_getglobal(L, "width");
		lua_getglobal(L, "height");
		lua_getglobal(L, "cellSize");

		if(!lua_isnumber(L, -3))
			error();
		if(!lua_isnumber(L, -2))
			error();
		if(!lua_isnumber(L, -1))
			error();

		*c_size = lua_tointeger(L, -1);
		*h = lua_tointeger(L, -2);
		*w = lua_tointeger(L, -3);


		// scan for other configuration
		// ...

		clear_stack();
	}

};

// RAII - ensures invariant that Lua stack size on destruction
// is same as on construction
class LuaStackProtect {
private:
	lua_State* const m_L;
	const int m_top;
public:
	LuaStackProtect(LuaState* L): 
		m_L(L->get_lstate()), 
		m_top(lua_gettop(L->get_lstate())) { }

	~LuaStackProtect() {
		// reset the state back
		lua_settop(m_L, m_top);
	}
};

}
