/*
 * LCD.h
 *
 * Created: 10/28/2023 12:12:09 PM
 *  Author: Hassan
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "DIO.h"

#define LCD_4_BIT 1
#define LCD_8_BIT 0

#define D4 PINB0
#define D5 PINB1
#define D6 PINB2
#define D7 PINB4

#define RS PINA3
#define EN PINA2

#define  LCD_PORT PB

// Commands of LCD
#define LCD_CMD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_CMD_FUNCTION_4BIT_2LINES_1st_CMD 			(0x02)
#define LCD_CMD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   						(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_CMD_DISP_OFF   								(0x08)
#define LCD_CMD_DISP_ON_CURSOR   						(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CMD_DISP_ON_BLINK   						(0x0D)
#define LCD_CMD_DISP_ON   								(0x0C)
#define LCD_CMD_ENTRY_DEC   							(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_CMD_ENTRY_INC_   							(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CMD_CLEAR_SCREEN							(0x01)
#define LCD_CMD_ENTRY_MODE

void LCD_Init(void);

void LCD_Clear(void);

void LCD_GoTo(uint8_t row,uint8_t col);

void LCD_WriteChar(uint8_t ch);

void LCD_WriteString(char * str);

void LCD_WriteNumber(uint32_t num);
void WriteIns(uint8_t ins);
void LCD_CustomerChar(uint8_t address , uint8_t*character);



#endif /* LCD_H_ */