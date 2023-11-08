/*
 * ADC.c
 *
 * Created: 11/2/2023 11:50:54 AM
 *  Author: hassa
 */ 
#define F_CPU   8000000UL

#include "STD.h"
#include "type.h"
#include "ADC.h"
#include "DIO.h"


void ADC_init()
{
	#if (ADC_VOLTAGE_REFERENCE == AVCC)
	ADMUX_Reg =(AVCC<<REFS0);
	#endif

	#if (TRIGGER_MODE == SINGLE_CONVERSION_MODE)
	ADCSRA_Reg = ADC_Division_Factor |(1<<ADEN) | (ADIE);
	#elif (TRIGGER_MODE == FREE_RUNNIGN)
	// set bit 5
	ADCSRA_Reg |=(1<<5);
	#endif
}


u16 ADC_Read( u8 ADC_Channel  )
{
	// select channel
	ADMUX_Reg |=(ADC_Channel<<0);
	// set pin input
	DIO_SetPinDir(DIO_PORTA,ADC_Channel,INPUT);
	// start conversion
	ADCSRA_Reg |=(1<<6);
	while ( (   (ADCSRA_Reg>>4) & (0x01)  ) == 0);
	// clear flag bit if not done in the ISR
	ADCSRA_Reg &=~(1<<4);

	return (ADC_DATA_Reg & 0x03ff );
}