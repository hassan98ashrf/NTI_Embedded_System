/*
 * LCD.h
 *
 * Created: 10/26/2023 11:29:44 AM
 *  Author: hassa
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "UTILS.h"

#define LCD_4_BIT 1
#define LCD_8_BIT 0

#define D4 PINB0
#define D5 PINB1
#define D6 PINB2
#define D7 PINB4

#define RS PINA3
#define EN PINA2

#define  LCD_PORT PB


void LCD_Init(void);

void LCD_Clear(void);

void LCD_GoTo(uint8_t row,uint8_t col);

void LCD_WriteChar(uint8_t ch);

void LCD_WriteString(char * str);

void LCD_WriteNumber(uint32_t num);

void LCD_CustomerChar(uint8_t address , uint8_t*character);





#endif /* LCD_H_ */