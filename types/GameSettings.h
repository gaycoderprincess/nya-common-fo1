struct tGameSetting {
	enum eValueType {
		VALUE_TYPE_INT,
		VALUE_TYPE_BOOL,
		VALUE_TYPE_FLOAT,
		VALUE_TYPE_STRING,
	};

	const char* category;
	const char* name;
	void* value;
	int type;
	float minValue;
	float maxValue;
};
auto& aGameSettings = *(tGameSetting**)0x4399E2;

auto& bImperialUnits = *(bool*)0x6C027C;
auto& nInterfaceMusicVolume = *(int*)0x6C02E0;
auto& nIngameMusicVolume = *(int*)0x6C02E8;
auto& nIngameSfxVolume = *(int*)0x6C02F0;
auto& nIngameMap = *(int*)0x6C0284;
auto& nRagdoll = *(int*)0x6C0288;
auto& nControllerDeadzone = *(int*)0x6BEE0C;

auto& nNumPlayers = *(int*)0x6C0294;
auto& nNumCars = *(int*)0x6C0298;