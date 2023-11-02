/*
 * KeyPad.h
 *
 * Created: 10/26/2023 8:28:45 PM
 *  Author: hassa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define ROWS_PORT PC
#define COLS_PORT PD

#define ROW1 5
#define ROW2 4
#define ROW3 3
#define ROW4 2
#define COL1 7
#define COL2 6
#define COL3 5
#define COL4 3

void KEYPAD_INIT();
uint8_t KEYPAD_READ();

#endif /* KEYPAD_H_ */