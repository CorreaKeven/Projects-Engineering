/*Estrutura de tempo*/

#include <stdio.h>
#include <string.h>
#include <time.h>

void escreve_data(struct tm *data)
{
	printf("%02d/%02d/%02d/", data->tm_day, data->tm_mon + 1, data->tm_year + 1900);
return	
}


int main(void)
{
do {
	time_t tempo;

struct tm *dh; /* data e hora fracionada */

tempo= time(NULL);
//printf("\n Tempo = %d segundos desde 1,1,1970\n",tempo);

escreve_data(dh);
printf("%02d:%02d:%02d\r", dh->tm_hour, dh->tm_min,dh->tm_sec);

sleep(1)
} while(1);
return 0;
}


