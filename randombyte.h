#include <cstdint>

class RandomByte {
	int SeedNo = 0xFC752521;

public:
	inline void Seed(int seed) { SeedNo=seed; }
	uint8_t NextRandomByte();
};
