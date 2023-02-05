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
#include "stdlib.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define cursor_off     0x0c
#define cursor_on      0x0e
#define cursor_blink   0x0f

#define comCartao (GPIOA-> IDR & (1<<6))

#define rs_0			GPIOA -> BRR = 1<<9
#define rs_1			GPIOA -> BSRR = 1<<9
#define en_0			GPIOC -> BRR = 1<<7
#define en_1			GPIOC -> BSRR = 1<<7

#define servo_0			GPIOC -> BRR = 1<<0
#define servo_1			GPIOC -> BSRR = 1<<0


#define  SCL      8    // Declare SCL GPIO-OUTPUT no Cube!!!
#define  SDA      9    // Declare SDA GPIO-OUTPUT no Cube!!!

#define  SCL_1    GPIOB->BSRR = 1 << SCL
#define  SCL_0    GPIOB->BRR = 1 << SCL
#define  SDA_1    GPIOB->BSRR = 1 << SDA
#define  SDA_0    GPIOB->BRR = 1 << SDA

#define no_lcd		1
#define na_serial	2

char aonde = no_lcd;

#define pb5_0 GPIOB->BRR = 1<<5 			/*PB5(D4) on/off */
#define pb5_1 GPIOB->BSRR = 1<<5
#define pb4_0 GPIOB->BRR = 1<<4 			/*PB4(D5) on/off */
#define pb4_1 GPIOB->BSRR = 1<<4
#define pb10_0 GPIOB->BRR = 1<<10 			/*PB10(D6) on/off */
#define pb10_1 GPIOB->BSRR = 1<<10
#define pa8_0 GPIOA->BRR = 1<<8 			/*PA8(D7)*/
#define pa8_1 GPIOA->BSRR = 1<<8

RTC_TimeTypeDef relogio;
RTC_DateTypeDef calendario;

char ch, d, u, h, m, s, dd, mm, yy;
char hora, min, seg, dia, mes, ano;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

ADC_HandleTypeDef hadc;
I2C_HandleTypeDef hi2c1;
RTC_HandleTypeDef hrtc;
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
static void MX_ADC_Init(void);
static void MX_I2C1_Init(void);
static void MX_RTC_Init(void);
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
int _io_putchar(int ch);
void lcd_clear();
void lcd_backlight(uint8_t backlight);
void lcd_progchar(void);

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
unsigned char i2c_write(unsigned char dado);
unsigned char i2c_read(unsigned char conf);


