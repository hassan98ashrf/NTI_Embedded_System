/*
 * KPD.h
 *
 * Created: 10/28/2023 12:44:16 PM
 *  Author: Hassan
 */ 


#ifndef KPD_H_
#define KPD_H_

#include "DIO.h"

#define ROWS 4
#define COLS 4

#define FIRST_INPUT  PIND3
#define FIRST_OUTPUT PINC2

#define NO_KEY 'T'

void KEYPAD_Init(void);
uint8_t KEYPAD_GetKey(void);


#endif /* KPD_H_ */