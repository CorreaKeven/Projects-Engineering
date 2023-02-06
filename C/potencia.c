#include <stdio.h>
#include <stdlib.h>

double potencia(double x, int n)
{
	double xn; /* x elevado a n*/
	int neg;   /* indice que n e negativo*/
	
	neg =(n<0);
	if(neg) n= -n;
	xn =1.0;
	
	while(n--){
		xn =xn * x;
	}
	return(neg? 1.0/xn: xn);
}

int main() {
	
	double x;
	int k;
	printf("\nx= ");
	scanf("%lf", &x);
	printf("k= ");
	scanf("%d", &k);
	printf("%lf elevado a %d= %lf\n", x, k, potencia(x ,k));
	return 0;
}
