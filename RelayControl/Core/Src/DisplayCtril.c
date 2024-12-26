#include "DisplayCtril.h"
#include <stdio.h>
#include <string.h>

char Line[20];
char Line2[20];
char* FixeLable[] = {"    MENU ", " RELAY SETTING "," RELAY STATUS"," TIME SET"," DN   UP     OK","  Relay" ,"   <-- Back","Relay  OD  OFD"};
char* ONOFFLable[] = {" OFF"," ON"};
char* RelayLable[] = {" Relay 1"," Relay 2" ," RO1 "," RO2 "};
char* TimeLable[] = {"On Time","Off Time","m"};
void Display_init()
{
	SSD1306_Init();
}
void MainScreen(SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2 ,SSD1306_COLOR_t sel3 )
{
	SSD1306_Clear();
    SSD1306_GotoXY (0,0);
	SSD1306_Puts (FixeLable[0], &Font_11x18, 1);
	SSD1306_GotoXY (0,20);
	SSD1306_Puts (FixeLable[1], &Font_7x10, sel1);
	SSD1306_GotoXY (0,30);
	SSD1306_Puts (FixeLable[2], &Font_7x10, sel2);
	SSD1306_GotoXY (0,40);
	SSD1306_Puts (FixeLable[3], &Font_7x10, sel3);
	SSD1306_GotoXY (0,52);
	SSD1306_Puts (FixeLable[4], &Font_7x10, 1);
    SSD1306_UpdateScreen();
}

void ScrollMenu(int8_t *pos)
{
	*pos = (*pos < 0)? 2 : (*pos > 2)? 0 : *pos;

	switch (*pos)
	{
	case 0:
		MainScreen(0 ,1, 1);
		break;
	case 1:
		MainScreen(1 ,0, 1);
		break;
	case 2:
		MainScreen(1 ,1, 0);
		break;
	default:
		break;
	}

}

void ScrollTimerSetting(uint16_t On_Delay1,uint16_t Off_Delay1,uint16_t On_Delay2,uint16_t Off_Delay2,int8_t *pos)
{
	*pos = (*pos < 0)? 2 : (*pos > 2)? 1 : *pos;

	switch (*pos)
	{
	case 0:
		TimerSetting(On_Delay1,Off_Delay1,On_Delay2,Off_Delay2,1,1);
		break;
	case 1:
		TimerSetting(On_Delay1,Off_Delay1,On_Delay2,Off_Delay2,0,1);
		break;
	case 2:
		TimerSetting(On_Delay1,Off_Delay1,On_Delay2,Off_Delay2,1,0);
		break;
	default:
		break;
	}

}

void RelayStatus(FlagStatus RO1,FlagStatus RO2)
{
	SSD1306_Clear();
	SSD1306_GotoXY (0,0);
	SSD1306_Puts (FixeLable[5], &Font_11x18, 1);

	UpdateLineText(Line,RelayLable[0],ONOFFLable[RO1]);
	SSD1306_GotoXY (0,25);
	SSD1306_Puts (Line, &Font_7x10, 1);

	UpdateLineText(Line,RelayLable[1],ONOFFLable[RO2]);
	SSD1306_GotoXY (0,35);
	SSD1306_Puts (Line, &Font_7x10, 1);

	SSD1306_GotoXY (0,52);
	SSD1306_Puts (FixeLable[6], &Font_7x10, 1);
	SSD1306_UpdateScreen();
}

void TimerSetting(uint16_t On_Delay1,uint16_t Off_Delay1,uint16_t On_Delay2,uint16_t Off_Delay2,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2)
{
	char OnDelay[20];
	char OffDelay[20];

	SSD1306_Clear();
	SSD1306_GotoXY (0,0);
	SSD1306_Puts (FixeLable[3], &Font_11x18, 1);

	//RELAY - 1 UPDATE
	sprintf(OnDelay,"%d",On_Delay1);
	sprintf(OffDelay,"%d",Off_Delay1);
	strcat(OnDelay," F=");
	strcat(OnDelay,OffDelay);
	UpdateLineText_T1(Line,RelayLable[2],OnDelay,'N');

	SSD1306_GotoXY (0,25);
	SSD1306_Puts (Line, &Font_7x10, sel1);

	//RELAY - 2 UPDATE
	sprintf(OnDelay,"%d",On_Delay2);
	sprintf(OffDelay,"%d",Off_Delay2);
	strcat(OnDelay," F=");
	strcat(OnDelay,OffDelay);
	UpdateLineText_T1(Line,RelayLable[3],OnDelay,'N');

	SSD1306_GotoXY (0,40);
	SSD1306_Puts (Line, &Font_7x10, sel2);

	SSD1306_GotoXY (0,52);
	SSD1306_Puts (FixeLable[4], &Font_7x10, 1);
	SSD1306_UpdateScreen();
}

