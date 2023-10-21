/*
 * LCDHAL.c
 *
 * Created: 10/21/2023 9:53:46 PM
 * Author : hassa
 */ 


#include <GPIO.h>
#include "LCD.h"

int main(void)
{
      LCD_setPinDirections();
      LCD_init();
      LCD_clear();


      LCD_typeString("Learn In Depth");
      LCD_goToSpecificPosition(LCD_LINE_TWO,0);
      LCD_typeString("~Mohamed Nabil");
    while (1) 
    {
    }
}

