#define LUA_REGISTRYINDEX	(-10000)
#define LUA_ENVIRONINDEX	(-10001)
//#define LUA_GLOBALSINDEX	(-10002)

class ScriptHost {
public:
	struct tLUAStruct {
		const char* unkString; // "unnamed"
		void* pLUAContext; // +4
	};

	uint8_t _0[0x8];
	tLUAStruct* pLUAStruct;
};
auto& pScriptHost = *(ScriptHost**)0x8E8418;

auto luaL_checktype = (void(*)(void*, int, int))0x50FD50;
auto luaL_checkudata = (void*(*)(void*, int, const char*))0x50F1E0;
auto luaL_typerror = (void(*)(void*, int, const char*))0x50FD10;
auto lua_pushnumber = (int(*)(void*, float))0x50E6C0;
auto luaL_checknumber = (double(*)(void*, int))0x50FEA0;
auto lua_tonumber = (double(*)(void*, int))0x50E440;
//auto lua_setfield = (void(*)(void*, int, const char*))0x5B4E70;
auto lua_pushcfunction = (void(*)(void*, void*, int))0x50E800;
auto lua_pushboolean = (int(*)(void*, int))0x50E880;
auto lua_pushlstring = (int(*)(void*, const wchar_t*, size_t))0x50E6E0;
auto lua_settable = (void(*)(void*, int))0x50EAC0;
auto lua_setglobal = (void(*)(void*, const char*))0x50E730;
auto lua_gettop = (int(*)(void*))0x50E080;
auto lua_rawgeti = (void(*)(void*, int, int))0x50E970;
auto lua_tolstring = (const wchar_t*(*)(void*, int))0x50E4D0;
//auto lua_getfield = (void(*)(void*, int, const char*))0x5B4AD0;
auto lua_settop = (void(*)(void*, int))0x50E090;
//auto lua_gettable = (void(*)(void*, int))0x5B4A90;
auto lua_type = (int(*)(void*, int))0x50E200;