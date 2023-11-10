/*
 * KPD.h
 *
 * Created: 10/29/2023 1:55:32 PM
 *  Author: Hassan
 */ 


#ifndef KPD_H_
#define KPD_H_
#include "GPIO.h"
// Keypad Information
#define R0 PIN_3
#define R1 PIN_2
#define R2 PIN_1
#define R3 PIN_0
#define C0 PIN_4
#define C1 PIN_5
#define C2 PIN_6
#define C3 PIN_7

#define KEYPAD_PORT PORTC
#define KEYPAD_PIN PINC
#define KEYPAD_DataDir DDRC

// Keypad Functions and global variables

void KEYPAD_INIT();
char KEYPAD_GET_KEY();

#endif /* KPD_H_ */