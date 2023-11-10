/*
 * KPD.c
 *
 * Created: 10/28/2023 12:45:03 PM
 *  Author: Hassan
 */ 
#include "KPD.h"

uint8_t KeysArr[ROWS][COLS]={   {'+','=','0','C'},
{'-','3','2','1'},
{'*','6','5','4'},
{'/','9','8','7'}   };

void KEYPAD_Init(void)
{
	for (uint8_t r=0;r<ROWS;r++)
	{
		digitalWrite(PORT_C,FIRST_OUTPUT+r,HIGH);
	}
}

uint8_t KEYPAD_GetKey(void)
{
	uint8_t f,r,c,key=NO_KEY;
	for (r=0;r<ROWS;r++)
	{
		digitalWrite(PORT_C,FIRST_OUTPUT+r,LOW);
		f=0;
		
		for(c=0;c<COLS+1;c++)
		{
			if(c!=1)
			{
				
				if (digitalRead(PORT_D,FIRST_INPUT+c)==LOW)
				{
					key=KeysArr[r][c-f];
					_delay_ms(3);
					while(digitalRead(PORT_D,FIRST_INPUT+c)==LOW);
					_delay_ms(3);
					
				}
			}
			else
			{
				f=1;
			}
		}
		digitalWrite(PORT_C,FIRST_OUTPUT+r,HIGH);
	}
	return key;
}
