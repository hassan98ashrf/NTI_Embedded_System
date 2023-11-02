/*
 * ADC.h
 *
 * Created: 11/2/2023 11:48:08 AM
 *  Author: hassa
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "STD.h"
#include "stdint.h"

#define ADCSRA *((volatile uint8_t*)0x26)
#define ADMUX  *((volatile uint8_t*)0x27)
#define ADCW  *((volatile uint16_t*)0x24)
#define ADCL  *((volatile uint8_t*)0x24)
#define ADCH  *((volatile uint8_t*)0x25)
#define SFIOR	*((volatile uint8_t*)0x26)

#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADTS0 5
#define ADTS1 6
#define ADTS2 7

/*Prescaler Options*/
#define PRESCALER2   0
#define PRESCALER4   2
#define PRESCALER8   3
#define PRESCALER16  4
#define PRESCALER32  5
#define PRESCALER64  6
#define PRESCALER128 7


/*ADC Channels*/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#define ADC0_PIN 0
#define ADC1_PIN 1
#define ADC2_PIN 2
#define ADC3_PIN 3
#define ADC4_PIN 4
#define ADC5_PIN 5
#define ADC6_PIN 6
#define ADC7_PIN 7

#define WRITE_ADJUSTMENT 0
#define LEFT_ADJUSTMENT 1

#define ENABLE 1
#define DISABLE 0

#define AREF 0
#define AVCC 1
#define Internal_Voltage 2

#define Free_Running_mode 0
#define Analog_Comparator 1
#define External_Interrupt0 2
#define Timer0_Compare_Match 3
#define Timer0_Overflow 4
#define  Timer1_Compare_MatchB 5
#define Timer1_Overflow 6
#define Timer1_Capture_Event 7

#define  ADC_AUTO_TRIGGER_EN ENABLE

#define ADC_AUTO_TRIGGER_SOURCE Free_Running_mode

#define Voltage_reference AVCC

#define PRESCALLER PRESCALER64

#define ADJUSTMENT LEFT_ADJUSTMENT

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7



uint8_t ADC_GetValsync(uint8_t addresscpy);
void ADC_vInt(void);
void ADC_voidStartConversion(uint8_t addresscpy);
void ADC_voidDisable();
void ADC_voidEnable();

void ADC_voidEnableInt();
void ADC_voidDisableInt();
uint8_t ADC_GetValAsync();
void EXT16_VID_SET_CALL_BACK(void (*PTR0)(void));

void __vector_16 (void) __attribute__ ((signal,used, externally_visible));

#endif /* ADC_H_ */