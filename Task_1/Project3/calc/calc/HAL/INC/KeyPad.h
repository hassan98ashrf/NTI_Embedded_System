/*
 * KeyPad.h
 *
 * Created: 10/26/2023 8:28:45 PM
 *  Author: hassa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stdint.h"



#define ROWS 4
#define COLS 4

#define FIRST_INPUT  PIND3
#define FIRST_OUTPUT PINC2

#define NO_KEY 'T'

void KEYPAD_Init(void);
uint8_t KEYPAD_GetKey(void);





#endif /* KEYPAD_H_ */