#include <cstdint>

class RandomByte {
	int SeedNo;

public:
	inline void Seed(int seed) { SeedNo=seed; }
	uint8_t NextRandomByte();
};
