/*
 * DIO.c
 *
 * Created: 11/2/2023 11:37:00 AM
 *  Author: hassa
 */ 
#include "DIO.h"
#include "STD.h"

void DIO_init()
{
	DDRA = conc_Bits(DDRAPIN7 , DDRAPIN6, DDRAPIN5, DDRAPIN4, DDRAPIN3, DDRAPIN2,DDRAPIN1,DDRAPIN0);
	DDRB = conc_Bits(DDRBPIN7 , DDRBPIN6, DDRBPIN5, DDRBPIN4, DDRBPIN3, DDRBPIN2,DDRBPIN1,DDRBPIN0);
	DDRC = conc_Bits(DDRCPIN7 , DDRCPIN6, DDRCPIN5, DDRCPIN4, DDRCPIN3, DDRCPIN2,DDRCPIN1,DDRCPIN0);
	DDRD = conc_Bits(DDRDPIN7 , DDRDPIN6, DDRDPIN5, DDRDPIN4, DDRDPIN3, DDRDPIN2,DDRDPIN1,DDRDPIN0);
}


void DIO_SetPinVal(uint8_t portName, uint8_t pinNum, uint8_t val)
{
	switch(portName)
	{
		case PA:
		if(val == 1) {SET_BIT(PORTA, pinNum);}
		else         {CLR_BIT(PORTA, pinNum);}
		break;
		case PB:
		if(val == 1) {SET_BIT(PORTB, pinNum);}
		else         {CLR_BIT(PORTB, pinNum);}
		break;
		case PC:
		if(val == 1) {SET_BIT(PORTC, pinNum);}
		else         {CLR_BIT(PORTC, pinNum);}
		break;
		case PD:
		if(val == 1) {SET_BIT(PORTD, pinNum);}
		else         {CLR_BIT(PORTD, pinNum);}
		break;
		default:
		break;
	}
}


void DIO_SetPortVal(uint8_t portName, uint8_t val)
{
	switch(portName)
	{
		case PA:
		PORTA = val;
		case PB:
		PORTB = val;
		case PC:
		PORTC = val;
		case PD:
		PORTD = val;
		default:
		break;
	}
}



uint8_t DIO_ReadPinVal(uint8_t portName, uint8_t pinNum)
{
	uint8_t returnValue = 0;
	switch(portName)
	{
		case PA:
		returnValue = READ_BIT(PINA, pinNum);
		break;
		case PB:
		returnValue = READ_BIT(PINB, pinNum);
		break;
		case PC:
		returnValue = READ_BIT(PINC, pinNum);
		break;
		case PD:
		returnValue = READ_BIT(PIND, pinNum);
		break;
		default:
		break;
	}
	return returnValue;
}



uint8_t DIO_ReadPortVal(uint8_t portName)
{
	uint8_t returnValue = 0;
	switch(portName)
	{
		case PA:
		returnValue = PINA;
		break;
		case PB:
		returnValue = PINB;
		break;
		case PC:
		returnValue = PINC;
		break;
		case PD:
		returnValue = PIND;
		break;
		default:
		break;
	}
	return returnValue;
}




void DIO_TogglePin(uint8_t portName, uint8_t pinNum)
{
	switch(portName)
	{
		case PA:
		TOG_BIT(PORTA, pinNum);
		break;
		case PB:
		TOG_BIT(PORTB, pinNum);
		break;
		case PC:
		TOG_BIT(PORTC, pinNum);
		break;
		case PD:
		TOG_BIT(PORTD, pinNum);
		break;
		default:
		break;
	}
}