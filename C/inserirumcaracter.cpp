//Programa *insira um caracter do alfabeto.


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


main ()
{

char letra;

do {
printf("\nInsira um caracter do alfabeto: \n");
letra=getche();


} while((letra<65) || (letra>90 && letra<97) || (letra>122));

printf("\nVoce digitou: '%c'\n",letra);
system("pause");

}
;


