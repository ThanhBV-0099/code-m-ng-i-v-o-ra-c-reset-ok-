/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
volatile uint16_t dem;
uint16_t t=0,t1=0,t2=0,i;
uint16_t vao=0,ra=0;
uint16_t t3=0,phanbiet=0,lap=0;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define GPIO_PIN_RESET 0
#define GPIO_PIN_SET 1
#define out_pin4(x) HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, x);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void SystemClock_Config(void);
void sensor_init(void);
void sosanh();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void sensor_init(void)
{
	//kiemtranutnhan();
	  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)== 0 && t1==0) // if the pin is HIGH 
  { 
		 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)==0); //wait for pin to go low 
		{
  t2=1;
		}
		}
	 else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)== 0 && t2==1) 
	 {
		 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)==0); 
		 {
			 vao++;
			 HAL_Delay(5);
			 t2=0;t1=0;
			 phanbiet=1;
		 }
	 }

	 else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)== 0 && t2==0) 
	 {
		 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)==0); 
		 {
			 t1=1;
		 }
	 }
	 else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)== 0 && t1==1) // if the pin is HIGH 
  { 
		 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)==0); //wait for pin to go low 
		{
			ra++;
			HAL_Delay(5);
			t1=0;t2=0;
		}
	}
}

void sosanh()
{
	
	for(i=0;i<2;i++)
	{
	if(i==0 ||i==1 ||i==2 )
	{
	if(vao==ra && vao==0 && ra==0)
		{
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0 ) 
		{ 
		dem=0;
		lap=0;
		do
		{
		dem++;
		HAL_Delay(2);
		}
		while ((dem<1000) && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0);
		{
			if(dem==1000) // nut nhan giu xong khong lam dao trang thai out 
			{
				vao=ra=0;
				dem=1000;
			for(lap=0;lap<10;lap++)
			{
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			HAL_Delay(100);
			}
		 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0); 
	
		}
			else 
				{
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
			HAL_Delay(2);
				break;
		}
	}
}
		}
		else if(vao==ra && vao!=0 && ra!=0)
		{
			out_pin4(0);
			vao=ra=0;
		}
		else if(ra>vao)
{
	out_pin4(0);
	vao=ra=0;
	break;
}	

		else if(vao>ra)
		{
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0 ) 
		{ 
		phanbiet=0;
		dem=0;
		lap=0;
		do
		{
		dem++;
		HAL_Delay(2);
		}
		while ((dem<1000) && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0);
		{
			if(dem==1000) // nut nhan giu xong khong lam dao trang thai out 
			{
				vao=ra=0;
				dem=1000;
			for(lap=0;lap<10;lap++)
			{
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			HAL_Delay(100);
			}
		 while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) == 0); 
	
		}
			else
			{	
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
			HAL_Delay(2);
			break;
		}
	}
}
			else if(phanbiet==1)
			{
				out_pin4(1);
				break;
			}		
		}

	}
}
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
  /* USER CODE BEGIN 2 */
// kl();
// lcd_goto_XY(1,1);
// string_lcd("alo");
// HAL_ADC_Start_IT(&hadc1);
//HAL_ADC_Start_DMA(&hadc1,&adc_value,1);
t3=0;
i=0;
phanbiet=0;
out_pin4(0);
HAL_GPIO_WritePin (GPIOC, GPIO_PIN_13, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		sensor_init();
		sosanh();
		
		
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
