/*
 * story.c
 *
 * Created: 10/26/2023 5:03:12 PM
 * Author : hassa
 */ 

#include "DIO.h"
#include "LCD.h"
#include "UTILS.h"

uint8_t  customChar[8] = {
	0b00100,
	0b01010,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010,
	0b10001
};

uint8_t  customChar2[8] = {
	0b11111,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

uint8_t  customChar3[8] = {
	0b00100,
	0b01010,
	0b11011,
	0b10001,
	0b10101,
	0b11011,
	0b01010,
	0b00100
};

uint8_t  customCharT1[8] = {
	0b11111,
	0b10000,
	0b10000,
	0b11111,
	0b10000,
	0b10000,
	0b10000,
	0b10000
};
uint8_t  customCharT2[8] = {
	0b11111,
	0b00001,
	0b00001,
	0b11111,
	0b00001,
	0b00001,
	0b00001,
	0b00001
};

int main(void)
{
    DIO_Init();
	LCD_Init();
	LCD_CustomerChar(1,customChar);
	LCD_CustomerChar(2,customChar2);
	LCD_CustomerChar(3,customChar3);
	LCD_CustomerChar(4,customCharT1);
	LCD_CustomerChar(5,customCharT2);
	LCD_GoTo(1,9);
	LCD_WriteChar(1);
	LCD_GoTo(3,0);
	LCD_WriteString("Engineer's story:(");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_GoTo(1,9);
	LCD_WriteChar(1);
	for(int i=0 ;i<20;i++){
		LCD_GoTo(2,i);
		LCD_WriteChar(2);
	}
	LCD_GoTo(3,0);
	LCD_WriteString("Waiting for the bus");
	LCD_GoTo(4,0);
	LCD_WriteString("every morning ");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_GoTo(1,0);
	LCD_WriteString("After many attempts");
	LCD_GoTo(2,0);
	LCD_WriteString("to reach this dream");
	LCD_GoTo(3,0);
	LCD_WriteString("COURSES!!!");
	LCD_GoTo(4,8);
	LCD_WriteChar(4);
	LCD_GoTo(4,9);
	LCD_WriteChar(5);
	LCD_GoTo(4,12);
	LCD_WriteChar(1);
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_GoTo(3,0);
	LCD_WriteString("Close ones helped me");
	LCD_GoTo(4,0);
	LCD_WriteString("to reach this way");
	LCD_GoTo(1,9);
	LCD_WriteChar(1);
	for(int i=8;i>5;i--){
		LCD_GoTo(1,i);
		LCD_WriteChar(1);
	}
	for(int i=10;i<13;i++){
		LCD_GoTo(1,i);
		LCD_WriteChar(1);
	}
	for(int i=0 ;i<20;i++){
		LCD_GoTo(2,i);
		LCD_WriteChar(2);
	}
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_GoTo(1,5);
	LCD_WriteChar(1);
	LCD_GoTo(1,10);
	LCD_WriteChar(3);
	LCD_GoTo(1,15);
	LCD_WriteChar(3);
	for(int i=0 ;i<20;i++){
		LCD_GoTo(2,i);
		LCD_WriteChar(2);
	}
	
	LCD_GoTo(3,0);
	LCD_WriteString("However,I have :(");
	LCD_GoTo(4,0);
	LCD_WriteString("sacrificed a lot ");
	_delay_ms(2000);
	LCD_Clear();
	
	
	LCD_GoTo(2,0);
	LCD_WriteString("In the end,  ");
	LCD_WriteChar(3);
	LCD_GoTo(3,0);
	LCD_WriteString("the hero wins");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_GoTo(1,9);
	LCD_WriteChar(1);
	for(int i=0 ;i<20;i++){
		LCD_GoTo(2,i);
		LCD_WriteChar(2);
	}
	LCD_GoTo(3,0);
	LCD_WriteString("But he remains alone");
	
	/*
	Waiting for the bus every morning to go to training is a beautiful thing.
	After many attempts to reach this dream.
	You have helped me a lot in this way
	However, I have sacrificed a lot of time with loved ones and health
	In the end, the hero wins the story
	But he remains alone
	*/
    while (1) 
    {
    }
}

