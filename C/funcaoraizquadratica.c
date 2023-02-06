/*PPEE 10/08/2017*/
/*FUNCAO RAIZ QUADRATICA*/

#include<stdio.h>
#include<math.h>

int main()
{
	double x;
	printf("\nTabela de Raiz Quadrada\n");
	printf("%4s%18s\n","x","sqrt(x)");
	for (x=0.0;  x<=2.0; x+=0.1){
		printf("%4.1lf%18.14lf\n",x,sqrt(x));
	}
	
	return 0;
}
