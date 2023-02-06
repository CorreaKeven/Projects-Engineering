/* 
Programa que lê arquivo por linhas
Escreve o arquivo com numeros de linhas
*/

#include <stdio.h>
#include <errno.h>

#define TAMLINHA 200
int nlin(char *nomearq) //Escreve o arquivo com numeros de linhas, Retorna 0 se OK; -1 se erro
{
FILE *arq;
char linha[TAMLINHA]
int nlin;
nlin=0;
arq = fopen(nomearq, "r");
if(arq == NULL){
	perror(nomearq);
	return -1;
	}
do	{
	fgets(linha, TAMLINHA, arq);
	if(feof(arq)) break; //sai se fim do arquivo
	nlin++;
	printf("%4d %s", nin, linha);
} while(1);
fclose(arq);
return 0;
}


int main(int argc, char**argv)
{
char nomearq[80];
if(argc < 2){
	printf("\n Nome do arquivo = ", argv[0]);
	scanf("%80s",nomearq);
	nlin(nomearq);
	}
else 	{
	nlin(argv[1]);
	}
return 0;
}
