

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


main ()
{

char num;

do {
printf("\nInsira um numero: \n");
num=getche();
}
while ( num>48 && num>57);

printf("Voce digitou : %c\n",num);

system("pause");
}
