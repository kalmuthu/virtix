#include "stdio.h"
#include "stdlib.h"

int main(char** argv, int argc){
	FILE* f = open("/dev/null", 0);
	
	print("Mash some keys! > ");

	for(;;)
		printf("%c", fgetc(stdin));

	return 0;
}