#include "randombyte.h"

uint8_t RandomByte::NextRandomByte() {
	int overflowBit;
	for(int i=0; i<8; ++i) {
		overflowBit= 0;
		if (SeedNo<0) {
			SeedNo= SeedNo^7779667;
			overflowBit= 1;
		}
		SeedNo= (SeedNo<<1) + overflowBit;
	}
	return (uint8_t) SeedNo;
}