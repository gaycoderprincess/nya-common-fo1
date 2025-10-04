class Player {
public:
	uint8_t _4[0x2AC];
	Controller* pController; // +2B0
	uint32_t nAutoTransmission; // +2B4
	uint32_t nAutoTransmissionThisFrame; // +2B8
	uint32_t nEasyDifficulty; // +2BC
	Car* pCar; // +2C0
	uint32_t nCarId; // +2C4
	uint32_t nCarSkinId; // +2C8
	uint8_t _2CC[0x4];
	uint32_t nCharacterTypeId; // +2D0
	uint32_t nCharacterSkinId; // +2D4
	float fNitroFromPropsTotal; // +2D8
	float fNitroFromPropsLast; // +2DC
	uint8_t _2E0[0x44];
	uint32_t nPlayerId; // +324
	uint32_t nPlayerType; // +328
	uint32_t nStartPosition; // +32C
	uint8_t _330[0xC];
	uint32_t nIsRagdolled; // +33C
	uint32_t nTimeRagdolled; // +340
	uint8_t _344[0x8];
	uint32_t nIsOutOfTrack; // +34C
	uint8_t _350[0x10];
	float fLastValidPosition[3]; // +360
	uint8_t _36C[0x20];
	FO2WString sPlayerName; // +38C
	Sector* pCurrentSector; // +3A8
	Sector* pLastSector; // +3AC
	uint8_t _3B0[0x94];
	uint32_t nCurrentSplit; // +444
	uint32_t nCurrentLap; // +448
	uint8_t _44C[0x3C];
	float fOutputSteerAngle; // +488
	float fGasPedal; // +48C
	float fBrakePedal; // +490
	float fHandbrake; // +494
	float fNitroButton; // +498
	uint8_t _49C[0x4];
	struct {
		bool bHoldBrake : 1; // 1
		bool bIsStaging : 1; // 2
	} nInputFlags; // +4A0
	uint8_t _4A4[0x2C];

	static inline auto ResetCar = (int(__thiscall*)(Player*, int))0x449280;

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual void _vf8() = 0;
	virtual void _vf9() = 0;
	virtual void _vf10() = 0;
	virtual void _vf11() = 0;
	virtual void _vf12() = 0;
	virtual void _vf_ResetCar(int) = 0;
};
static_assert(sizeof(Player) == 0x4D0);

class AIPlayer : public Player {
public:
	uint8_t _4D0[0x198];
	uint32_t nAIId; // +668
	uint32_t nAIClassId; // +66C
	uint8_t _670[0x4];
	uint32_t nIsDerbyAI; // +674
	uint8_t _678[0x548];

	static inline auto LoadProfile = (void(__stdcall*)(AIPlayer*))0x406530;
};
static_assert(sizeof(AIPlayer) == 0xBC0);