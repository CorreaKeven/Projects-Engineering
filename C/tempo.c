/* Estrutura de tempo */
#include <stdio.h>
#include <string.h>

struct tempo {
	int hora;
	int minuto;
	int segundo;
};

/* Declaracao inicializada */
struct tempo inicio = {12, 45, 20 };

void escreve_tempo(struct tempo *pst)
{
	printf(" %02d:%02d:%02d ", 
		pst->hora, pst->minuto, pst->segundo);
}

void ajusta_hora(struct tempo *pst)
{
	if(pst->segundo > 59) {
		pst->minuto += pst->segundo/60;
		pst->segundo %= 60;
	}
	if(pst->minuto > 59) {
		pst->hora += pst->minuto/60;
		pst->minuto %= 60;
	}
	if(pst->hora > 23) {
		pst->hora %=24;
	}
}	

void soma_segundos(struct tempo *pst, int seg)
{
	pst->segundo += seg;
	ajusta_hora(pst);
}

int main()
{
	struct tempo agora, fim;
	agora.hora = 19;
	agora.minuto = 59;
	agora.segundo = 0;
	printf("\nAgora = ");
	escreve_tempo(&agora);
	printf("\nInicio = ");
	escreve_tempo(&inicio);
	/* copiar os dados do inicio no fim */
	memcpy(&fim, &inicio, sizeof(inicio));
	soma_segundos(&fim, 1000);
	printf("\nFim = ");
	escreve_tempo(&fim);
	return 0;
}