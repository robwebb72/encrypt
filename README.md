# encrypt

Encrypt is a very simple file encryption command line utility written in C++ as a learning tool.

It takes 2 inputs:-

- a 32bit hexadecimal number as a seed for a random number generator
- the name of a file to be encrypted

It reads the file into memory and sets the random number seed.
For each of the file's bytes loaded, it XOR's that byte with the next byte from the random number generator.  The encrypted buffer is the written over the original file.

