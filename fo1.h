#include <d3d9.h>

#include "scriptenums.h"
#include "types/FO2String.h"
#include "types/FO2Vector.h"
#include "types/LUA.h"
#include "types/DeviceD3d.h"
#include "types/FileManager.h"
#include "types/Font.h"
#include "types/Car.h"
#include "types/Player.h"
#include "types/GameFlow.h"
#include "types/GameSettings.h"
#include "types/ScoreManager.h"
#include "languages.h"

auto gPalette = (uint32_t*)0x6C44E8;

#include "fo1helpers.h"
#include "fo1hooks.h"

auto& pLoadingScreen = *(void**)0x6C0050;

auto& nMusicPopupTimeOffset = *(int*)0x6BFFEC;