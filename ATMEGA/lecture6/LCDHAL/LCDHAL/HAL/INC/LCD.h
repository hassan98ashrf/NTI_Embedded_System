/*
 * LCD.h
 *
 * Created: 10/21/2023 10:17:05 PM
 *  Author: hassa
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "GPIO.h"


//Macros For Rs Pin
#define LCD_RS_PORT		DIO_PORTB	
#define LCD_RS_PIN		DIO_PIN1

//Macros For Rw Pin
#define LCD_RW_PORT		DIO_PORTB
#define LCD_RW_PIN		DIO_PIN2

//Macros For Enable Pin
#define LCD_E_PORT		DIO_PORTB
#define LCD_E_PIN		DIO_PIN3

						/*Macros For DATA Pins Configuration*/
/*
Options For LCD Mode:
 LCD_8_BIT_MODE
 LCD_4_BIT_MODE     */
 
#define LCD_MODE	 LCD_4_BIT_MODE

/*Macros For 8 bit mode Configuration*/

//FULL PORT CONTROL
#define LCD_DATA_PORT		DIO_PORTA


/*Macros For 4 bit mode Configuration*/

#define LCD_D0_PORT		DIO_PORTA
#define LCD_D0_PIN		DIO_PIN0

#define LCD_D1_PORT		DIO_PORTA
#define LCD_D1_PIN		DIO_PIN1

#define LCD_D2_PORT		DIO_PORTA
#define LCD_D2_PIN		DIO_PIN2

#define LCD_D3_PORT		DIO_PORTA
#define LCD_D3_PIN		DIO_PIN3

#define LCD_D4_PORT		DIO_PORTA
#define LCD_D4_PIN		DIO_PIN4

#define LCD_D5_PORT		DIO_PORTA
#define LCD_D5_PIN		DIO_PIN5

#define LCD_D6_PORT		DIO_PORTA
#define LCD_D6_PIN		DIO_PIN6

#define LCD_D7_PORT		DIO_PORTA
#define LCD_D7_PIN		DIO_PIN7


// MACROS For LCD Bit Mode
#define LCD_4_BIT_MODE	4
#define LCD_8_BIT_MODE	8
// MACROS For LCD Shift Direction
#define LCD_SHIFT_LEFT	0
#define LCD_SHIFT_RIGHT	1

// MACROS For LCD Line Number
#define LCD_LINE_ONE 1
#define LCD_LINE_TWO 2


//Main Functions
void LCD_setPinDirections(void);
void LCD_init(void);
void LCD_sendCmnd(uint8_t cmnd);
void LCD_sendChar(uint8_t data);

static void writeHalfPort(uint8_t value);

//OTHER Functions
void LCD_sendString(uint8_t* data);
void LCD_typeString(uint8_t* data);  //Send string with typing effect
void LCD_writeNumber(uint32_t number);
void LCD_clear(void);
void LCD_shift(uint8_t shiftDirection);
void LCD_goToSpecificPosition(uint8_t lineNumber,uint8_t position);


#endif /* LCD_H_ */