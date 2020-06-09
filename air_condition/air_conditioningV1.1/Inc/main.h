/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define ON		1
#define OFF    0
	#define SHORT_HIT		1000
#define LONG_HIT		3000
#define	u8 unsigned char
#define	u16 unsigned int
#define	u32 unsigned long
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define led_status_Pin GPIO_PIN_13
#define led_status_GPIO_Port GPIOC
#define led_ctrl1_Pin GPIO_PIN_14
#define led_ctrl1_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_15
#define KEY2_GPIO_Port GPIOC
#define CTR_OUT4_Pin GPIO_PIN_0
#define CTR_OUT4_GPIO_Port GPIOC
#define CTR_OUT1_Pin GPIO_PIN_1
#define CTR_OUT1_GPIO_Port GPIOC
#define SW1_Pin GPIO_PIN_0
#define SW1_GPIO_Port GPIOA
#define KEY3_Pin GPIO_PIN_6
#define KEY3_GPIO_Port GPIOA
#define KEY3_EXTI_IRQn EXTI9_5_IRQn
#define KEY4_Pin GPIO_PIN_7
#define KEY4_GPIO_Port GPIOA
#define KEY4_EXTI_IRQn EXTI9_5_IRQn
#define IR_Pin GPIO_PIN_4
#define IR_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_1
#define KEY1_GPIO_Port GPIOB
#define KEY1_EXTI_IRQn EXTI1_IRQn
#define SW2_Pin GPIO_PIN_2
#define SW2_GPIO_Port GPIOB
#define CTR_OUT2_Pin GPIO_PIN_12
#define CTR_OUT2_GPIO_Port GPIOB
#define CTR_OUT3_Pin GPIO_PIN_13
#define CTR_OUT3_GPIO_Port GPIOB
#define DC_Pin GPIO_PIN_14
#define DC_GPIO_Port GPIOB
#define BLK_Pin GPIO_PIN_15
#define BLK_GPIO_Port GPIOB
#define PWM_Pin GPIO_PIN_8
#define PWM_GPIO_Port GPIOA
#define water_adc_Pin GPIO_PIN_11
#define water_adc_GPIO_Port GPIOC
#define Humid_EN_Pin GPIO_PIN_12
#define Humid_EN_GPIO_Port GPIOC
#define MOSI_Pin GPIO_PIN_3
#define MOSI_GPIO_Port GPIOB
#define MISO_Pin GPIO_PIN_4
#define MISO_GPIO_Port GPIOB
#define SCK_Pin GPIO_PIN_5
#define SCK_GPIO_Port GPIOB
#define IIC_SCL_Pin GPIO_PIN_6
#define IIC_SCL_GPIO_Port GPIOB
#define IIC_SDA_Pin GPIO_PIN_7
#define IIC_SDA_GPIO_Port GPIOB
#define led_ctrl2_Pin GPIO_PIN_8
#define led_ctrl2_GPIO_Port GPIOB
#define RES_Pin GPIO_PIN_9
#define RES_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
