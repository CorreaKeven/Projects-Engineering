/*

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TM 24
#define TAMLINHA 512


char * le_linha(FILE *arq) {

char *buf;
char *tmp;
int le_char = 0;
int tam_buf = TAMLINHA;
char *linha = malloc(tam_buf);

if ( !linha ) {
return NULL;
}
buf = linha;
	while ( fgets(buf, tam_buf - le_char, arq) ) {			
		le_char = strlen(linha);
		if (linha[le_char - 1] == '\n') {
			linha[le_char - 1] = '\0';
			return linha;
			}
		else{
			tam_buf = 2 * tam_buf;
			tmp = realloc(linha, tam_buf);
			if ( tmp ) {
				linha = tmp;
				buf = linha + le_char;
			}
			else {
			free(linha);
			return NULL;
			}
		}
	}
return NULL;
}
//************
void escreve(char palavra[200], char texto[200])
{
FILE *arq;
int nlin =0, sim=0;
char *linha;
arq = fopen(texto, "r");
//printf("ESCREVE 1 - Texto: %s - Palavra: %s \n", texto, palavra); 
system("clear");
printf(" ---- Eduardo Cury Teixeira ---- \n ----       Trabalho 3      ---- \n");
printf(" ------------------------------- \n");
printf(" - Procurado: \n");
	while ((linha = le_linha(arq))) {
		nlin++;		
		if ( strstr(linha, palavra) != NULL){
			fprintf(stdout, " - %d: ",nlin);
			fprintf(stdout, "%s\n", linha);
			sim++;
			}
		}
		if (sim==0){
		printf(" - Não foi possível encontrar a palavra \"%s\" no texto. \n", palavra);

//	printf("ESCREVE 2 - Texto: %s - Palavra: %s \n", texto, palavra); 
	free(linha);
	}
//printf("ESCREVE 3 - Texto: %s - Palavra: %s \n", texto, palavra); 
}
//************
int main(int argc, char *argv[]) {
char texto[TM], palavra[TM];
FILE *arq;
system("clear");
printf(" ---- Eduardo Cury Teixeira ---- \n ----       Trabalho 3      ---- \n");
printf(" ------------------------------- \n");
if(argc>=2)
strncpy(palavra, argv[1], TM);
if(argc<3){
	if(argc<2){
	printf(" - Não foi possível encontrar a palavra procurada.\n - Qual a palavra a ser procurada? ");
	gets(palavra);
	printf(" - Não foi possível encontrar o texto.\n - Qual o texto a ser procurado? ");
	gets(texto);
	arq = fopen(texto, "r");
	}
	else{
	printf(" - Não foi possível encontrar o texto.\n - Qual o texto a ser procurado? ");
	gets(texto);
	arq = fopen(texto, "r");
	}
}
else{
strncpy(texto, argv[2], TM);
arq = fopen(texto, "r");
}
while (arq == NULL)
{
printf(" - Não foi possível encontrar o texto.\n - Qual o texto a ser procurado? ");
gets(texto);
arq = fopen(texto, "r");
printf(" -\n");
}
escreve(palavra, texto);
printf(" ------------------------------- \n");
printf(" - Texto: %s\n - Palavra: %s \n", texto, palavra); 
printf(" ------------------------------- \n\n");
return 0;
}
