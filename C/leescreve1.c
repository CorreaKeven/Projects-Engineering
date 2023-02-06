//*Redirecionamento de Entrada e Saida

#include <stdio.h>

int main()
{
int c;
while((c=getchar()) != -1) 
{
putchar(c);
}
return 0;
}
