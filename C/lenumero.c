/*programa que le numero*/
#include <stdio.h>
#include <stdlib.h>

void escrevenumero(int num){
	
	static const char *numeros[] = 
	{
	"zero","um","dois","tres","quatro","cinco","seis","sete","oito","nine"};
	if(num > 9) return;
	printf(numeros[num]);
}



int main(int argc, char **argv)
{
	int x;
	if(argc < 2){
		fprintf(stderr,"Sintaxe:\n%s <numero>\n",argv[0]);
		return -1;
	}
	/*x = atoi(argv[1]);*/
	sscanf(argv[1],"%d",&x);
	printf("\nx=%d\n",x);
	escrevenumero(x);
	printf("\n");
	return 0;
	
}
