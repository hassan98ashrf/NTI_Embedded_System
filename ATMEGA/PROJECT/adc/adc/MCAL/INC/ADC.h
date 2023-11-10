/*
 * ADC.h
 *
 * Created: 11/2/2023 11:48:08 AM
 *  Author: hassa
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD.h"
#include "type.h"
#include "ADC.h"

#define ADMUX_Reg           (*((volatile u8*)0x27))

#define  REFS1		7
#define  REFS0		6
#define  ADLAR		5
#define  MUX4		4
#define  MUX3	    3
#define  MUX2	   	2
#define  MUX1		1
#define  MUX0		0


#define ADCSRA_Reg          (*((volatile u8*)0x26))
#define  ADEN		7
#define  ADSC		6
#define  ADATE		5
#define  ADIF		4
#define  ADIE	    3
#define  ADPS2	   	2
#define  ADPS1		1
#define  ADPS0		0


#define SFIOR_Reg           (*((volatile u8*)0x50))
#define  ADTS2 7
#define  ADTS1 6
#define  ADTS0 5


#define ADCL_Reg           (*((volatile u8*)0x24))
#define ADCH_Reg           (*((volatile u8*)0x25))
#define ADC_DATA_Reg       (*((volatile u16*)0x24))

//--channels----
#define ADC0              0
#define ADC1              1
#define ADC2              2
#define ADC3              3
#define ADC4              4
#define ADC5              5
#define ADC6              6
#define ADC7              7

#define AREF            0
#define AVCC            1
#define Internal_2_56V  3

#define ADC_div_128   7
#define ADC_div_64    6
#define ADC_div_32    5
#define ADC_div_16    4
#define ADC_div_8     3
#define ADC_div_4     2
#define ADC_div_2     1

#define FREE_RUNNING                0
#define ANALOG_COMPARATOR	        1
#define EXTERNAL_INTERRUPT_REQUEST  2
#define Timer0_Compare_Match	    3
#define Timer0_Overflow			    4
#define Timer_Compare_Match_B	    5
#define Timer1_Overflow			    6
#define Timer1_Capture_Event	    7

#define SINGLE_CONVERSION_MODE      8

#define ADC_VOLTAGE_REFERENCE     AVCC

#define TRIGGER_MODE             SINGLE_CONVERSION_MODE

#define ADC_Division_Factor      ADC_div_128

void ADC_init();
u16 ADC_Read( u8 ADC_Channel  ) ;

#endif /* ADC_H_ */