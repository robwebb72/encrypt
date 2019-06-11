#include <cstdio>
#include <sys/stat.h>
#include <cstdint>
#include <cstdlib>
#include <new>


#include "binaryfile.h"


BinaryFile::BinaryFile() {
	buffer = nullptr;
	bufferSize = 0;
}


BinaryFile::~BinaryFile() {
	if (buffer!=nullptr) delete buffer;
}


uint8_t * BinaryFile::AllocMemory(int numberOfBytes) const {
	uint8_t * buffptr;
	try {
		buffptr = new uint8_t[bufferSize];
	} catch(std::bad_alloc& ba) {
		buffptr = nullptr;
	}
	return buffptr;
}

int BinaryFile::SaveFile(char * filename) {
	FILE * file;
	if ( (file = fopen(filename, "wb")) ) {
		if(fwrite( buffer, sizeof(uint8_t), bufferSize, file)!= bufferSize) {
			fclose( file );
			return -1;
		};
		fclose( file );
		return 0;
	}
	return -1;
}


int BinaryFile::GetFileSize(char * filename) {
	struct stat info;
	if( stat(filename, &info) == -1) {
		return -1;
	}
	return info.st_size;
}


int BinaryFile::ReadFile(char * filename) {

	bufferSize = GetFileSize(filename);
	if ( bufferSize != -1 ) {
		FILE * file;
		buffer = AllocMemory(bufferSize);
		if ( buffer != nullptr ) {
			if ( (file = fopen(filename,"rb") ) ) {
				int elementsRead = fread( buffer, sizeof(uint8_t), bufferSize, file );
				fclose( file );
				if (elementsRead != bufferSize) return -1;
				return 0;
			}
		}
	}
	return -1;
}
