/*Argumentos da linha de comando*/

#include <stdio.h>
/*argv[]   tambem serviria no lugar de **argv */
int main (int argc, char**argv)
{
	int i;
	printf("\n argc=%d\n",argc);
	
	for (i=0; i<argc;i++)
	{
		printf("argv[%d]=\"%s\"\n",i,argv[i]);
	}
	return 0;	
}
