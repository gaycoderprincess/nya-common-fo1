class Player;

enum class eCarFixPart : uint32_t {
	BODY = 0,
	ENGINE = 1,
	UNK_2 = 2,
	UNK_3 = 3,
	WHEELS = 4,
	SUSPENSION = 5,
	UNK_6 = 6,
	WINDOWS = 7,
	LIGHTS = 8,
};

class Car;
class Engine;
class CarPerformance;

class Engine {
public:
	uint8_t _0[0x10];
	CarPerformance* pPerformance; // +10
	float fInertiaEngine; // +14
	float fInvInertiaEngine; // +18
	uint8_t _1C[0x24];
	float fEngineFriction; // +40
	float fInertiaEngine2; // +44
	float fZeroPowerRpm; // +48 IdleRpm / 2
	float fIdleRpm; // +4C
	float fTorqueMax; // +50
	struct tTorqueCurve {
		float fRpm;
		float fCurve;
	} aTorque[20]; // +54
	uint32_t nTorqueCurveParams; // +F4
	float fExhaustPeakRpm; // +F8
	uint8_t _FC[0x4];
	float fUnknown_100; // +100
	float fUnknown_104; // +104
	float fTurboAcceleration; // +108
	float fNitroAcceleration; // +10C
	float fNitro; // +110
	float fMaxNitro; // +114
	uint8_t _118[0x4];
	float fEngineRpm; // +11C
	float fHealth; // +120 responsible for engine fire
	uint8_t _124[0x8];
	float fMass; // +12C

	static inline auto GetEngineSpeed = (float(__fastcall*)(uint32_t fExhaustPeakRpm, Engine*, float fIdleRpm))0x431D10;
};
static_assert(sizeof(Engine) == 0x130);

class Gearbox {
public:
	uint8_t _4[0xC];
	CarPerformance* pPerformance; // +10
	float fCurrentGearInertia; // +14
	float fInvCurrentGearInertia; // +18
	float fCurrentGearRatio; // +1C
	float fInvCurrentGearRatio; // +20
	uint8_t _24[0x1C];
	int32_t nCurrentGear; // +40
	uint8_t _44[0x8];
	uint32_t nClutchState; // +4C
	float fCurrentClutchTime; // +50
	uint32_t nNumGears; // +54
	float fGearRRatio; // +58
	float fGearNRatio; // +5C
	float fGear1Ratio; // +60
	float fGear2Ratio; // +64
	float fGear3Ratio; // +68
	float fGear4Ratio; // +6C
	float fGear5Ratio; // +70
	float fGear6Ratio; // +74
	float fGearRInertia; // +78
	float fGearNInertia; // +7C
	float fGear1Inertia; // +80
	float fGear2Inertia; // +84
	float fGear3Inertia; // +88
	float fGear4Inertia; // +8C
	float fGear5Inertia; // +90
	float fGear6Inertia; // +94
	uint8_t _98[0x8];
	float fGear1Upshift; // +A0 kmh
	float fGear2Upshift; // +A4 kmh
	float fGear3Upshift; // +A8 kmh
	float fGear4Upshift; // +AC kmh
	float fGear5Upshift; // +B0 kmh
	float fGear6Upshift; // +B4 kmh
	float fClutchEngageTime; // +B8
	float fClutchReleaseTime; // +BC

	static inline uintptr_t ChangeToGear_call = 0x4339C0;
	void __attribute__((naked)) __fastcall ChangeToGear(int gear) {
		__asm__ (
			"mov eax, ecx\n\t"
			"mov ecx, edx\n\t"
			"jmp %0\n\t"
				:
				:  "m" (ChangeToGear_call)
		);
	}

	static inline uintptr_t ShiftGear_call = 0x433A10;
	void __attribute__((naked)) __fastcall ShiftGear(int gear) {
		__asm__ (
			"mov esi, ecx\n\t"
			"mov ecx, edx\n\t"
			"jmp %0\n\t"
				:
				:  "m" (ShiftGear_call)
		);
	}

	virtual void _vf0() {};
	virtual void _vf1() {};
	virtual void _vf2() {};
	virtual void Process(float time) {}; // updates clutch and shifts gear
};
static_assert(sizeof(Gearbox) == 0xC0);

class Differential {
public:
	uint8_t _0[0x10];
	CarPerformance* pPerformance; // +10
	float fInertiaDriveShaft; // +14
	float fInvInertiaDriveShaft; // +18
	float fEndRatio; // +1C
	float fInvEndRatio; // +20
	uint8_t _24[0x1C];
	float fUnknown40; // +40
	uint8_t _44[0x28];
	float fClutchTorque; // +6C
};
static_assert(sizeof(Differential) == 0x70);

