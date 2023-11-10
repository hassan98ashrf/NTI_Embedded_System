/*
 * EEPROM.c
 *
 * Created: 11/3/2023 9:24:19 AM
 * Author : Hassan
 */ 

 #define F_CPU   16000000UL

 #include "I2C.h"
 #include "DIO.h"
 #include "LCD.h"
 #include "EEPROM.h"
 #include "util/delay.h"



 int main(void)
 {
	 LCD_vInit();
	 LCD_vWriteString("Welcome!");
	 uint8_t X;
	 
	 EEPROM_Init();
	
	 EEPROM_SaveData(0x00,0x00,'5');
	 _delay_ms(100);
	 
	 
	LCD_vClearScreen();
	LCD_vWriteString("clear lcd");
	 
	 _delay_ms(1000);
	 LCD_vClearScreen();
	 _delay_ms(1000);
	 

	 X= EEPROM_ReadData(0x00,0x00);
	 _delay_ms(1000);

	 LCD_vWriteString("EEPROM Read= ");
	 LCD_vWriteData(X);
	 while(1);
 }