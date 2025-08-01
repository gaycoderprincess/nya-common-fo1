enum eTrack {
	TRACK_FOREST1A = 1,
	TRACK_FOREST2A = 2,
	TRACK_FOREST3A = 3,
	TRACK_PIT1A = 4,
	TRACK_PIT2A = 5,
	TRACK_PIT3A = 6,
	TRACK_RACING1A = 7,
	TRACK_RACING2A = 8,
	TRACK_TOWN2A = 11,
	TRACK_TOWN3A = 12,
	TRACK_WINTER1A = 13,
	TRACK_WINTER2A = 14,
	TRACK_DERBY1A = 22,
	TRACK_DERBY2A = 23,
	TRACK_DERBY3A = 24,
	TRACK_ARENA1A = 25,
	TRACK_ARENA2A = 26,
	TRACK_ARENA3A = 27,
	TRACK_FOREST1B = 28,
	TRACK_FOREST2B = 29,
	TRACK_FOREST3B = 30,
	TRACK_PIT1B = 31,
	TRACK_PIT2B = 32,
	TRACK_PIT3B = 33,
	TRACK_RACING1B = 34,
	TRACK_RACING2B = 35,
	TRACK_TOWN2B = 36,
	TRACK_TOWN3B = 37,
	TRACK_WINTER1B = 38,
	TRACK_WINTER2B = 39,
	TRACK_FOREST1C = 40,
	TRACK_FOREST2C = 41,
	TRACK_FOREST3C = 42,
	TRACK_PIT1C = 43,
	TRACK_PIT2C = 44,
	TRACK_PIT3C = 45,
	TRACK_RACING1C = 9,
	TRACK_RACING2C = 10,
	TRACK_TOWN2C = 15,
	TRACK_TOWN3C = 16,
	TRACK_WINTER1C = 17,
	TRACK_WINTER2C = 18,
	TRACK_LONGJUMP = 19,
	TRACK_HIGHJUMP = 20,
	TRACK_BULLSEYE = 46,
	TRACK_BOWLING = 47,
	TRACK_DARTS = 48,
	TRACK_CLOWN = 49,
};

enum class eGameMode : uint32_t {
	SINGLEPLAYER = 1,
	HOST = 2,
	JOIN = 3,
	SPLITSCREEN = 4,
};

enum class eEventType : uint32_t {
	RACE,
	DERBY,
	STUNT,
};

enum class eSubEventType : uint32_t {
	NONE,
	RACE_NORMAL,
	RACE_CAREER,
	RACE_TIMETRIAL,
	RACE_SMASHYSMASH,
	RACE_DOUBLESMASH,
	RACE_TAG,
	DERBY_LASTMANSTANDING,
	STUNT_LONGJUMP,
	STUNT_HIGHJUMP,
	STUNT_DARTS,
	STUNT_CLOWN,
	STUNT_CURLING,
	STUNT_BOWLING,
};