//Faça um programa para o cálculo de uma folha de pagamento, sabendo que os descontos são do Imposto
//e Renda, que depende do salário bruto (conforme tabela abaixo) e 3% para o Sindicato e que o FGTS
//corresponde a 11% do Salário Bruto, mas não é descontado (é a empresa que deposita). O Salário
//Líquido corresponde ao Salário Bruto menos os descontos. O programa deverá pedir ao usuário o valor
//da sua hora e a quantidade de horas trabalhadas no mês.
//? Desconto do IR:
//? Salário Bruto até 900 (inclusive) - isento
//? Salário Bruto até 1500 (inclusive) - desconto de 5%
//? Salário Bruto até 2500 (inclusive) - desconto de 10%
//? Salário Bruto acima de 2500 - desconto de 20%
//Imprima na tela as informações, dispostas conforme o exemplo abaixo.
//No exemplo o valor da hora é 5 e a quantidade de hora é 220.
//? Salário Bruto: (5 * 220) : R$ 1100,00
//? (-) IR (5%) : R$ 55,00
//? (-) INSS ( 10%) : R$ 110,00
//? FGTS (11%) : R$ 121,00
//? Total de descontos : R$ 165,00
//? Salário Liquido : R$ 935,00




#include <stdlib.h>
#include <stdio.h>

float calculo(float a,float b)

{      
float salariobruto,IR,INSS,FGTS,salarioliquido,totaldescontos;

      salariobruto=a*b;
      
if (salariobruto <= 900)
      {
      INSS=salariobruto*0.10;
      FGTS=salariobruto*0.11;
      totaldescontos=INSS;
      salarioliquido=totaldescontos;
      
      printf("Seu Salario bruto: %.00f\n",salariobruto);
      printf("Imposto de renda: Isento\n");
      printf("INSS : %.00f\n",INSS);
      printf("FGTS : %.00f\n",FGTS);
      printf("Total de descontos: %.00f\n",totaldescontos);
      printf("Salario Liquido: %.00f\n",salarioliquido);
      return(salariobruto);}
      
if ((salariobruto>900) && (salariobruto<1501)){

      IR=salariobruto*0.05;
      INSS=salariobruto*0.10;
      FGTS=salariobruto*0.11;
      totaldescontos=INSS+IR;
      salarioliquido=salariobruto-totaldescontos;
      printf("Seu Salario bruto: %.00f\n",salariobruto);
      printf("Imposto de renda:%.00f\n",IR);
      printf("INSS: %.00f\n",INSS);
      printf("FGTS : %.00f\n",FGTS);
      printf("Total de descontos: %.00f\n",totaldescontos);
      printf("Salario Liquido: %.00f\n",salarioliquido);
      return(salariobruto);}
      
if ((salariobruto>1500) || (salariobruto>2500))
{
      IR=salariobruto*0.10;
      INSS=salariobruto*0.10;
      FGTS=salariobruto*0.11;
      totaldescontos=INSS+IR;
      salarioliquido=salariobruto-totaldescontos;
      printf("Seu Salario bruto:R$ %.00f\n",salariobruto);
      printf("Imposto de renda:R$ %.00f\n",IR);
      printf("INSS: %.00f\n",INSS);
      printf("FGTS : %.00f\n",FGTS);
      printf("Total de descontos:%.00f\n",totaldescontos);
      printf("Salario Liquido: %.00f\n",salarioliquido);
      return(salariobruto);
      }
if (salariobruto >=2500)
     { IR=salariobruto*0.20;
      INSS=salariobruto*0.10;
      FGTS=salariobruto*0.11;
      totaldescontos=INSS+IR;
      salarioliquido=salariobruto-totaldescontos;
      printf("Seu Salario bruto: %.00f\n",salariobruto);
      printf("Imposto de renda:%.00f\n",IR);
      printf("INSS : %.00f\n",INSS);
      printf("FGTS : %.00f\n",FGTS);
      printf("Total de descontos: %.00f\n",totaldescontos);
      printf("Salario Liquido: %.00f\n",salarioliquido);
      return(salariobruto);
      ;}
}

main ()
{
     float horastrabalhadas,valordahora,calculo1;
     printf("\nEste programa calcula a folha de pagamento\n");
     printf("\nInsira quanto custa sua hora trabalhada: \n");
     scanf("%f",&valordahora);
     printf("\nInsira o numero de horas trabalhadas neste mes: \n");
     scanf("%f",&horastrabalhadas);
     calculo1=calculo(horastrabalhadas,valordahora);
     system("pause");
     
     
}
     
