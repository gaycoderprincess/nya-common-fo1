#include <vector>

namespace NyaFO2Hooks {
	std::vector<void(*)()> aEndSceneFuncs;
	std::vector<void(*)()> aPresentFuncs;
	std::vector<void(*)()> aPostPresentFuncs;
	std::vector<void(*)()> aD3DResetFuncs;
	std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aWndProcFuncs;
	std::vector<void(*)(void*)> aScriptFuncs;

	auto EndSceneOrig = (HRESULT(__thiscall*)(void*))nullptr;
	HRESULT __fastcall EndSceneHook(void* a1) {
		for (auto& func : aEndSceneFuncs) {
			func();
		}
		return EndSceneOrig(a1);
	}

	auto PresentOrig = (HRESULT(__thiscall*)(void*))nullptr;
	HRESULT __fastcall PresentHook(void* a1) {
		for (auto& func : aPresentFuncs) {
			func();
		}
		auto result = PresentOrig(a1);
		for (auto& func : aPostPresentFuncs) {
			func();
		}
		return result;
	}

	auto D3DResetOrig = (void(*)())nullptr;
	void D3DResetHook() {
		for (auto& func : aD3DResetFuncs) {
			func();
		}
		return D3DResetOrig();
	}

	auto WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
	LRESULT __stdcall WndProcHook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		for (auto& func : aWndProcFuncs) {
			func(hWnd, msg, wParam, lParam);
		}
		return WndProcOrig(hWnd, msg, wParam, lParam);
	}

	auto lua_setglobal_callback = (void(*)(void*, const char*))nullptr;
	void ScriptHook(void* a1, const char* a2) {
		for (auto& func : aScriptFuncs) {
			func(a1);
		}
		return lua_setglobal_callback(a1, a2);
	}

	void PlaceD3DHooks() {
		if (!EndSceneOrig) {
			EndSceneOrig = (HRESULT(__thiscall*)(void*))(*(uintptr_t*)0x667954);
			NyaHookLib::Patch(0x667954, &EndSceneHook);
			PresentOrig = (HRESULT(__thiscall*)(void*))(*(uintptr_t*)0x667938);
			NyaHookLib::Patch(0x667938, &PresentHook);
			D3DResetOrig = (void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5055AD, &D3DResetHook);
		}
	}

	void PlaceWndProcHook() {
		if (!WndProcOrig) {
			WndProcOrig = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x504FF8);
			NyaHookLib::Patch(0x504FF8, &WndProcHook);
		}
	}

	void PlaceScriptHook() {
		if (!lua_setglobal_callback) {
			lua_setglobal_callback = (void(*)(void*, const char*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x43A862, &ScriptHook);
		}
	}
}