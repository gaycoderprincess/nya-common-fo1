uintptr_t FO2QuatToMatrix_call = 0x501BF0;
void __attribute__((naked)) __fastcall FO2QuatToMatrix(float* quaternion, float* matrix) {
	__asm__ (
		"pushad\n\t"
		"mov eax, edx\n\t"
		"call %0\n\t"
		"popad\n\t"
		"ret\n\t"
			:
			: "m" (FO2QuatToMatrix_call)
	);
}

uintptr_t FO2MatrixToQuat_call = 0x502700;
void __attribute__((naked)) __fastcall FO2MatrixToQuat(float* matrix, float* quaternion) {
	__asm__ (
		"pushad\n\t"
		"push edx\n\t"
		"call %0\n\t"
		"popad\n\t"
		"ret\n\t"
			:
			: "m" (FO2MatrixToQuat_call)
	);
}

auto FO2MatrixInvert = (void(__thiscall*)(float* dst, float* src))0x501CD0;