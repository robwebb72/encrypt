#ifndef RANDOM_BYTE_H_
#define RANDOM_BYTE_H_

#include <cstdint>

class RandomByte {
	int SeedNo;

public:
	RandomByte();
	inline void Seed(int seed) { SeedNo=seed; }
	uint8_t NextRandomByte();
};
#endif // RANDOM_BYTE_H_