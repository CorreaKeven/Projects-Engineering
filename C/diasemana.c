#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int formulaK( int d, int m, int a){
	return (d + 2*m + (3*m + 3)/5 + a + a/4 + 7001);  // formula para data.
}


int main( int argc,  char** argv)
 {
/*argc – é um valor inteiro que indica a quantidade de argumentos.*/
/*argv – é um vetor de char que contém os argumentos*/


int d;  // dia
int m; // mes
int ano; // ano
int a; // ano-1900
int bisexto = 0; //bisexto
int ds; // dia da semana

		  //jan fev mar abri mai jun jul agt set out nob dez.
int dias_mes[] =  { 31, 28, 31, 30,  31, 30, 31, 31, 30, 31, 30, 31 } ; 
char *dia_sem[] = { "Segunda", "Terca", "Quarta","Quinta", "Sexta", "Sabado", "Domingo"};
char *mes_ano[] = { "Janeiro", "Feveiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };




//entrada de dados
printf("Ola, Este programa informa o dia da semana decorrente da data informada.\n");
printf("Informe o dia,mes e ano respectivamente\n");
scanf("%d %d %d", &d, &m, &ano);


char* mes = mes_ano[m-1]; 

a = ano-1900; 	// conforme regra: subtrair 1900 do ano.

if( (a % 4) == 0 )    //se o modulo do ano for igual a 0 ele e bisexto
{ 
	bisexto = 1;
	dias_mes[1] = 29;
}  


//validação da entrada  
int error = 0;

if( d < 1 || d > dias_mes[m-1] )	
{	
	printf("Por favor insira um dia valido.\n");
	error = 1;
}

if( m < 1 || m> 12)
{
	printf("Por favor insira um mes valido.\n");
	error = 2;
}

if ( error != 0 ){
	return -1;
}

	
if( m < 3 )
{
	m+=12;
	a--;
}

int k = formulaK(d,m,a);

ds = ( k % 7 );

char* dia = dia_sem[ds];

// imprimi resultados

printf("%s, %d de %s de %d",dia,d,mes,ano);

if(bisexto==1)
{	
	printf(", %d e bisexto\n",ano);	
}
else {
	printf(", %d nao e bisexto\n",ano);
}

}
