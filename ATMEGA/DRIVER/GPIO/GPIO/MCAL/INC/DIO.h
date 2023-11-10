/*
 * INC.h
 *
 * Created: 10/28/2023 11:48:31 AM
 *  Author: Hassan
 */ 


#ifndef INC_H_
#define INC_H_

/*******************************************************************************
                                     Includes
 *******************************************************************************/

#include "ATmega32.h"


//@ref 1
#define INPUT			0
#define OUTPUT			1
#define INPUT_PULLUP	3

//@ref 2
#define LOW				0
#define HIGH			1

//@ref 3
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
	
//@ref 4
typedef enum
{
	PORT_A ,
	PORT_B ,
	PORT_C ,
	PORT_D ,
}PORTS;

/********************************************************************************************
			 All ports and pins should be selected from @ref 3 & @ref 4
*********************************************************************************************/
   
void pinMode(PORTS PORT , DIO_PinType PIN , uint8_t mode); // Mode must be set from @ref 1
void digitalWrite(PORTS PORT , DIO_PinType PIN , uint8_t value); // Value must be set from @ref 1
void digitalToggle(PORTS PORT , DIO_PinType PIN);
uint8_t digitalRead(PORTS PORT , DIO_PinType PIN);

void portMode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void portWrite(PORTS PORT , uint8_t value); // Value must be set from @ref 1
void portToggle(PORTS PORT);
uint8_t portRead(PORTS PORT);

// For deal with 4 most bits or 4 lowest bits
void MSB_portMode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void MSB_portWrite(PORTS PORT , uint8_t value); // Value must be set from @ref 1
uint8_t MSB_portRead(PORTS PORT);

void LSB_portMode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void LSB_portWrite(PORTS PORT , uint8_t value); // Value must be set from @ref 1
uint8_t LSB_portRead(PORTS PORT);



#endif /* INC_H_ */