#include <cstdint>

class BinaryFile {

		uint8_t *buffer;
		int bufferSize;
		int GetFileSize(char * filename);
		
	public:
		BinaryFile();
		~BinaryFile();
		void SaveFile(char * filename);
		int ReadFile(char * filename);

		inline uint8_t * getBufferPtr() { return buffer; }
		inline int getBufferSize() { return bufferSize; }
};
