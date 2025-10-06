class IngameMenu {
public:
	enum eMenu {
		MENU_NONE = 0,
		MENU_PAUSEMENU = 1,
		MENU_PRESS_START = 2,
		MENU_ACTION_VIEWREPLAY = 3,
		MENU_ACTION_QUITRACE = 4,
		MENU_ACTION_RESTARTRACE = 5,
		MENU_RACE_COUNTDOWN = 6,
		MENU_RACE_FINISH_POPUP = 7,
		MENU_END_OF_RACE = 8,
		MENU_SOUNDOPTIONS = 9,
		MENU_PROMPT_QUITRACE = 10,
		MENU_RACE_RESULTS = 11, // can be a fullscreen menu or just a small box depending on whether it's a stunt event!
		MENU_REPLAY_UI = 12,
		MENU_STUNT_END_OF_ROUND = 13,
		MENU_PAUSEMENU_MULTIPLAYER = 14,
		MENU_END_OF_RACE_SPLITSCREEN = 15,
		MENU_CAREER_STUNT_RESULTS = 16,
		MENU_GAMEMODE_TUTORIAL = 17,
		MENU_PROMPT_QUIT_MULTIPLAYER = 18,
		MENU_PROMPT_RESTARTRACE = 21,
		MENU_PROMPT_QUIT_MULTIPLAYER_2 = 22,
	};

	uint8_t _0[0x5C];
	uint32_t nCurrentMenu; // +5C
	uint8_t _60[0x34];
	uint32_t nMenuJustChanged; // +94

	static inline uintptr_t DrawPressStart_call = 0x45AC50;
	int __attribute__((naked)) __fastcall DrawPressStart() {
		__asm__ (
			"pushad\n\t"
			"mov eax, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (DrawPressStart_call)
		);
	}
};