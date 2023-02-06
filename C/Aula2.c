/*
Primeiro Programa de PPEE
Eduardo Cury Teixeira
*/

#include <stdio.h>

int main(void)
{
int i;
char c;
unsigned char uc;
    uc = 80;
    i = uc;
    printf("\n c = %d", i);
    uc = uc+80;
    i = uc;
    printf("\n c+80 = %d \n ", i);
    return 0;
           
}
/*

   -> char            - 8bits    - 1byte, intervalo de números:   -128 até 127
   -> unsigned char   - 8bits    - 1byte, intervalo de números:      0 até 255
   -> short           - 16bits   - 2byte, intervalo de números: -32768 até +32767
   -> unsigned short  - 16bits   - 2byte, intervalo de números:      0 até 65535
   -> int			  - 32bits*  - 4byte, intervalo de números:  - 2³¹ até 2³¹ -1
   -> unsigned int	  - 32bits*  - 4byte, intervalo de números:      0 até 2³²
   -> unsigned long	  - 32bits*  - 4byte 
   -> long long 	  - 64bits*  - 8byte  
      
   * o int pode variar de acordo com a arquitetura do computador
  
   
   		EXPRESSÕES ARITIMÉTICAS E LÓGICAS:
   
   Constantes Inteiras:
   		Número decimal 		49
   		Hexadecimal			0x31
   		Caractere ASCII 	'1'
   		
    Operadores: Operações prioritárias, Multiplicação e divisão
    	* 	Multiplicação
    	/ 	Divisão
    	+ 	Soma
    	- 	Subtração
    Operações Relacionais
    	> 	Maior
    	< 	Menor
    	>= 	Maior Igual				onde, 
    	<=	Menor Igual				0 -> Falso
    	== 	Igual					1 -> Verdadeiro
    	!=	Diferente
    	
    	Exemplo:
    	int x, y;
    	x = 23;
    	y = 4 + (x == 23);
    	Qual o valor de y? 5, pois x == 23 é TRUE, enão y = 4 + (1)
    	
    	Divisão
    	int x, y;
    	x = 3;
    	y = 2 * x/2;
    	Qual o valor de y? 3
*/