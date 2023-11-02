

/*
 * CALC.c
 *
 * Created: 11/1/2023 5:06:44 PM
 *  Author: hassa
 */ 
#include "CALC.h"

int exp_arr[80] = {0} ;
uint8_t exp_arr_index = 0;
uint8_t readValu = 0xff;
uint8_t rawnum = 1;
uint8_t colmnum = 1;
uint8_t globalFlag = 0;

void Calc_init(void)
{
	DIO_init();
	LCD_INIT();
	_delay_ms(1000);
	KEYPAD_INIT();
}

void  shiftArr(uint8_t index)
{
	for(uint8_t i = index; i<=exp_arr_index; i++)
	{
		exp_arr[i] = exp_arr[i+2];
	}
	exp_arr_index-=2;
	return;
}
void calc_CalculateResult()
{
	//exp_arr_index--;
	for(uint8_t i=0; i<=exp_arr_index; i++)
	{
		if(exp_arr[i] == '*') {exp_arr[i-1] *= exp_arr[i+1]; shiftArr(i); i=0;}
		else if(exp_arr[i] == '/') {exp_arr[i-1] /= exp_arr[i+1]; shiftArr(i); i=0;}
	}
	for(uint8_t i=0; i<=exp_arr_index; i++)
	{
		if(exp_arr[i] == '+') {exp_arr[i-1] += exp_arr[i+1]; shiftArr(i); i=0;}
		else if(exp_arr[i] == '-') {exp_arr[i-1] -= exp_arr[i+1]; shiftArr(i); i=0;}
	}
	return;
}
void calc_DisplayResult()
{
	
	LCD_MOVE_CURSOR(rawnum , colmnum);
	LCD_write_char(readValu);
	_delay_ms(1500);
	LCD_instruction(CLEAR_DISPLAY);
	rawnum=1; colmnum=1;
	LCD_MOVE_CURSOR(rawnum , colmnum);
	LCD_SEND_STRING("Result = ");
	LCD_MOVE_CURSOR(1,10);
	//7th digit
	LCD_write_char((exp_arr[exp_arr_index] / 1000000) +48);
	//6th digit
	LCD_write_char(((exp_arr[exp_arr_index] %1000000)/100000) +48);
	//5th digit
	LCD_write_char(((exp_arr[exp_arr_index] %100000)/10000) +48);
	//4th digit
	LCD_write_char(((exp_arr[exp_arr_index]%10000)/1000) +48);
	//3rd digit
	LCD_write_char(((exp_arr[exp_arr_index]%1000)/100) +48);
	//2nd digit
	LCD_write_char(((exp_arr[exp_arr_index]%100)/10) +48);
	//1st digit
	LCD_write_char(((exp_arr[exp_arr_index]%10)/1) +48);
	
	globalFlag = 1;
	return;
}

void calc_toint(uint8_t digit)
{
	digit -= 48;
	exp_arr[exp_arr_index] *= 10;
	exp_arr[exp_arr_index] += digit;
	return;
}

void calc_CheckNum(uint8_t num)
{
	if((num!='*') && (num!='/') && (num!='+') && (num!='-'))
	{
		calc_toint(num);
	}
	else
	{
		exp_arr_index++;
		exp_arr[exp_arr_index] = num;
		exp_arr_index++;
	}
	return;
}

void Calculator()
{
	readValu = KEYPAD_READ();
	if(readValu == '=')
	{
		calc_CalculateResult();
		calc_DisplayResult();
	}
	while( (readValu != 0xff)  &&  (readValu != '=') )
	{
		if(globalFlag == 1)
		{LCD_instruction(CLEAR_DISPLAY);
			globalFlag = 0;
			exp_arr_index=0;
			for(uint8_t i=0; i<80; i++) {exp_arr[i]=0;}
		}
		
		calc_CheckNum(readValu);
		LCD_MOVE_CURSOR(rawnum , colmnum);
		LCD_write_char(readValu);
		colmnum++;
		if(colmnum == 21){ rawnum++;  }
		colmnum%=21;rawnum %= 4;
		readValu = 0xff;
	}
}