/*
 * DIO.h
 *
 * Created: 10/26/2023 10:55:53 AM
 *  Author: hassa
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "UTILS.h"

typedef enum{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_PinType;



typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus;

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_PortType;


typedef enum{
	LOW,
	HIGH
}DIO_VoltageType;

void DIO_Init(void);
DIO_VoltageType DIO_ReadPin (DIO_PinType pin);
void DIO_WritePin (DIO_PinType pin,DIO_VoltageType volt);
void DIO_TogglePin (DIO_PinType pin);
void DIO_WritePort (DIO_PortType port ,uint8_t data);
uint8_t  DIO_ReadPort (DIO_PortType port);
void DIO_InitPin(DIO_PinType pin ,DIO_PinStatus status);
extern const DIO_PinStatus DIO_PinsStatusArr[TOTAL_PINS];



#endif /* DIO_H_ */