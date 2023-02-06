/* 
Estruturas de dados

Programa teste de estruturas de dados

*/

#include <stdio.h>
#include <stdlib.h>

struct aluno{		//struct aluno funciona como um tipo de dados
	char nome[22];
	int nmat;
	int nota_ppee;
	};	//instância

void escreve_dados_aluno(struct aluno *pal)
{
system("clear");
printf("\n---- Dados do Aluno ----\n");
printf("- Nome: %s", pal->nome);
printf("- Mat.: %d\n", pal->nmat);
printf("- Nota: %d\n", pal->nota_ppee);
printf("------------------------\n");
}

int main(int argc, char**argv)
{
char buf[20];
struct aluno aluno1; 	//aluno1 com var local tipo struct aluno
printf("Nome = ");
fgets(aluno1.nome, 22, stdin);
printf("Matrícula = ");
//scanf("%d\n", &(aluno1.nmat));
fgets(buf, 20, stdin);
aluno1.nmat = atoi(buf);
aluno1.nota_ppee = 10;
//printf("Nome = %s", aluno1.nome);
//escrita usando uma função como passagem de dado por apontador (por referência)
escreve_dados_aluno(&aluno1); 	//&Variavel - Endereço da variável, apontador para variável.
return 0;
}

