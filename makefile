OBJECT_FILES = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

encrypt : $(OBJECT_FILES)
	@g++ -o encrypt $(OBJECT_FILES)
	@cp test_orig.txt test.txt
	@echo Build completed.

encrypter.o : encrypter.cpp encrypter.h
	@g++ -c encrypter.cpp

randombyte.o : randombyte.cpp randombyte.h
	@g++ -c randombyte.cpp

binaryfile.o : binaryfile.cpp binaryfile.h
	@g++ -std=c++11 -c binaryfile.cpp

encrypt.o : encrypt.cpp randombyte.h binaryfile.h encrypter.h
	@g++ -c encrypt.cpp

.PHONY : clean
.IGNORE : clean

clean :
	@rm -f $(OBJECT_FILES) 
	@rm -f encrypt
	@echo Project cleaned.