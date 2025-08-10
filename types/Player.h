class Player {
public:
	uint8_t _4[0x2BC];
	Car* pCar; // +2C0
	uint32_t nCarId; // +2C4
	uint32_t nCarSkinId; // +2C8
	uint8_t _2CC[0xC];
	float fNitroFromPropsTotal; // +2D8
	float fNitroFromPropsLast; // +2DC
	uint8_t _2E0[0x44];
	uint32_t nPlayerId; // +324
	uint32_t nPlayerType; // +328
	uint8_t _32C[0x60];
	FO2WString sPlayerName; // +38C
	uint8_t _3A8[0xE0];
	float fOutputSteerAngle; // +488
	float fGasPedal; // +48C
	float fBrakePedal; // +490
	float fHandbrake; // +494
	float fNitroButton; // +498

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

// AIPlayer +674 is probably derby ai bool