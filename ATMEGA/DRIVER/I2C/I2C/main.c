/*
 * I2C.c
 *
 * Created: 10/31/2023 1:41:14 PM
 * Author : Hassan
 */ 

#include <avr/io.h>

#include "I2C.h"

int main(void)
{
	unsigned char ch = 0;
	I2C_Init(0x48);
	
	
	while (1)
	{
		_delay_ms(500);
		
		I2C_Start();    
		
		I2C_Write(0b11010000+0);
		
		while(TWSR != 0x18);    
		
		I2C_Write(ch++);   
		
		while(TWSR != 0x28);   
		
		I2C_Stop();
	}
}

