/* 
Programa arqinfo.c
Lista os arquivos de um diretório

*/

#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#ifdef unix
#define DIRBARRA '/'
#else
#define DIRBARRA '//'
#endif


int ledir(char *nomedir)
{
char caminho[1024];
DIR *sdir;
int k;
struct dirent *itemdir;
struct stat statarq;
printf("\nDir: \"%s\"\n", nomedir);
sdir = opendir(nomedir);
printf("\n\033[01;35mA\033[01;37m/\033[01;34mD\033[01;37m   Size    Local\033[22;37m\n");
if (sdir == NULL) return 1;
for(k=0; nomedir[k]; k++)
	caminho[k]=nomedir[k];
caminho[k++]=DIRBARRA;
while((itemdir = readdir(sdir)) != NULL){
	if(itemdir-> d_name[0] =='.') continue;
	
	strcpy(caminho+k, itemdir->d_name);
	stat(caminho, &statarq);
	if(S_ISDIR(statarq.st_mode)) printf("\033[01;34mDIR\033[22;37m");
	if(S_ISREG(statarq.st_mode)) printf("\033[01;35mARQ\033[22;37m");	
	printf("%8lu   %s\n",statarq.st_size, caminho);
}
closedir(sdir);
return 0;
}

int main(int argc, char **argv)
{

if(ledir(argc < 2? ".": argv[1]) != 0);
printf("\n");
return 0;
}
