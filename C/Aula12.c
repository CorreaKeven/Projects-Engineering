/* 

	Programa escreve de decimal para Binário.

esrevebin numero_decimal

O Programa deve ler um numero decimal na 2ª palavra da linha de comando e escrevelo como um numero binário de 32 Bits

#include <stdlib.h>
#include <stdio.h>
void escrevebin(int num)
{
int k;
printf(" ");
k=31;
while(k >= 0){
	if(num & (1 << k)) putchar('1');
	else putchar('0');
	if((k & 3)==0) putchar('.'); //   (k & 3) -> Agrupa em grupos de 4
	k --;	
	}
}

int main(int argc, char**argv)
{
int x;
if(argc < 2){
	fprintf(stderr, "\n Sintaxe: %s numero\n", argv[0]);
	return 1;
	}
x=atoi(argv[1]);
printf("\n Numero lido = %d (decimal)\n",x);
escrevebin(x);
printf(" bin\n\n");
return 0;
}


Programa para escrever numero 1000000000 em binário


#include <stdio.h>
int main(int argc, char**argv)
{
int x;
x= 1000000000;
printf("\n x = %d\n", x);
printf("\n 2*x = %d\n", 2*x);
printf("\n 3*x = %d\n", 3*x);
printf("\n 4*x = %d\n", 4*x);
return 0;
}
*/

#include <stdlib.h>
#include <stdio.h>
void escrevebin(int num)
{
int k;
for(k = 32; k--; num<<=1) putchar(num < 0 ? '1':'0');
}

int main(int argc, char**argv)
{
int x;
if(argc < 2){
	fprintf(stderr, "\n Sintaxe: %s numero\n", argv[0]);
	return 1;
	}
x=atoi(argv[1]);
printf("\n Numero lido = %d (decimal)\n",x);
escrevebin(x);
printf(" bin\n\n");
return 0;
}
