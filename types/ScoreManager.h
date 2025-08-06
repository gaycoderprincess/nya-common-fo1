class PlayerScoreRace {
public:
	uint32_t nPlayerId; // +4
	int32_t nPosition; // +8
	uint8_t _C[0xC];
	bool bHasFinished; // +18
	bool bIsDNF; // +19
	uint8_t _1A[0x1E];
	uint32_t nStuntMetersScore[3]; // +38 longjump, highjump (meters = score * 100)
	uint8_t _44[0x8];
	uint32_t nStuntPointsScore[3]; // +4C darts, clown, curling, bowling
	uint8_t _58[0x8];
	uint32_t nCurrentLap; // +60
	uint8_t _64[0x30];
	uint32_t nFinishTime; // +94

	virtual void _vf0() = 0;
	virtual void _vf1() = 0;
	virtual void _vf2() = 0;
	virtual bool HasFinished() = 0;
	virtual bool IsDNF() = 0;
	virtual uint32_t GetFinishTime() = 0;
};

class ScoreManager {
public:
	uint8_t _0[0x8];
	uint32_t nNumPlayers; // +8
	uint32_t nNumLaps; // +C
	uint8_t _10[0x64];
	PlayerScoreRace** aScores; // +74
};
auto& pScoreManager = *(ScoreManager***)0x6C5238;
ScoreManager* GetScoreManager() {
	return *pScoreManager;
}

template<typename T>
T* GetPlayerScore(int playerId) {
	if (!pScoreManager) return nullptr;

	auto scoreManager = GetScoreManager();
	for (int i = 0; i < scoreManager->nNumPlayers; i++) {
		auto score = scoreManager->aScores[i];
		if (score->nPlayerId + 1 == playerId) {
			return (T*)score;
		}
	}
	return nullptr;
}