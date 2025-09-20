class DevTexture {
public:
	uint8_t _0[0x10];
	uint32_t nLoadState; // +10
	uint32_t nFlags; // +14
	uint8_t _18[0x4];
	FO2String sPath; // +1C
	uint8_t _38[0x18];
	PDIRECT3DTEXTURE9 pD3DTexture; // +50
};

class DeviceD3d {
public:
	enum eRenderState {
		RENDERSTATE_CULLMODE = 1,
		RENDERSTATE_ZWRITEENABLE = 2,
		RENDERSTATE_ZFUNC = 3,
		RENDERSTATE_ALPHAFUNC = 4,
	};

	static inline auto& pD3DDevice = *(IDirect3DDevice9**)0x6C00D8;
	static inline auto& hWnd = *(HWND*)0x6C00EC;

	static inline auto& nDesiredCullMode = *(int*)0x6C4954;

	static inline auto CreateTextureFromFile = (DevTexture*(__thiscall*)(DeviceD3d*, DevTexture*, const char* path, uint32_t flags))0x50B060;
	static inline auto CreateTextureFromMemory = (DevTexture*(__thiscall*)(DeviceD3d*, DevTexture*, uint8_t* data, uint32_t dataSize, uint32_t flags))0x50B410;

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual void _vf7() = 0;
	virtual void _vf8() = 0;
	virtual void _vf9() = 0;
	virtual void _vf10() = 0;
	virtual void _vf11() = 0;
	virtual void _vf12() = 0;
	virtual void _vf13() = 0;
	virtual void _vf14() = 0;
	virtual void _vf15() = 0;
	virtual void _vf16() = 0;
	virtual void _vf17() = 0;
	virtual void _vf18() = 0;
	virtual void _vf19() = 0;
	virtual void _vf20() = 0;
	virtual void _vf21() = 0;
	virtual void _vf22() = 0;
	virtual void _vf23() = 0;
	virtual void SetRenderState(int state, int value) = 0;
	virtual void _vf25() = 0;
	virtual void _vf26() = 0;
	virtual void _vf27() = 0;
	virtual void _vf28() = 0;
	virtual void _vf29() = 0;
	virtual void _vf30() = 0;
	virtual void _vf31() = 0;
	virtual void _vf32() = 0;
	virtual void _vf33() = 0;
	virtual void _vf34() = 0;
	virtual void _vf35() = 0;
	virtual void _vf36() = 0;
	virtual void _vf37() = 0;
	virtual void _vf38() = 0;
	virtual void _vf39() = 0;
	virtual void _vf40() = 0;
	virtual void _vf41() = 0;
	virtual void _vf42() = 0;
	virtual void _vf43() = 0;
	virtual void _vf44() = 0;
	virtual void _vf45() = 0;
	virtual void _vf46() = 0;
	virtual void _vf47() = 0;
	virtual void _vf48() = 0;
	virtual void _vf49() = 0;
	virtual void _vf50() = 0;
	virtual void _vf51() = 0;
	virtual void _vf52() = 0;
	virtual void _vf53() = 0;
	virtual void _vf54() = 0;
	virtual void _vf55() = 0;
	virtual void _vf56() = 0;
	virtual void _vf57() = 0;
	virtual void _vf58() = 0;
	virtual void _vf59() = 0;
	virtual void _vf60() = 0;
	virtual DevTexture* _vf_CreateTextureFromFile(DevTexture* pTexture, const char* path, uint32_t flags) = 0;
	virtual DevTexture* _vf_CreateTextureFromMemory(DevTexture* pTexture, uint8_t* data, uint32_t dataSize, uint32_t flags) = 0;
	virtual void _vf63() = 0;
	virtual void _vf64() = 0;
	virtual void _vf65() = 0;
	virtual void _vf66() = 0;
	virtual void _vf67() = 0;
	virtual void _vf68() = 0;
	virtual void _vf69() = 0;
};
auto& pDeviceD3d = *(DeviceD3d**)0x6C0098;

auto& nGameResolutionX = *(int*)0x6B0D88;
auto& nGameResolutionY = *(int*)0x6B0D8C;

auto LoadTextureFromFile = (DevTexture*(__stdcall*)(void*, const char* path, int, int))0x4EFE40;