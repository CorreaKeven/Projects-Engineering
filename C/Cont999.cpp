#include <stdio.h>       /// Escreva um algoritimo que leia um numero inteiro entre 100 e 999 e imprima na saida cada um dos algarismos que compoem o numero espaçadamente
#include <stdlib.h>

main ()
{
int cont, a, b, c;
printf("Este programa transforma um numero em CDU\n");
printf("Insira um valor inteiro entre 100 e 999: ");
scanf("%i",&cont);

a=cont/100;
b=(cont-(a*100))/(10);
c=cont-(a*100)-(b*10);

printf("\no valor digitado foi: %i sua centena e: %i sua dezena e: %i sua unidade e: %i\n",cont,a,b,c);
system("pause");
return 0;
}
