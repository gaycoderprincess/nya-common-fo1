class Player;

class Car {
public:
	uint8_t _0[0x98];
	FO2String sFolderPath; // +98
	uint8_t _B4[0x1E20];
	float fRagdollVelocity; // +1ED4
	uint8_t _1ED8[0x1850];
	Player* pPlayer; // +3728
	uint8_t _372C[0x50];
	float fDamage; // +377C

	static inline auto LaunchRagdoll = (void(__stdcall*)(Car*, float))0x414580;
	static inline auto Reset = (void(__stdcall*)(Car*, float*, float*))0x41AB90;
};