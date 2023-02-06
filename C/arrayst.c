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
int main()
{ 
int x=123;
char nome[10];
int y=456;
printf("\nNome = ");
gets(nome);
printf("\nBoa noite \"%s\"!\n",nome);
printf("x=%d; y=%d\n",x,y);
return 0;
}
