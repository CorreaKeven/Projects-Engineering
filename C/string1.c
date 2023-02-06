#include <stdio.h>
#include <ctype.h>

void escreve(char *txt)
{
	int i;
	for(i = 0; txt[i]!='\0'; i++){
		putchar(toupper(txt[i]));
	}
}

void escreve2(char *txt)
{
	while(*txt) putchar(*txt++);
}

int main()
{
	char txt[]="string de teste\n";
	escreve(txt);
	escreve2(txt);
	puts(txt);
	putchar(txt[3]);
	return 0;
}