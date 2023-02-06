/*
		Alocação dinâmica de memória
	Ex: Triangulo de Pascal
	
	coluna
	0   1   2   3   4   5   6   7   8
 linha	  
   0    1
   1    1   1
   2    1   2   1  
   3    1   3   3   1
   4    1   4   6   4   1  
   5    1   5   10  10  5   1  
   6    1   6   15  20  15  6   1
   7    1   7   21  35  35  21  7   1
   8    1   8   28  56  70  56  28  8   1

Regra:
um determinado elemento em relação ao vizinho de cima e um vizinho de cima a esquerda;

Coeficientes binominais,
Ex: Coef. Binomiais (3 8), (n m)    onde n -> linha, e n -> coluna
Pn,m = (n!)/(m!(n-m)!)
Pn,m+1 = ((n-m)/(m+1))*Pn,m

Escreva um programa para escrever o triangulo de pascal. Recebe na linha de comando o numero de linas, se numero de linhas 
faltar ou for inválido use 10 linhas.
Ex:

#include <stdio.h>
void pascal (int nlin)
{
int lin, col, p;	
	for (lin=0; lin < nlin; lin++){
	p=1;		
		for (col=0; col <= lin; col++){
 		printf(" %6d", p);
		p=p*((lin-col)/(col+1));
		}
	printf("\n");
	}
}

int main (int argc, char **argv)
{
int n;
printf("\n Triangulo de pascal\n Numero de linhas: ");
if(argc < 2) n = 10;
else{
	n = atoi(argv[1]);
}
pascal(n);
return 0;
}



Exemplo alocando a linha:
#include <stdio.h>
void pascal (int nlin)
{
int lin, col, p1[20], p2[20];
p1[0]=1; p1[1]=0;	
	for (lin=0; lin < nlin; lin++){
		p2[0]=1;
		for (col=0; col <= lin; col++){
			p2[col]=p1[col-1]+p1[col];
		}
		for (col=0; col<=lin; col++);{
			printf("%5d", p2[col]);
			p1[col]=p2[col];
		}
		p1[lin+1]=0;
		printf("\n");
	}
}

int main (int argc, char **argv)
{
int n;
printf("\n Triangulo de pascal\n Numero de linhas: ");
if(argc < 2) n = 10;
else{
	n = atoi(argv[1]);
}
pascal(n);
return 0;
}



Exemplo alocando a linha dinâmicamente:

*/

#include <stdio.h>
#include <string.h>

void pascal (int nlin)
{
int lin, col, *p1, *p2;
p1 = malloc((nlin+1)*sizeof(int));
p2 = malloc((nlin+1)*sizeof(int));
p1[0]=1; p1[1]=0;	
	for (lin=0; lin < nlin; lin++){
		p2[0]=1;
		for (col=0; col <= lin; col++){
			p2[col]=p1[col-1]+p1[col];
		}
		for (col=0; col<=lin; col++);{
			printf("%5d", p2[col]);
			p1[col]=p2[col];
		}
		p1[lin+1]=0;
		printf("\n");
	}
}

int main (int argc, char **argv)
{
int n;
printf("\n Triangulo de pascal\n Numero de linhas: ");
if(argc < 2) n = 10;
else{
	n = atoi(argv[1]);
}
pascal(n);
return 0;
}
