/*
 * KeyPad.c
 *
 * Created: 10/26/2023 8:28:58 PM
 *  Author: hassa
 */ 


#include "DIO.h"
#include "KeyPad.h"


uint8_t arr[4][4] = { {'7','8','9','/'},  {'4','5','6','*'}, {'1','2','3','-'}, {'A','0','=','+'}};

void KEYPAD_INIT()
{
	DIO_EN_PULLUP(COLS_PORT, COL1);
	DIO_EN_PULLUP(COLS_PORT, COL2);
	DIO_EN_PULLUP(COLS_PORT, COL3);
	DIO_EN_PULLUP(COLS_PORT, COL4);
}

uint8_t KEYPAD_READ()
{
	uint8_t returnValue = 0xff; //NotPressed
	uint8_t bitRead=1;
	for(uint8_t row=0; row<4; row++)
	{
		DIO_SetPinVal(ROWS_PORT, ROW1, 1);
		DIO_SetPinVal(ROWS_PORT, ROW2, 1);
		DIO_SetPinVal(ROWS_PORT, ROW3, 1);
		DIO_SetPinVal(ROWS_PORT, ROW4, 1);
		switch (row)
		{
			case 0:
				DIO_SetPinVal(ROWS_PORT, ROW1, 0);
				break;
			case 1:
				DIO_SetPinVal(ROWS_PORT, ROW2, 0);
				break;
			case 2:
				DIO_SetPinVal(ROWS_PORT, ROW3, 0);
				break;
			case 3:
				DIO_SetPinVal(ROWS_PORT, ROW4, 0);
				break;
		}
		
		for(uint8_t col=0; col<4; col++)
		{
			switch (col)
			{
				case 0:
					bitRead = DIO_ReadPinVal(COLS_PORT, COL1);
					break;
				case 1:
					bitRead = DIO_ReadPinVal(COLS_PORT, COL2);
					break;
				case 2:
					bitRead = DIO_ReadPinVal(COLS_PORT, COL3);
					break;
				case 3:
					bitRead = DIO_ReadPinVal(COLS_PORT, COL4);
					break;
			}
			if(bitRead == 0) {returnValue = arr[row][col]; break;}
		}
		if(bitRead == 0) {break;}
	}
	
	
	return returnValue;
}