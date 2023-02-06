#include <stdlib.h>
#include <stdio.h>


void escreve(char *txt)
{
 while(*txt) putchar(*txt++);
 
	}


int main(int argc, char *argv[])
{
 int i;
 for (i=1; i<argc; i++) {
	 escreve(argv[i]);
	 putchar(' ');
 }
 escreve("\r\n");
  return 0;
}
