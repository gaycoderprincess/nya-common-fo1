class BfsManager {
public:

	static inline auto DoesFileExist = (bool(__thiscall*)(void*, const char*, int*))0x4F98D0;

	static inline uintptr_t AddBFSFile_call = 0x4EEE50;
	static void __attribute__((naked)) __fastcall AddBFSFile(const char* fileName) {
		__asm__ (
			"pushad\n\t"
			"mov eax, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (AddBFSFile_call)
		);
	}
};
auto& pBfsManager = *(BfsManager**)0x6C00A0;

class FileCodec {
public:

	virtual void _vf0() = 0;
	virtual void ReadBytes(void* out, int numBytes) = 0;
	virtual void _vf2() = 0;
	virtual void _vf3() = 0;
	virtual void _vf4() = 0;
	virtual void _vf5() = 0;
	virtual void _vf6() = 0;
	virtual size_t GetFileSize() = 0;
};

class File {
public:
	FO2String sPath; // +0
	uint32_t nFlags; // +1C
	FileCodec* pFileCodec; // +20
	bool bLoaded; // +24

	static inline uintptr_t ctor_jmp = 0x4EEF10;
	void __attribute__((naked)) __thiscall ctor() {
		__asm__ (
			"pushad\n\t"
			"mov esi, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (ctor_jmp)
		);
	}

	static inline uintptr_t dtor_jmp = 0x4EF110;
	void __attribute__((naked)) __thiscall dtor() {
		__asm__ (
			"pushad\n\t"
			"mov esi, ecx\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret\n\t"
				:
				:  "m" (dtor_jmp)
		);
	}

	static inline uintptr_t Load_jmp = 0x4EEFF0;
	void __attribute__((naked)) __thiscall Load(const char* path, int args) {
		__asm__ (
			"pushad\n\t"
			"mov esi, ecx\n\t" // this
			"push dword ptr [esp+0x28]\n\t"
			"push dword ptr [esp+0x28]\n\t"
			"call %0\n\t"
			"popad\n\t"
			"ret 8\n\t"
				:
				:  "m" (Load_jmp)
		);
	}

	File() {
		ctor();
	}
	~File() {
		dtor();
	}
};
static_assert(sizeof(File) == 0x28);

uintptr_t ParseGameDDS_jmp = 0x509FE0;
bool __attribute__((naked)) __fastcall ParseGameDDS(uint8_t* header, void*, DevTexture* pThis, File* pFile) {
	__asm__ (
		"pushad\n\t"
		"mov eax, ecx\n\t"
		"call %0\n\t"
		"popad\n\t"
		"ret\n\t"
			:
			:  "m" (ParseGameDDS_jmp)
	);
}

uintptr_t ParseGameDDS2_jmp = 0x50A5C0;
bool __attribute__((naked)) __fastcall ParseGameDDSFromMemory(uint8_t* header, void*, DevTexture* pThis, uint8_t* pFile) {
	__asm__ (
		"pushad\n\t"
		"mov eax, ecx\n\t"
		"call %0\n\t"
		"popad\n\t"
		"ret\n\t"
			:
			:  "m" (ParseGameDDS2_jmp)
	);
}

uintptr_t DoesFileExist_call = 0x4EF1A0;
bool __attribute__((naked)) __fastcall DoesFileExist(const char* fileName, int flags = 0) {
	__asm__ (
		"mov eax, ecx\n\t"
		"mov ecx, edx\n\t"
		"jmp %0\n\t"
			:
			:  "m" (DoesFileExist_call)
	);
}