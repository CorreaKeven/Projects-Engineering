/*  Copia de um arquivo   */
/* COPYARQ copia  arquivo em disco..  */
#include <stdio.h>
#include <stdlib.h>
main (int argc, char *argv[])
{
  FILE *entr, *saida;  
  char ch;
  if (argc !=3) { printf ("Falta nome do arquivo \n");
                               exit (1);
                            }
  if ((entr=fopen (argv[1], "rb")) == NULL)
               {
                printf ("o arquivo entrada nao pode ser aberto\n");
                exit (1);
                }
  if ((saida=fopen (argv[2], "wb")) == NULL)
               {
               	printf ("o arquivo saida nao pode ser aberto\n");
               exit (1);
               }
  /*  copiando o arquivo   */
  while(!feof(entr))
               { 
               ch = getc (entr);
               if(ferror(entr)) {
                         printf("erro lendo o arquivo");
                                       break;
                                 }
               putc (ch, saida);
               if(ferror(saida)) {
                          printf("erro na gravacao do arquivo");
                                  break;
                                 }
               }
fclose (entr);
fclose (saida);
return 0;
}
