/*
 * LCD.h
 *
 * Created: 11/2/2023 11:55:48 AM
 *  Author: hassa
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "type.h"


#define Four_Bit_Mode			4
#define Eight_Bit_Mode			8
#define MODE					Four_Bit_Mode

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
void LCD_vWriteCommand(u8 cmd);
void LCD_vWriteData(u8 data);
void LCD_vSendString(u8 *data);
void LCD_vClearScreen();
void LCD_MoveCursor(u8 row,u8 coloumn);
void LCD_vWriteString(char * Str);
void LCD_WriteNUM(u32 NUM);




#endif /* LCD_H_ */