#include <stdio.h>
#include <stdlib.h>

void escrevebin(int num){
	int m; /*Mascasa que seleciona um bit*/
	for(m=1; m<=num; m=(m<<1));
	while((m= m>>1)){
		putchar((m & num)? '1':'0');
		}
}

void escrevenum(int num int base){
	int k=0;
	char digitos[20];
	do{
		digitos[k++]= (num % base) +'0';
		num =num /base;
	} while (num);
	while(k--) putchar(digitos[k]);
}

int main (int argc, char **argv)
{
int x;
if(argc>1){
	scanf(argv[1],"d",&x); /*Le x da linha de comando*/
}
else {
	printf("\nx="); /*se nao tem linha de comando */
	scanf("%d",&x); /*Solicita x em modo interativo*/
}
printf("\n x= %d (decimal) = 0x%X (hexadecimal\n)",x,x);
escrevebin(x);
printf(" (binario)\n");
escrevenum(x,10);
return 0;	
}


