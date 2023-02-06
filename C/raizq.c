/* PPEE 10/08/2017 */
/* Funcao raiz quadrada */

#include <stdio.h>
#include <math.h>

int niter;

double raizq(double x)
{
	double r, rn;
	rn = 2.0;
	niter = 0;
	do	{
		niter++;
		r = rn;
		rn = (x/r + r)/2;
	} while(fabs(rn - r) > 1e-12);
	return rn;
}

int main()
{
	double x;
	printf("\nTabela de Raiz Quadrada\n");
	printf("%4s%18s%18s%8s\n",
		"x", "sqrt(x)", "raizq(x)", "niter");
	for( x = 0.0; x < 2.05; x += 0.1) {
		printf("%4.1lf%18.14lf%18.14lf%6d\n", 
		x, sqrt(x), raizq(x), niter);
	}
	return 0;
}