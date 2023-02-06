/* 
Procurar substring dentro de um arquivo

1. Verificar inf da linha de comnando
2. Abrir arq de entrada

palheiro	int n = numero de letras que coincidiram, -> Var local

Salada de abacate com abobora e abacaxi
Palheiro abacaxi -> a, n=0; b, n=1; a, n=2; c, n=3; a, n=4; 

procurar por "abacaxi" -> Abacaxi "agulha"

subrotina para substituir strstr
char *strstr (char *palheiro, char *agulha)
n=0

| Se panheiro[n] == '\o' retorna com palavra não encontrada.
| compara palheiro[n] com agulha[n]
| nao coincidiu
| { pahleiro++; n=0 }
coincidiu
n++;
verificar se chegou no fim da agulha
se agulha[n]=='\0'
sim -> Encontrou a palavra -> retorno da função. (palavra encontrada)
não continua (retorna para primeira linha)


*/

#include <stdio.h>
#include <errno.h>
#define TAMLINHA 200

/* Procura por numero em uma linha de texto */

void procuranums(char *txt)
{
int c, ca;
ca=0;
while((c = *txt++)!=0) {
	if(c >= '0' && c <= '9') 
		putchar(c); c = -10;
	if(ca == -10 && c != -10) 
		putchar(' ');
	ca = c;
	}
}

/* Procura numeros em um arquivo */

int procuranum(FILE *arq)
{
char linha[TAMLINHA];
do	{
	fgets(linha, TAMLINHA, arq);
	procuranums(linha);
	} while(!feof(arq));
putchar('\n');
return 0;
}

int main(int argc, char **argv)
{
FILE *arq;
if(argc < 2) {
/* Se falta o nome do arquivo, usa a entrad padrao */
	arq = stdin;
	}
else	{
	arq = fopen(argv[1], "r");
	if(arq == NULL){
		perror(argv[0]);
		return 1;
		}
	}
procuranum(arq);
fclose(arq);
return 0;
}


