/*
 * DIO.h
 *
 * Created: 11/3/2023 9:58:38 AM
 *  Author: Hassan
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "stdint.h"

#define PORTA   (*(volatile uint8_t*)(0x3B))
#define DDRA    (*(volatile uint8_t*)(0x3A))
#define PINA    (*(volatile uint8_t*)(0x39))

#define PORTB   (*(volatile uint8_t*)(0x38))
#define DDRB    (*(volatile uint8_t*)(0x37))
#define PINB    (*(volatile uint8_t*)(0x36))

#define PORTC   (*(volatile uint8_t*)(0x35))
#define DDRC    (*(volatile uint8_t*)(0x34))
#define PINC    (*(volatile uint8_t*)(0x33))


#define PORTD  (*(volatile uint8_t*)(0x32))
#define DDRD   (*(volatile uint8_t*)(0x31))
#define PIND   (*(volatile uint8_t*)(0x30))

typedef enum{DIO_PORTA,DIO_PORTB, DIO_PORTC, DIO_PORTD} PORT_TYPE;
typedef enum{LOW, HIGH , INPUT, OUTPUT} MODE_TYPE;
typedef enum {Pin0, Pin1, Pin2, Pin3, Pin4, Pin5, Pin6,Pin7}PIN_TYPE;


void DIO_SetPinDir(PORT_TYPE, PIN_TYPE, MODE_TYPE);
void DIO_SetPinValue(PORT_TYPE,PIN_TYPE,MODE_TYPE);

uint8_t Dio_GetPinValue(PORT_TYPE,PIN_TYPE);
void Set_InputPullUp(PORT_TYPE,PIN_TYPE);
void DIO_TogglePinValue(PORT_TYPE,PIN_TYPE);



#endif /* DIO_H_ */