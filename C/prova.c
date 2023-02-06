#include <stdlib.h>
#include <stdio.h>
#include <stype.h>



void soletraOTAN(char *txt){
int k,c; /*INDICE DO ARRAY TXT[K]*/
static const char *letrasOTAN[]={
"Alpha","Bravo","Charly","Delta","Eco","Foxtrot","Golf","Hotel","India","Juliet",
"Kilo","Lima","Mike","November","Oscar","Papa","Quebec","Romeo","Sierra","Tango",
"Uniform","VIctor","Whiskey","Xray","Yoga","Zulu"}

for(k=0; txt[k] ;k++)
{	c=toupper(txt[k]); /* PEGA LETRA CONVERTENDO PARA MAIUSCULO*/
if(c>='A' && c<='Z'){ /*Se é letra */
if(k) putchar('-');
printf("%s",letrasOTAN[c-'A']); /* Escreve nome da letra*/
}
}
}

int int main(int argc, char **argv){
	int i;
	for(i=1; i<argc; i++){
		soletraOTAN(argv[i]);
	printf("\n");/*Nova Linha*/}
	return 0;		
	}	
}