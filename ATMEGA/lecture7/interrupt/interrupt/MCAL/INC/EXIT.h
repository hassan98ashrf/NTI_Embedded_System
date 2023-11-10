/*
 * EXIT.h
 *
 * Created: 10/24/2023 3:20:12 PM
 *  Author: amlta
 */ 


#ifndef EXIT_H_
#define EXIT_H_
#include "ATmega32.h"

typedef enum{
	EX_INT0 = 0,
	EX_INT1,
	EX_INT2
}EX_Interrupt_Source_type;



typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}Trigger_Edge_type;


void EXI_ENABLE(EX_Interrupt_Source_type interrupt);
void EXI_DISABLE(EX_Interrupt_Source_type interrupt);
void EXI_TriggerEdge(EX_Interrupt_Source_type interrupt,Trigger_Edge_type edge);



#endif /* EXIT_H_ */