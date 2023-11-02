/*
 * DIO.h
 *
 * Created: 11/2/2023 11:32:15 AM
 *  Author: hassa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "stdint.h"

//pins Dir
#define In 0
#define OUT 1

//portA PIN Dir
#define DDRAPIN0 In
#define DDRAPIN1 In
#define DDRAPIN2 OUT
#define DDRAPIN3 OUT
#define DDRAPIN4 In
#define DDRAPIN5 OUT
#define DDRAPIN6 OUT
#define DDRAPIN7 OUT

//portB PIN Dir
#define DDRBPIN0 OUT
#define DDRBPIN1 OUT
#define DDRBPIN2 OUT
#define DDRBPIN3 OUT
#define DDRBPIN4 OUT
#define DDRBPIN5 OUT
#define DDRBPIN6 OUT
#define DDRBPIN7 OUT

//portC PIN Dir
#define DDRCPIN0 OUT
#define DDRCPIN1 OUT
#define DDRCPIN2 OUT
#define DDRCPIN3 OUT
#define DDRCPIN4 OUT
#define DDRCPIN5 OUT
#define DDRCPIN6 OUT
#define DDRCPIN7 OUT

//portD PIN Dir
#define DDRDPIN0 OUT
#define DDRDPIN1 OUT
#define DDRDPIN2 In
#define DDRDPIN3 OUT
#define DDRDPIN4 OUT
#define DDRDPIN5 OUT
#define DDRDPIN6 OUT
#define DDRDPIN7 OUT

//portA
#define PORTA *((volatile uint8_t*) 0x3B)
#define DDRA *((volatile uint8_t*) 0x3A)
#define PINA *((volatile uint8_t*) 0x39)

//portB
#define PORTB *((volatile uint8_t*) 0x38)
#define DDRB *((volatile uint8_t*) 0x37)
#define PINB *((volatile uint8_t*) 0x36)

//portc
#define PORTC *((volatile uint8_t*) 0x35)
#define DDRC *((volatile uint8_t*) 0x34)
#define PINC *((volatile uint8_t*) 0x33)

//portD
#define PORTD *((volatile uint8_t*) 0x32)
#define DDRD *((volatile uint8_t*) 0x31)
#define PIND *((volatile uint8_t*) 0x30)

void DIO_init();
void DIO_SetPinVal(uint8_t portName, uint8_t pinNum, uint8_t val);
void DIO_SetPortVal(uint8_t portName, uint8_t val);
uint8_t DIO_ReadPinVal(uint8_t portName, uint8_t pinNum);
uint8_t DIO_ReadPortVal(uint8_t portName);
void DIO_TogglePin(uint8_t portName, uint8_t pinNum);


#endif /* DIO_H_ */