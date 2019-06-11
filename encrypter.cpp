#include "encrypter.h"

void Encrypter::encryptMemory (uint8_t * bufferPtr, int bufferSize) {
	for(int i=0; i< bufferSize;++i) {
		*bufferPtr= *bufferPtr^randomByte.NextRandomByte();
		bufferPtr++;
	}
}
