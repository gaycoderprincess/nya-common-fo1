#include <codecvt>

class Font {
public:
	uint8_t _0[0x4];
	NyaDrawing::CNyaRGBA32 nColor; // +4
	uint8_t _8[0x14];
	struct {
		bool bXCenterAlign : 1;
		bool bXRightAlign : 1;
	}; // +1C
	uint8_t _20[0x14];
	float fScaleX; // +34
	float fScaleY; // +38

	static inline auto GetFont = (Font*(__stdcall*)(void*, const char*))0x4396A0;
	static inline auto Display = (void(__thiscall*)(Font*, float, float, int, float, const wchar_t*))0x4F0D00;
	//static inline auto GetWidth = (float(*)(Font*, const wchar_t*, ...))0x54F7A0;
};

struct tFontBak {
	NyaDrawing::CNyaRGBA32 nColor;
	bool bXCenterAlign : 1;
	bool bXRightAlign : 1;
	float fScaleX;
	float fScaleY;
};

void DrawStringFO2(tNyaStringData data, const wchar_t* string, const char* font) {
	auto pFont = Font::GetFont(*(void**)0x6C5240, font);

	tFontBak bak;
	bak.fScaleX = pFont->fScaleX;
	bak.fScaleY = pFont->fScaleY;
	bak.nColor = pFont->nColor;
	bak.bXCenterAlign = pFont->bXCenterAlign;
	bak.bXRightAlign = pFont->bXRightAlign;

	pFont->fScaleX = data.size * nResX / 20.0;
	pFont->fScaleY = data.size * nResY / 20.0;
	pFont->bXRightAlign = data.XRightAlign;
	pFont->bXCenterAlign = data.XCenterAlign;
	pFont->nColor.r = data.b;
	pFont->nColor.g = data.g;
	pFont->nColor.b = data.r;
	pFont->nColor.a = data.a;
	pFont->fScaleX *= GetAspectRatioInv();
	if (data.YCenterAlign) {
		data.y -= data.size * 0.5;
	}
	Font::Display(pFont, data.x * nResX, data.y * nResY, 0, 0.0, string);

	pFont->fScaleX = bak.fScaleX;
	pFont->fScaleY = bak.fScaleY;
	pFont->nColor = bak.nColor;
	pFont->bXCenterAlign = bak.bXCenterAlign;
	pFont->bXRightAlign = bak.bXRightAlign;
}

/*float GetStringWidthFO2(tNyaStringData data, const wchar_t* string, const char* font) {
	auto pFont = Font::GetFont(*(void**)0x6C5240, font);

	tFontBak bak;
	bak.fScaleX = pFont->fScaleX;
	bak.fScaleY = pFont->fScaleY;
	bak.nColor = pFont->nColor;
	bak.bXCenterAlign = pFont->bXCenterAlign;
	bak.bXRightAlign = pFont->bXRightAlign;

	pFont->fScaleX = data.size * nResX / 20.0;
	pFont->fScaleY = data.size * nResY / 20.0;
	pFont->bXRightAlign = data.XRightAlign;
	pFont->bXCenterAlign = data.XCenterAlign;
	pFont->nColor.r = data.b;
	pFont->nColor.g = data.g;
	pFont->nColor.b = data.r;
	pFont->nColor.a = data.a;
	pFont->fScaleX *= GetAspectRatioInv();
	if (data.YCenterAlign) {
		data.y -= data.size * 0.5;
	}
	auto w = Font::GetWidth(pFont, string);

	pFont->fScaleX = bak.fScaleX;
	pFont->fScaleY = bak.fScaleY;
	pFont->nColor = bak.nColor;
	pFont->bXCenterAlign = bak.bXCenterAlign;
	pFont->bXRightAlign = bak.bXRightAlign;

	w /= (double)nResX;
	// adjust width if widescreen fix is installed
	if (GetModuleHandleA("ZPatchFO2.asi")) {
		w /= 4.0 / 3.0;
		w *= (double)nResX / (double)nResY;
	}
	return w;
}*/

void DrawStringFO2(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringFO2(data, converter.from_bytes(name).c_str(), "FontMenuLarge");
}

void DrawStringFO2_Small(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringFO2(data, converter.from_bytes(name).c_str(), "FontMenuSmall");
}

void DrawStringFO2_Ingame12(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringFO2(data, converter.from_bytes(name).c_str(), "Ingame12");
}

void DrawStringFO2_Ingame24(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringFO2(data, converter.from_bytes(name).c_str(), "Ingame24");
}

/*float GetStringWidthFO2(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return GetStringWidthFO2(data, converter.from_bytes(name).c_str(), "FontLarge");
}*/