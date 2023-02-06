/*
Escreva um programa em linguagem C chamado procuraarq.cpara procurar por um arquivo em um diretório, incluindo recursivamente os subdiretórios.
Este programa deve receber uma ou duas palavras adicionais na linha de comando, com a seguinte sintaxe: 

procuraarq <palavra procurada> [dir-inicial]

O programa deve verificar os nomes dos arquivos do [dir-inicial] em busca da <palavra procurada>. Se o nome do arquivo contiver esta palavra, o programa deve escrever este nome com o caminho de diretórios que leva até ele. Arquivos cujo nome não contem a palavra procurada não devem ser escritos.
Se o programa tiver sido chamado sem o [dir-inicial] na linha de comando, assume-se que o diretório inicial deve ser o diretório corrente ".".
A busca deve ser recursiva: A pesquisa deve ser feita também dentro dos subdiretórios.
Para verificar se a palavra procurada existe no nome do item de diretório pode-se usar a função strstr.
Para precorrer recursivamente os diretórios obtendo o nome de todos os arquivos, estude o programa feito na aula de 16/05/2012:

*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#ifdef unix
#define DIRBARRA '/'
#else
#define DIRBARRA '\\'
#endif
#define CMAX 1024

int procuraarq(char *palavra, char *nomedir)
{
char caminho[CMAX];
char buffer[CMAX];
DIR *sdir;
int k;
int ret=0;
struct dirent *itemdir;
struct stat statarq;	
sdir = opendir(nomedir);
if(sdir == NULL) return 1;
for(k = 0; nomedir[k]; k++)
	caminho[k] = nomedir[k];
caminho[k++] = DIRBARRA;
while((itemdir = readdir(sdir))!= NULL) 
{
	if(itemdir->d_name[0]=='.') continue;
	if(k + strlen(itemdir->d_name) + 1 >= CMAX) continue;	
	strcpy(caminho+k, itemdir->d_name);
	stat(caminho, &statarq);
	if(S_ISDIR(statarq.st_mode)) procuraarq(palavra,caminho);
	if(S_ISREG(statarq.st_mode)){
		strcpy(buffer,itemdir->d_name);
		if(strstr(buffer,palavra)!=NULL){
			ret=1;              
			printf("\n - Dir: \"%s\"", nomedir);
			printf("\n - Caminho: %s",caminho);
			}
		}
}
closedir(sdir);
return ret;
}

int main(int argc, char **argv)
{
int x;
printf("\n ---- Eduardo Cury Teixeira ---- \n ----       Trabalho 4      ---- \n");
printf(" ------------------------------- ");
if(argc < 2)
	printf("\n - Sintaxe: %s <palavra-procurada> <diretorio>\n",argv[0]);
else{
	if(argc == 2){
		x=procuraarq(argv[1],".");
		printf("\n - Arquivo procurado: %s\n",argv[1]);
	}
	if(argc == 3){
		x=procuraarq(argv[1],argv[2]);
		printf("\n - Arquivo procurado: %s\n",argv[1]);
	}
}
if(x == 0)
	printf(" - O Arquivo %s nao foi encontrado\n",argv[1]);        

printf(" ------------------------------- \n\n");
return 0;
}
