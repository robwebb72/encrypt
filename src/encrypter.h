#ifndef ENCRYPTER_H_
#define ENCRYPTER_H_

#include "randombyte.h"

class Encrypter {
	RandomByte randomByte;

	public:
		inline void setSeed(int seed) {randomByte.Seed(seed);}
		void encryptMemory (uint8_t * bufferPtr, int bufferSize);

};
#endif // ENCRYPTER_H_