/*
 * LCD.c
 *
 * Created: 11/2/2023 4:03:50 PM
 *  Author: hassa
 */ 
#define F_CPU 800000
#include "util/delay.h"
#include "LCD.h"
#include "STD.h"
void LCD_INIT()
{
	
	_delay_ms(40);
	LCD_instruction(0x33);
	_delay_ms(1);
	LCD_instruction(0x32);
	_delay_ms(1);
	//function set
	LCD_instruction(FOUR_BIT_MODE);//0x28
	_delay_ms(1);
	LCD_instruction(0x0c);
	_delay_ms(1);
	LCD_instruction(CLEAR_DISPLAY);//0x01
	_delay_ms(1);
	LCD_instruction(RETURN_HOME); // 0x02
	_delay_ms(1);
}

void LCD_EN()
{
	DIO_SetPinVal(ENPORT, ENPIN, HIGH);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, LOW);
	_delay_ms(2);
}

void LCD_instruction(unsigned char cmnd)
{
	
	DIO_SetPinVal(RSPORT, RSPIN, 0);	
	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(cmnd,4));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(cmnd,5));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(cmnd,6));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(cmnd,7));
	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);		
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);

	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(cmnd,0));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(cmnd,1));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(cmnd,2));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(cmnd,3));
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);
	
}

void LCD_write_char(unsigned char data)
{
	
	DIO_SetPinVal(RSPORT, RSPIN, 1);
	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(data,4));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(data,5));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(data,6));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(data,7));
	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);

	DIO_SetPinVal(LCD_PORT, LCD_D4, READ_BIT(data,0));
	DIO_SetPinVal(LCD_PORT, LCD_D5, READ_BIT(data,1));
	DIO_SetPinVal(LCD_PORT, LCD_D6, READ_BIT(data,2));
	DIO_SetPinVal(LCD_PORT, LCD_D7, READ_BIT(data,3));
	
	DIO_SetPinVal(ENPORT, ENPIN, 1);
	_delay_ms(2);
	DIO_SetPinVal(ENPORT, ENPIN, 0);
	_delay_ms(2);
	
}


void LCD_SEND_STRING(char *data)
{
	while((*data)!='\0')
	{
		LCD_write_char(*data);
		data++;
	}
}


void LCD_CLR_SCREEN(void)
{
	LCD_instruction(CLEAR_DISPLAY);
	_delay_ms(10);                    
}


void LCD_MOVE_CURSOR(unsigned char row , unsigned char column)
{
	
	unsigned char data = 0x80;
	if(row>4||row<1||column>20||column<1)
	{
		data=0x80;                       
	}
	else if(row==1)
	{
		data=0x80+column-1 ;
	}
	else if (row==2)
	{
		data=0xc0+column-1;
	}else if (row==3)
	{
		data=0x94+column-1;
	}
	else if (row==4)
	{
		data=0xD4+column-1;
	}
	LCD_instruction(data);
	_delay_ms(1);
}