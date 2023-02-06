/*
Trabalho PPEE
Eduardo Cury Teixeira

*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int k, d, m, a, ds, sim;

//********************
void inserir_data(){
//printf(" FUNCAO INSERIR_DATA -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);
printf(" Gostaria de inserir outra data (1=sim)? ");
scanf("%d",&sim);	
	if(sim != 1)
	getchar();
	else{
				
		printf(" Por favor, insira Dia, Mês e Ano: ");
		scanf("%d %d %d",&d, &m, &a);		
		checa_data();			
	}
//printf(" FUNCAO INSERIR_DATA 2 -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);
}
//********************
void func_fevereiro()
{
int ano;
ano=a;
//printf("\n FUNCAO FEVEREIRO 1 -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);  
if (m==2 && d>28)
	{
	if((d==30)||(d==31)){
		printf(" O mês em questão (%d) não tem %d dias.\n",m,d);
		inserir_data();	
		}
	if(d==29){
			if(ano%4!=0 || ano==2000){
			printf(" O ano em questão (%d) não é um ano bissexto, portanto não tem 29 dias.\n",a);
			inserir_data();
			}
		}
	}
else{

}
}

void checa_data()
{
//printf("\n FUNCAO CHECA DATA -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);  
	if(((m==2 && d>28) || (m==4 || m==6 || m==9 || m==11) && (d==31)) || (d>31 || m>12 || a<1900)){
	{
		if((m==2 && d>28))
		func_fevereiro();	
		if((m==4 || m==6 || m==9 || m==11) && d==31)
		{
			printf("O mês em questão (%d) não tem 31 dias.\n",m);
			inserir_data();	
		}
		if(d>31 || m>12 || a<1900 ||d<1 || m<1)
		{
			printf(" Ops, data inválida. ");
				if(d>31)
				printf("O dia inserido (%d) é maior que 31. ",d);
				if(d<1)
				printf("O dia inserido (%d) é menor que 1. ",d);
				if(m>12)
				printf("O mês inserido (%d) é maior que 12. ",m);
				if(m<1)
				printf("O mês inserido (%d) é menor que 1. ",m);
				if(a<1900)
				printf("O ano inserido (%d) é menor que 1900.", a);
			printf("\n");	
			inserir_data();	
			}
		}
	}
}
//********************
void calcula_data()
{
a -= 1900;
		if(m<3) //Se o mes é janeiro ou fevereiro (m < 3) some 12 ao mes e subtria 1 do ano
		{
			m=m+12;
			a=a-1;
		}
		k=d+2*m+(3*m+3)/5+a+a/4+1;
		ds = (k % 7);			
//printf(" FUNCAO CALCULA_DATA -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);  
}
//********************
void diasem ()
{
a += 1900;
//printf(" FUNCAO DIASEM -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);  

	if(ds<=6 && ds>=0)
	{
		printf(" O dia solicitado ");
		if((a>=2012)&&((m==4 && d>=19) || m>4))
			printf("será um");
		else{
			printf("foi um");	
			}
	}	
	if(ds==0)
		printf("a segunda-feira, %d/",d);
	if(ds==1)
		printf("a terça-feira, %d/",d);
	if(ds==2)
		printf("a quarta-feira, %d/",d);
	if(ds==3)
		printf("a quinta-feira, %d/",d);
	if(ds==4)
		printf("a sexta-feira, %d/",d);
	if(ds==5)
		printf(" sabado, %d/",d);
	if(ds==6)
		printf(" domingo, %d/",d);

//printf(" FUNCAO DIASEM -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);  
}
//********************
void diames ()
{
//printf("\n FUNCAO DIAMES -> D %d, M %d, A %d, K %d, DS %d\n",d, m, a, k, ds);  
if(a!=-1 && (m<=14 && m>=1))
	{
	if(m==13)	printf("JAN/%d \n",a+1);
	if(m==14)	printf("FEV/%d \n",a+1);
	if(m==3)	printf("MAR/%d \n",a);
	if(m==4)	printf("ABR/%d \n",a);
	if(m==5)	printf("MAI/%d \n",a);
	if(m==6)	printf("JUN/%d \n",a);
	if(m==7)	printf("JUL/%d \n",a);
	if(m==8)	printf("AGO/%d \n",a);
	if(m==9)	printf("SET/%d \n",a);
	if(m==10)	printf("OUT/%d \n",a);
	if(m==11)	printf("NOV/%d \n",a);
	if(m==12)	printf("DEZ/%d \n",a);
	}
}
//********************
int main(int argc, char **argv)
{	
	system("clear");
	ds = 9;	
	printf("\n Aluno: Eduardo Cury Teixeira\n ----- Trabalho 2 -----\n\n");	
	if(argc == 4){
	d = atoi(argv[1]);
	m = atoi(argv[2]);
	a = atoi(argv[3]);
	}
	if(d==0 && m==0 && a==0){
		printf(" Não foi inserida nenhuma data.\n");
		printf(" Por favor, insira Dia, Mês e Ano: ");
		scanf("%d %d %d",&d, &m, &a);
	
	}			 	
	checa_data();	
	calcula_data();
	diasem ();
	diames ();
	printf("\n");
return 0;
}

	
