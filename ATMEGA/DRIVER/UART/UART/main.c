/*
 * UART.c
 *
 * Created: 10/29/2023 1:28:44 AM
 * Author : Hassan
 */ 




#include "LCD.h"
#include "USART.h"
#include "KPD.h"
#include "GPIO.h"

#define NO_PRESSED_KEY 0xFF
uint8_t key = NO_PRESSED_KEY;


int main(void)
{
	//Initialize LCD
	LCD_init();
	KEYPAD_INIT();
	char val ;
	

	while (1)
	{
		
		val = KEYPAD_GET_KEY();
		switch(val)
		{
			case '!' :
			break;
			
			case '?' :
			LCD_clear_screen();
			break;
			
			default:
			LCD_Send_A_Character(val);
		}
	}
}