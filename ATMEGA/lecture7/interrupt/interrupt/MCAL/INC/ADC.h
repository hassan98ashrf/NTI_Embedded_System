/*
 * ADC.h
 *
 * Created: 10/23/2023 11:08:13 AM
 *  Author: amlta
 */ 


#ifndef ADC_H_
#define ADC_H_
//---------
//Includes
//---------
#include "ATmega32.h"


typedef enum
{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
}ADC_VREF_TYPE;

typedef enum
{
	ADC_SCALER_2=0,
	ADC_SCALER_4=2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
}ADC_SCALAR_TYPE;




typedef enum
{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_CHANNEL_TYPE;

void ADC_init(ADC_VREF_TYPE vref , ADC_SCALAR_TYPE scaler);
uint16_t ADC_READ(ADC_CHANNEL_TYPE);
void start_conv();



#endif /* ADC_H_ */