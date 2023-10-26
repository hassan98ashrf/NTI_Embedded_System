/*
 * DIO.c
 *
 * Created: 10/26/2023 11:08:38 AM
 *  Author: hassa
 */ 


#include "DIO.h"

const DIO_PinStatus DIO_PinsStatusArr[TOTAL_PINS]={
	INFREE,      /* Port A Pin 0 ADC0*/
	OUTPUT,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	INFREE,      /* Port A Pin 7 ADC7*/
	OUTPUT,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/
	OUTPUT,		 /* Port B Pin 3   /OC0*/
	OUTPUT,		 /* Port B Pin 4 /ss*/
	OUTPUT,		 /* Port B Pin 5 //mosi*/
	OUTPUT,		 /* Port B Pin 6 /miso*/
	OUTPUT,		 /* Port B Pin 7 clk*/
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	OUTPUT,		 /* Port D Pin 0 */
	OUTPUT,		 /* Port D Pin 1 */
    INPULL,      /* Port D Pin 2 /INT0*/
	INPULL,      /* Port D Pin 3 / INT1 */
	OUTPUT,		 /* Port D Pin 4  OC1B*/
	INPULL,		 /* Port D Pin 5 OC1A*/
	INPULL,		 /* Port D Pin 6 /   ICP*/
	INPULL		 /* Port D Pin 7 */
};

void DIO_Init(void)
{
	DIO_PinType i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,DIO_PinsStatusArr[i]);
	}
}

void DIO_InitPin(DIO_PinType pin ,DIO_PinStatus status)
{
	uint8_t pin_num = pin%8;
	DIO_PortType port =pin/8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
			
		}
		break;
		
	}
}
DIO_VoltageType DIO_ReadPin (DIO_PinType pin)
{
	DIO_VoltageType volt=LOW;
	uint8_t pin_num =pin%8;
	DIO_PortType port =pin/8;
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		volt=READ_BIT(PIND,pin_num);
		break;
		
	}
	return volt;
}
void DIO_WritePin (DIO_PinType pin,DIO_VoltageType volt)
{
	uint8_t pin_num =pin%8;
	DIO_PortType port =pin/8;
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
			
		}
	}
	else
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
			
		}
	}
	
}
void DIO_TogglePin (DIO_PinType pin)
{
	uint8_t pin_num =pin%8;
	DIO_PortType port =pin/8;
	switch(port)
	{
		case PA:
		TGL_BIT(PORTA,pin_num);
		break;
		case PB:
		TGL_BIT(PORTB,pin_num);
		break;
		case PC:
		TGL_BIT(PORTC,pin_num);
		break;
		case PD:
		TGL_BIT(PORTD,pin_num);
		break;
		
	}
}
void DIO_WritePort (DIO_PortType port ,uint8_t data)
{
	switch(port)
	{
		case PA:
		PORTA= data;
		break;
		case PB:
		PORTB= data;
		break;
		case PC:
		PORTC= data;
		break;
		case PD:
		PORTD= data;
		break;
		
	}
}
uint8_t  DIO_ReadPort (DIO_PortType port)
{
	
	uint8_t data=0;
	switch(port)
	{
		case PA:
		data =PORTA;
		break;
		case PB:
		data =PORTB;
		break;
		case PC:
		data =PORTC;
		break;
		case PD:
		data =PORTD;
		break;
		
	}
	return data ;
	
}