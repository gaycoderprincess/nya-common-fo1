class MenuScene {
public:
	uint8_t _0[0x1FC8];
	uint32_t nCar; // +1FC8
	uint32_t nCarSkin; // +1FCC
};

class MenuInterface {
public:
	uint8_t _0[0x18];
	float fMenuTimer; // +18
	uint8_t _1C[0x34];
	MenuScene* pMenuScene; // +50
	uint8_t _54[0x1DC];
	uint32_t bMusicPopupFinished; // +230
	uint32_t bMusicPopupActive; // +234
	uint32_t nMusicPopupTimer; // +238
};

class PlayerHost {
public:
	uint8_t _0[0x1E24C];
	uint32_t nRaceTime; // +1E24C
};
auto& pPlayerHost = *(PlayerHost**)0x68B7C0;

class GameFlow {
public:
	uint8_t _0[0x2828];
	PlayerHost* pHost; // +2828
	uint8_t _282C[0xC4];
	MenuInterface* pMenuInterface; // +28F0
};
auto& pGameFlow = *(GameFlow**)0x6A7CE0;