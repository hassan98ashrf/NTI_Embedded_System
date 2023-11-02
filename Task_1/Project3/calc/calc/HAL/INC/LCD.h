/*
 * LCD.h
 *
 * Created: 10/26/2023 11:29:44 AM
 *  Author: hassa
 */ 


#ifndef LCD_H_
#define LCD_H_

#define RSPORT PA
#define RSPIN PIN3

#define ENPORT PA
#define ENPIN PIN2

#define LCD_PORT PB

#define LCD_D4 PIN0
#define LCD_D5 PIN1
#define LCD_D6 PIN2
#define LCD_D7 PIN4


#define CLEAR_DISPLAY					0x01
#define RETURN_HOME						0x02
#define CURSOR_MOVE_RIGHT				0x06
#define CURSOR_MOVE_LEFT				0x04
#define DISPLAY_SHIFT_LEFT				0x07
#define DISPLAY_SHIFT_RIGHT				0x05
#define DISPLAY_ON_CURSOR_ON			0x0e
#define DISPLAY_ON_CURSOR_OFF			0x0c
#define DISPLAY_ON_CURSOR_BLINK			0x0f
#define DISPLAY_OFF_CURSOR_OFF			0x08
#define DISPLAY_OFF_CURSOR_ON			0x0a
#define SHIFT_CURSOR_POSITION_LEFT		0x10
#define SHIFT_CURSOR_POSITION_RIGHT		0x14
#define SHIFT_ENTIRE_DISPLAY_LEFT		0x18
#define SHIFT_ENTIRE_DISPLAY_RIGHT		0x1c
#define FOUR_BIT_MODE					0x28
#define EIGHT_BIT_MODE					0x38

void LCD_INIT();
void LCD_EN();
void LCD_instruction(unsigned char cmd);
void LCD_write_char(unsigned char data);
void LCD_SEND_STRING(char *data);
void LCD_MOVE_CURSOR(unsigned char row , unsigned char column);
void LCD_CLR_SCREEN(void);

#endif /* LCD_H_ */