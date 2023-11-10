/*
 * adc.c
 *
 * Created: 11/2/2023 11:29:34 AM
 * Author : hassa
 */ 

#include "STD.h"
#include "type.h"
#include "DIO.h"
#include "EXIT.h"
#include "LCD.h"
#include "ADC.h"


void toggle_portA_PIN0();

int main_exint()
{
	void (*LocalPtr)(void) = NULL;
	// this pin is connected as pull up
	DIO_SetPinDir(DIO_PORTD,Pin2,INPUT);
	//  ,pd2 int0
	EX_INT_SET_MODE(INT0_PIN,IRQ_AT_lOW_LEVEL);
	EX_INT_Set_INT0_IRQ_Handler(toggle_portA_PIN0);
	while (1)
	{
		
	}
	
}

void toggle_portA_PIN0()
{
	DIO_SetPinDir(DIO_PORTA,Pin0,OUTPUT);
	DIO_TogglePinValue(DIO_PORTA,Pin0);
}
