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

auto& nInterfaceMusicVolume = *(int*)0x6C02E0;
auto& nIngameMusicVolume = *(int*)0x6C02E8;