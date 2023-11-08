#ifndef INC_ATmega32_H_
#define INC_ATmega32_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//INCLUDES
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include <stdlib.h>
#include <stdint.h>

//==================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Base address for peripherals
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//////////DIO

#define PORTA_Address	(0x3B)
#define DDRA_Address	(0x3A)
#define PINA_Address	(0x39)

#define PORTB_Address	(0x38)
#define DDRB_Address	(0x37)
#define PINB_Address	(0x36)

#define PORTC_Address	(0x35)
#define DDRC_Address	(0x34)
#define PINC_Address	(0x33)

#define PORTD_Address	(0x32)
#define DDRD_Address	(0x31)
#define PIND_Address	(0x30)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripherals instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//////////DIO

#define PORTA 	*((volatile uint8_t*)PORTA_Address)
#define DDRA 	*((volatile uint8_t*)DDRA_Address)
#define PINA 	*((volatile uint8_t*)PINA_Address)

#define PORTB 	*((volatile uint8_t*)PORTB_Address)
#define DDRB 	*((volatile uint8_t*)DDRB_Address)
#define PINB 	*((volatile uint8_t*)PINB_Address)

#define PORTC 	*((volatile uint8_t*)PORTC_Address)
#define DDRC 	*((volatile uint8_t*)DDRC_Address)
#define PINC 	*((volatile uint8_t*)PINC_Address)

#define PORTD 	*((volatile u8*)PORTD_Address)
#define DDRD 	*((volatile u8*)DDRD_Address)
#define PIND 	*((volatile u8*)PIND_Address)

#endif