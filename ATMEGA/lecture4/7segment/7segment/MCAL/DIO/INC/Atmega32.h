/*
 * Atmega32.h
 *
 * Created: 10/17/2023 2:47:27 PM
 *  Author: amlta
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============== Includes ==============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include <util/delay.h>

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============= Clock Macro ============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define F_CPU  8000000UL


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//==== Base addresses for Memories =====
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define DATA_ADRESS_BASE	0x0000
#define IO_Registers		0x0020
#define Internal_SRAM		0x0060





//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//========= Peripheral register ========
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//DIO
typedef struct DIO_t {
	uint8_t PIN;
	uint8_t DDR;
	uint8_t PORT;
}DIO_t;




//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//========= Peripheral Instants ========
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//GPIO/
/*
#define PORTA		((struct GPIO_t*)(IO_Registers + 0x19))
#define PORTB		((struct GPIO_t*)(IO_Registers + 0x16))
#define PORTC		((struct GPIO_t *)(IO_Registers + 0x13))
#define PORTD		((struct GPIO_t *)(IO_Registers + 0x10))
*/









#endif /* ATMEGA32_H_ */