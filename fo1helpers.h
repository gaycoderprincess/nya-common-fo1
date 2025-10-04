#include <format>

int GetNumSkinsForCar(int carId) {
	auto path = std::format("data/cars/car_{}/skin", carId);
	int i;
	for (i = 0; i < 255; i++) {
		auto file1 = (path + std::to_string(i+1) + ".dds");
		auto file2 = (path + std::to_string(i+1) + "_damaged.dds");
		if (!DoesFileExist(file1.c_str()) || !DoesFileExist(file2.c_str())) {
			break;
		}
	}
	return i;
}

enum eGameState {
	GAME_STATE_NONE,
	GAME_STATE_MENU,
	GAME_STATE_RACE,
	GAME_STATE_REPLAY
};

int GetGameState() {
	if (pGameFlow->pMenuInterface) return GAME_STATE_MENU;
	if (pPlayerHost) {
		if (pPlayerHost->nIsInReplay) return GAME_STATE_REPLAY;
		return GAME_STATE_RACE;
	}
	return GAME_STATE_NONE;
}

#ifndef NYA_COMMON_NO_D3D
NyaDrawing::CNyaRGBA32 GetPaletteColor(int id) {
	auto col = *(NyaDrawing::CNyaRGBA32*)&gPalette[id];
	return {col.b, col.g, col.r, 255};
}
#endif

bool DoesTrackExist(int id) {
	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10001, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);
	auto value = lua_type(lua, lua_gettop(lua));
	lua_settop(lua, oldtop);
	return value;
}

int GetNumTracks() {
	int count = 0;
	for (int i = 0; i < 256; i++) {
		if (DoesTrackExist(i+1)) count = i+1;
	}
	return count;
}

bool DoesTrackValueExist(int id, const char* name) {
	if (!DoesTrackExist(id)) return false;

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10001, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	auto value = lua_type(lua, lua_gettop(lua));
	lua_settop(lua, oldtop);
	return value;
}

float GetTrackValueNumber(int id, const char* name) {
	if (!DoesTrackValueExist(id, name)) return 0;

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10001, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	auto f = luaL_checknumber(lua, lua_gettop(lua));

	lua_settop(lua, oldtop);

	return f;
}

std::string GetTrackValueString(int id, const char* name) {
	if (!DoesTrackValueExist(id, name)) return "";

	auto lua = pScriptHost->pLUAStruct->pLUAContext;
	auto oldtop = lua_gettop(lua);

	lua_getfield(lua, -10001, "Levels");
	lua_rawgeti(lua, lua_gettop(lua), id);

	auto oldtop2 = lua_gettop(lua);
	lua_setglobal(lua, name);
	lua_gettable(lua, oldtop2);
	std::string str = (const char*)lua_tolstring(lua, lua_gettop(lua));

	lua_settop(lua, oldtop);

	return str;
}

std::string GetTrackName(int id) {
	return GetTrackValueString(id, "Name");
}

std::string GetTrackDescription(int id) {
	return GetTrackValueString(id, "Description");
}

class CNyaRaceTimer {
public:
	int32_t nLastUpdate = 0;
	double fDeltaTime = 0;
	double fTotalTime = 0;
	double fMinDelta = 1.0 / 10.0; // delta for 10fps by default, any less and it's capped

	CNyaRaceTimer() { }
	CNyaRaceTimer(float minDelta) {
		fMinDelta = minDelta;
	}
	double Process() {
		if (pLoadingScreen || GetGameState() != GAME_STATE_RACE) {
			fDeltaTime = 0;
			nLastUpdate = 0;
			return 0;
		}

		auto now = pPlayerHost->nRaceTime;
		fDeltaTime = (now - nLastUpdate) / 1000.0;
		if (fDeltaTime < 0) fDeltaTime = 0;
		nLastUpdate = now;

		if (fDeltaTime > fMinDelta) fDeltaTime = fMinDelta;
		fTotalTime += fDeltaTime;
		return fDeltaTime;
	}
};