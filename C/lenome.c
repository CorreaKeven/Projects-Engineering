#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void traspf(char *txt){
	
	int i;
	for(i = 0; txt[i]; i++);
	while (i--){
		putchar(txt[i]);
		}
}


int main(int argc, char **argv)
{
	
traspf(argv[0]);
return 0;
}















/*
void lenomeinvertido(char *txt){
	
	int i;
	for(i = 0; txt[i]; i++);
	while (i--){
		putchar(txt[i]);
		}
}

int main (int argc*, char argv**) {
	
	int i;
	for (i = argc-1; i >= 0; i--){
		
		lenomeinvertido(argv[i]);
		putchar(' ');
	}
	lenomeinvertido("\n\r");
	return 0;
}

*/
