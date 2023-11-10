/*
 * LCD.c
 *
 * Created: 10/20/2023 10:54:12 AM
 *  Author: amlta
 */ 
#include "LCD.h"


	


void LCD_kick()
{

	LCD_CTRL |= (1<<EN_switch);//enable
	_delay_ms(20);
	LCD_CTRL &= ~(1<<EN_switch); //no command during
	
}

void LCD_GOTO_XY(uint8_t line,uint8_t position)
{
	if (line == 1)
	{
		if (position <20 && position>=0)
		{
			LCD_write_command(LCD_Begin_at_first_row + position);
		}
		
	}
	else if(line == 2)
	{
		if (position <40 && position>=0)
		{
			LCD_write_command(LCD_Begin_at_second_row + position);
		}
	}
	else if(line == 3)
	{
		if (position <60 && position>=0)
		{
			LCD_write_command(LCD_Begin_at_third_row + position);
		}
	}
	else if(line == 4)
	{
		if (position <80 && position>=0)
		{
			LCD_write_command(LCD_Begin_at_fourth_row + position);
		}
	}
	
	
}
void LCD_isbusy()
{
	//Data_dir_LCD_PORT &= ~ (0xFF << data_shift); //inputl
	Data_dir_LCD_PORT= 0x00; //inputl
	LCD_CTRL |= (1<<RW_switch);//read mode
	LCD_CTRL &= ~(1<<RS_switch);
	LCD_kick();
	Data_dir_LCD_PORT =0xFF;
	LCD_CTRL &= ~(1<<RW_switch);
}

void LCD_Clear_screen()
{
	LCD_write_command(LCD_clear_screen);
}

void LCD_init()
{
	_delay_ms(20);
	Data_dir_LCD_PORT = 0xFF; //output
	Data_dir_LCD_CTRL |= (1<<EN_switch) | (1<<RW_switch) | (1<<RS_switch);
	LCD_CTRL &= ~(1<<EN_switch) | (1<<RW_switch) | (1<<RS_switch);
	
	_delay_ms(15);
	#ifdef Eight_bit_mode
	LCD_write_command(LCD_function_8bit_2line);
	#endif
	#ifdef four_bit_mode
	LCD_write_command(LCD_RETURN_HOME);
	LCD_write_command(LCD_function_4bit_2line);
	#endif
	LCD_Clear_screen();
	LCD_write_command(LCD_RETURN_HOME);
	LCD_write_command(LCD_entry_mode);
	LCD_write_command(LCD_Begin_at_first_row);
	LCD_write_command(LCD_DISP_on_cursor_blink);
}

void LCD_write_command(unsigned char command)
{
	
	#ifdef Eight_bit_mode
	//LCD_isbusy();
	LCD_PORT = command;
	LCD_CTRL &= ~(1<<RW_switch) | (1<<RS_switch);
	_delay_ms(1);
	LCD_kick();
	#endif

	#ifdef four_bit_mode

		
		//LCD_isbusy();
		GET_BIT(command,4)?SET_BIT(LCD_PORT,GPIO_PinNumber_0):CLR_BIT(LCD_PORT,GPIO_PinNumber_0);
		GET_BIT(command,5)?SET_BIT(LCD_PORT,GPIO_PinNumber_1):CLR_BIT(LCD_PORT,GPIO_PinNumber_1);
		GET_BIT(command,6)?SET_BIT(LCD_PORT,GPIO_PinNumber_2):CLR_BIT(LCD_PORT,GPIO_PinNumber_2);
		GET_BIT(command,7)?SET_BIT(LCD_PORT,GPIO_PinNumber_4):CLR_BIT(LCD_PORT,GPIO_PinNumber_4);
		
		LCD_CTRL &= ~ (1<<RS_switch);
		LCD_kick();
		_delay_ms(200);
		
		
		GET_BIT(command,0)?SET_BIT(LCD_PORT,GPIO_PinNumber_0):CLR_BIT(LCD_PORT,GPIO_PinNumber_0);
		GET_BIT(command,1)?SET_BIT(LCD_PORT,GPIO_PinNumber_1):CLR_BIT(LCD_PORT,GPIO_PinNumber_1);
		GET_BIT(command,2)?SET_BIT(LCD_PORT,GPIO_PinNumber_2):CLR_BIT(LCD_PORT,GPIO_PinNumber_2);
		GET_BIT(command,3)?SET_BIT(LCD_PORT,GPIO_PinNumber_4):CLR_BIT(LCD_PORT,GPIO_PinNumber_4);
		
		_delay_ms(1);
		LCD_kick();

	#endif
}