void servo_motor(int servo);
void lcd_update();

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int __io_putchar(int ch) {
	    if (aonde == no_lcd){if (ch != '\n') lcd_wrchar(ch);}
		if (aonde == na_serial) HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 10);
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
  MX_ADC_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */

  //int leitura;
  //HAL_ADC_Init(&hadc);  // conversor analogico digital

   HAL_UART_Init(&huart2); // Uart(Universal Asynchronous Receiver/Transmitter) porta serial
   HAL_I2C_Init(&hi2c1);
   HAL_RTC_Init(&hrtc);
   HAL_RTC_WaitForSynchro(&hrtc);

   lcd_init(cursor_off);
   lcd_clear();

   char password[4]={0,0,0,0};
   char testePass[4]={0,0,0,0};
   int certa;
   int senhacadastrada=0;
   int senhacorreta,config,estado;
   int erro;

   	   	 do{

	     if (comCartao == 0)
	       {
	        aonde = no_lcd;
	    	lcd_goto(0,0);
	    	printf("Cadastrar senha :");
	    	aonde = na_serial;
	    	printf("\rCadastre uma senha para o cartao\n");
	    	config=1;
	     for(int k = 0; k < 4 ; k++)
		 {
		 do
		 {
		   erro = HAL_UART_Receive(&huart2,(uint8_t *)&password[k], 1, 2);
		 } while (erro != HAL_UART_ERROR_NONE);
		 	 HAL_UART_Transmit(&huart2, (uint8_t *)&password[k], 1, 2);
		 	 password[k] = password[k] - '0';  		//conv ascii decimal
		 }
	     if (comCartao == 0)
	    	       {    for(int k = 0 ; k < 4 ; k++)
	     {
	    	 int pos_mem=100+k;
	    	 HAL_I2C_Mem_Write(&hi2c1,0xA0,pos_mem,1,(uint8_t*)&password[k],1,10);
	    	 HAL_Delay(10);

	     }

	      for (int k=0; k<4; k++)
	      {
	    	int pos_mem=100+k;
	      	HAL_I2C_Mem_Read(&hi2c1, 0xA0, pos_mem, 1, (uint8_t*)&testePass[k], 1, 10);
	      	}
	         aonde = na_serial;
	         printf("\n\rSenha cadastrada %d%d%d%d\n",testePass[0],testePass[1],testePass[2],testePass[3]);
	     	 aonde = no_lcd;
	     	 lcd_clear();
	     	 lcd_goto(0,0);
	     	 printf("\nSenha cadastrada\n");
	     	 senhacadastrada=1;
	     	 config=3;
	     	 HAL_Delay(500);
	    } else {
	    	       aonde = no_lcd;
	    	       lcd_clear();
	    		   printf("Insira o cartao de acesso\n");
	    		   HAL_Delay(100);
	    	   	   aonde = na_serial;
	    	   	   printf("\r\n");
	    	   	   printf("\rInsira o cartao de acesso\n");
	    	   	   HAL_Delay(500);
	    	   }
	       }else {
    	       aonde = no_lcd;
    	       lcd_clear();
    		   printf("Insira o cartao de acesso\n");
    		   HAL_Delay(100);
    	   	   aonde = na_serial;
    	   	   printf("\r\n");
    	   	   printf("\rInsira o cartao de acesso\n");
    	   	   printf("\r\n");
    	   	   HAL_Delay(500);
    	   }

	     }while(senhacadastrada==0);

   		aonde = na_serial;
   		printf("\rAjuste da data\n");
   		printf("\rDia/mes/ano\n");
   		//AJUSTE DA DATA
   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		d = ch-'0'; //converte ascii p decimal

   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		u = ch - '0';
   		dd = 10 * d + u;
   		if (dd>31) dd=31;
   		ch = '/';
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);
   		aonde = no_lcd;
   		lcd_clear();
   		lcd_goto(8,0);
   		printf("\r%02d/\n", dd); // imprime a data

   			//AJUSTE DO MES
   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		d = ch-'0'; //converte ascii p decimal

   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		u = ch - '0';
   		mm = 10 * d + u;
   		if (dd>28 && mm==2) mm+=1;
   		if (dd>30 && (mm==4 || mm==6 || mm==9 || mm==11)) mm+=1;
   		if (mm>12) mm=12;
   		ch = '/';
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);
   		lcd_goto(11,0);
   		printf("\r%02d/\n", mm); // imprime mes

   			//AJUSTE DO SEGUNDO
   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		d = ch-'0'; //converte ascii p decimal

   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		u = ch - '0';
   		yy = 10 * d + u;

   		lcd_goto(14,0);
   		printf("\r%02d\n", yy); // imprime ano

   		aonde = na_serial;
   		printf("\n");


   		aonde = na_serial;
   		printf("\rDigite a hora\n");

   		//AJUSTE DA HORA
   		do{

   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		d = ch-'0'; //converte ascii p decimal

   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		u = ch - '0';
   		h = 10 * d + u;
   		if (h>23) h=23;
   		ch = ':';
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);
   		aonde = no_lcd;
   		lcd_goto(8,1);
   		printf("\r%02d:\n", h); // imprime a hora

   			//AJUSTE DO MINUTO
   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		d = ch-'0'; //converte ascii p decimal

   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		u = ch - '0';
   		m = 10 * d + u;
   		if(m>59) m=59;
   		ch = ':';
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);
   		lcd_goto(11,1);
   		printf("\r%02d:\n", m); // imprime minuto

   			//AJUSTE DO SEGUNDO
   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		d = ch-'0'; //converte ascii p decimal

   		do{
   			erro = HAL_UART_Receive(&huart2, (uint8_t*)&ch, 1, 2);
   		} while(erro != HAL_UART_ERROR_NONE);
   		HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 2);

   		u = ch - '0';
   		s = 10 * d + u;
   		if(s>59) s=59;

   		lcd_goto(14,1);
   		printf("\r%02d\n", s); // imprime segundo

   		relogio.Hours = h;
   		relogio.Minutes = m;
   		relogio.Seconds = s;

   		calendario.Date = dd;
   		calendario.Month = mm;
   		calendario.Year = yy;

   		HAL_RTC_SetTime(&hrtc, &relogio, RTC_FORMAT_BIN);
   		HAL_RTC_SetDate(&hrtc, &calendario, RTC_FORMAT_BIN);

   		estado=0;
   		aonde = na_serial;
   		printf("\n");

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  lcd_update();
	  do
	  {
		  lcd_update();
      if (comCartao == 0)//cartao continua inserido
    {

   	aonde = na_serial;
   	printf("\r\n");
    printf("\rInsira a senha para abrir a porta : \n");
    config=1;
    lcd_update();
    	for(int k = 0; k < 4 ; k++)
    	{ lcd_update();
    		do
    		{
    		 	erro = HAL_UART_Receive(&huart2, (uint8_t *)&testePass[k], 1, 100);
    		 	lcd_update();
    		} while (erro != HAL_UART_ERROR_NONE);
    	 	 HAL_UART_Transmit(&huart2, (uint8_t *)&testePass[k], 1, 100);
    	 	 testePass[k] = testePass[k] - '0';  		//conv ascii decimal
    	}
    	 if (comCartao == 0)//cartao continua inserido
    	    {
    		 lcd_update();

        	/* for(int k = 0 ; k <4 ; k++)
      	 {
      		int pos_mem=100+k;
      		HAL_I2C_Mem_Read(&hi2c1, 0xA0, pos_mem, 1, (uint8_t*)&testePass[k], 1, 10);
      	  }*/
    	certa=0;
      	for (int k=0; k<4; k++) //compara a senha
      		{lcd_update();
      			if (password[k]==testePass[k]) certa=certa+1;
      		}

      	            if(certa!=4)
      	            {
      	 	 	 	aonde = na_serial;
    				printf("\rSenha incorreta\n");
    				aonde = no_lcd;
    			    lcd_goto (0,0);
    				printf("Senha\n");
    				lcd_goto (0,1);
    				printf("Inc.\n");
    				HAL_Delay(10);
    				lcd_update();
      	            }else{

      	            	aonde = na_serial;
      	            	printf("\rSenha correta\n");
      	            	aonde = no_lcd;
      	                lcd_goto (0,0);
      	                printf("Senha\n");
      	                lcd_goto (0,1);
      	                printf("Cor.\n");
      	            	HAL_Delay(1000);
      	            	servo_motor(1);
      	            	HAL_Delay(5000);
      	            	servo_motor(2);
      	            	lcd_update();
      	            }
    }
      	  	  	else
      	  	  	{
      	  	  	lcd_update();
      	  	  	if(config==1)
      	  	  	{
      	  	  		aonde = na_serial;
      	  	  		printf("\rInsira o cartao de acesso\n");
      	  	  		printf("\r\n");
      	  	  		aonde = no_lcd;
      	  	  		printf("Insira o cartao de acesso\n");
      	  	  		config=2;
    	     	 }
      	  	  	}
    	 lcd_update(); }else { estado=1;}


      lcd_update();	  }while(config<3);
}if(estado=1){
			aonde = na_serial;
	  		printf("\rInsira o cartao de acesso\n");
	  		printf("\r\n");
	  		aonde = no_lcd;
	  		printf("Insira o cartao de acesso\n");
	  		config=2;
	  		if(comCartao==1)estado=0;
}


	lcd_update();
}
  /* USER CODE END 3 */


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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1
                              |RCC_PERIPHCLK_RTC;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 0x1;
  sDate.Year = 0x0;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

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
  huart2.Init.BaudRate = 9600;
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
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC7 PC8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_7|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin PA8 PA9 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
	// Envia 4 bits + significativos (bit Ã  bit)
    lcd_send4bit(ch>>4);

	rs_1;
	en_1;
	delayus(5);
	en_0;
	// Envia 4 bits - significativos (bit Ã  bit)
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
int _io_putchar(int ch)
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


