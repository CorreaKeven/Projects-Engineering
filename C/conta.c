//*Redirecionamento de Entrada e Saida

#include <stdio.h>

int main()
{
int c;
int nbytes=0;
int nlinhas=0;
while((c=getchar()) != -1) 
{
	nbytes++;
	if (c == '\n') nlinhas++;
}
printf("\n Foram recebidos %d Bytes\n",nbytes);
printf("%d linhas\n", nlinhas);
return 0;
}
