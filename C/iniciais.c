#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
	
	int i;
	
	for(i = 1; i < argc; i++)
	{
		printf("%c. ",toupper(argv[i][0]));		
	}
	return 0;
}
