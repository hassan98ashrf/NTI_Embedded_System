/*
 * 7segment.c
 *
 * Created: 10/17/2023 2:28:35 PM
 * Author : amlta
 */ 

#include <avr/io.h>
#include "DIO.h"

void Sev_Seg (char Number) // Function to write the BCD of a number to the seven segment pins (PC4-7)
{

	switch(Number)

	{

		case 0:

		{
			PORTC&=~(1<<5)&~(1<<6)&~(1<<7)&~(1<<4);

			break;

		}

		case 1:

		{
			PORTC|=(1<<4);

			PORTC&=~(1<<5)&~(1<<6)&~(1<<7);

			break;

		}

		case 2:

		{
			PORTC|=(1<<5);

			PORTC&=~(1<<4)&~(1<<6)&~(1<<7);

			break;

		}

		case 3:

		{
			PORTC|=(1<<4)|(1<<5);

			PORTC&=~(1<<6)&~(1<<7);

			break;

		}

		case 4:

		{
			PORTC|=(1<<6);

			PORTC&=~(1<<4)&~(1<<5)&~(1<<7);

			break;

		}

		case 5:

		{
			PORTC|=(1<<4)|(1<<6);

			PORTC&=~(1<<5)&~(1<<7);

			break;

		}

		case 6:

		{

			PORTC|=(1<<5)|(1<<6);

			PORTC&=~(1<<4)&~(1<<7);

			break;

		}

		case 7:

		{

			PORTC|=(1<<4)|(1<<5)|(1<<6);

			PORTC&=~(1<<7);

			break;

		}

		case 8:

		{

			PORTC|=(1<<7);

			PORTC&=~(1<<4)&~(1<<5)&~(1<<6);

			break;

		}

		case 9:

		{

			PORTC|=(1<<7)|(1<<4);

			PORTC&=~(1<<5)&~(1<<6);

			break;

		}  
	} 
}


int main(void)
{
	DDRA |= 0xff;
	PORTA &=0x00;
    while (1) 
    {
		char count=0; 
		for (count=0;count<=99;count++) // This loop is to increment the number that will be displayed
		{
			for (int i=0;i<=17;i++) // This loop introduces some more delay so that the counting is slow enough for our eyes to recognize it
			{
				Sev_Seg(count%10); //write the first digit of "count" value to the first seven-segment
				PORTA|=(1<<2); //Enable the first seven-segment
				_delay_ms(10);
				PORTA&=~(1<<2); //disable the first seven-segment
				Sev_Seg(count/10); //write the second digit of "count" value to the second seven-segment
				PORTA|=(1<<3); //Enable the second seven-segment
				_delay_ms(10);
				PORTA&=~(1<<3); //disable the second seven-segment
			} 
		}   
	} 
}

