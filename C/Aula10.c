/*	Tipos de variáveis em C

Variáveis globais:
	Declara fora de todas as funções. Alocada durante toda a execução do programa e visível para todas as funções:
Parâmetros da função:
	Variáveis locais:
	- Declaradas dentro da função
	- Memória alocada na pilha, Aloca no início da execução da função.	
	- Desaloca no fim da função.
	- Nome definido apenas dentro da função
	Variável local Estática (atributo static)
	- Declarada dentro da função com atributo static
	- Não é desalocada entre uma chamada e outra
	- Visível somente dentro da função
	ex:
	#include <stdio.h>
	
	int conta_chamadas(void)
	{
	static int conta=0;
	conta ++;
	return conta;
	}
	int main()
	{
	int c;	
	do {
		c=getchar();
		printf("N = %d\n",conta_chamadas());
	} while(1);
	return 0;
	}

	
	Atributo const -> constante
	- Variável com atributo const só tem valor inicializadona declaração.
	- Não pode ser modificada pelo programa.
	static const char *unidade[]={"zero", "um"};
	-> char, tipo básico		0	1
	-> *unidade string == apontador para char -> O compilador define a dimensão com base na inicialização
	-> [] dimensão omitida
	Exemplo:	
	puts(unidade[1]);

******************************************************************************************************************************

	Exercício:
Decompor um número em fatores primos.

Fazer uma função
Void fatorprimo(int num) -> escreve o numero decomposto em fatores primos.
onde:
num 	-> valor a ser fatorado
fatorp	-> Inicia com 2
void fatorprimo(int num)
{
	int fatorp=2;
	int N = num/fatorp;
	while(N>fatorp){
		
		if ((num/fatorp)*fatorp == num)
		{
			num = num/fatorp;
			printf("%d \n", fatorp);
			if((num/fatorp)==fatorp){
			printf("%d \n", fatorp);
			}		
		}
		else
		{
			fatorp ++;
		}
	}

		
}

int main()
{
	int n;
	printf("\n Valor do número = ");
	scanf("%d",&n);
	fatorprimo(n);
	return 0;
}

******************************************************************************************************************************

Escrever uma lista de todos os numeros primos menores que (valor especificado na linha de comando) ou 1000
Método da Peneira de Eratostenes (sieve of Eratosthenes)
funciona fazendo um mapa de bits de todos os numeros:
2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37

o numero 1 não é primo
o dois é primo por definição e o único primo par
2 é primo, então retirar os numeros multiplos de 2 -> 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 ...
sobra:
x  3  x  5  x  7  x  9  x  11 x  13 x  15 x  17 x  19
x  21 x  23 x  25 x  27 x  29 x  31 x  33 x  35 x  37
3 é primo, então retirar os numeros múltiplos de 3 -> 3 6 9 12 15 18 21 24 27 30 33 36 ...
sobra:
x  x  x  5  x  7  x  x  x  11 x  13 x  x  x  17 x  19
x  x  x  23 x  25 x  27 x  29 x  31 x  x  x  35 x  37
5 é primo, então retirar os números múltiplos de 5 -> 5 10 15 20 25 30 35 ...
sobra:
x  x  x  x  x  7  x  x  x  11 x  13 x  x  x  17 x  19
x  x  x  23 x  x  x  27 x  29 x  31 x  x  x  x  x  37
7 é primo, então retirar os números múltiplos de 7 -> 7 14 21 28 30 37 ...
sobra:
x  x  x  x  x  x  x  x  x  11 x  13 x  x  x  17 x  19
x  x  x  23 x  x  x  27 x  29 x  31 x  x  x  x  x  x 

*/

#include <stdio.h>

void fatorprimo(int num)
{
	int fatorp=2;
	int N = num/fatorp;
	while(N>fatorp){
		
		if ((num/fatorp)*fatorp == num)
		{
			num = num/fatorp;
			printf("%d \n", fatorp);
			if((num/fatorp)==fatorp){
			printf("%d \n", fatorp);
			}		
		}
		else
		{
			fatorp ++;
		}
	}

		
}

int main()
{
	int n;
	printf("\n Valor do número = ");
	scanf("%d",&n);
	fatorprimo(n);
	return 0;
}
