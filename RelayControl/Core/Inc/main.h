/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
void UP_Button_Update();
void DN_Button_Update();
void OK_Button_Update();
void Btn_Ctrl();
void Scrn_ctrl();
void OnOffUpdated();
void UpdatedRelayStatus();
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PC11_IN_Pin GPIO_PIN_11
#define PC11_IN_GPIO_Port GPIOC
#define PC11_IN_EXTI_IRQn EXTI4_15_IRQn
#define PC12_IN_Pin GPIO_PIN_12
#define PC12_IN_GPIO_Port GPIOC
#define PC12_IN_EXTI_IRQn EXTI4_15_IRQn
#define PC13_IN_Pin GPIO_PIN_13
#define PC13_IN_GPIO_Port GPIOC
#define PC13_IN_EXTI_IRQn EXTI4_15_IRQn
#define PC0_OUT_Pin GPIO_PIN_0
#define PC0_OUT_GPIO_Port GPIOC
#define PC1_OUT_Pin GPIO_PIN_1
#define PC1_OUT_GPIO_Port GPIOC
#define PA1_OUT_Pin GPIO_PIN_1
#define PA1_OUT_GPIO_Port GPIOA
#define PA4_OUT_Pin GPIO_PIN_4
#define PA4_OUT_GPIO_Port GPIOA
#define PB2_OUT_Pin GPIO_PIN_2
#define PB2_OUT_GPIO_Port GPIOB
#define PB10_OUT_Pin GPIO_PIN_10
#define PB10_OUT_GPIO_Port GPIOB
#define PB11_OUT_Pin GPIO_PIN_11
#define PB11_OUT_GPIO_Port GPIOB
#define PB12_OUT_Pin GPIO_PIN_12
#define PB12_OUT_GPIO_Port GPIOB
#define PA12_IN_Pin GPIO_PIN_12
#define PA12_IN_GPIO_Port GPIOA
#define PA15_OUT_Pin GPIO_PIN_15
#define PA15_OUT_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
