/*
 * LCD.h
 *
 * Created: 10/20/2023 10:53:38 AM
 *  Author: amlta
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

//commands


#define LCD_PORT PORTB_base
#define Data_dir_LCD_PORT DDRB_base
#define LCD_CTRL PORTA_base
#define Data_dir_LCD_CTRL DDRA_base


#define RS_switch 3
#define RW_switch 1
#define EN_switch 2
#define data_shift 4

//#define Eight_bit_mode
#define four_bit_mode

#define  LCD_function_8bit_2line	(0x38)
#define  LCD_function_4bit_2line	(0x28)
#define  LCD_move_DISP_right		(0x1C)
#define  LCD_move_DISP_left			(0x18)
#define  LCD_move_cursor_right		(0x14)
#define  LCD_move_cursor_left		(0x10)
#define  LCD_DISP_off				(0x08)
#define  LCD_DISP_on_cursor			(0x0E)
#define  LCD_DISP_on_cursor_blink	(0x0F)
#define  LCD_DISP_on_blink			(0x0D)
#define  LCD_DISP_on				(0x0C)
#define  LCD_entry_DEC				(0x04)
#define  LCD_entry_DEC_shift		(0x05)
#define  LCD_entry_INC				(0x06)
#define  LCD_entry_INC_shift		(0x07)
#define  LCD_Begin_at_first_row		(0x80)
#define  LCD_Begin_at_second_row	(0xC0)
#define  LCD_Begin_at_third_row		(0x94)
#define  LCD_Begin_at_fourth_row	(0xD4)
#define  LCD_clear_screen			(0x01)
#define  LCD_entry_mode				(0x06)
#define LCD_RETURN_HOME				(0x02)
#define CGRAM_ADD 0x40
#define MAX_LOCATION 8

void LCD_init (void);
void LCD_write_command (unsigned char command);

void LCD_write_char (unsigned char data);
void LCD_write_char_xy (unsigned char data,uint8_t row , uint8_t col);

void LCD_write_string ( char* data);


void LCD_write_num ( uint16_t data);
void LCD_write_num_xy ( uint16_t data,uint8_t row , uint8_t col);

void LCD_isbusy (void);
void LCD_GOTO_XY (uint8_t line , uint8_t x);
void LCD_Clear_screen (void);

void LCD_custom(uint8_t *Local_u8_pattern,uint8_t Local_u8_location);

#endif /* LCD_H_ */