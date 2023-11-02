/*
 * calc.c
 *
 * Created: 10/26/2023 7:57:08 PM
 * Author : hassa
 */ 



#include "DIO.h"
#include "CALC.h"

int main()
{
	Calc_init();
	
	while(1)
	{
		Calculator(); 
		_delay_ms(250);
	}
	
}