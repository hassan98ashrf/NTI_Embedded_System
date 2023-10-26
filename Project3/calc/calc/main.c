/*
 * calc.c
 *
 * Created: 10/26/2023 7:57:08 PM
 * Author : hassa
 */ 


#include "UTILS.h"
#include "DIO.h"
#include "LCD.h"
#include "KeyPad.h"

#define NO_PRESSED_KEY 0xFF


uint8_t key = NO_PRESSED_KEY;

int main()
{
	DIO_Init();
	DIO_Init();
	LCD_Init();
	
	
	while(1)
	{
		key = KEYPAD_GetKey();
		LCD_WriteChar(key);
	}
	
}