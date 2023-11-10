/*
 * I2C.h
 *
 * Created: 10/31/2023 2:00:01 PM
 *  Author: Hassan
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char cByte);
void I2C_Stop();




#endif /* I2C_H_ */