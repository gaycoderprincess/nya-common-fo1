class BfsManager {
public:

	static inline auto DoesFileExist = (bool(__thiscall*)(void*, const char*, int*))0x4F98D0;

	static inline uintptr_t AddBFSFile_call = 0x4EEE50;
	static int __attribute__((naked)) __fastcall AddBFSFile(const char* fileName) {
		__asm__ (
				"mov eax, ecx\n\t"
				"call %0\n\t"
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
	uint8_t _0[0x20];
	FileCodec* pFileCodec; // +20
};

uintptr_t ParseGameDDS_jmp = 0x509FE0;
bool __attribute__((naked)) __fastcall ParseGameDDS(uint8_t* header, void*, DevTexture* pThis, File* pFile) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			:  "m" (ParseGameDDS_jmp)
	);
}

uintptr_t ParseGameDDS2_jmp = 0x50A5C0;
bool __attribute__((naked)) __fastcall ParseGameDDS2(uint8_t* header, void*, DevTexture* pThis, uint8_t* pFile) {
	__asm__ (
		"mov eax, ecx\n\t"
		"jmp %0\n\t"
			:
			:  "m" (ParseGameDDS2_jmp)
	);
}