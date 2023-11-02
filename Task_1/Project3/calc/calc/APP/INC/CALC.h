/*
 * CALC.h
 *
 * Created: 11/1/2023 5:04:14 PM
 *  Author: hassa
 */ 


#ifndef CALC_H_
#define CALC_H_

#define F_CPU 8000000
#include "DIO.h"
#include "util/delay.h"
#include "LCD.h"
#include "KeyPad.h"

void Calc_init(void);
void  shiftArr(uint8_t index);
void calc_CalculateResult();
void calc_DisplayResult();
void calc_toint(uint8_t digit);
void calc_CheckNum(uint8_t num);
void Calculator();


#endif /* CALC_H_ */