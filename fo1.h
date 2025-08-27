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
#include "types/Car.h"
#include "types/Player.h"
#include "types/GameFlow.h"
#include "types/GameSettings.h"
#include "types/ScoreManager.h"
#include "types/LoadingScreen.h"
#include "types/Track.h"
#include "types/EventManager.h"
#include "types/CameraManager.h"
#include "types/IngameMenu.h"

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