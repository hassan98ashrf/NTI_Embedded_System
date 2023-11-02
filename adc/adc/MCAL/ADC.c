/*
 * ADC.c
 *
 * Created: 11/2/2023 11:50:54 AM
 *  Author: hassa
 */ 
#include "ADC.h"
//#include "util/delay.h"

void (*Callback)(void) = NULL;

void ADC_voidEnable()
{
	SET_BIT(ADCSRA,ADEN);
}

void ADC_voidDisable()
{
	CLR_BIT(ADCSRA,ADEN);
}


void ADC_voidStartConversion(uint8_t addresscpy)
{
	ADMUX=(ADMUX&0xE0)|addresscpy;
	SET_BIT(ADCSRA,ADSC);
}


void ADC_vInt(void)
{
	
	switch(Voltage_reference)
	{
		case 0:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case 1:
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case 2:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
	}
	
	switch(ADJUSTMENT)
	{
		case 0:
			CLR_BIT(ADMUX,ADLAR);
			break;
		case 1:
			SET_BIT(ADMUX,ADLAR);
			break;
	}
	
	switch(PRESCALLER)
	{
		case 0:
			SET_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
		case 1:
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
		case 2:
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
			break;
		
		case 3:
			CLR_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
			
		case 4:
			SET_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
			
		case 5:
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
			
		case 6:
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
			break;
	}
	switch(ADC_AUTO_TRIGGER_EN)
	{
		
		case 0:
		ADC_voidDisableInt();
		break;
		
		case 1:
		switch(ADC_AUTO_TRIGGER_SOURCE)
		{
			case 0:
				CLR_BIT(SFIOR, ADTS0);
				CLR_BIT(SFIOR, ADTS1);
				CLR_BIT(SFIOR, ADTS2);
				break;
			case 1:
				SET_BIT(SFIOR, ADTS0);
				CLR_BIT(SFIOR, ADTS1);
				CLR_BIT(SFIOR, ADTS2);
				break;
			case 2: 
				CLR_BIT(SFIOR, ADTS0);
				SET_BIT(SFIOR, ADTS1);
				CLR_BIT(SFIOR, ADTS2);
				break;
			case 3:
				SET_BIT(SFIOR, ADTS0);
				SET_BIT(SFIOR, ADTS1);
				CLR_BIT(SFIOR, ADTS2);
				break;
			case 4:
				CLR_BIT(SFIOR, ADTS0);
				CLR_BIT(SFIOR, ADTS1);
				SET_BIT(SFIOR, ADTS2);
				break;
			case 5:
				SET_BIT(SFIOR, ADTS0);
				CLR_BIT(SFIOR, ADTS1);
				SET_BIT(SFIOR, ADTS2);
				break;
			case 6:
				CLR_BIT(SFIOR, ADTS0);
				SET_BIT(SFIOR, ADTS1);
				SET_BIT(SFIOR, ADTS2);
				break;
			case 7:
				SET_BIT(SFIOR, ADTS0);
				SET_BIT(SFIOR, ADTS1);
				SET_BIT(SFIOR, ADTS2);
				break;
		}
		ADC_voidEnableInt();
		break;
		
		default:
		break;
	}
	
	
	ADC_voidEnable();
}



uint8_t ADC_GetValsync(uint8_t addresscpy)
{
	ADC_voidStartConversion(addresscpy);
	while((READ_BIT(ADCSRA,ADSC)));
	return ADCH;
}


uint8_t ADC_GetValAsync()
{
	return ADCH;
}


void ADC_voidEnableInt()
{
	SET_BIT(ADCSRA, ADIE);
	SET_BIT(ADCSRA, ADATE);
}


void ADC_voidDisableInt()
{
	CLR_BIT(ADCSRA, ADIE);
	CLR_BIT(ADCSRA, ADATE);
}


void EXT16_VID_SET_CALL_BACK(void (*PTR0)(void))
{
	Callback = PTR0;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible));
void __vector_16 (void){  if(Callback != NULL){Callback();}  }