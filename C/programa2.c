/*********************
PPEE programa 2
Keven Correa
***********************/

#include <stdio.h>

int main()
{
	int i;
	printf("\nNumeros de 0 a 9\n");
	printf("%2s %4s\n", "i","i*i");
	for(i = 0; i < 10; i++) {
		printf("%2d %4d\n", i, i*i);
	}
	return 0;
}