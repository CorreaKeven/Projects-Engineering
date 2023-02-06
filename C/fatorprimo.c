#include <stdlib.h>
#include <stdio.h>

void fatorprimo(int num){
	int div;
	int s;
	s = 2;
	div = 2;
	while(div * div <= num){
		switch(div){
			case 2: div = 3;
			break;
			case 3: div = 5;
			break;
			default: div += s;
			s ^=(2 ^ 4);
			break;
			
		}
		
		
printf("%d *", div);
		}
	
	
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
	fatorprimo(num);
	return 0;	
}
