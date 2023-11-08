/*
 * calc.c
 *
 * Created: 10/26/2023 7:57:08 PM
 * Author : hassa
 */ 


#define  F_CPU 8000000UL
#include "STD.h"
#include "type.h"
#include "DIO.h"
#include "KeyPad.h"
#include "LCD.h"
#include "util/delay.h"

u8 GlobalLineArray[50] = {0};
int main()
{
	Keypad_vInit();
	LCD_vInit();
	while (1)
	{
		u8 counter =0;
		u8 LocKeypadVal = Keypad_u8Read();
		if(LocKeypadVal == NOTPRESSED)
		{
			continue;
		}
		else if(LocKeypadVal == '=')
		{
			// go for processing
			LCD_vWriteData(LocKeypadVal);
		}
		else
		{
			GlobalLineArray[counter] = LocKeypadVal;
			LCD_vWriteData(LocKeypadVal);
			counter++;
			LocKeypadVal = NOTPRESSED;
		}
	}
}