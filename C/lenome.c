/*Constante Strin*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void escreve(char *txt)
{
	int i;  /*indice inteiro*/
	for (i=0; txt[i]!='\0';i++){
		putchar(toupper(txt[i]));  /*toupper transforma em maiusculas as  strings*/
	}
}
void escreve2(char *txt)/* funcao escreve2*/{
	while(*txt) putchar(*txt++);  /*aponta para o endereco de memoria txt e verifica se e verdadeiro ou seja verifica se a alguma string no endereco*/
}
#define NOMEMAX 80


int main()
{ 
int i;
int x=123;
char nome[NOMEMAX];
int y=456;
printf("\nNome = ");
fgets(nome, NOMEMAX,stdin);
for (i=0;(i < NOMEMAX-1) && (nome[i] >= ' '); i++);
	nome[i]= '\0';
	
	printf("\nBoa noite \"%s\"!\n",nome);
printf("x=%d; y=%d\n",x,y);
return 0;
}
