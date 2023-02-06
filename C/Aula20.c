/* 

Programa que busca e substitui palavras num texto

./Aula20 <palavra_procurada> <palavra_substitui>

*/


#include <stdio.h>

int substitui(char *procurada, char *substituta, FILE *entra, FILE *sai)
{
int k;						//índice na palavra procurada
int c;						//caractere obtido no arquivo de entrada
char palavra[200];
k=0;
do	{
	c = fgetc(entra);
	if(c == EOF) 
		break; 			//-1 = EOF (indicador de fim de entrada)
	if(k>196) 
		k=196; 			//protege contra buffer overflow
	if(c == procurada[k]) {
		palavra[k++] = c;	
		if(palavra[k]=='\0'){ 		//se a palavra procurada chegou a fim com todas as letras coincidindo
			fputs(substituta, sai);	//Escreve a substituta
			k=0;
		}
	}
	else	{ //letras diferentes
		palavra[k++] = c;
		fwrite(palavra,1,k,sai);		//escreve letras acumuladas
		k=0;
	}
} while(1);
return 0;
}

int main(int argc, char **argv)
{
FILE *entrada, *saida; //strings de entrada e saída
entrada = stdin;
saida = stdout;
if(argc<3){
	fprintf(stderr, 
		"\nSintaxe:\n%s <palavra procurada>" 
		"<palavra substituta>\n", argv[0]);
	return 1;
	}
return substitui(argv[1], argv[2], entrada, saida);
}