class CarPerformance {
public:
	Car* pCar; // +0 (+350)
	Engine* pEngine; // +4 (+354)
	Engine Engine; // +8 (+358)
	Gearbox Gearbox; // +138 (+488)
	Differential Differential; // +1F8 (+548)
};

class Body {
public:
	class Suspension {
	public:
		uint8_t _0[0x4];
		float fMinLength; // +11D8
		float fMaxLength; // +11DC
		float fRestLength; // +11E0
		float fDefaultCompression; // +11E4
		float fBumpDamp; // +11E8
		float fReboundDamp; // +11EC
		float fBumperLength; // +11F0
		float fBumperConst; // +11F4
		float fBumperRestitution; // +11F8
		float fRollBarStiffness; // +11FC
		float fCamberAngle; // +1200 * 0.017453292
		float fCamberChangeUp; // +1204 * 0.017453292
		float fCamberChangeDown; // +1208 * 0.017453292
		float fCamberChangeIn; // +120C
		float fCamberChangeOut; // +1210
		uint8_t _1214[0x4];
	};
	static_assert(sizeof(Suspension) == 0x44);

	float fWheelDisplacement; // +1110
	float fWheelAligningTorqueLimits[2]; // +1114
	float fDriverLoc[3]; // +111C
	uint32_t nDriverType; // +1128
	float fMass; // +112C
	float fMass2; // +1130
	uint8_t _1134[0x4];
	float fMomentOfInertia[3]; // +1138
	float fCenterOfMass[3]; // +1144
	float fCenterOfMass2[3]; // +1150
	float fAeroDrag[3]; // +115C
	float fAeroDragLoc[3]; // +1168
	float fDamping[2]; // +1174
	float fCenterOfDownForce[3]; // +117C
	float fDownForceConst; // +1188
	float fSteeringSpeeds[2]; // +118C
	float fSteeringLimit; // +1194
	float fSteeringReduction; // +1198
	float fTireTurnAngleIn; // +119C * 0.017453292
	float fTireTurnAngleOut; // +11A0 * 0.017453292
	float fTireCenteringSpeed; // +11A4
	float fBrakeBalance[3]; // +11A8
	float fBrakeTorque; // +11B4
	float fHandBrakeTorque; // +11B8
	uint32_t nFrontTraction; // +11BC
	uint32_t nRearTraction; // +11C0
	float fFFFrictionNominalLoad; // +11C4
	float fFFFrictionOffset; // +11C8
	float fFFCenteringNominalLoad; // +11CC
	float fFFCenteringOffset; // +11D0
	Suspension SuspensionFront; // +11D4
	Suspension SuspensionRear; // +1218
	float fFrontTireRadius; // +125C
	float fFrontTireWidth; // +1260
	float fFrontTireMass; // +1264
	float fFrontTireMomentOfInertia; // +1268
	float fFrontSuspensionLift; // +126C
	float fRearTireRadius; // +1270
	float fRearTireWidth; // +1274
	float fRearTireMass; // +1278
	float fRearTireMomentOfInertia; // +127C
	float fRearSuspensionLift; // +1280
	float fArcadeSteerBalanceFactor[3]; // +1284
	float fArcadeSteerBalanceRate[3]; // +1290
	float fArcadeBrakePower; // +129C
};
static_assert(sizeof(Body) == 0x12A0-0x1110);

class TireDynamics {
public:
	float fRollingResistance; // +0
	float fInducedDragCoeff; // +4
	float fPneumaticTrail; // +8
	float fPneumaticOffset; // +C
	float fZStiffness[3]; // +10
	float fXStiffness[3]; // +1C
	float fCStiffness[2]; // +28
	float fZFriction[2]; // +30
	float fXFriction[2]; // +38
	float fSlideControl; // +40
	float fUnderSteer; // +44
	float fSlowDown; // +48
};
static_assert(sizeof(TireDynamics) == 0x4C);

class DamageEntity {
public:
	uint8_t _0[0xA0];
	uint32_t nEntityType; // +A0 4 is car
	uint8_t _A4[0xEC];
	void* pBasePtr; // +190
};

class DamageData {
public:
	uint8_t _0[0x24];
	float fImpactForce; // +24
	float fImpactForce2; // +28
	uint8_t _2C[0x8];
	DamageEntity* pEntity; // +34
};

