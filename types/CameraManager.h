class Camera {
public:
	uint8_t _0[0x40];
	float mMatrix[4*4]; // +40
	uint8_t _80[0x70];
	float fLeft; // +F0
	float fRight; // +F4
	float fTop; // +F8
	float fBottom; // +FC
	uint8_t _100[0xC];
	float fNearZ; // +10C
	float fFarZ; // +110
	float fFOV; // +114
	float fAspectX; // +118
	float fAspectY; // +11C

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
#endif
};

class CameraManager {
public:
	uint8_t _0[0x28];
	Camera* pCamera; // +28
	Player* pPlayer; // +2C
};
auto& pCameraManager = *(CameraManager**)0x6C5230;