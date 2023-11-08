/*
 * ATmeag32.h
 *
 * Created: 10/21/2023 9:59:19 PM
 *  Author: hassa
 */ 


#ifndef ATMEAG32_H_
#define ATMEAG32_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============= Clock Macro ============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define F_CPU 16000000
#include <util/delay.h> 
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

//PORT_A_REGISTERS
#define PORTA (*(volatile uint8_t*)0x3B) //output reg
#define DDRA  (*(volatile uint8_t*)0x3A) //direction reg
#define PINA  (*(volatile uint8_t*)0x39) //input reg
//PORT_B_REGISTERS
#define PORTB (*(volatile uint8_t*)0x38)
#define DDRB  (*(volatile uint8_t*)0x37)
#define PINB  (*(volatile uint8_t*)0x36)
//PORT_C_REGISTERS
#define PORTC (*(volatile uint8_t*)0x35)
#define DDRC  (*(volatile uint8_t*)0x34)
#define PINC  (*(volatile uint8_t*)0x33)
//PORT_D_REGISTERS
#define PORTD (*(volatile uint8_t*)0x32)
#define DDRD  (*(volatile uint8_t*)0x31)
#define PIND  (*(volatile uint8_t*)0x30)


#define SET_BIT(REG,BIT) REG |=(1<<BIT)
#define CLR_BIT(REG,BIT) REG &=(~(1<<BIT))
#define TOG_BIT(REG,BIT) REG ^= (1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)


#endif /* ATMEAG32_H_ */