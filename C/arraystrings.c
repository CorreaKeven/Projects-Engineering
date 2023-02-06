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
	
	char txt[]="Keven de souza Correa\n";
escreve(txt);
puts(txt); /* tambem printa  puts = 's' de string*/
escreve2(txt);


return 0;
}
