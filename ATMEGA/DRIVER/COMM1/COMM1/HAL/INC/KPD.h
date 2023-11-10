/*
 * KPD.h
 *
 * Created: 10/29/2023 7:39:32 PM
 *  Author: Hassan
 */ 


#ifndef KPD_H_
#define KPD_H_


#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"


#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT				PORTD
#define DataDir_KEYPAD_PORT		DDRD
#define keypadPIN				PIND


void Keypad_init();
char Keypad_getkey();


#endif /* KPD_H_ */