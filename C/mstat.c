/*Programa mstat
	Pega informacoes sobre um arquivo*/
#include <stdio.h>  // cabeçalho
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>

void escreve_data(time_t tempo){
	struct tm *dh;
	dh = localtime(&tempo);
	printf("%02d/%02d/%04d ",dh->tm_mday,dh->tm_mon+1, dh->tm_year +1900);
	return;
	}

		
int escrevestat(char *nomea)
{
	struct stat mst;
	int ret;
	ret = stat(nomea, &mst);
	if(ret){ //Tratamento de erro
	perror("stat"); //
		return ret;
	}
	
	printf("\n Nome do arquivo: \"%s\"\n",nomea);
	printf("\nTamanho do arquivo: %u\n",
		(unsigned)mst.st_size);
		printf("\nModificado em : ");
		escreve_data(mst.st_mtime);
return ret;	
}

	
int main(int argc, char **argv)
{
	char *nomearq;
	char nome[80];
	if(argc >1) { /*o nome esta' e, argv[1]*/
	nomearq= argv[1];
	} else {
		printf("\nNome do arquivo = ");
		scanf("%80s", nome);
		nomearq = nome;	
	}
	
	escrevestat(nomearq);
	return 0;
}
