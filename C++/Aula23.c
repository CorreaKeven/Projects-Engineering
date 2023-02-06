/* Exercício para a Prova

Tópicos:
1 - Funções:
Tarefa:
Escreva uma função double raizq(double x) que usa este algoritmo para calcular a raiz quadrada.
Escreve um programa principal que testa esta função.

A raiz quadrada de um numero pode ser calculada usando um método interativo:

Seja N o numero do qual se quer calcular a raiz. x⁰ valor da aproximação inicial.

x¹ = ((n/x⁰) + x⁰)/2

Quando x^(n+1)= ((n/x^n)+ x^n)/2

x^(n+1) é praticamente igual a x^n, 

x^(n+1) = Raiz(n)

--------------------------------------------------------------------------------------------------------

1. Escreva  um programa que escreve quantas letras tem em cada palavra da linha de comando.
Escrever em cada linha a palavra e o numero de letras correspondente. Exemplo:
> nletras um dois tres
nletras	7
um 	2
dois 	4
tres 	4

--------------------------------------------------------------------------------------------------------

Escreva um programa chamado lebun que recebe um numero binario na linha de comando.
Se faltar o informa a sintae desejada.
Escreve o resultado como um numero decimal e hexadecimal

--------------------------------------------------------------------------------------------------------
#Makefile
Um programa tem os arquivos main.x e subrotinas.c e o makefile em um diretório. 
O makefile é o seguinte:

CC = gcc
COPT = -Wall
OBJETOS = main.o subrotinas.o
all : prog.exe
%.o : %.c
	$(CC) $(COPT) -c -o $@ $<
prog.exe: $(OBJETOS)
	$(CC) $(COPT) -o prog.exe $(OBJETOS)
clean:
	rm -f $(OBJETOS)

Que comandos são gerados quando se escreve:

	$(CC) $(COPT) -C -O $@ $<
$(CC) 	= gcc
$(COPT) = -Wall
-c 	= -c
-o	= -o
$@ 	= Arquivo gerado = main.o
$<	= Arquivo final	 = main.c

resultado: gcc -Wall -c -o main.o main.c

resultado: gcc -Wall -c -o subrotinas.o subrotinas.c


	$(CC) $(COPT) -C -O $@ $<
$(CC) 	  = gcc
$(COPT)   = -Wall
-o	  = -o
prog.exe  = prog.exe
(OBJETOS) = main.o subrotinas.o

resultado: gcc -Wall -c -o main.o main.c


--------------------------------------------------------------------------------------------------------

#Makefile
ALVO = prog2
COPT = -Wall
all: $(ALVO)

$(ALVO): main.c
	gcc $(COPT) -o $ALVO main.c
*/



/*
-----------------------------------------------------------------------------------------------------------------------------

CALCULA TAMANHO DO ARQUIVO.

#include <stdio.h>

int main (int argc, char **argv)
{
FILE *arq;
int n; 
if(argc < 2) {
	fprintf(stderr, "Sintaxe>\n%s <nome-do-arquivo>\n", argv[0]);
	return 1;
	}
arq = fopen(argv[1], "r");
if(arq == NULL) {
	perror(arqv[0]);
	return 2;
	}
n = 0;
while(fgetc(arq)!= -1) n++;
fclose(arq);
printf("\nO arquivo %s tem %d bytes\n", argv[1], n);
return 0;
} 

-----------------------------------------------------------------------------------------------------------------------------
*/

/*

1) Escreva um programa chamado numlinhas, que recebe dados da entrada padrão e escreve uma mensagem que diz quantas linhas de texto foram recebidas
2) Escreve uma linha de comando que usa o programa numlinhas para descobrir quantos arquivos tem no diretório /etc

resposta 2: ls -l /bin | nimlinhas 

comando para determinar o numero de linhas do arquivo numlinhas.c: numlinhas < numlinhas.c
< recebe o arq. numlinhas.c na entrada padrão.

NUMERO DE LINHAS DE TEXTO RECEBIDAS NA ENTRADA PADRÃO:

*/

#include <stdio.h>

int main (int argc, char **argv)
{
int nlin;
int c;
while((c=getchar()) != -1){
	if(c == '\n') nlin++;
	}
printf("\n Foram recebidas %d linhas\n", nlin);
return 0;
}
