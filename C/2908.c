#include <stdlib.h>
#include <stdio.h>
void escrevenum(int n){
	static char *numeros[] = {
	"zero","um","dois","tres","quatro",
	"cinco","seis","sete","oito","nove",
	"dez","onze","doze","treze","quatorze","qinze"};
	
if(n > 15) return;

printf(numeros[n]);	
}


int main(int argc,char **argv)
{
	int num;
	if (argc < 2){
		printf("\nnum= ");
		scanf("%d",&num);
	}
	else{
		sscanf(argv[1],"%d",&num);
		
	}
	escrevenum(num);
	return 0;	
}
