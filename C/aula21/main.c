/**********************************
Programa principal do projeto dirmake
***********************************/

#include "ledir.h"
#include <stdio.h>

int main(int argc, char **argv)
{
if(ledir(argc < 2? ".": argv[1])!= 0) {
	perror(argv[0]);
	return 1;
	}
return 0;
}
