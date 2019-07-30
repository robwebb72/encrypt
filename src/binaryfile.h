#ifndef BINARY_FILE_H_
#define BINARY_FILE_H_

#include <cstdint>

class BinaryFile {

		uint8_t *buffer;
		int bufferSize;
		int GetFileSize(char * filename);
		uint8_t *AllocMemory(int numberOfBytes) const;
	public:
		BinaryFile();
		~BinaryFile();
		int SaveFile(char * filename);
		int ReadFile(char * filename);

		inline uint8_t * getBufferPtr() { return buffer; }
		inline int getBufferSize() { return bufferSize; }
};
#endif // BINARY_FILE_H_