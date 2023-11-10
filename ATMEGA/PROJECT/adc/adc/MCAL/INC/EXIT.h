/*
 * EXIT.h
 *
 * Created: 11/2/2023 11:42:31 AM
 *  Author: hassa
 */ 


#ifndef EXIT_H_
#define EXIT_H_

#include "STD.h"
#include "type.h"
#include "avr/interrupt.h"
#include "EXIT.h"

#define  MCUCR_PORT		(*((volatile u8*) (0x55)))
#define  MCUSCR_PORT		(*((volatile u8*) (0x54)))

#define GIFR_PORT		(*((volatile u8*) (0x5A)))
#define GICR_PORT		(*((volatile u8*) (0x5B)))

typedef enum {IRQ_AT_lOW_LEVEL,IRQ_AT_ANY_LOGIC_CHANGE, IRQ_AT_FALLING_EDGE, IRQ_AT_RISING_EDGE,NO_IRQ_RESPONCE}EXT_IRQ_TYPE;

typedef enum {INT0_PIN, INT1_PIN, INT2_PIN}INT_PIN_TYPE;

#define INT2_PIN	2
#define INT1_PIN	1
#define INT0_PIN	0

void GIE();
void GID();
void EX_INT_Set_INT0_IRQ_Handler(void (*F_ptr)(void));
void EX_INT_Set_INT1_IRQ_Handler(void (*F_ptr)(void));
void EX_INT_Set_INT2_IRQ_Handler(void (*F_ptr)(void));
void EX_INT_SET_MODE(INT_PIN_TYPE IntPin_Number, EXT_IRQ_TYPE IRQ);



#endif /* EXIT_H_ */