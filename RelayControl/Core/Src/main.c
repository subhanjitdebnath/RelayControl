/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DisplayCtril.h"
#include "FlashReadWrite.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
	FlagStatus  Set_RO2 = SET,Set_RO1 = RESET;
	FlagStatus updatedisplay = RESET;
	int8_t pos = 0;
	typedef enum
		{
			MAIN_SCREEN,
			RELAY_SCREEN,
			TIME_SCREEN,
			RO1_TIME_SCREEN,
			RO2_TIME_SCREEN,
			MESSAGE_SCREEN,
			NONE_SCREEN,
		}Screen_POS;

		Screen_POS ScreenPos = MAIN_SCREEN;
	typedef enum
	{
		OK_BTN,
		DN_BTN,
		UP_BTN,
		NONE_BTN,
	}Btn_Pressed;

	typedef enum
	{
		ON_TIME,
		OFF_TIME,
		NONE_TIME,
	}Time_State;
	Time_State TimeState = NONE_TIME;
Btn_Pressed Btn_Triggerd = NONE_BTN;


uint16_t On_Time1 =30,Off_Time1 =30,On_Time2 =40,Off_Time2 =40;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
  	RetriveData();
    Display_init();
	MainScreen(1 ,1, 1);
	ScreenPos = MAIN_SCREEN;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	//HAL_GPIO_WritePin(RO1_GPIO_Port, RO1_Pin, Set_RO1);
	//HAL_GPIO_WritePin(RO2_GPIO_Port, RO2_Pin, Set_RO2);

	if(updatedisplay)
	{
		Scrn_ctrl();
		updatedisplay = RESET;
	}
	if(Btn_Triggerd != NONE_BTN)
	{
		Btn_Ctrl();
	}
	if(TimeState != NONE_TIME)
	{

		if(HAL_GPIO_ReadPin(UP_BT_GPIO_Port, UP_BT_Pin) == GPIO_PIN_RESET)
			{
				HAL_Delay(100);
				Btn_Triggerd = UP_BTN;
			}

	}


	  HAL_Delay(100);
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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00300617;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, RO1_Pin|RO2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : OK_BT_Pin DN_BT_Pin UP_BT_Pin */
  GPIO_InitStruct.Pin = OK_BT_Pin|DN_BT_Pin|UP_BT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RO1_Pin RO2_Pin */
  GPIO_InitStruct.Pin = RO1_Pin|RO2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  //HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == OK_BT_Pin)
  {
	  Btn_Triggerd = OK_BTN;
  }
  else if(GPIO_Pin == DN_BT_Pin)
  {
	  Btn_Triggerd = DN_BTN;
  }
  else if(GPIO_Pin == UP_BT_Pin)
  {
	  Btn_Triggerd = UP_BTN;
  }
  else
  {
	  Btn_Triggerd = NONE_BTN;
  }
}
void OK_Button_Update()
{
	switch(ScreenPos)
	{
	case MAIN_SCREEN:
		if(pos == 1)
		{
			ScreenPos = NONE_SCREEN;
		}
		else if(pos == 2)
		{
			ScreenPos = TIME_SCREEN;
		}
		pos = 0;
		updatedisplay = SET;
		break;
	case RELAY_SCREEN:
		break;
	case TIME_SCREEN:
		if(pos == 1)
		{
			ScreenPos = RO1_TIME_SCREEN;
		}
		else if(pos == 2)
		{
			ScreenPos = RO2_TIME_SCREEN;
		}
		pos = 0;
		updatedisplay = SET;
		break;
	case RO1_TIME_SCREEN:
		if(TimeState == NONE_TIME)
		{
			TimeState = ON_TIME;
		}
		else if(TimeState == ON_TIME)
		{
			TimeState = OFF_TIME;
		}
		else if(TimeState == OFF_TIME)
		{
			ScreenPos = MESSAGE_SCREEN;
			TimeState = NONE_TIME;
		}
		else
		{
			ScreenPos = MAIN_SCREEN;
			TimeState = NONE_TIME;
		}
		updatedisplay = SET;
		break;
	case RO2_TIME_SCREEN:
		if(TimeState == NONE_TIME)
		{
			TimeState = ON_TIME;
		}
		else if(TimeState == ON_TIME)
		{
			TimeState = OFF_TIME;
		}
		else if(TimeState == OFF_TIME)
		{
			ScreenPos = MESSAGE_SCREEN;
			TimeState = NONE_TIME;
		}
		else
		{
			ScreenPos = MAIN_SCREEN;
			TimeState = NONE_TIME;
		}
		updatedisplay = SET;
		break;
	case NONE_SCREEN:
		Set_RO1 = SET;
		Set_RO2 = RESET;
		updatedisplay = SET;
		break;
	default:
		break;
	}
}
void UP_Button_Update()
{
	switch(ScreenPos)
	{
	case MAIN_SCREEN:
		updatedisplay = SET;
		pos--;
		break;
	case RELAY_SCREEN:
		break;
	case TIME_SCREEN:
		updatedisplay = SET;
		pos--;
		break;
	case RO1_TIME_SCREEN:
		if(TimeState == ON_TIME)
		{
			On_Time1++;
		}
		else if(TimeState == OFF_TIME)
		{
			Off_Time1++;
		}
		else
		{
		}
		updatedisplay = SET;
		break;
	case RO2_TIME_SCREEN:
		if(TimeState == ON_TIME)
		{
			On_Time2++;
		}
		else if(TimeState == OFF_TIME)
		{
			Off_Time2++;
		}
		else
		{
		}
		updatedisplay = SET;
		break;
	case NONE_SCREEN:
		Set_RO2 = SET;
		Set_RO1 = SET;
		updatedisplay = SET;
		break;
	default:
		break;
	}
}
void DN_Button_Update()
{
	switch(ScreenPos)
	{
	case MAIN_SCREEN:
		updatedisplay = SET;
		pos++;
		break;
	case RELAY_SCREEN:
		break;
	case TIME_SCREEN:
		updatedisplay = SET;
		pos++;
		break;
	case RO1_TIME_SCREEN:
		if(TimeState == ON_TIME)
		{
			On_Time1--;
		}
		else if(TimeState == OFF_TIME)
		{
			Off_Time1--;
		}
		else
		{
		}
		updatedisplay = SET;
		break;
	case RO2_TIME_SCREEN:
		if(TimeState == ON_TIME)
		{
			On_Time2--;
		}
		else if(TimeState == OFF_TIME)
		{
			Off_Time2--;
		}
		else
		{
		}
		updatedisplay = SET;
		break;
	case NONE_SCREEN:
		Set_RO2 = SET;
		Set_RO1 = RESET;
		Btn_Triggerd = DN_BTN;
		break;
	default:
		break;
	}
}

