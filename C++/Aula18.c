/* 
Programa arqinfo.c
Lista os arquivos de um 

int main (int argc, char **argv)
{
DIR *sdir
struct dirent *itemdir;
sdir = opendir(argc < 2? ".": argv[1]);
if (sdir == NULL) {
	perror(argv[0]);
	return 1;
while((itemdir = readdir(sdir)) != NULL){
	if(itemdir-> d_name[0])=='.') continue;
	printf("%s\n", itemdir->d_name);
closedir(sdir);
return 0;
}

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
int ledir(char *nomedir)
{
DIR *sdir;
struct dirent *itemdir;
struct stat statarq;
printf("\n Dir: \"%s\"\n", nomedir);
sdir = opendir(nomedir);
if (sdir == NULL) return 1;
while((itemdir = readdir(sdir)) != NULL){
	if(itemdir-> d_name[0] =='.') continue;
	stat(itemdir->d_name, &statarq);
	if(S_ISDIR(statarq.st_mode)) printf("DIR");
	if(S_ISREG(statarq.st_mode)) printf("ARQ");	
	printf("%8lu %s\n",statarq.st_size, itemdir->d_name);
}
closedir(sdir);
return 0;
}

int main(int argc, char **argv)
{
if(ledir(argc < 2? ".": argv[1]) != 0)
return 0;
}
