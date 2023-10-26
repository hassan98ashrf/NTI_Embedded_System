/*
 * LCD.c
 *
 * Created: 10/26/2023 11:32:32 AM
 *  Author: hassa
 */ 


#include "DIO.h"
#include "LCD.h"






#if LCD_8_BIT ==1
 void WriteIns(uint8_t ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
 void WriteData(uint8_t data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
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
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
 void WriteData(uint8_t data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
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