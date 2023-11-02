/*
 * EXIT.h
 *
 * Created: 11/2/2023 11:42:31 AM
 *  Author: hassa
 */ 


#ifndef EXIT_H_
#define EXIT_H_

#include "STD.h"
#include "DIO.h"

#define MCUCR *((volatile uint8_t*) 0x55)
#define MCUCSR *((volatile uint8_t*) 0x54)
#define GICR *((volatile uint8_t*) 0x5b)
#define GIFR *((volatile uint8_t*) 0x5a)
#define SREG *((volatile uint8_t*) 0x5f)

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6


#define INT2 5
#define INT0 6
#define INT1 7

#define INTF2 5
#define INTF0 6
#define INTF1 7

#define SENSE_CONTROL0 FALLING_EDGE
#define SENSE_CONTROL1 FALLING_EDGE


#define SENSE_CONTROL2 FALLING_EDGE
#define LOW_LEVEL 0
#define ANY_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define ENABLE 1
#define DISABLE 0

#define EXTINT0_PORT PORTD
#define EXTINT1_PORT PORTD
#define EXTINT2_PORT PORTB

#define EXTINT0_PIN PIN2
#define EXTINT1_PIN PIN3
#define EXTINT2_PIN PIN2

#define EN_INT0 ENABLE
#define EN_INT1 DISABLE
#define EN_INT2 DISABLE

void EXTinterrupt_init();
void EXT0_VID_SET_CALL_BACK(void (*PTR0)(void));
void EXT1_VID_SET_CALL_BACK(void (*PTR1)(void));
void EXT2_VID_SET_CALL_BACK(void (*PTR2)(void));
void _vector_1 (void) __attribute__ ((signal,used, externally_visible));
void _vector_2 (void) __attribute__ ((signal,used, externally_visible));
void _vector_3 (void) __attribute__ ((signal,used, externally_visible));

void GIE_voidEnable(void);
void GIE_voidDisable(void);


#endif /* EXIT_H_ */