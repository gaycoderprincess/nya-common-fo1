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
	uint8_t _0[0x14];
	FO2Vector<Player*> aPlayers; // +14
	FO2Vector<Player*> aLocalPlayers; // +20
	uint8_t _2C[0x1E220];
	int32_t nRaceTime; // +1E24C

	int GetNumPlayers() {
		return aPlayers.GetSize();
	}
};
auto& pPlayerHost = *(PlayerHost**)0x68B7C0;

class PlayerProfile {
public:
	uint8_t _0[0x52];
	wchar_t wsPlayerName[16]; // +52
	uint8_t _72[0x2];
	uint32_t nMoney; // +74
	uint32_t nCarType; // +78
	uint32_t nCarClass; // +7C
	uint32_t nCarSkin; // +80
	uint8_t _84[0x10];
	uint32_t nEasyDifficulty; // +94
	uint32_t nCurrentClass; // +98
	uint8_t _9C[0x8];
	uint32_t nAutosaveSlot; // +A4
	uint8_t _A8[0xC];
	uint32_t nMoneyGained; // +B4
	uint32_t nMoneySpent; // +B8
	uint8_t _BC[0x5C];
	uint8_t aCarUpgrades[40]; // +118
	uint32_t nNumCarUpgrades; // +140
	uint8_t _144[0x20C4];
};
static_assert(sizeof(PlayerProfile) == 0x2208);

class GameFlow {
public:
	uint8_t _0[0x20];
	uint32_t nLevel; // +20
	uint8_t _24[0x110];
	uint32_t nClass; // +134
	uint32_t nCar; // +138
	uint8_t _13C[0x8];
	eGameMode nGameMode; // +144
	uint32_t nIsCareerMode; // +148
	uint8_t _14C[0x4];
	uint32_t nAutoTransmission; // +150
	eEventType nEventType; // +154
	eSubEventType nSubEventType; // +158
	uint8_t _15C[0x49C];
	PlayerProfile Profile; // +5F8
	uint8_t _2800[0x10];
	uint8_t nIsPaused; // +2810
	uint8_t _2811[0x17];
	PlayerHost* pHost; // +2828
	uint8_t _282C[0xC4];
	MenuInterface* pMenuInterface; // +28F0
	uint8_t _28F4[0x40];
	int32_t nSaveSlot; // +2934
};
auto& pGameFlow = *(GameFlow**)0x6A7CE0;

Player* GetPlayer(int id) {
	auto host = pGameFlow->pHost;
	if (!host) return nullptr;
	if (id < 0 || id >= host->aPlayers.GetSize()) return nullptr;
	auto ply = host->aPlayers[id];
	if (!ply || !ply->pCar) return nullptr;
	return ply;
}