/*
 *implementaÃ§Ã£o I2C
 */
void i2c_init(void)
{
  SDA_1;
  SCL_1;
  delayus(5);
}

void i2c_start(void)
{
  SDA_0;
  delayus(5);
  SCL_0;
  delayus(1);
}

void i2c_stop(void)
{
  SDA_0;
  delayus(1);
  SCL_1;
  delayus(5);
  SDA_1;
  delayus(5);
}

unsigned char i2c_write(unsigned char dado)
{
  int i;
  unsigned char resp;

  for(i=7; i>=0; i--)
  {
    if((dado & (1<<i)) != 0) SDA_1;  else SDA_0;
    delayus(1);
    SCL_1;
    delayus(5);
    SCL_0;
    delayus(5);
  }

  SDA_1;
  delayus(1);
  SCL_1;
  if((GPIOB->IDR & (1<<SDA)) != 0) resp=0xff; else resp=0;
  delayus(5);
  SCL_0;
  delayus(5);
  SDA_0;
  delayus(1);

  return resp;
}

unsigned char i2c_read(unsigned char conf)
{
  int i;
  unsigned char v=0;

  SDA_1;
  delayus(1);
  for(i=7; i>=0; i--)
  {
    v <<= 1;
    SCL_1;
    if((GPIOB->IDR & (1<<SDA)) !=0)  v++;
    delayus(5);
    SCL_0;
    delayus(5);
  }
  if(conf) SDA_1; else SDA_0;
  SCL_1;
  delayus(5);
  SCL_0;
  delayus(5);

  return v;
}

