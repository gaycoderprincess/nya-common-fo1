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
	uint8_t _0[0x2068];
	uint32_t nNumSplitpoints; // +2068
	uint8_t _206C[0x648];
	Minimap* pMinimap; // +26B4

	static inline auto aBonusObjects = (int*)0x6BD9E0; // object count per type
};

auto& pEnvironment = *(Track**)0x6C004C;