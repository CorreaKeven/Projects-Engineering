#include <stdio.h>
int main()
{
	int R0=0, R1=1, R2=2, cont =1;
    printf("Serie de Fibonacci Crescente");
	printf("\n%do numero = %d",cont, R0);            
    while(R0<1000000)
    {
            
            R0 = R1;
			R1 = R2;
            R2=R0+R1;
            cont=cont++;
            printf("\n%do numero = %d",cont, R0);            
    }

     if(R0>1000000)
 	printf("\n\nSerie de Fibonacci Decrescente");
    {
            while(R0!=1)
            {
            R0 = R2-R1;
			R2 = R1;
			R1 = R0;
			printf("\n%do numero = %d",cont, R0);                     
    		cont=cont--;
    		}
    		if(R0=1)
    		{
			R0=0;    
			printf("\n%do numero = %d",cont, R0);                
    		}
    }
    
    return 0;
}
