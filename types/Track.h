class Minimap {
public:
	uint8_t _0[0x140];
	float fMapTopLeft[2]; // +140
	float fMapBottomRight[2]; // +148
	float fScreenPos[2]; // +150
	float fScreenSize[2]; // +158
};
static_assert(sizeof(Minimap) == 0x160);

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

	uint8_t _0[0x1168];
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