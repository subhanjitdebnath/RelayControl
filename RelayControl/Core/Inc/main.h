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
#define OK_BT_Pin GPIO_PIN_11
#define OK_BT_GPIO_Port GPIOC
#define OK_BT_EXTI_IRQn EXTI4_15_IRQn
#define DN_BT_Pin GPIO_PIN_12
#define DN_BT_GPIO_Port GPIOC
#define DN_BT_EXTI_IRQn EXTI4_15_IRQn
#define UP_BT_Pin GPIO_PIN_13
#define UP_BT_GPIO_Port GPIOC
#define UP_BT_EXTI_IRQn EXTI4_15_IRQn
#define RO2_Pin GPIO_PIN_1
#define RO2_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
