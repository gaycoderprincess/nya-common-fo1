class MenuScene {
public:
	uint8_t _0[0x1FC8];
	uint32_t nCar; // +1FC8
	uint32_t nCarSkin; // +1FCC
};

class MenuInterface {
public:
	uint8_t _0[0x50];
	MenuScene* pMenuScene; // +50
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