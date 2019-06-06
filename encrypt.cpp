#include <cstdio>
#include <cstdint>

#include "randombyte.h"
#include "binaryfile.h"

// TODO: extract the Encrypter class from this file

class Encrypter {
	RandomByte randomByte;

	public:
		void setSeed(int seed) {
			randomByte.Seed(seed);
		}

		void encryptMemory (uint8_t * bufferPtr, int bufferSize) {
			for(int i=0; i< bufferSize;++i) {
				*bufferPtr= *bufferPtr^randomByte.NextRandomByte();
				bufferPtr++;
			}
		}
};

void PrintUsage(char *filename) {
	printf("command format is %s <encryption key> filename",filename);
	puts("");
	puts("Where:-");
	puts("    encryption key - a 32 bit key in hexadecimal");
	puts("    filename - name of the file to be encrypted/decrypted");
}


int main(int argc, char *argv[]) {

	if (argc != 3) {
		PrintUsage(argv[0]);
		return 1;
	}

	BinaryFile binfile;

	if (binfile.ReadFile(argv[2])==-1) {
		puts("Error reading file.");
		return 1;
	};

	int userSeed;
	sscanf(argv[1], "%x", &userSeed);

	Encrypter encrypt;
	encrypt.setSeed(userSeed);
	encrypt.encryptMemory(binfile.getBufferPtr(), binfile.getBufferSize());

	binfile.SaveFile(argv[2]);

	return 0;

}