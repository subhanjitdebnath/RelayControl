/*
 * IOTesting.c
 *
 *  Created on: Dec 30, 2024
 *      Author: Subhanjit Debnath
 */

#include "main.h"

typedef struct
{
	FlagStatus   PA12_IN_STATE;
	FlagStatus   PC12_IN_STATE;
	FlagStatus   PC13_IN_STATE;
	FlagStatus   PC11_IN_STATE;
	FlagStatus   PC0_OUT_CTRL;
	FlagStatus   PC1_OUT_CTRL;
	FlagStatus   PA1_OUT_CTRL;
	FlagStatus   PA4_OUT_CTRL;
	FlagStatus   PB2_OUT_CTRL;
	FlagStatus   PB10_OUT_CTRL;
	FlagStatus   PB11_OUT_CTRL;
	FlagStatus   PB12_OUT_CTRL;
	FlagStatus   PA15_OUT_CTRL;
}IOs;

typedef struct
{
	uint8_t PA12_IN_COUNT;
	FlagStatus PA12_TRIG;

	uint8_t PC12_IN_COUNT;
	FlagStatus PC12_TRIG;

	uint8_t PC13_IN_COUNT;
	FlagStatus PC13_TRIG;

	uint8_t PC11_IN_COUNT;
	FlagStatus PC11_TRIG;
}IOs_counter;

IOs IO_Testing;
IOs_counter Counter;

void IO_TestingON(void)
{
	//INPUTS
	IO_Testing.PC11_IN_STATE = HAL_GPIO_ReadPin(PC11_IN_GPIO_Port, PC11_IN_Pin);
	if(IO_Testing.PC11_IN_STATE != Counter.PC11_TRIG )
	{
		IO_Testing.PC11_IN_STATE = Counter.PC11_TRIG ;
		Counter.PC11_IN_COUNT++;
	}
	IO_Testing.PC12_IN_STATE = HAL_GPIO_ReadPin(PC12_IN_GPIO_Port, PC12_IN_Pin);
	if(IO_Testing.PC12_IN_STATE != Counter.PC12_TRIG )
		{
			IO_Testing.PC12_IN_STATE = Counter.PC12_TRIG ;
			Counter.PC12_IN_COUNT++;
		}
	IO_Testing.PC13_IN_STATE = HAL_GPIO_ReadPin(PC13_IN_GPIO_Port, PC13_IN_Pin);
	if(IO_Testing.PC13_IN_STATE != Counter.PC13_TRIG )
		{
			IO_Testing.PC13_IN_STATE = Counter.PC13_TRIG ;
			Counter.PC13_IN_COUNT++;
		}
	IO_Testing.PA12_IN_STATE = HAL_GPIO_ReadPin(PA12_IN_GPIO_Port, PA12_IN_Pin);
	if(IO_Testing.PA12_IN_STATE != Counter.PA12_TRIG )
		{
			IO_Testing.PA12_IN_STATE = Counter.PA12_TRIG ;
			Counter.PA12_IN_COUNT++;
		}

	//OUTPUTS
	HAL_GPIO_WritePin(PC0_OUT_GPIO_Port, PC0_OUT_Pin, IO_Testing.PC0_OUT_CTRL);
	HAL_GPIO_WritePin(PC1_OUT_GPIO_Port, PC1_OUT_Pin, IO_Testing.PC1_OUT_CTRL);
	HAL_GPIO_WritePin(PA1_OUT_GPIO_Port, PA1_OUT_Pin, IO_Testing.PA1_OUT_CTRL);
	HAL_GPIO_WritePin(PA4_OUT_GPIO_Port, PA4_OUT_Pin, IO_Testing.PA4_OUT_CTRL);
	HAL_GPIO_WritePin(PB2_OUT_GPIO_Port, PB2_OUT_Pin, IO_Testing.PB2_OUT_CTRL);
	HAL_GPIO_WritePin(PB10_OUT_GPIO_Port, PB10_OUT_Pin, IO_Testing.PB10_OUT_CTRL);
	HAL_GPIO_WritePin(PB11_OUT_GPIO_Port, PB11_OUT_Pin, IO_Testing.PB11_OUT_CTRL);
	HAL_GPIO_WritePin(PB12_OUT_GPIO_Port, PB12_OUT_Pin, IO_Testing.PB12_OUT_CTRL);
	HAL_GPIO_WritePin(PA15_OUT_GPIO_Port, PA15_OUT_Pin, IO_Testing.PA15_OUT_CTRL);

}
