/*
		Arrays e Apontadores
	\" -> Barra reversa retira do elemento seguinte a função especial, no caso, imprime as aspas
*/

#include <stdio.h>

void escrevetexto (char *txt)
{
	int i;
	for(i=0; txt[i]; i++){
		putchar(txt[i]);
		}
}

void escrevetexto2 (char *txt)
{
	while(*txt) putchar(*txt++);
}


int main ()
{
	/*
	char *pc; 											// Apontador para char
	char ac[40];										// Array de char com 40 lugares	
	char str[]="String1";								// Array de caracteres inicializado 
	int k;
	/*printf("str = \"%s\"\n", str);
	for(k=0; k<8; k++){
		printf("str[%d] = %c = 0x%02X\n", k, str[k], (int)str[k]);
	}*/
	//printf("%s",str+3);
	char str[]="string2\n";
	escrevetexto("\n Aula4 \n");
	escrevetexto(str);
	escrevetexto2(str);
	return 0;
}

