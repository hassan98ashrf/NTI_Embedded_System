/*
 * PING.c
 *
 * Created: 10/26/2023 2:43:31 PM
 *  Author: hassa
 */ 



#include "DIO.h"
#include "LCD.h"
#include "PING.h"

uint8_t  customChar[8] = {
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100
};


uint8_t  customChar2[8] = {
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100
};

uint8_t flag_direction=1;
uint8_t ch_1=1,ch_2=1;

uint8_t score1=0;
uint8_t score2=0;
uint8_t i=1,j=1;


void Ping_Init(void)
{
	DIO_Init();
	LCD_Init();
	LCD_CustomerChar(1,customChar);
	LCD_GoTo(4,0);
	LCD_WriteString("Player1:0  Player2:0");
}



void Ping_Play(void)
{
	LCD_GoTo(ch_2,19);
	LCD_WriteChar(1);
	LCD_GoTo(ch_1,0);
	LCD_WriteChar(1);
	
	
	if (flag_direction)
	{
		if(!DIO_ReadPin(BALL1_DOWN))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(BALL1_DOWN));
			j++;
			if(j==4)
			{
				j=3;
			}
		}
		if(!DIO_ReadPin(BALL1_UP))
		{
			
			_delay_ms(20);
			while(!DIO_ReadPin(BALL1_UP));
			j--;
			if(j==0)
			{
				j=1;
			}
		}
		
		if(!DIO_ReadPin(PLAYER2_DOWN))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(PLAYER2_DOWN));
			LCD_GoTo(ch_2,19);
			LCD_WriteChar(' ');
			ch_2++;
			
			if(ch_2==4)
			{
				ch_2=3;
			}
		}
		
		if(!DIO_ReadPin(PLAYER2_UP))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(PLAYER2_UP));
			LCD_GoTo(ch_2,19);
			LCD_WriteChar(' ');
			ch_2--;
			if(ch_2==0)
			{
				ch_2=1;
			}
		}
		
		LCD_GoTo(j,i);
		LCD_WriteChar('0');
		_delay_ms(300);
		LCD_GoTo(j,i);
		LCD_WriteChar(' ');
		i++;
		if (i==18)
		{
			if(j!=ch_2)
			{
				DIO_WritePin(PUZ,HIGH);
				_delay_ms(300);
				DIO_WritePin(PUZ,LOW);
				score1++;
				LCD_GoTo(4,8);
				LCD_WriteNumber(score1);
			}
			flag_direction=0;
		}

	}
	else
	{
		
		if(!DIO_ReadPin(BALL2_DOWN))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(BALL2_DOWN));
			j++;
			if(j==4)
			{
				j=3;
			}
		}
		if(!DIO_ReadPin(BALL2_UP))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(BALL2_UP));
			j--;
			if(j==0)
			{
				j=1;
			}
		}
		
		if(!DIO_ReadPin(PLAYER1_DOWN))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(PLAYER1_DOWN));
			LCD_GoTo(ch_1,0);
			LCD_WriteChar(' ');
			ch_1++;
			if(ch_1==4)
			{
				ch_1=3;
			}
		}
		
		if(!DIO_ReadPin(PLAYER1_UP))
		{
			_delay_ms(20);
			while(!DIO_ReadPin(PLAYER1_UP));
			LCD_GoTo(ch_1,0);
			LCD_WriteChar(' ');
			ch_1--;
			if(ch_1==0)
			{
				ch_1=1;
			}
		}
		
		LCD_GoTo(j,i);
		LCD_WriteChar('0');
		_delay_ms(300);
		LCD_GoTo(j,i);
		LCD_WriteChar(' ');
		i--;
		if (i==1)
		{
			if(j!=ch_1)
			{
				DIO_WritePin(PUZ,HIGH);
				_delay_ms(300);
				DIO_WritePin(PUZ,LOW);
				score2++;
				LCD_GoTo(4,19);
				LCD_WriteNumber(score2);
			}
			flag_direction=1;
		}
	}
}