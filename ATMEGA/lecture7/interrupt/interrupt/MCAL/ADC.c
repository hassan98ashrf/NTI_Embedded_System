/*
 * ADC.c
 *
 * Created: 7/1/2023 10:52:42 PM
 *  Author: hassa
 */ 


//---------
//Includes
//---------
#include "ADC.h"
		
//---------------
//macros function
//---------------	
void (*P_ADC_CallBack)();		



void ADC_init(ADC_VREF_TYPE vref , ADC_SCALAR_TYPE scaler)
{
	

	#if scaler == ADC_SCALER_2
	SET_BIT(ADCSRA,ADPS0);
	#elif scaler == ADC_SCALER_4
	SET_BIT(ADCSRA,ADPS1);
	#elif scaler == ADC_SCALER_8
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	#elif scaler == ADC_SCALER_16
	SET_BIT(ADCSRA,ADPS2);
	#elif scaler == ADC_SCALER_32
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS2);
	#elif scaler == ADC_SCALER_64
	SET_BIT(ADCSRA,ADPS1); // Choose the Prescalar
	SET_BIT(ADCSRA,ADPS2);
	#elif scaler == ADC_SCALER_128
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#endif
	
	switch(vref){
		case VREF_AREF:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case VREF_AVCC:
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case VREF_256:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
	}

	ADCSRA &=0xf8;
	ADCSRA |= scaler;
	SET_BIT(ADCSRA,ADEN);
	
}

uint16_t ADC_READ(ADC_CHANNEL_TYPE channel)
{
	ADMUX = (ADMUX & 0xE0) | (ADMUX | channel);
	
	SET_BIT(ADCSRA,ADSC);
	
	start_conv();

	uint8_t lowByte = ADCL;
	uint8_t highByte = ADCH;

	// Combine the two 8-bit registers to get the 10-bit ADC result
	uint8_t result = (highByte << 8) | lowByte;

	return result;
}

void start_conv(){
	while(GET_BIT(ADCSRA,ADSC));
	CLR_BIT(ADCSRA,ADIF);
}