void Btn_Ctrl()
{
	switch(Btn_Triggerd)
	{
	case OK_BTN:
		OK_Button_Update();
		break;
	case UP_BTN:
		UP_Button_Update();
		break;
	case DN_BTN:
		DN_Button_Update();
		break;
	case NONE_BTN:
		break;
	default:
		break;
	}
	Btn_Triggerd = NONE_BTN;
}

void Scrn_ctrl()
{
	switch(ScreenPos)
		{
		case MAIN_SCREEN:
			ScrollMenu(&pos);
			break;
		case RELAY_SCREEN:
			RelayStatus(Set_RO1,Set_RO2);
			break;
		case TIME_SCREEN:
			ScrollTimerSetting(On_Time1,Off_Time1,On_Time2,Off_Time2,&pos);
			break;
		case RO1_TIME_SCREEN:
			if(TimeState == ON_TIME)
			{
				Relay1TimeSetting(On_Time1,Off_Time1,0,1);
			}
			else if(TimeState == OFF_TIME)
			{
				Relay1TimeSetting(On_Time1,Off_Time1,1,0);
			}
			else
			{
				Relay1TimeSetting(On_Time1,Off_Time1,1,1);
			}
			break;
		case RO2_TIME_SCREEN:
			if(TimeState == ON_TIME)
			{
				Relay2TimeSetting(On_Time2,Off_Time2,0,1);
			}
			else if(TimeState == OFF_TIME)
			{
				Relay2TimeSetting(On_Time2,Off_Time2,1,0);
			}
			else
			{
				Relay2TimeSetting(On_Time2,Off_Time2,1,1);
			}
			break;
		case MESSAGE_SCREEN:
			SaveData();
			Message1();
			ScreenPos = MAIN_SCREEN;
			updatedisplay = SET;
			break;
		case NONE_SCREEN:
			RelayStatus(Set_RO1,Set_RO2);
			break;
		default:
			break;
		}
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
