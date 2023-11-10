/*
 * interrupt.c
 *
 * Created: 10/22/2023 12:08:43 PM
 * Author : amlta
 */ 


#include "LCD.h"
#include "DIO.h"
#include "ADC.h"



int main()
{
	uint32_t lm_read;
	
	//uint16_t blink[16] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	
	LCD_init();

	ADC_init(VREF_AVCC,ADC_SCALER_64);
	LCD_GOTO_XY(1,0);
	LCD_Clear_screen();
	LCD_write_string("Lm35 : ");

	while (1)
	{
		//LCD_write_string("   ");
		LCD_GOTO_XY(2, 10);
		lm_read = (uint16_t)(ADC_READ(CH_7));
		lm_read =(uint16_t) (((uint16_t)lm_read * 150*5)/(1023*1.5));
		LCD_write_num(lm_read);
		LCD_write_char('C');
		LCD_Clear_screen();
		_delay_ms(500);

	}

	return 0;
}