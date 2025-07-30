#include <format>

bool DoesFileExist(const char* path) {
	int tmp[2];
	return BfsManager::DoesFileExist(pBfsManager, path, tmp);
}

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
	GAME_STATE_RACE
};

int GetGameState() {
	if (pGameFlow->pMenuInterface) return GAME_STATE_MENU;
	if (pPlayerHost) return GAME_STATE_RACE;
	return GAME_STATE_NONE;
}