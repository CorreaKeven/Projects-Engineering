/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define cursor_off     0x0c
#define cursor_on      0x0e
#define cursor_blink   0x0f

#define rs_0			GPIOA -> BRR = 1<<9
#define rs_1			GPIOA -> BSRR = 1<<9
#define en_0			GPIOC -> BRR = 1<<7
#define en_1			GPIOC -> BSRR = 1<<7


#define inc	 	(GPIOC->IDR & (1<<6))
#define dec  	(GPIOC->IDR & (1<<5))
#define enter 	(GPIOB->IDR & (1<<15))


#define pb5_0 GPIOB->BRR = 1<<5 			/*PB5(D4) on/off */
#define pb5_1 GPIOB->BSRR = 1<<5
#define pb4_0 GPIOB->BRR = 1<<4 			/*PB4(D5) on/off */
#define pb4_1 GPIOB->BSRR = 1<<4
#define pb10_0 GPIOB->BRR = 1<<10 			/*PB10(D6) on/off */
#define pb10_1 GPIOB->BSRR = 1<<10
#define pa8_0 GPIOA->BRR = 1<<8 			/*PA8(D7)*/
#define pa8_1 GPIOA->BSRR = 1<<8


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

 const unsigned char tab_char[64] =
 {
  0x0e, 0x1b, 0x04, 0x04, 0x07, 0x10, 0x0e, 0x00,
  0x0e, 0x04, 0x0e, 0x15, 0x17, 0x11, 0x0e, 0x00,
 };
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

    void lcd_wrcom4(uint8_t com4);
	void lcd_wrcom(uint8_t com);
	void lcd_wrchar(unsigned char ch);
	void lcd_wr2dig(uint8_t val);
	void lcd_init(uint8_t cursor);
	void lcd_goto(uint8_t x, uint8_t y);
	void lcd_wrstr(char *str);
	void udelay(void);
	void delayus(uint16_t tempo);
	int __io_putchar(int ch);
	void lcd_clear();
	void lcd_backlight(uint8_t backlight);
	void rele1_on(void);
	void rele1_off(void);
	void rele2_on(void);
	void rele2_off(void);
	void lcd_progchar(void);



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	int fputc(int ch, FILE * f)
	{
	 lcd_wrchar(ch);
	 return ch;
	}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int h, m, s, hh=0, mm=0, ss=0, prog=0, hora_ini=0, duracao=0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  lcd_init(cursor_on);
  lcd_clear(0x01);
  lcd_goto(0,0);
  lcd_wrchar('L');
  lcd_wrchar('[');
  lcd_wrchar(' ');
  lcd_wrchar(']');
  lcd_goto(0,1);
  lcd_wrchar('C');
  lcd_wrchar('[');
  lcd_wrchar(' ');
  lcd_wrchar(']');
  lcd_progchar();

  lcd_goto(7,0);
  lcd_wrchar(0);
  lcd_goto(13,0);
  lcd_wrchar(1);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if(enter == 0)
	  {
	  	HAL_Delay(300);
	  	prog++;
	  }

	  if(prog==0)
	  {
		  lcd_goto(8,1);
		  lcd_wr2dig(hh);
		  lcd_wrchar(':');
		  lcd_wr2dig(mm);
		  lcd_wrchar(':');
		  lcd_wr2dig(ss);
		  lcd_goto(5,0);
		  lcd_goto(2,1);
		  lcd_wrchar('.');
		  lcd_goto(2,0);
		  lcd_wrchar('.');

	  }

	  if(prog == 1)
	  {
		  if(inc == 0)
	  	{
	  		HAL_Delay(150);
	  		hora_ini+=1;
	  		if(hora_ini>24)
	  		{
	  			hora_ini = 0;
	  		}
	  	}
	  	if(dec == 0)
	  	{
	  		HAL_Delay(150);
	  		hora_ini--;
	  		if(hora_ini<0)
	  		{
	  			hora_ini = 24;
	  		}
	  	}
	  	lcd_goto(8,0);
	  	lcd_wr2dig(hora_ini);
	  }

	  if(prog == 2)
	  {
		  if(inc == 0)
	  	{
	  		HAL_Delay(150);
	  		duracao+=1;
	  		if(duracao>59)
	  		{
	  			duracao = 0;
	  		}
	  	}
	  	if(dec == 0)
	  	{
	  		HAL_Delay(150);
	  		duracao--;
	  		if(duracao<0)
	  		{
	  			duracao = 59;
	  		}
	  	}
	  	lcd_goto(14,0);
	  	lcd_wr2dig(duracao);
	  }

	  if(prog == 3)
	  {

	  	if(inc == 0)
	  	{
	  		HAL_Delay(150);
	  		hh+=1;
	  		if(hh>24)
	  		{
	  			hh = 0;
	  		}
	  	}
	  	if(dec == 0)
	  	{
	  		HAL_Delay(150);
	  		hh--;
	  		if(hh<0)
	  		{
	  			hh = 24;
	  		}
	  	}
	  	lcd_goto(8,1);
	  	lcd_wr2dig(hh);
	  }
	  if(prog == 4)
	  {

	  	if(inc == 0)
	  	{
	  		HAL_Delay(150);
	  		mm+=1;
	  		if(mm>59)
	  		{
	  			mm = 0;
	  		}
	  	}
	  	if(dec == 0)
	  	{
	  		HAL_Delay(150);
	  		mm--;
	  		if(mm<0)
	  		{
	  			mm = 59;
	  		}
	  	}
	  	lcd_goto(11,1);
	  	lcd_wr2dig(mm);
	  }
	  if(prog == 5)
	  {
	  	if(inc == 0)
	  	{
	  		HAL_Delay(150);
	  		ss+=1;
	  		if(ss>59)
	  		{
	  			ss = 0;
	  		}
	  	}
	  	if(dec == 0)
	  	{
	  		HAL_Delay(150);
	  		ss--;
	  		if(ss<0)
	  		{
	  			ss = 59;
	  		}
	  	}
	  	lcd_goto(14,1);
	  	lcd_wr2dig(ss);
	  }
	  if(prog == 6)
	  {
		  for(h =hh; h<24;h++)
		  {
			  hh=0;
			 if (h >= 18)
			 {
				 lcd_goto(2, 0);
				 lcd_wrchar('X');
				 rele1_on();
				 lcd_backlight(1);
			 }
			else
			 {
				lcd_goto(2,0);
				lcd_wrchar('.');
				rele1_off();
				lcd_backlight(0);
			 }
			for(m=mm; m<60; m++)
			{
				mm=0;
				lcd_goto(14,0);
				lcd_wr2dig(duracao);
				if(h==hora_ini)
				{
					if(duracao>0)
					{
						rele2_on();
						lcd_goto(2,1);
						lcd_wrchar('X');
						duracao--;
					}
					else
					{
						rele2_off();
						lcd_goto(2,1);
						lcd_wrchar('.');
					}
				}
				for (s=ss; s<60; s++)
				{
					ss=0;
					lcd_goto(8,1);
					lcd_wr2dig(h);
					lcd_wrchar(':');
					lcd_wr2dig(m);
					lcd_wrchar(':');
					lcd_wr2dig(s);
					HAL_Delay(955);
				}

			}
		  }
	  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 38400;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_4
                          |GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin PA8 PA9 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB1 PB2 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB13 PB14 PB4
                           PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_4
                          |GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void lcd_send4bit(unsigned char x)
{
	if ((x & (1 << 0)) == 0) pb5_0; else pb5_1;
	if ((x & (1 << 1)) == 0) pb4_0; else pb4_1;
	if ((x & (1 << 2)) == 0) pb10_0; else pb10_1;
	if ((x & (1 << 3)) == 0) pa8_0; else pa8_1;

}
void lcd_wrcom(uint8_t com)
{
	// Envia 4 bits + significativos
	lcd_send4bit(com>>4);

    rs_0;
	en_1;
	delayus(5);
	en_0;

	// Envia 4 bits - significativos
	lcd_send4bit(com & 0x0f);
	rs_0;
	en_1;
	delayus(5);
	en_0;

	HAL_Delay(5);

}
void lcd_wrcom4(uint8_t com4)
{
	lcd_send4bit(com4);
	rs_0;
	en_1;
	delayus(5);
	en_0;
	HAL_Delay(5);

}
void lcd_wrstr(char *str)
{
	while(*str) lcd_wrchar(*(str++));
}
void lcd_progchar(void)
{
 unsigned char i;
 lcd_wrcom(0x40);
 for (i = 0; i < 16; i++)
 lcd_wrchar(tab_char[i]);
 lcd_wrcom(0x80);
}
void lcd_wrchar(unsigned char ch)   //
{
	// Envia 4 bits + significativos (bit à bit)
    lcd_send4bit(ch>>4);

	rs_1;
	en_1;
	delayus(5);
	en_0;
	// Envia 4 bits - significativos (bit à bit)
	lcd_send4bit(ch & 0x0f);
    rs_1;
	en_1;
	delayus(5);
	en_0;

	HAL_Delay(5);

}
void lcd_init(uint8_t cursor)  //
{
	lcd_wrcom4(3);
	lcd_wrcom4(3);
	lcd_wrcom4(3);
	lcd_wrcom4(2);
	lcd_wrcom(0x28);
	lcd_wrcom(cursor);
	lcd_wrcom(0x06);
	lcd_wrcom(0x01);
}
void lcd_goto(uint8_t x, uint8_t y)
{
	uint8_t  comando = 0x80;
	if(y==0) comando= 0x80;
	if(y==1) comando= 0xc0;
	if(y==2) comando= 0x90;
	if(y==3) comando= 0xd0;
	if(x<20) comando+=x;
	lcd_wrcom(comando);
}
int __io_putchar(int ch)
{
	 if (ch != '\n') lcd_wrchar(ch);
	return ch;
}
void udelay(void)
{
	int tempo=7;
	while(tempo--);
}
void delayus(uint16_t tempo)
{
	while(tempo--) udelay();
}
void lcd_wr2dig(uint8_t val)
{
	lcd_wrchar((val/10)+48);
	lcd_wrchar((val%10)+48);
}
void lcd_clear()
{
	lcd_wrcom(0x01);
}
void lcd_backlight(uint8_t backlight)
{
	if(backlight == 1) GPIOB -> BSRR = 1<<6;
}
void rele1_on(void)
{
	GPIOB -> BSRR = 1<<13;
}
void rele1_off(void)
{
	GPIOB -> BRR = 1<<13;
}
void rele2_on(void)
{
	GPIOB -> BSRR = 1<<14;
}
void rele2_off(void)
{
	GPIOB -> BRR = 1<<14;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
