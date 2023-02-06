#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
/* Header local do projeto */
#include "ledir.h"

int ledir(char *nomedir)
{
char caminho[CAMINHOMAX];	/* diretorio com o nome do arquivo */
DIR *sdir;
int k;	/* Local na strig de caminho*/
struct dirent *itemdir;
struct stat statarq;
printf("\nDir: \"%s\"\n", nomedir);
sdir = opendir(nomedir);
if(sdir == NULL) return 1;
for(k = 0; nomedir[k]; k++) caminho[k] = nomedir[k];
caminho[k++] = DIRBARRA;	/* DIRBARRA=='/' ou '\\' */
while((itemdir = readdir(sdir))!= NULL) {
	if(itemdir->d_name[0]=='.') continue;
/* Testar para evitar buffer overflow */
	if(k + strlen(itemdir->d_name) + 1 >= CAMINHOMAX) continue;
	strcpy(caminho+k, itemdir->d_name);
	stat(caminho, &statarq);
	if(S_ISDIR(statarq.st_mode)) ledir(caminho);
	if(S_ISREG(statarq.st_mode)) printf("ARQ");
	printf("%8lu %s\n", statarq.st_size, caminho);
	}
closedir(sdir);
return 0;
}
