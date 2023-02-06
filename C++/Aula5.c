/*
			Parametros para a função main
	Este programa mostra parametros da linha de comando
	char *argv 	- um asterisco mostra o apontador
	char **argv - com dois asterisco mostra o apontador para o apontador
	int argc 	- parametro inteiro que informa quantas palavras tem na linha de comando
	char **argv - este paramentro aponta par char*, o objeto argv[0]="args(\0)"					(\0) -> fim de string
															 argv[1]="um(\0)"
															 argv[2]="dois(\0)"
															 argv[3]="tres(\0)"
				  O parametro char** argv retira um nivel de indirecao. tratando diretamente com o caracter. Ex:
				  											 argv[3][1]="r(\0)" sendo um arrey bidimensional de caracteres.
	SHELL:	
	dudu@EdCury:~/Documentos/PUC/PPEE/Aulas/Aula5/Aula5/bin/Debug$ dir
	Aula5  Aula5.d	Aula5.o  main.d  main.o
	dudu@EdCury:~/Documentos/PUC/PPEE/Aulas/Aula5/Aula5/bin/Debug$ ./Aula5 um dois tres
 	argc = 4
 	argv(0) = "./Aula5"
 	argv(1) = "um"
 	argv(2) = "dois"
 	argv(3) = "tres"

	Exercíco:
	Escrever um programa que escreve as palavras da linha de comando convertendo letras minusculas para maiusculas,
	Obs: usando o header <ctype.h> pode-se usar a funcao int toupper(int) que converte um caracter de minusculo para maiusculo.
	no código ascii, 0x41 'A', 0x61 'a'
					 0x42 'B', 0x62 'b'
	Resolucao:
#include <ctype.h>
#include <stdio.h>
int main (int argc, char **argv)
{
	int i,j;
	printf("\n");
	for(i=0; i<argc; i++){
		for(j=0; argv[i][j]; j++){
		putchar(toupper(argv[i][j]));
		printf("");
		}
	printf("\n");
	}
	printf("\n");
	return 0;
}

	Exercicio:
	Escrever um programa que escreve linha de comando de tras para a frente.				 
*/
#include <ctype.h>
#include <stdio.h>
	/****************************************************************
	Mostra a linha de comando em letras maiúsculas PARTE 1
void escreve_maiuscula(char *txt)
{
	int c;
	while(*txt){
		if(c >='a' && c<='z'){
			c +='A'-'a';
		}
	putchar(c);
	}
}
	***************************************************************/
int main (int argc, char **argv)
{
	int i,j;
	printf("\n");
	for(i=argc; i=0; i--){
		for(j=argv[i][j]; j=0; j--){
		putchar(toupper(argv[i][j]));
		printf("");
		}
	printf("\n");
	}
	/****************************************************************
	Mostra a linha de comando em letras maiúsculas PARTE 2
	printf("\n");
	for(i=0; i<argc; i++){
		escreve_maiuscula(argv[i]);
	putchar(' ');
	}
	***************************************************************/
	/***************************************************************
	Este programa mostra parametros da linha de comando
	
	printf ("\n argc = %d", argc);
	for(i=0; i<argc; i++){
		printf ("\n argv(%d) = \"%s\"", i, argv[i]);
	}
	***************************************************************/
	printf("\n");
	return 0;
}

