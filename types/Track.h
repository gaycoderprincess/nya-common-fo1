class Minimap {
public:
	uint8_t _0[0x140];
	float fMapTopLeft[2]; // +140
	float fMapBottomRight[2]; // +148
	float fScreenPos[2]; // +150
	float fScreenSize[2]; // +158
};
static_assert(sizeof(Minimap) == 0x160);

// vertex 1 0000D939 (+3)
// vertex 2 0000D935 (+6)
// vertex 3 0000D97D (+9)
// +9 7D +A D9 +B 00
struct __attribute__((packed)) tCollisionPoly {
	struct tInt24 {
		uint8_t data[3];

		const uint32_t Get() {
			uint32_t value = data[0];
			value += data[1] * 256;
			value += data[2] * 65536;
			return value;
		}
		void Set(const uint32_t value) {
			memcpy(data, &value, 3);
		}
	};

	// unknownid:
	// byte_68BDF4[v7 >> 11]
	// byte_68BDF4[(v7 >> 6) & 0x1F]

	// nFlags:
	// trees 1
	// objects 3
	// water 6
	// ground 27

	uint8_t nFlags; // +0
	uint8_t nMaterial : 6; // +1
	uint8_t nUnk2 : 2; // +1
	uint8_t nUnk3; // +2
	tInt24 nVertex1; // +3
	tInt24 nVertex2; // +6
	tInt24 nVertex3; // +9
};

struct tCollisionRegion {
	// v77 = ((nFlags >> 5) & 0x7F) + 1
	// v24 = v76 + 12 * (nFlags >> 12);

	// 0887007B
	// gets me 00000004 for count and 8870 for id
	// 23A40020 23AA6560

	// 0886C07B
	// shr 00443603
	// and 00000003

	// first byte is 3 bytes
	struct __attribute__((packed)) tFlags {
		uint32_t value;

		int GetPolyCount() {
			return ((value >> 5) & 0x7F) + 1;
		}

		bool HasPolys() {
			return (value & 0x10) != 0;
		}

		int GetIndex() {
			return value >> 12;
		}

		void SetPolyCount(int i) {
			if (i <= 0) return;
			value |= ((i - 1) << 5) & 0x7F;
		}

		void SetHasPolys(bool b) {
			if (b) {
				value |= 0x10;
			}
			else {
				value &= ~0x10;
			}
		}

		void SetIndex(int i) {
			value |= i << 12;
		}
	} nFlags;
	int16_t nXPosition;
	int16_t nXSize;
	int16_t nYPosition;
	int16_t nYSize;
	int16_t nZPosition;
	int16_t nZSize;
};

class TrackCollision {
public:
	float fCoordMultipliers1[3]; // +0 doesn't seem to do anything?
	float fCoordMultipliers2[3]; // +C makes collisions wonky if changed lower
	float fCoordMultipliersInv1[3]; // +18 used for shadows and body collision
	float fCoordMultipliersInv2[3]; // +24 doesn't seem to do anything..? it is read though
	float fWorldCenter[3]; // +30 never seems to be read in-game?
	float fWorldSize[3]; // +3C never seems to be read in-game?
	float* aVertices; // +48
	tCollisionRegion* aRegions; // +4C
	tCollisionPoly* aPolys; // +50
	uint32_t nValue1; // +54
};
static_assert(sizeof(TrackCollision) == 0x58);

class Track {
public:
	struct tSplitpoint {
		float fLeft[3]; // +0
		float fRight[3]; // +C
		float fPosition[3]; // +18
		uint8_t _24[0x18];
	};
	static_assert(sizeof(tSplitpoint) == 0x3C);

	struct tStartpoint {
		float fPosition[4];
		float fMatrix[4*4];
	};
	static_assert(sizeof(tStartpoint) == 0x50);

	uint8_t _0[0x20];
	TrackCollision* pCollision; // +20
	uint8_t _24[0x1144];
	tSplitpoint aSplitpoints[32]; // +1168
	uint8_t _18E8[0x780];
	uint32_t nNumSplitpoints; // +2068
	uint8_t _206C[0x4];
	tStartpoint aStartpoints[8]; // +2070
	uint8_t _22F0[0x3C4];
	Minimap* pMinimap; // +26B4

	static inline auto aBonusObjects = (int*)0x6BD9E0; // object count per type
};
auto& pEnvironment = *(Track**)0x6C004C;

class TrackAI {
public:
	struct tSplineData {
		uint8_t _0[0x4];
		uint32_t nNumSplines; // +4
	};
	tSplineData* pAIRaceLine; // +0
	tSplineData* pAIBorderLineLeft; // +4
	tSplineData* pAIBorderLineRight; // +8
};
auto& pTrackAI = *(TrackAI**)0x6C5220;