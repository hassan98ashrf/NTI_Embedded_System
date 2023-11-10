/*
 * Atmega32.h
 *
 * Created: 10/20/2023 10:47:43 AM
 *  Author: amlta
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============== Includes ==============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#define F_CPU 8000000UL

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============== Includes ==============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#include "util/delay.h"



#define IO_Registers		0x0020
#define ADC_Base_										0x24




//GPIO

typedef struct  {
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;
}GPIO_t;


//GPIO

//PORT A
#define PORTA_base	 *((volatile unsigned char*) 0x3B)
#define DDRA_base	 *((volatile unsigned char*) 0x3A)
#define PINA_base	 *((volatile unsigned char*) 0x39)

//PORT B
#define PORTB_base	 *((volatile unsigned char*) 0x38)
#define DDRB_base	 *((volatile unsigned char*) 0x37)
#define PINB_base	 *((volatile unsigned char*) 0x36)

//PORT C
#define PORTC_base	 *((volatile unsigned char*) 0x35)
#define DDRC_base	 *((volatile unsigned char*) 0x34)
#define PINC_base	 *((volatile unsigned char*) 0x33)

//PORT D
#define PORTD_base	 *((volatile unsigned char*) 0x32)
#define DDRD_base	 *((volatile unsigned char*) 0x31)
#define PIND_base	 *((volatile unsigned char*) 0x30)


//PORT A
#define PORTA	 ((GPIO_t*) PORTA_base)
#define DDRA	 ((GPIO_t*) DDRA_base)
#define PINA	 ((GPIO_t*) PINA_base)

//PORT B
#define PORTB	 ((GPIO_t*) PORTB_base)
#define DDRB	 ((GPIO_t*) DDRB_base)
#define PINB	 ((GPIO_t*) PINB_base)

//PORT C
#define PORTC	 ((GPIO_t*) PORTC_base)
#define DDRC	 ((GPIO_t*) DDRC_base)
#define PINC	 ((GPIO_t*) PINC_base)

//PORT D
#define PORTD	 *((GPIO_t*) PORTD_base)
#define DDRD	 *((GPIO_t*) DDRD_base)
#define PIND	 *((GPIO_t*) PIND_base)

#define ADMUX		(*(volatile unsigned char*)0x27)
#define ADLAR		 5
#define REFS0		 6
#define REFS1		 7

#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)

#define ADC_								(*(volatile unsigned char*)(ADC_Base_))


//Enable Interrupts

#define SREG				*((volatile uint8_t *)(0x5F))

#define ENABLE_INT()		SREG |= (1<<7)

#define DISABLE_INT()		SREG &= ~(1<<7)

/*External Interrupt */
#define MCUCSR   (*(volatile unsigned char*)0x54)
#define ISC2 6

#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define GICR     (*(volatile unsigned char*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR    (*(volatile unsigned char*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5


#define SET_BIT(reg,bit) (reg |= (1<< bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit) (reg ^= (1<< bit))
#define GET_BIT(reg,bit) ((reg>>bit) & 0x1)

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20



/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)


#define ISR_NOBLOCK    __attribute__((interrupt))
#define ISR_NAKED      __attribute__((naked))    // It will force the compiler to not write anything (No pushing or popping or even reti ), it will execute what you wrote only in assembly


// Variadic macro-like a function ,....
// You tell him that he will receive a main variable (vect), There might be another variable, if you receive it or not, don't make an error
// Where it will be replaced ?? instead of __VA_ARGS___ (Variadic arguments)

#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)


#endif /* ATMEGA32_H_ */