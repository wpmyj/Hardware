/* USER CODE BEGIN Header */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "led.h"
#include "stdio.h"
#include "settings.h"
#include "key.h"
#include "settings.h"
#include "machine.h"
#include "display.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart3_rx;

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#pragma import(__use_no_semihosting)
void _sys_exit(int x)
{
x = x;
}
struct __FILE
{
int handle;
};
FILE __stdout;

int fputc(int ch, FILE *f)
{
				//发送数据到串口
	unsigned char tmp;
	tmp =(unsigned char )ch;
 HAL_UART_Transmit(&huart3, &tmp, 1, 1);
	return ch;
}
extern unsigned char Receive_data[UART1_BUFFER_SIZE],Receive_data_temp[UART1_BUFFER_SIZE];

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	u8 i,j;
	float t=0;
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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
		init_params();
	__HAL_UART_CLEAR_FLAG(&huart1,UART_IT_IDLE);	
	__HAL_UART_DISABLE_IT(&huart1, UART_IT_IDLE);	//使能空闲中断
	HAL_UART_Receive_DMA(&huart1,Receive_data_temp,UART1_BUFFER_SIZE);
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);	//使能空闲中断
	//TIM1->CCR2 = 9999; 
	init_Pid();	
	LCD_Init();//LCD初始化
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);

	//xianshi(); //显示信息
	 //LCD_DrawPoint(10,0);
	//  LCD_Fill(10,0,319,10,DARKBLUE);
	unsigned int index;
	index = 5;
//	showhanzi16X16(index,18,0,LIGHTBLUE);	
//	showhanzi16X16(index+3+24,18,1,LIGHTBLUE);	
//		showhanzi16X16(index+3+24*4,18,2,LIGHTBLUE);	
//	showhanzi16X16(index+3+24*5,18,3,LIGHTBLUE);
//	showhanzi16X16(index+24*8+3,18,4,LIGHTBLUE);	
//	showhanzi16X16(index+24*9+3,18,5,LIGHTBLUE);
//showhanzi(0+32*0,62+3+20,0,LIGHTBLUE);	
//showhanzi(0+32*1,62+3+20,1,LIGHTBLUE);	
//showhanzi(0+32*0,62+3+32+20,2,LIGHTBLUE);
//showhanzi(0+32*1,62+3+32+20,3,LIGHTBLUE);

//showhanzi(index+32*5+3,62+3+20,4,LIGHTBLUE);	
//showhanzi(index+32*6+3,62+3+20,5,LIGHTBLUE);	
//showhanzi(index+32*5+3,62+3+32+20,2,LIGHTBLUE);
//showhanzi(index+32*6+3,62+3+32+20,3,LIGHTBLUE);

//	showhanzi16X16(0,180+3,4,LIGHTBLUE);	
//	showhanzi16X16(0,180+3+24,5,LIGHTBLUE);

//	//LCD_ShowNum(index+24*10+3,18,19,2,LIGHTBLUE);
//	//LCD_ShowString(14*10+3,36,"LCD_W:",LIGHTBLUE);
//	LCD_DrawLine(0, 60,320, 60);//****************************
//	LCD_DrawLine(0, 61,320, 61);
//	LCD_DrawLine(0, 62,320, 62);	
//	LCD_DrawLine(0, 180,320, 180);//******************************
//	LCD_DrawLine(0, 181,320, 181);
//	LCD_DrawLine(0, 182,320, 182);
	//showimage(); //显示40*40图片

	LCD_ShowChinese(index,18,"风速",LIGHTBLUE,BLACK,24,0);
	LCD_ShowChinese(index+24*3,18,"定速",LIGHTBLUE,BLACK,24,0);
	LCD_ShowChinese(index+24*7,18,"水温",LIGHTBLUE,BLACK,24,0);
	LCD_ShowIntNum(index+24*10,14,26,2,LIGHTBLUE,BLACK,32);
	LCD_ShowChinese(index+24*11+10,14,"℃",LIGHTBLUE,BLACK,32,0);

	LCD_ShowChinese(index,62+23,"设定",LIGHTBLUE,BLACK,32,0);
	LCD_ShowChinese(index,62+23+32*1,"温度",LIGHTBLUE,BLACK,32,0);
	LCD_ShowIntNum(index+24*3,62+42,26,2,YELLOW,BLACK,32);
	LCD_ShowChinese(index+24*4+12,62+42,"℃",YELLOW,BLACK,32,0);

	LCD_ShowChinese(index+32*5,62+23,"当前",LIGHTBLUE,BLACK,32,0);
	LCD_ShowChinese(index+32*5,62+23+32*1,"温度",LIGHTBLUE,BLACK,32,0);
	LCD_ShowIntNum(index+24*10,62+42,26,2,YELLOW,BLACK,32);
	LCD_ShowChinese(index+24*11+10,62+42,"℃",YELLOW,BLACK,32,0);

	LCD_ShowChinese(index+10,183+10,"模式",LIGHTBLUE,BLACK,24,0);
	LCD_ShowChinese(index+10+24*3,183+10,"定速",LIGHTBLUE,BLACK,24,0);
	LCD_ShowChinese(index+24*7,183+10,"定时开",LIGHTBLUE,BLACK,24,0);
	LCD_ShowIntNum(index+24*10,183+10,26,2,LIGHTBLUE,BLACK,32);
	LCD_ShowChinese(index+24*11+10,183+10,"℃",LIGHTBLUE,BLACK,32,0);

	LCD_DrawLine(0,60,320,0,YELLOW);//**************************************
	LCD_DrawLine(0,61,320,0,YELLOW);
	LCD_DrawLine(0,62,320,0,YELLOW);
	
	LCD_DrawLine(0,180,320,0,YELLOW);//***************************************
	LCD_DrawLine(0,181,320,0,YELLOW);
	LCD_DrawLine(0,182,320,0,YELLOW);		
  
	
	