class Car {
public:
	int aObjectsSmashed[10]; // +0
	struct tCarCollisionData {
		int32_t lastHitTimestamp; // +0
		float damage; // +4
	} aCarCollisions[8]; // +28
	uint8_t _68[0x8];
	float fBrakeBalance; // +70
	float fTireTurnAngleIn; // +74
	float fTireTurnAngleOut; // +78
	FO2String sName; // +7C
	FO2String sFolderPath; // +98
#ifdef NYA_MATH_H
	NyaVec3 vCollisionFullCenter; // +B4
	NyaVec3 vCollisionFullRadius; // +C0
	NyaVec3 vCollisionBottomCenter; // +CC
	NyaVec3 vCollisionBottomRadius; // +D8
	NyaVec3 vCollisionTopCenter; // +E4
	NyaVec3 vCollisionTopRadius; // +F0
#else
	float vCollisionFullCenter[3]; // +B4
	float vCollisionFullRadius[3]; // +C0
	float vCollisionBottomCenter[3]; // +CC
	float vCollisionBottomRadius[3]; // +D8
	float vCollisionTopCenter[3]; // +E4
	float vCollisionTopRadius[3]; // +F0
#endif
	uint8_t _FC[0x54];
	float mMatrix[4*4]; // +150 used as ptr for collision checks
	uint8_t _190[0xB0];
	float qQuaternion[4]; // +240
	uint8_t _250[0x10];
	float vVelocity[3]; // +260
	uint8_t _26C[0x4];
	float vAngVelocity[3]; // +270
	uint8_t _27C[0x20];
	float fMass; // +29C
	uint8_t _2A0[0xB0];
	CarPerformance Performance; // +350
	uint8_t _5B8[0xB58];
	Body Body; // +1110
	uint8_t _12A0[0x8];
	float fGasPedal; // +12A8
	float fBrakePedal; // +12AC
	float fNitroButton; // +12B0
	float fHandbrake; // +12B4
	float fSteerAngle; // +12B8
	uint8_t _12BC[0x54];
	TireDynamics TireDynamics[8]; // +1310
	uint8_t _1570[0x964];
	float fRagdollVelocity; // +1ED4
	uint8_t _1ED8[0x28];
	uint32_t nIsRagdolled; // +1F00
	uint8_t _1F04[0x1824];
	Player* pPlayer; // +3728
	uint8_t _372C[0x50];
	float fDamage; // +377C
	uint8_t _3780[0x38];
	float fTimeInAir; // +37B8
	uint8_t _37BC[0x3C];
	void* pEngineSound; // +37F8 not a pointer, data begins here
	uint8_t _37FC[0xA5C];
	void* pSurfaceSounds; // +4258 not a pointer, data begins here

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

	inline float& GetNitro() {
		return Performance.Engine.fNitro;
	}
	inline float& GetMaxNitro() {
		return Performance.Engine.fMaxNitro;
	}

	static inline auto LaunchRagdoll = (void(__stdcall*)(Car*, float))0x414580;
	static inline auto Reset = (void(__stdcall*)(Car*, float* pos, float* matrix))0x41AB90;
	static inline auto SelectEngine = (void(__stdcall*)(Car*, int))0x42E850;

	static inline uintptr_t LoadEngineSounds_call = 0x40DE70;
	static void __attribute__((naked)) __fastcall LoadEngineSounds(bool useAISounds, int unk0, void* engineSounds, const char* path, int unk0_2) {
		__asm__ (
			"mov eax, ecx\n\t"
			"mov ecx, edx\n\t"
			"jmp %0\n\t"
				:
				:  "m" (LoadEngineSounds_call)
		);
	}

	static inline uintptr_t LoadSurfaceSounds_call = 0x412530;
	static void __attribute__((naked)) __thiscall LoadSurfaceSounds(int unk4, void* surfaceSounds, const char* path) {
		__asm__ (
			"mov eax, ecx\n\t"
			"jmp %0\n\t"
				:
				:  "m" (LoadSurfaceSounds_call)
		);
	}

	static inline uintptr_t InitEngine_call = 0x42E9A0;
	void __attribute__((naked)) __fastcall InitEngine(int engine) {
		__asm__ (
			"pushad\n\t"
			"mov eax, ecx\n\t"
			"mov ebx, edx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (InitEngine_call)
		);
	}

	static inline uintptr_t FinishInitEngine_call = 0x42EAF0;
	void __attribute__((naked)) __fastcall FinishInitEngine(int unknown) {
		__asm__ (
			"pushad\n\t"
			"mov eax, edx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (FinishInitEngine_call)
		);
	}

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

	static inline uintptr_t GetDerbyDamage_call = 0x416E40;
	float __attribute__((naked)) __fastcall GetDerbyDamage() {
		__asm__ (
			"mov eax, ecx\n\t"
			"call %0\n\t"
			"ret\n\t"
				:
				:  "m" (GetDerbyDamage_call)
		);
	}
};
static_assert(sizeof(Car) == 0x425C);

auto fBonusTypeMayhem = (float*)0x6BD990;
auto fBonusTypePrice = (float*)0x6BD968;