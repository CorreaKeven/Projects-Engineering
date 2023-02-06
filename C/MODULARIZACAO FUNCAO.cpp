//Gere um programa que receba cinco valores numericos e aprensente a sua médie. Crie uma funcao que receba esses valores e calcule a media

#include <stdio.h>
#include <stdlib.h>

float media1(float a, float b, float c, float d, float e)
{
     float media;
      media=(a+b+c+d+e)/5.0;
      return(media);
      }
      
 main()
{
     float num_1,num_2,num_3,num_4,num_5,med;
     printf("Este programa calcula a media de 5 numeros respectivamente\n");
     printf("\nInforme os 5 numeros:\n");
     scanf("%f %f %f %f %f",&num_1,&num_2,&num_3,&num_4,&num_5);
     med=media1(num_1,num_2,num_3,num_4,num_5);               //CHAMADA A FUNÇÃO.
     printf("\nA media destes numeros e %.3f\n",med);

system("pause");

}
