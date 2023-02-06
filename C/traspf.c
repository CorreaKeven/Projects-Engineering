/*PROGRAMA QUE ESCREVE A LINHA DE COMANDO DE TRAS PARA A FRENTE*/


#include <stdlib.h>
#include <stdio.h>

/*ESCREVE UM TEXTO DE TRAS PARA FRENTE*/
void traspf(char *txt)
{
	int i;
/*encontra o fim da string*/
for (i=0; txt[i]; i++);
/*Volta escrevendo de tras para frete*/
while (i--) putchar (txt[i]);
}

int main(int argc, char *argv[])
{
 int i;
 for (i=argc-1; i>=0; i--) {
	 traspf(argv[i]);
	 putchar(' ');
 }
 traspf("\n\r");
  return 0;
}
