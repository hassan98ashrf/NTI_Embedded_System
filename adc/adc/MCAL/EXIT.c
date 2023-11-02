/*
 * EXIT.c
 *
 * Created: 11/2/2023 11:44:43 AM
 *  Author: hassa
 */ 
#include "EXIT.h"

void (*CallbackFunc1)(void) = NULL;

void EXTinterrupt_init()
{
	
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT2);
	
	switch(SENSE_CONTROL0)
	{
		case 0:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		
		case 1:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		case 2:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case 3:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		default:
		break;
	}
	
	switch(SENSE_CONTROL1)
	{
		case 0:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		
		case 1:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		case 2:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		case 3:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		default:
		break;
	}
	
	switch(SENSE_CONTROL2)
	{
		case 2:
			CLR_BIT(MCUCR,ISC10);
			break;
		case 3:
			SET_BIT(MCUCR,ISC10);
			break;
		default:
		break;
	}
}


void EXT0_VID_SET_CALL_BACK(void (*PTR0)(void))
{
	CallbackFunc1 = PTR0;
}

void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}

void __vector_1 (void) __attribute__ ((signal,used, externally_visible));
void __vector_1 (void) { if(CallbackFunc1 != NULL){ CallbackFunc1();}  }