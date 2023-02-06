#include <stdio.h>

/* Escreve um texto de tras para a frente */
void traspf(char *txt)
{
int i; /* Indice */
/* Percorre o texto sem escrever ate achar o fim */
for(i = 0; txt[i]; i++);
while(i--) {
           putchar(txt[i]);
           }
}

int main(int argc, char **argv)
{
int i;
putchar('\n');
for(i = argc - 1; i > 0 ; i-- ){
      traspf(argv[i]);
      putchar(' ');
      }
putchar('\n');
return 0;
}
