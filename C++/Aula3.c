/*
			Função Seno
	Função seno -> sin(x)
	Fazer uma tabela da função sin(x)
	
	Implementação de uma função:
	Uso -> Chamada dentro de uma expressão, os parâmetros podem ser expressões aritméticas.
	
	Definição (implementações)
	[Tipo de dado retornado] [nome da função] (parâmetros, )
	double seno (double x)
	{
		implementação
		....
		return resultado;
	}
	
	Para implementar uma função seno usaremos a Série de McLaurin
	sen(x)= x/1! - x³/3! + x⁵/5! - x⁷/7! ...
	modo Picareta:
	sen(x)= x/1! - x³/6 + x⁵/120 - x⁷/5040 ...
	
	dudu@EdCury:~/Documentos/PUC/PPEE/Aulas/Aula3/Aula3$ gcc -o Aula3 Aula3.c -lm -Wall
dudu@EdCury:~/Documentos/PUC/PPEE/Aulas/Aula3/Aula3$ ./Aula3

   x              sin(x)             seno(x)                erro
 0.0    0.00000000000000    0.00000000000000    0.00000000000000
 0.1    0.09983341664683    0.09983341664683    0.00000000000000
 0.2    0.19866933079506    0.19866933079506    0.00000000000000
 0.3    0.29552020666134    0.29552020666134   -0.00000000000000
 0.4    0.38941834230865    0.38941834230865   -0.00000000000000
 0.5    0.47942553860420    0.47942553860420    0.00000000000000
 0.6    0.56464247339504    0.56464247339504    0.00000000000000
 0.7    0.64421768723769    0.64421768723769    0.00000000000000
 0.8    0.71735609089952    0.71735609089955    0.00000000000003
 0.9    0.78332690962748    0.78332690962764    0.00000000000016
 1.0    0.84147098480790    0.84147098480866    0.00000000000076

*/
#include <stdio.h>
#include <math.h>

double seno(double x)
{
double soma, termo, x2;
int k;
x2 = x*x;
soma = termo = x;
k = 1;
do	{
	k += 2;
	termo = - termo * x2 /k /(k-1);
	soma += termo;
	} while(k < 12);
return soma;
}

int main()
{
double x;
printf("\n%4s%20s%20s%20s\n", "x", "sin(x)", "seno(x)", "erro");
for(x = 0.0; x < 1.0; x += 0.1) {
	printf("%4.1lf%20.14lf%20.14lf%20.14lf\n", x, sin(x), seno(x), seno(x)-sin(x));
	}
return 0;
}




/*

				Números em Ponto Flutuante
	Tipos:
		Float (%f)  -> Precisão simples -> 4 Bytes (32bits)		IEEE 754 Define as características
		Double (%jf)-> Precisão dupla -> 8 Bytes (64bits)		dos números em Ponto Flutuante. 
	- -	- - - -	- - - -	- - - -	- - - -	- - - -	- - - -	- - - -	- - - -	- - - -	- - - -	- - - -	- - 
	mantissa x 2^(expoente de 2)
	Obs: Há sinal na mantissa (+-) e no expoente de 2 (+-)
	%1.2lf -> Onde 1 = Largura do campo e 2 são os dígitos depois do campo

	
		int main ()
{
double x;
	for(x = 0.0; x<1.0; x+=0.1){
		printf("x=%4.1lf\n",x);
	}
	return 0;
}

			
*/