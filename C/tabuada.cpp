#include <stdlib.h>
#include <stdio.h>

main()
{  int n,n1,n2;

      printf("  Este programa mostra a tabuada de um numero qualquer de 1 ate 10\n\n Insira o numero: ");
      scanf("%d",&n1);
      
      for(n=0; n<=10; n++)
      {
            n2=n*n1;
               
            printf("\n%d x %d = %d  ",n1,n,n2);
            }
            system("pause");
            }
                 
