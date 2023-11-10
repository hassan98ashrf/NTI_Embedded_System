/*
 * CFile1.c
 *
 * Created: 10/28/2023 12:17:22 PM
 *  Author: Hassan
 */ 

#include "LCD.h"

#if LCD_8_BIT ==1
void WriteIns(uint8_t ins)
{
	digitalWrite(PORT_A,RS,LOW);
	digitalWrite(LCD_PORT,ins);
	digitalWrite(PORT_A,EN,HIGH);
	_delay_ms(1);
	digitalWrite(PORT_A,EN,LOW);
	_delay_ms(1);
}
void WriteData(uint8_t data)
{
	digitalWrite(PORT_A,RS,HIGH);
	digitalWrite(LCD_PORT,data);
	digitalWrite(PORT_A,EN,HIGH);
	_delay_ms(1);
	digitalWrite(PORT_A,EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(35);
	WriteIns(0x38);// set function
	WriteIns(0x08);//0x0c  , 0x0e  courser enable
	WriteIns(0x01);//clear
	_delay_ms(1);
	WriteIns(0x06);
}
#else
void WriteIns(uint8_t ins)
{
	digitalWrite(PORT_A,RS,LOW);
	digitalWrite(PORT_B,D7,Read_Bit(ins,7));
	digitalWrite(PORT_B,D6,Read_Bit(ins,6));
	digitalWrite(PORT_B,D5,Read_Bit(ins,5));
	digitalWrite(PORT_B,D4,Read_Bit(ins,4));
	digitalWrite(PORT_A,EN,HIGH);
	_delay_ms(1);
	digitalWrite(PORT_A,EN,LOW);
	_delay_ms(1);
	digitalWrite(PORT_B,D7,Read_Bit(ins,3));
	digitalWrite(PORT_B,D6,Read_Bit(ins,2));
	digitalWrite(PORT_B,D5,Read_Bit(ins,1));
	digitalWrite(PORT_B,D4,Read_Bit(ins,0));
	digitalWrite(PORT_A,EN,HIGH);
	_delay_ms(1);
	digitalWrite(PORT_A,EN,LOW);
	_delay_ms(1);
}
void WriteData(uint8_t data)
{
	digitalWrite(PORT_A,RS,HIGH);
	digitalWrite(PORT_B,D7,Read_Bit(data,7));
	digitalWrite(PORT_B,D6,Read_Bit(data,6));
	digitalWrite(PORT_B,D5,Read_Bit(data,5));
	digitalWrite(PORT_B,D4,Read_Bit(data,4));
	digitalWrite(PORT_A,EN,HIGH);
	_delay_ms(1);
	digitalWrite(PORT_A,EN,LOW);
	_delay_ms(1);
	digitalWrite(PORT_B,D7,Read_Bit(data,3));
	digitalWrite(PORT_B,D6,Read_Bit(data,2));
	digitalWrite(PORT_B,D5,Read_Bit(data,1));
	digitalWrite(PORT_B,D4,Read_Bit(data,0));
	digitalWrite(PORT_A,EN,HIGH);
	_delay_ms(1);
	digitalWrite(PORT_A,EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(35);
	WriteIns(0x02);// set function
	WriteIns(0x28);
	WriteIns(0x0c);//0x0c  , 0x0e  cursor enable
	WriteIns(0x01);//clear
	_delay_ms(1);
	WriteIns(0x06);
}
#endif

void LCD_GoTo(uint8_t line,uint8_t cell)
{
	if (line ==1)
	{
		WriteIns(0x80+cell);

	}
	else if (line==2)
	{
		WriteIns(0xc0+cell);
	}
	else if (line==3)
	{
		WriteIns(0x94+cell);
	}
	else if (line==4)
	{
		WriteIns(0xd4+cell);
	}
	
}

void LCD_WriteChar(uint8_t ch)
{
	WriteData(ch);
}

void LCD_WriteString(char* str)
{
	uint8_t i=0;
	for (i=0;str[i];i++)
	{
		WriteData(str[i]);
	}
}


void LCD_WriteNumber(uint32_t num)
{
	uint8_t str[10],i;
	
	
	if (num==0)
	{
		LCD_WriteChar('0');
	}
	else if (num<0)
	{
		LCD_WriteChar('-');
		num = num*-1;
	}
	
	for (i=0;num>0;i++)
	{
		str[i] = ((num%10)+'0');
		num = num/10;
	}
	for (i=i-1;i!=255;i--)
	{
		LCD_WriteChar(str[i]);
	}
	
}


void LCD_CustomerChar(uint8_t address , uint8_t*character)
{
	
	WriteIns(0x40+(address*8));
	
	for(uint8_t i=0;i<8;i++)
	{
		WriteData(character[i]);
	}
	WriteIns(0x80);
}

void LCD_Clear()
{
	WriteIns(0x01);
	_delay_ms(2);
	WriteIns(0x80);
	
}

void LCD_WriteNumber_u8(uint8_t num)//1:9
{
	LCD_Clear();
	LCD_WriteChar('0'+num);
}