#include "stdlib.h"

int main(char** argc, int argv){
	int f = open("/dev/stdout", 0);
	write(f, "Hello, World!\n", 14);
	//_exit(0);
	return 0;
}
