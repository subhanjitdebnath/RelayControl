/*
 * FlashReadWrite.c
 *
 *  Created on: Aug 4, 2024
 *      Author: Subhanjit Debnath
 */
#include "FlashReadWrite.h"

extern uint16_t   	On_Time1;
extern uint16_t  	On_Time2;
extern uint16_t   	Off_Time1;
extern uint16_t  	Off_Time2;

volatile uint32_t Address = 0x0801f800;

static SavingData   FlashData_;


void SaveData(void)
{
	UpdateLedDataBeforeSaving();
	EraseFlash();
	WriteData();
}

void UpdateLedDataBeforeSaving(void)
{
	FlashData_.Timeset.OnTime1  = On_Time1;
	FlashData_.Timeset.OnTime2  = On_Time2;
	FlashData_.Timeset.OffTime1  = Off_Time1;
	FlashData_.Timeset.OffTime2  = Off_Time2;
}

//Erase the memory location
void EraseFlash(void)
{
	FLASH_EraseInitTypeDef FlashEraseDefination; //Structure

	uint32_t FlashEraseFault = 0;
	HAL_FLASH_Unlock();

	FlashEraseDefination.TypeErase = FLASH_TYPEERASE_PAGES;
	FlashEraseDefination.Banks= FLASH_BANK_1;
	FlashEraseDefination.Page=63;
	FlashEraseDefination.NbPages=1;

	HAL_FLASHEx_Erase(&FlashEraseDefination, &FlashEraseFault);

	HAL_FLASH_Lock();
}


//Write the data
void WriteData(void)
{
	HAL_FLASH_Unlock();
    (void) HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address,FlashData_.DataToSave );
	HAL_FLASH_Lock();
}

//Retrive the data
void RetriveData(void)
{
	data_to_retive data;
	memcpy(data.data,(uint32_t*)Address, 8);
	FlashData_.DataToSave = data.Data64;
	On_Time1 = FlashData_.Timeset.OnTime1;
	Off_Time1 = FlashData_.Timeset.OffTime1;
	On_Time2 = FlashData_.Timeset.OnTime2;
	Off_Time2 = FlashData_.Timeset.OffTime2;

}
