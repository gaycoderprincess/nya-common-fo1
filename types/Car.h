class Player;

enum class eCarFixPart : uint32_t {
	BODY = 0,
	ENGINE = 1,
	WHEELS = 4,
	SUSPENSION = 5,
	WINDOWS = 7,
	LIGHTS = 8,
};

class Car {
public:
	int nObjectsSmashedThisFrame[10]; // +0
	struct tCarCollisionData {
		uint32_t unknown;
		float damage;
	} aCarCollisions[8]; // +28
	uint8_t _68[0x30];
	FO2String sFolderPath; // +98
	uint8_t _B4[0x9C];
	float mMatrix[4*4]; // +150
	uint8_t _190[0xB0];
	float qQuaternion[4]; // +240
	uint8_t _250[0x10];
	float vVelocity[3]; // +260
	uint8_t _29C[0x4];
	float vAngVelocity[3]; // +270
	uint8_t _27C[0x20];
	float fMass; // +29C
	uint8_t _2A0[0x1C8];
	float fNitro; // +468
	float fMaxNitro; // +46C
	uint8_t _470[0xCAC];
	float vDriverLoc[3]; // +111C
	uint8_t _1128[0xDAC];
	float fRagdollVelocity; // +1ED4
	uint8_t _1ED8[0x28];
	uint32_t nIsRagdolled; // +1F00
	uint8_t _1F04[0x1824];
	Player* pPlayer; // +3728
	uint8_t _372C[0x50];
	float fDamage; // +377C
	uint8_t _3780[0x38];
	float fTimeInAir; // +37B8

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
	inline NyaVec3* GetVelocity() {
		return (NyaVec3*)vVelocity;
	}
	inline NyaVec3* GetAngVelocity() {
		return (NyaVec3*)vAngVelocity;
	}
#endif

	static inline auto LaunchRagdoll = (void(__stdcall*)(Car*, float))0x414580;
	static inline auto Reset = (void(__stdcall*)(Car*, float*, float*))0x41AB90;

	static inline uintptr_t Fix_call = 0x416B60;
	int __attribute__((naked)) __fastcall FixPart(eCarFixPart part) {
		__asm__ (
			"mov eax, edx\n\t"
			"call %0\n\t"
			"ret\n\t"
				:
				:  "m" (Fix_call)
		);
	}
};