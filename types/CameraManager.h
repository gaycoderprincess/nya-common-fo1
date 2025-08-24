class CameraManager {
public:
	uint8_t _0[0x28];
	void* pCamera; // +28
	Player* pPlayer; // +2C
};
auto& pCameraManager = *(CameraManager**)0x6C5230;