void Relay1TimeSetting(uint16_t On_Delay,uint16_t Off_Delay,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2)
{
	char OnDelay[20];
	char OffDelay[20];

	SSD1306_Clear();
	SSD1306_GotoXY (0,0);
	SSD1306_Puts (RelayLable[0], &Font_11x18, 1);


		sprintf(OnDelay,"%d",On_Delay);
		sprintf(OffDelay,"%d",Off_Delay);

		strcat(OnDelay,"m");
		strcat(OffDelay,"m");
		//On Delay - 1 UPDATE
		UpdateLineText(Line,TimeLable[0],OnDelay);
		SSD1306_GotoXY (0,25);
		SSD1306_Puts (Line, &Font_7x10, sel1);

		//Off Delay - 1 UPDATE
		UpdateLineText(Line,TimeLable[1],OffDelay);
		SSD1306_GotoXY (0,40);
		SSD1306_Puts (Line, &Font_7x10, sel2);

		SSD1306_GotoXY (0,52);
		SSD1306_Puts (FixeLable[4], &Font_7x10, 1);
		SSD1306_UpdateScreen();
}

void Relay2TimeSetting(uint16_t On_Delay,uint16_t Off_Delay,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2)
{
	char OnDelay[20];
	char OffDelay[20];

	SSD1306_Clear();
	SSD1306_GotoXY (0,0);
	SSD1306_Puts (RelayLable[1], &Font_11x18, 1);


		sprintf(OnDelay,"%d",On_Delay);
		sprintf(OffDelay,"%d",Off_Delay);
		strcat(OnDelay,"m");
		strcat(OffDelay,"m");
		//On Delay - 1 UPDATE
		UpdateLineText(Line,TimeLable[0],OnDelay);
		SSD1306_GotoXY (0,25);
		SSD1306_Puts (Line, &Font_7x10, sel1);

		//Off Delay - 1 UPDATE
		UpdateLineText(Line,TimeLable[1],OffDelay);
		SSD1306_GotoXY (0,40);
		SSD1306_Puts (Line, &Font_7x10, sel2);

		SSD1306_GotoXY (0,52);
		SSD1306_Puts (FixeLable[4], &Font_7x10, 1);
		SSD1306_UpdateScreen();
}

void Message1()
{
	SSD1306_Clear();
	SSD1306_GotoXY (0,20);
	SSD1306_Puts ("SAVING TIME..", &Font_11x18, 1);
	SSD1306_UpdateScreen();
	HAL_Delay(200);
}

void RelaySetting(FlagStatus R1,FlagStatus R2,SSD1306_COLOR_t sel1 , SSD1306_COLOR_t sel2)
{
	char S[20];
	char OffDelay[20];

	SSD1306_Clear();
	SSD1306_GotoXY (0,0);
	SSD1306_Puts (FixeLable[1], &Font_11x18, 1);

	//RELAY - 1 UPDATE
	if(R1)
	{
		UpdateLineText(Line,RelayLable[0],"Enable");
	}
	else
	{
		UpdateLineText(Line,RelayLable[0],"Disable");
	}
	SSD1306_GotoXY (0,25);
	SSD1306_Puts (Line, &Font_7x10, sel1);

	//RELAY - 2 UPDATE
	if(R2)
	{
		UpdateLineText(Line,RelayLable[1],"Enable");
	}
	else
	{
		UpdateLineText(Line,RelayLable[1],"Disable");
	}
	SSD1306_GotoXY (0,40);
	SSD1306_Puts (Line, &Font_7x10, sel2);

	SSD1306_GotoXY (0,52);
	SSD1306_Puts (FixeLable[4], &Font_7x10, 1);
	SSD1306_UpdateScreen();
}















void UpdateLineText(char line[] , char* s1 , char* s2)
{
	memset(line,'\0',20);
	int i =0;
	while(*s1 != '\0')
	{
		line[i] = *s1;
		s1++;
		i++;
	}
	line[i] = ' ';
	i++;
	line[i] = '=';
	i++;
	while(*s2 != '\0')
	{
		line[i] = *s2;
		s2++;
		i++;
	}
}
void UpdateLineText_T1(char line[] , char* s1 , char* s2, char sperator)
{
	memset(line,'\0',20);
	int i =0;
	while(*s1 != '\0')
	{
		line[i] = *s1;
		s1++;
		i++;
	}
	line[i] = sperator;
	i++;
	line[i] = '=';
	i++;
	while(*s2 != '\0')
	{
		line[i] = *s2;
		s2++;
		i++;
	}
}
