/*

Entrada/saída de dados e arquivos (Streams)

Streams padrão:
	
	descritor		Stream
				apontador para
	numero inteiro		uma estrutura
	que especifica		tipo file definida
	um arquivo aberto	no <stdio.h>
				

	0			stdout	>	Saída padrão   (console)
	1			stdin	<	Entrada padrão (console)
	2			stderr	2>	Saída de erro  (console)

	
	./Aula9 < Aula9.c		//Redireciona a entrada stdin para um arquivo
					//Getchar pega dadps dp arquivo Aula9.c


	./Aula9 > saida.txt		//Redireciona a saída para um arquivo
	
	./Aula9 < Aula9.c > saida2.txt	//copia arquivo de entrada (Aula9.c) para arquivo de saida (saida2.txt)
	
	dir | ./Aula9			//dir -> pede diretorio, | pipe -> conecta a saida de um comando com a entrada do 2º comando
					//dir | Aula9 -> programa irá receber os dados dir.
	
	dir | ./Aula9 > saida.txt 	//escreve o dir no programa de saida

	./Aula9 >> saida.txt		//anexa dados ao final do arquivo

#include <stdio.h>
#include <ctype.h>
int main()
{
int c;
do	{
	c = getchar();
	c = toupper(c);	
	if (c<0) break;	
	putchar(c);
	}while(1);	
return 0;
}

**************************

Programa que le um arquivo e escreve na saida padrao
Usando as strings de modo geral
*/

#include <stdio.h>
/********************************
Recebe o nome do arquivo
Le o arquivo e escreve em stdout
Retorna 0 em caso de sucesso
********************************/

int escrevearq(char *nomearq)
{
int c;
FILE *arq;          /* Stream do arquivo */
arq = fopen(nomearq, "r");    /* Abre para leitura */
if(arq == NULL) {
       perror("Abrindo o arquivo");
       return -1;      /* fim com fracasso */
       }
while((c = fgetc(arq)) != -1) {
         putchar(c);   /* escreve o caractere lido */
         }
fclose(arq);           /* fecha arquivo */
return 0;              /* fim com sucesso */
}

int main(int argc, char **argv)
{
if(argc < 2) {
        fprintf(stderr, "\nSintaxe:\n%s <nome-do-arquivo>\n",
                        argv[0]);
        return 1;
        }
escrevearq(argv[1]);
return 0;
}

