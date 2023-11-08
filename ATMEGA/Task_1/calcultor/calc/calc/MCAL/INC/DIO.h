/*
 * DIO.h
 *
 * Created: 10/26/2023 10:55:53 AM
 *  Author: hassa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "type.h"
#define PORTA   (*(volatile u8*)(0x3B))
#define DDRA    (*(volatile u8*)(0x3A))
#define PINA    (*(volatile u8*)(0x39))

#define PORTB   (*(volatile u8*)(0x38))
#define DDRB    (*(volatile u8*)(0x37))
#define PINB    (*(volatile u8*)(0x36))

#define PORTC   (*(volatile u8*)(0x35))
#define DDRC    (*(volatile u8*)(0x34))
#define PINC    (*(volatile u8*)(0x33))


#define PORTD  (*(volatile u8*)(0x32))
#define DDRD   (*(volatile u8*)(0x31))
#define PIND    (*(volatile u8*)(0x30))

typedef enum{DIO_PORTA,DIO_PORTB, DIO_PORTC, DIO_PORTD} PORT_TYPE;
typedef enum{LOW, HIGH , INPUT, OUTPUT} MODE_TYPE;
typedef enum {Pin0, Pin1, Pin2, Pin3, Pin4, Pin5, Pin6,Pin7}PIN_TYPE;


void DIO_SetPinDir(PORT_TYPE, PIN_TYPE, MODE_TYPE);
void DIO_SetPinValue(PORT_TYPE,PIN_TYPE,MODE_TYPE);

u8 Dio_GetPinValue(PORT_TYPE,PIN_TYPE);
void Set_InputPullUp(PORT_TYPE,PIN_TYPE);
void DIO_TogglePinValue(PORT_TYPE,PIN_TYPE);

#endif /* DIO_H_ */