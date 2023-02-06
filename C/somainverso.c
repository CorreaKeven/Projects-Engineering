#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double somainv(int n)
{
	double soma = 0;
	int k;
	for(k=1; k<=n; k++) {
		soma+=1.0/k;
	}
	return soma;
}
int main(void)
{
int n;
	
printf("Boa Noite\nEste programa faz o somatorio dos inversos\n");
printf("Insira um valor inteiro : ");
scanf(" %d",&n);
printf("somainv=%lf\n",somainv(n));

return 0;

}
