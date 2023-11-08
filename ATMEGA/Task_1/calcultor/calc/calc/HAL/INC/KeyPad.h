/*
 * KeyPad.h
 *
 * Created: 10/26/2023 8:28:45 PM
 *  Author: hassa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "type.h"

#define	NOTPRESSED	0XFF
void Keypad_vInit();
u8	 Keypad_u8Scan();
char Keypad_u8Read();


#endif /* KEYPAD_H_ */