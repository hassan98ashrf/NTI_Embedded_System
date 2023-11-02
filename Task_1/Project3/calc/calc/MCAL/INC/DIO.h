/*
 * DIO.h
 *
 * Created: 10/26/2023 10:55:53 AM
 *  Author: hassa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "MEMmap.h"
#include "STD.h"
#include "stdint.h"

//pins Dir//////////////
#define In 0
#define OUT 1

//portA PIN Dir
#define DDRAPIN0 OUT
#define DDRAPIN1 OUT
#define DDRAPIN2 OUT
#define DDRAPIN3 OUT
#define DDRAPIN4 OUT
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
#define DDRDPIN2 OUT
#define DDRDPIN3 In
#define DDRDPIN4 OUT
#define DDRDPIN5 In
#define DDRDPIN6 In
#define DDRDPIN7 In


void DIO_init();
void DIO_SetPinVal(uint8_t portName, uint8_t pinNum, uint8_t val);
void DIO_SetPortVal(uint8_t portName, uint8_t val);
uint8_t DIO_ReadPinVal(uint8_t portName, uint8_t pinNum);
uint8_t DIO_ReadPortVal(uint8_t portName);
void DIO_TogglePin(uint8_t portName, uint8_t pinNum);
void DIO_EN_PULLUP(uint8_t portName, uint8_t pinNum);


#endif /* DIO_H_ */