/*
 * DisplayCtril.h
 *
 *  Created on: Dec 25, 2024
 *      Author: Subhanjit Debnath
 */

#ifndef INC_DISPLAYCTRIL_H_
#define INC_DISPLAYCTRIL_H_
#include "ssd1306.h"
void Display_init();
void MainScreen(SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2 ,SSD1306_COLOR_t sel3 );
void ScrollMenu(int8_t *pos);
void UpdateLineText(char line[] , char* s1 , char* s2);
void RelayStatus(FlagStatus RO1,FlagStatus RO2);
void TimerSetting(uint16_t On_Delay1,uint16_t Off_Delay1,uint16_t On_Delay2,uint16_t Off_Delay2,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2);
void ScrollTimerSetting(uint16_t On_Delay1,uint16_t Off_Delay1,uint16_t On_Delay2,uint16_t Off_Delay2,int8_t *pos);
void UpdateLineText_T1(char line[] , char* s1 , char* s2, char sperator);

void Relay1TimeSetting(uint16_t On_Delay,uint16_t Off_Delay,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2);
void Relay2TimeSetting(uint16_t On_Delay,uint16_t Off_Delay,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2);

void Message1();
#endif /* INC_DISPLAYCTRIL_H_ */
