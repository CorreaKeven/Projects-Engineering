/* 
Escreva um programa chamado lebin.c que lê um numero binario
especificado na linha de comando e escreve este numero 
na forma decimal equivalente.

#include <stdio.h>
int lebin(char *str)
{
int n, c;
n = 0;
do	{
	c=*str++;
	if ((c!='0')&&(c!='1')) break;
	n=2*n + (c-0);
	} while (1);
if (( c!='\n')&&( c!='\0')&&( c!='\r'))
printf(" Dígito inválido: \'%c'\n", c);
return n;	
}

int main(int argc, char**argv)
{
int num;
char texto[80];
if(argc < 2){
	printf("\n Sintaxe: %s numero_binário\n", argv[0]);
	printf("\n n = ");
	fgets(texto, 80, stdin);
	num = lebin(texto);		
	return 1;
	}
else num = lebin(argv[1]);
printf("\n n = %d\n", num);
return 0;
}



com base

*/

/*************************************
PPEE 25/04/2012
Programa que le arquivo por linhas
Escreve o arquivo com numeros de linhas
***************************************/

#include <stdio.h>
#include <errno.h>
#define TAMLINHA 200

/* Escreve o arquivo com numeros de linha */
/* Retorna 0 se OK; -1 se teve erro */
int nlin(char *nomearq)
{
FILE *arq;	/* stream do arquivo */
char linha[TAMLINHA];	/* Linha de texto do arquivo */
int nlin;	/* numero da linha */
nlin = 0;
arq = fopen(nomearq, "r");
if(arq == NULL) {
	perror(nomearq);
	return -1;
	}
do	{
	fgets(linha, TAMLINHA, arq);
	if(feof(arq)) break;	/* Sai se fim do arquivo */
	nlin++;
	printf("%4d %s", nlin, linha);
	} while(1);
fclose(arq);
return 0;
}

int main(int argc, char **argv)
{
char nomearq[80];
int res;
if(argc < 2) {
	printf("\nNome do arquivo = ");
	scanf("%80s", nomearq);
	res = nlin(nomearq);
	}
else	{
	res = nlin(argv[1]);
	}
return res;
}

