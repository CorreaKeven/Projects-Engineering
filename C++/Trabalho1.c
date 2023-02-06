/*
Eduardo Cury Teixeira

Escreva uma função em linguagem C para calcular o arco-seno de um número. Esta função deve ter o seguinte protótipo

double logn(double x);

Esta função deve calcular a função logaritmo natural (base e) usando apenas as 4 operações aritméticas básicas, sem usar funções da biblioteca.

O programa principal faz um diálogo com o usuário solicitando um valor de x, e calculando em seguida o valor do logn(x) uasndo a função solicitada e comparando com o logaritmo obtido com a função log(x)da biblioteca padrão do C.

Se x for negativo ou zero o programa deve terminar com uma mensagem.
*/

/*
#include <stdio.h>
#include <math.h>

int main ()
{
	double x;
	double logn(double x);
	//y=M_LN2;
	printf(" Ln de %.2lf: %lf \n",x,loge(x));
	return 0;
}

*/


#include <stdio.h>
#include <math.h>

double logn(double x)
{
double k, soma=0;
double p, p1, p2, p3, div=1;
p=((x-1)/(x+1));
p1=(p);
p2=(p*p);
p3=0;
//printf("x = %.lf, \np1 = %lf, soma = %lf\n", x, p, soma);
for(div=1; div<=100000; div=div+2){
	soma=(p1/div)+soma;
	//printf("p%.lf %.14lf,p%.lf %.14lf, p%.lf %.14lf, soma %.14lf\n",div, p1, div+1, p2, div+2, p3, soma);		
	p1=(p1*p2);
	} 	
	k = 2*(soma);
	return k;
}

int main(int argc, char **argv)
{
double x, y;
int sim=1;
printf("\n Aluno: Eduardo Cury Teixeira\n\n ----- Trabalho 1 -----");
while(sim==1){
	sim=0;
	printf("\n Numero a ser calculado: ");
	scanf( "%lf", &x );
	y=logn(x);
		if(x>0){
			printf("\n Ln de %.lf: %20.14lf,\n Com log: %20.14lf, conforme a tabela.",x,y,log(x));
		}
		else{
			printf(" Numero a ser calculado deve ser maior que ZERO. \n");
			return 0;		
		}
		printf("\n Calcular um novo valor(1-Sim)? "); 			
		scanf( "%i", &sim );
		if(sim!= 1){
			printf("\n");			
			return 0;
		}	
	}
return 0;
}
