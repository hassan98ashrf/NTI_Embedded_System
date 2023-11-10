/*
 * LCD.h
 *
 * Created: 11/3/2023 9:59:02 AM
 *  Author: Hassan
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "stdint.h"


#define Four_Bit_Mode			4
#define Eight_Bit_Mode			8
#define MODE_lcd					Four_Bit_Mode

#define RS_PORT					DIO_PORTA
#define RS_PIN					Pin3

#define EN_PORT					DIO_PORTA
#define EN_PIN					Pin2

#define RW_PORT					DIO_PORTA
#define RW_PIN					Pin0

#define FuncitonSet1						0x33
#define FuncitonSet2						0x32
#define CMD_CLEAR_DISPLAY					0x01
#define CMD_CURSOR_ON_DISPLAN_ON			0x0e
#define CMD_RETURN_HOME						0x02
#define CMD_ENTRY_MODE						0x06

#define LCD_4_Bit_Mode_2_Line_5_8_Dots		0x28
#define Display_Cursor_ON_Blink_OFF			0x0E
#define Clear_Display_Screen				0x01
#define Shift_Cursor_Right_Per_Read_Write	0x06



//static void Send_FallingEdge(void);

void LCD_vInit(void);
void LCD_vWriteCommand(uint8_t cmd);
void LCD_vWriteData(uint8_t data);
void LCD_vSendString(uint8_t *data);
void LCD_vClearScreen();
void LCD_MoveCursor(uint8_t row,uint8_t coloumn);
void LCD_vWriteString(char * Str);
void LCD_WriteNUM(uint32_t NUM);

#endif /* LCD_H_ */