#include <d3d9.h>

#include "scriptenums.h"
#include "languages.h"
#include "fo1math.h"

#include "types/FO2String.h"
#include "types/FO2Vector.h"
#include "types/LUA.h"
#include "types/DeviceD3d.h"
#include "types/FileManager.h"
#ifndef NYA_COMMON_NO_D3D
#include "types/Font.h"
#endif
#include "types/Controller.h"
#include "types/Track.h"
#include "types/Car.h"
#include "types/Player.h"
#include "types/GameFlow.h"
#include "types/GameSettings.h"
#include "types/ScoreManager.h"
#include "types/LoadingScreen.h"
#include "types/MenuEventManager.h"
#include "types/CameraManager.h"
#include "types/IngameMenu.h"

auto FO2Malloc = (void*(__cdecl*)(size_t))0x5EB023;

auto gPalette = (uint32_t*)0x6C44E8;

#include "fo1helpers.h"
#include "fo1hooks.h"

auto& nMusicPopupTimeOffset = *(int*)0x6BFFEC;

class RNGGenerator {
public:
	static inline auto& pCurrentValue = *(int**)0x6BFD30;
	static inline auto& nNumValuesLeft = *(int*)0x6948F0;
	static inline auto aValueTable = (int*)0x6BF370;
	static inline auto Reset = (void(*)())0x501AC0;
};

struct tLineOfSightIn {
	float vStart[3]; // +0
	uint8_t _C[0x18];
	float vDir[3]; // +24
	uint8_t _30[0xC];
	float fMaxDistance; // +3C
	float fMinDistance; // +40
	uint8_t _44[0x20];
	void* pTrackCollision; // +64
	void* pCollisionVertices; // +68
	uint8_t _6C[0x8];
	bool bIgnoreBackfaces; // +74
	bool bGetClosestHit; // +75 returns first match if false

	tLineOfSightIn() {
		memset(this,0,sizeof(*this));
		fMaxDistance = 100.0;
		fMinDistance = 0.01;
		bIgnoreBackfaces = true;
		bGetClosestHit = true;
	}
};

struct tLineOfSightOut {
	float fHitNormal[3];
	float fHitDistance;
};

static inline uintptr_t CheckLineOfSight_call = 0x4B30C0;
#ifdef NYA_MATH_H
bool __attribute__((naked)) __fastcall CheckLineOfSight(NyaVec3* vStart, tLineOfSightIn* prop, tCollisionRegion* aRegionLock, NyaVec3* vDir, tLineOfSightOut* out, uint32_t flags, void* a8) {
#else
bool __attribute__((naked)) __fastcall CheckLineOfSight(float* vStart, tLineOfSightIn* prop, tCollisionRegion* aRegionLock, float* vDir, tLineOfSightOut* out, uint32_t flags, void* a8) {
#endif
	__asm__ (
		"push ecx\n\t"
		"push edx\n\t"
		"push ebx\n\t"
		"push ebp\n\t"
		"push esi\n\t"
		"push edi\n\t"

		"mov edi, edx\n\t" // prop

		// TrackCollision ptr
		"mov eax, 0x6C004C\n\t"
		"mov eax, [eax]\n\t"
		"mov edx, [eax+0x20]\n\t"

		// stack params
		"push dword ptr [esp+0x2C]\n\t"
		"push dword ptr [esp+0x2C]\n\t"
		"push dword ptr [esp+0x2C]\n\t"
		"push dword ptr [esp+0x2C]\n\t"
		"push dword ptr [esp+0x2C]\n\t"

		"call %0\n\t"
		"pop edi\n\t"
		"pop esi\n\t"
		"pop ebp\n\t"
		"pop ebx\n\t"
		"pop edx\n\t"
		"pop ecx\n\t"
		"ret 0x14\n\t"
			:
			:  "m" (CheckLineOfSight_call)
	);
}