// Escreve no Smart Card...
void i2c_smartcard_wr(unsigned char slave, unsigned char data)
{
  i2c_start();
  i2c_write(slave);
  i2c_write(data);
  i2c_stop();
  delayus(10000);
}

// Escreve um unico byte....
// Memoria do tipo 8x8...
//
void i2c_wrmem(unsigned char slave, unsigned char address, unsigned char data)
{
  i2c_start();
  i2c_write((slave&0xfe));
  i2c_write(address);
  i2c_write(data);
  i2c_stop();
  delayus(10000);
}

// Le um unico byte...
// Memoria do tipo 8x8...
//
unsigned char i2c_rdmem(unsigned char slave, unsigned char address)
{
  unsigned char resp;
  i2c_start();
  i2c_write((slave&0xfe));
  i2c_write(address); // endereco de gravacao
  i2c_stop();
  i2c_start(); // re-start
  i2c_write((slave&0xfe) + 1); // slave adress da memoria + operacao R
  resp = i2c_read(0xff); //apos leitura envia um nak
  i2c_stop();

  return resp;
}

void servo_motor(int servo)
{
	if(servo == 0)
	{
		for(int k = 0; k<20; k++)
		{
			servo_1;
			HAL_Delay(1.5);
			servo_0;
			HAL_Delay(18.5);
		}
	}
	if(servo == 1)
	{
		for(int k = 0; k<20; k++)
				{
					servo_1;
					HAL_Delay(1);
					servo_0;
					HAL_Delay(19);
				}
	}
	if(servo == 2)
		{
			for(int k = 0; k<20; k++)
					{
						servo_1;
						HAL_Delay(2);
						servo_0;
						HAL_Delay(18);
					}
		}
}

void lcd_update()
{
	HAL_RTC_GetDate(&hrtc, &calendario, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&hrtc, &relogio, RTC_FORMAT_BIN);

	hora = relogio.Hours;
	min = relogio.Minutes;
	seg = relogio.Seconds;

	dia = calendario.Date;
	mes = calendario.Month;
	ano = calendario.Year;

	aonde = no_lcd;
	lcd_goto(8 ,0);
	printf("%02d/%02d/%02d\n", dia, mes, ano);
	lcd_goto(8, 1);
	printf("%02d:%02d:%02d\n", hora, min, seg);
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
