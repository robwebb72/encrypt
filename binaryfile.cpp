#include <cstdio>
#include <sys/stat.h>
#include <cstdint>
#include <cstdlib>

#include "binaryfile.h"


BinaryFile::BinaryFile() {
	buffer = 0L;
	bufferSize = 0;
}


BinaryFile::~BinaryFile() {
	if (buffer!=nullptr) delete buffer;
}


void BinaryFile::SaveFile(char * filename) {
	FILE * file;
	if ( (file = fopen(filename, "wb")) ) {
// todo: handle issue if fwrite fails (i.e. it returns anything other than bufferSize)
		fwrite( buffer, sizeof(uint8_t), bufferSize, file);
		fclose( file );
	}
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
		if ( (file = fopen(filename,"rb")) ) {
			buffer = new uint8_t[bufferSize];
// todo: deal with the case when new fails
			fread( buffer, sizeof(uint8_t), bufferSize, file );
// todo: what to do if fread fails?
			fclose( file );
			return 0;
		}
	}
	return -1;
}