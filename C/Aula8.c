/*

Exemplo de numero 3 do programa do Pascal da Aula7		
Cria uma matriz na memoria com alocação dinâmica.

função alocamat
aloca memoria para uma matriz triangular inferior
*/

#include <stdio.h>
#include <stdlib.h>

int **alocamat (int nmax)
{
int **mat, lin, col;
//criando apontadores para as linhas
mat=(int **)malloc(nmax*sizeof(int *));
//Aloca memoria para cada linha
for(lin=0; lin <nmax; lin++){
	mat(lin)=(int *)malloc(lin+2)*sizeof(int);
}
return mat;
}

void pascal (int **mpas, int nmax)
{
int lin, col;
mpas [0][0]=1;
mpas [0][1]=1;
	for(lin=1; lin <nmax; lin++){
		mpas[lin][0]=1;
		for(col=1; col <=lin; lin++){
			mpas[lin][col]=mpas[lin-1][col-1]+mpas[lin-1][col];
		}
	mpas[lin][col]=0;
	}
}

void escrevemat(int **mat, int nmax);
{
int lin, col;
printf("\n");
for(lin=0; col<=lin; col++){
	printf("%5d", mat[lin][col]);
	}
	printf("\n");
	}
}

void libera(int **mat, int nmax)
{
	for(lin=1; lin <nmax; lin++){
	free(mat[lin]);
	}
free(mat);
}


int main(int argc, char **argv)
{
int n;
int **pas;
if(argc <=2)n=10;
else{
n=atoi(argv[1]);
}
pas=alocmat(n);
pascal=(pas,n);
escrevemat=(pas,n);
libera=(pas,n);
return 0;
}