void LCD_write_char(unsigned char data)
{
	
	#ifdef Eight_bit_mode
	//LCD_isbusy();
	LCD_PORT = data;
	LCD_CTRL |=  (1<<RS_switch);
	//LCD_CTRL &= ~(1<<RW_switch) ;
	_delay_ms(1);
	LCD_kick();
	#endif

	#ifdef four_bit_mode
	
	

	
	
	GET_BIT(data,4)?SET_BIT(LCD_PORT,GPIO_PinNumber_0):CLR_BIT(LCD_PORT,GPIO_PinNumber_0);
	GET_BIT(data,5)?SET_BIT(LCD_PORT,GPIO_PinNumber_1):CLR_BIT(LCD_PORT,GPIO_PinNumber_1);
	GET_BIT(data,6)?SET_BIT(LCD_PORT,GPIO_PinNumber_2):CLR_BIT(LCD_PORT,GPIO_PinNumber_2);
	GET_BIT(data,7)?SET_BIT(LCD_PORT,GPIO_PinNumber_4):CLR_BIT(LCD_PORT,GPIO_PinNumber_4);
	
	//LCD_CTRL &= ~((1<<RW_switch) 
	LCD_CTRL |= (1<<RS_switch);
	LCD_kick();
	_delay_ms(200);
	
	GET_BIT(data,0)?SET_BIT(LCD_PORT,GPIO_PinNumber_0):CLR_BIT(LCD_PORT,GPIO_PinNumber_0);
	GET_BIT(data,1)?SET_BIT(LCD_PORT,GPIO_PinNumber_1):CLR_BIT(LCD_PORT,GPIO_PinNumber_1);
	GET_BIT(data,2)?SET_BIT(LCD_PORT,GPIO_PinNumber_2):CLR_BIT(LCD_PORT,GPIO_PinNumber_2);
	GET_BIT(data,3)?SET_BIT(LCD_PORT,GPIO_PinNumber_4):CLR_BIT(LCD_PORT,GPIO_PinNumber_4);
	LCD_CTRL |= (1<<RS_switch);
	LCD_kick();
	_delay_ms(200);
	
	
	
	#endif
}

void LCD_write_string(char* data)
{
	int count =0;
	
	while(*data > 0)
	{
		count++;
		LCD_write_char(*data++);
		if(count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		if (count ==32)
		{
			LCD_Clear_screen();
			LCD_GOTO_XY(2,0);
			count =0;
		}
	}
}




void LCD_write_num(uint16_t num){
	LCD_PORT = num;
	LCD_CTRL |=  (1<<RS_switch);
	
	uint8_t ch[10],i=0,j=0;
	if(num == 0)
	{
		LCD_write_char('0');
	}
	else
	{
		while(num)
		{
			ch[i] = num % 10 + '0';  //To convert int to char
			num /= 10;
			i++;
		} //Thus number entered is reversed so, we want to display it correctly
		for(j=i;j>0;j--)
		{
			LCD_write_char(ch[j-1]);
		}
	}
}

void LCD_write_num_xy(uint16_t data,uint8_t row , uint8_t col){
	LCD_PORT = data;
	LCD_CTRL |=  (1<<RS_switch);
	if(row == 1){
		LCD_write_char(LCD_Begin_at_first_row);
		_delay_ms(1);
	}else if(row == 2){
		LCD_write_char(LCD_Begin_at_second_row);
		_delay_ms(10);
	}

	for(int j=1;j<=col;j++){
		LCD_write_char(LCD_move_DISP_right);
	}

	LCD_write_num(data);

}
void LCD_write_char_xy(uint8_t data,uint8_t row,uint8_t col){
	LCD_PORT = data;
	LCD_CTRL |=  (1<<RS_switch);


	if(row == 1){
		LCD_write_command(LCD_Begin_at_first_row);
		_delay_ms(1);
		}else if(row == 2){
		LCD_write_command(LCD_Begin_at_second_row);
		_delay_ms(10);
		}

	for(int j=1;j<=col;j++){
		LCD_write_command(LCD_move_DISP_right);
	}
	LCD_write_command(data);

}

void LCD_custom(uint8_t *Local_u8_pattern,uint8_t Local_u8_location)
{
	// First send the address in CGRAM
	LCD_write_command(CGRAM_ADD + (Local_u8_location * MAX_LOCATION));
	// Adding 0x40 is the command to set CGRAM address
	// + each character takes 8 bytes
	for(uint8_t Local_Iterator=0;Local_Iterator<MAX_LOCATION;Local_Iterator++){
		// Passing the bytes on the pattern on LCD
		LCD_write_command(Local_u8_pattern[Local_Iterator]);
	}
	
}