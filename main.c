#include "stm32f10x.h"
#include "lcd.h"
#include "delay.h"
#include "spi.h"
#include "led.h"
#include "SDCARD.h"
#include "Fat.h"


int main()
{
	//uint8_t responsedata=0;
	
	delayinit();
	delay_ms(10);
	SPI1_Init();
	
	SPI2init();
	
	LED_Init();
	LCD_Init();
	
	
	
	LCD_Clear(BLACK);
	POINT_COLOR=WHITE;
	
	LCD_ShowString(1,1,150,18,16,"SDCard Response:");
	if(SDCardBegin() == 1)
		{
			SDMBRRead();
			SDFATGetInfo();	
			LCD_ShowString(130,1,120,16,16,"Complete");
	
			SDCardDisplayinfo();	
			delay_ms(500);
			LCD_Clear(BLACK);
			SDFatDisplayInfo();
			delay_ms(500);
			LCD_Clear(BLACK);
			SDlocateRootDir();
		}
		
}
