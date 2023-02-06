//*Redirecionamento de Entrada e Saida

#include <stdio.h>
#include <ctype.h>

int main()
{
int c;
while((c=getchar()) != -1) 
{ c=toupper(c);
putchar(c);
}
return 0;
}
