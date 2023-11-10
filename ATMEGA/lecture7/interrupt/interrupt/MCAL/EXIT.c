/*
 * EXIT.c
 *
 * Created: 10/24/2023 3:21:06 PM
 *  Author: amlta
 */ 

#include "EXIT.h"

#define NULLPTR   ((void*)0)  
static void (*INT0_Fptr) (void) = NULLPTR;
static void (*INT1_Fptr) (void) = NULLPTR;
static void (*INT2_Fptr) (void) = NULLPTR;



void EXI_Set_CallBack(EX_Interrupt_Source_type interrupt, void (*LocalPtr)(void)){
	switch(interrupt){
		case EX_INT0:
			INT0_Fptr = LocalPtr;
			break;
		case EX_INT1:
			INT1_Fptr = LocalPtr;
			break;
		case EX_INT2:
			INT2_Fptr = LocalPtr;
			break;
	}
}




void EXI_ENABLE(EX_Interrupt_Source_type interrupt){
	switch(interrupt){
		case EX_INT0:
			SET_BIT(GICR,INT0);
			break;
		case EX_INT1:
		SET_BIT(GICR,INT1);
			break;
			case EX_INT2:
		SET_BIT(GICR,INT2);
			break;
	}
}


void EXI_DISABLE(EX_Interrupt_Source_type interrupt){
	switch(interrupt){
		case EX_INT0:
		CLR_BIT(GICR,INT0);
		break;
		case EX_INT1:
		CLR_BIT(GICR,INT1);
		break;
		case EX_INT2:
		CLR_BIT(GICR,INT2);
		break;
	}
}

void EXI_TriggerEdge(EX_Interrupt_Source_type interrupt,Trigger_Edge_type edge){
	switch(interrupt){
		case EX_INT0:
			switch(edge){
				case LOW_LEVEL:
					CLR_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
					break;
				case ANY_LOGIC_CHANGE:
					SET_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
					break;
				case FALLING_EDGE:
					CLR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			}
				break;
			case EX_INT1:
				switch(edge){
					case LOW_LEVEL:
						CLR_BIT(MCUCR,ISC10);
						CLR_BIT(MCUCR,ISC11);
						break;
					case ANY_LOGIC_CHANGE:
						SET_BIT(MCUCR,ISC10);
						CLR_BIT(MCUCR,ISC11);
						break;
					case FALLING_EDGE:
						CLR_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
						break;
					case RISING_EDGE:
						SET_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
						break;
				}
			break;
		case EX_INT2:
		switch(edge){
			case FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			default:   
			CLR_BIT(MCUCSR,ISC2);
		}
		break;
	}
}




ISR(INT0_vect){
	if(INT0_Fptr != NULLPTR){
		INT0_Fptr();
	}
}

ISR(INT1_vect){
	if(INT1_Fptr != NULLPTR){
		INT1_Fptr();
	}
}

ISR(INT2_vect){
	if(INT2_Fptr != NULLPTR){
		INT2_Fptr();
	}
}