class Player {
public:
	uint8_t _0[0x2C0];
	Car* pCar; // +2C0
	uint32_t nCarId; // +2C4
	uint32_t nCarSkinId; // +2C8
	uint8_t _2CC[0x58];
	uint32_t nPlayerId; // +324
	uint32_t nPlayerType; // +328
	uint8_t _32C[0x60];
	FO2WString sPlayerName; // +38C
};