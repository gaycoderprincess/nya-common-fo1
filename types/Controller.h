enum eControllerButton {
	CONTROLLER_BUTTON_A,
	CONTROLLER_BUTTON_B,
	CONTROLLER_BUTTON_X,
	CONTROLLER_BUTTON_Y,
	CONTROLLER_BUTTON_EXTRA1,
	CONTROLLER_BUTTON_EXTRA2,
	CONTROLLER_BUTTON_EXTRA3,
	CONTROLLER_BUTTON_EXTRA4,
	CONTROLLER_BUTTON_START,
	CONTROLLER_BUTTON_SELECT,
	CONTROLLER_BUTTON_UP,
	CONTROLLER_BUTTON_DOWN,
	CONTROLLER_BUTTON_LEFT,
	CONTROLLER_BUTTON_RIGHT,
	CONTROLLER_BUTTON_DIGITAL_UP,
	CONTROLLER_BUTTON_DIGITAL_DOWN,
	CONTROLLER_BUTTON_DIGITAL_LEFT,
	CONTROLLER_BUTTON_DIGITAL_RIGHT,
	CONTROLLER_BUTTON_LEFT_TRIGGER,
	CONTROLLER_BUTTON_RIGHT_TRIGGER,
};

class Controller {
public:
	uint32_t _4[0x191];
	struct tInput {
		uint32_t keyboardKey;
		uint8_t _0[0xC];
	} aInputs[20];

	// KeyboardController functions
	static inline auto IsMenuInputJustPressed = (bool(__thiscall*)(Controller*, int))0x4FB090;
	static inline auto IsGameInputJustPressed = (bool(__thiscall*)(Controller*, int))0x4FB050;
	static inline auto GetInputValue = (int(__thiscall*)(Controller*, int))0x4FB000;
	static inline auto IsInputJustPressed2 = (int(__thiscall*)(Controller*, int))0x4FB0E0;
	static inline auto GetInputValue2 = (int(__thiscall*)(Controller*, int))0x4FB110;
	static inline auto GetAnalogInput = (int(__thiscall*)(Controller*, int, float*))0x4F2F10;

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual void Reset() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual bool IsGearSwitchingAvailable() = 0;
	virtual void _vf8() = 0;
	virtual bool _vf_IsMenuInputJustPressed(int input) = 0;
	virtual bool _vf_IsGameInputJustPressed(int input) = 0;
	virtual int _vf_GetInputValue(int input) = 0;
	virtual void _vf12() = 0;
	virtual void _vf13() = 0;
	virtual int _vf_IsInputJustPressed2(int input) = 0;
	virtual int _vf_GetInputValue2(int input) = 0;
	virtual float _vf_GetAnalogInput(int input) = 0;
};

class InputManager {
public:
	uint8_t _0[0x4];
	uint32_t nNumControllers; // +4
	uint8_t _8[0x10];
	Controller* aControllers[]; // +18

	static inline uintptr_t IsKeyJustPressed_call = 0x4F16C0;
	int __attribute__((naked)) __thiscall IsKeyJustPressed(int key) {
		__asm__ (
			"push ebx\n\t"
			"mov ebx, ecx\n\t" // this
			"push dword ptr [esp+0x8]\n\t"
			"call %0\n\t"
			"pop ebx\n\t"
			"ret 4\n\t"
				:
				:  "m" (IsKeyJustPressed_call)
		);
	}
};
auto& pInputManager = *(InputManager**)0x6C5244;