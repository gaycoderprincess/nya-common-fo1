#include <d3d9.h>

#include "scriptenums.h"
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
#include "languages.h"

auto gPalette = (uint32_t*)0x6C44E8;

#include "fo1helpers.h"
#include "fo1hooks.h"

auto& nMusicPopupTimeOffset = *(int*)0x6BFFEC;