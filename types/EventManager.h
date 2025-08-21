class EventManager {
public:
	enum eEvent {
		GAME_ENTERMENU = 1,
		GAME_RACE = 2,
		GAME_CONTINUE = 3,
	};

	uint8_t _0[0xC];
	uint32_t nEventId; // +C
	uint32_t n10; // +10
	uint8_t _14[0xC];
	uint32_t n20; // +20
	uint8_t _24[0x34];
	uint32_t n58; // +58
	uint8_t _5C[0x8];
	uint32_t n64; // +64

	void PostEvent(int eventId) {
		nEventId = eventId;
		n10 = 1;
		n20 = 0;
		n58 = n64;
	}
};
static_assert(sizeof(EventManager) == 0x68);

auto& pEventManager = *(EventManager**)0x6C5248;