//		LCD_ShowChinese(0,0,"中景园电子",RED,WHITE,32,0);
//		LCD_ShowString(0,40,"LCD_W:",RED,WHITE,16,0);
//		LCD_ShowIntNum(48,40,LCD_W,3,RED,WHITE,24);
//		LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
//		LCD_ShowIntNum(128,40,LCD_H,3,RED,WHITE,16);
//		LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
//		LCD_ShowString(0,70,"Increaseing Nun:",RED,WHITE,16,0);
//		LCD_ShowFloatNum1(128,70,t,4,RED,WHITE,16);
//		t+=0.11;
//		for(j=0;j<5;j++)
//		{
//			for(i=0;i<6;i++)
//			{
//				LCD_ShowPicture(40*i,120+j*40,40,40,gImage_1);
//			}
//		}
//	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		//run_process();
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */
  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */
  /* USER CODE END ADC1_Init 1 */
  /** Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = ENABLE;
  hadc1.Init.NbrOfDiscConversion = 1;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 7;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_55CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_4;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = ADC_REGULAR_RANK_6;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_VREFINT;
  sConfig.Rank = ADC_REGULAR_RANK_7;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */
  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */
  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */
  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */
  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */
  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
  /* USER CODE END USART3_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, led_status_Pin|led_ctrl1_Pin|CTR_OUT4_Pin|CTR_OUT1_Pin 
                          |Humid_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SW2_Pin|CTR_OUT2_Pin|CTR_OUT3_Pin|DC_Pin 
                          |BLK_Pin|MOSI_Pin|SCK_Pin|IIC_SCL_Pin 
                          |IIC_SDA_Pin|led_ctrl2_Pin|RES_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PWM_GPIO_Port, PWM_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_status_Pin led_ctrl1_Pin CTR_OUT4_Pin CTR_OUT1_Pin 
                           Humid_EN_Pin */
  GPIO_InitStruct.Pin = led_status_Pin|led_ctrl1_Pin|CTR_OUT4_Pin|CTR_OUT1_Pin 
                          |Humid_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : KEY2_Pin */
  GPIO_InitStruct.Pin = KEY2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(KEY2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SW1_Pin */
  GPIO_InitStruct.Pin = SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : KEY3_Pin KEY4_Pin */
  GPIO_InitStruct.Pin = KEY3_Pin|KEY4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : IR_Pin water_adc_Pin */
  GPIO_InitStruct.Pin = IR_Pin|water_adc_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : KEY1_Pin */
  GPIO_InitStruct.Pin = KEY1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SW2_Pin CTR_OUT2_Pin CTR_OUT3_Pin DC_Pin 
                           BLK_Pin MOSI_Pin SCK_Pin IIC_SCL_Pin 
                           IIC_SDA_Pin led_ctrl2_Pin RES_Pin */
  GPIO_InitStruct.Pin = SW2_Pin|CTR_OUT2_Pin|CTR_OUT3_Pin|DC_Pin 
                          |BLK_Pin|MOSI_Pin|SCK_Pin|IIC_SCL_Pin 
                          |IIC_SDA_Pin|led_ctrl2_Pin|RES_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PWM_Pin */
  GPIO_InitStruct.Pin = PWM_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PWM_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MISO_Pin */
  GPIO_InitStruct.Pin = MISO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MISO_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */
extern key_stru key;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	unsigned int i;
	i=50000;
	while(i--)
	 ;
	if(GPIO_Pin==KEY1_Pin)
	{
		
		if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)==GPIO_PIN_RESET)
		{
		    key.keytime= HAL_GetTick();
			key.keynum = key.keynum|0x01;  

		}
	}
	else if(GPIO_Pin==KEY4_Pin)
	{
		if(HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin)==0)
		{
			key.keytime = HAL_GetTick();
			key.keynum = key.keynum|0x40;
		}


	}
	else if(GPIO_Pin==KEY3_Pin)
	{
		if(HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin)==0)
		{
			key.keytime = HAL_GetTick();
			key.keynum = key.keynum|0x10;
		}
	}
	else if(GPIO_Pin==KEY2_Pin)
	{
		if(HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)==0)
		{
			key.keytime = HAL_GetTick();
			key.keynum = key.keynum|0x04;
		}
	}
	else
		;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
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
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
