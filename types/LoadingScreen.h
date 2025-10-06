class LoadingScreen {
public:

	static inline uintptr_t Draw_call = 0x4C0610;
	void __attribute__((naked)) __thiscall Draw(float a2) {
		__asm__ (
			"pushad\n\t"
			"mov edi, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (Draw_call)
		);
	}
};

auto& pLoadingScreen = *(LoadingScreen**)0x6C0050;
