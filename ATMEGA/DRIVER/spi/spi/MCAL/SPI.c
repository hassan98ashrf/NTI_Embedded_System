/*
 * SPI.c
 *
 * Created: 10/31/2023 11:17:51 AM
 *  Author: Hassan
 */ 
#include "SPI.h"
#include "DIO.h"


SPI_CONFIG* g_SPI_Config =NULL ;



void MCAL_SPI_Init( SPI_CONFIG* SPI_Config )
{
	g_SPI_Config = SPI_Config  ;
	// Safety for register
	uint8_t Temp_SPCR=0;
	uint8_t Temp_SPSR=0;
	//set BaudRate_Prescalers
	switch(SPI_Config->BaudRate_Prescalers)
	{
		case SPI_BaudRate_Prescalers_4:
		{
			Temp_SPCR &=SPI_Config->BaudRate_Prescalers  ;
			break ;
		}
		
		case SPI_BaudRate_Prescalers_128:
		{
		
			Temp_SPCR |= SPI_Config->BaudRate_Prescalers ;
			break ;
		}
	};
	//Set mode
	switch(SPI_Config->MODE)
	{
		case SPI_MODE_Master :
		Temp_SPCR |=SPI_Config->MODE ;
		break ;
		case SPI_MODE_Slave :
		Temp_SPCR &=SPI_Config->MODE ;
		break ;
	}
	// set speed Communication
	switch( SPI_Config->Speed_Communication )
	{
	case SPI_Speed_Communication_Normal :
		Temp_SPSR &=SPI_Config->Speed_Communication ;
		break ;
	case SPI_Speed_Communication_Double_Speed :
		Temp_SPSR |=SPI_Config->Speed_Communication ;
		break ;	
	}
	//set Polarity
	switch(  SPI_Config->Polarity )
	{
	case SPI_Polarity_High_level_idle_state :
		Temp_SPCR |=SPI_Config->Polarity ;
		MCAL_GPIO_WritePin(GPIOB,GPIO_PIN7,1) ; //set pin idle high 
		break ;
	case SPI_Polarity_Low_level_idle_state :
		Temp_SPCR &=SPI_Config->Polarity ;
		break ;
	}
	// set Phase
	switch(  SPI_Config->Phase )
	{
	case SPI_Phase_Data_Latched_On_First_Clock :
		Temp_SPCR &=SPI_Config->Phase ;
		break ;
	case SPI_Phase_Data_Latched_On_Second_Clock :
		Temp_SPCR |= SPI_Config->Phase ;
		break ;
	}
	//set Data_Order
	switch(  SPI_Config->Data_Order )
	{
	case SPI_Data_Order_LSB_Transmitted_First :
		Temp_SPCR |=SPI_Config->Data_Order ; 
		break ;
	case SPI_Data_Order_MSB_Transmitted_First :
		Temp_SPCR &=SPI_Config->Data_Order ;
		break ;
	}
	// set IRQ_EN
	switch(  SPI_Config->IRQ_EN )
	{
	case SPI_IRQ_ENABLE_Disable :
		Temp_SPCR &=SPI_Config->IRQ_EN ;
		EXTI_GLOBAL_Disable() ;
		break ;
	case SPI_IRQ_ENABLE_Enable :
		Temp_SPCR |=SPI_Config->IRQ_EN ;
		EXTI_GLOBAL_Enable() ;
		break ;
	}
	SPI->SPSR = Temp_SPSR ;
	SPI->SPCR = Temp_SPCR ;
	SPI->SPCR |= SPI_Enable() ;	
}


void MCAL_SPI_DeInit( void )
{
	EXTI_GLOBAL_Disable() ;
	SPI->SPCR = SPI_Disable() ;
}



void MCAL_SPI_ReceiveData( uint8_t* PRXBuffer , enum SPI_polling_mechanism polling_EN)
{
	
	if( polling_EN == Enabled)
	{
		while(!(SPI->SPSR & (1<<7)));
	}
	 *PRXBuffer = SPI->SPDR ;
}


void MCAL_SPI_SendData( uint8_t* PTXBuffer , enum SPI_polling_mechanism polling_EN)
{
	SPI->SPDR = *PTXBuffer ;
	if( polling_EN == Enabled)
	{
		while(!(SPI->SPSR & (1<<7)));
	}
	
}


void MCAL_SPI_Receive_Send_Data( uint8_t* PTXBuffer , enum SPI_polling_mechanism polling_EN)
{
	if( polling_EN == Enabled)
	{
		while(!(SPI->SPSR & (1<<7)));
	}
	SPI->SPDR = *PTXBuffer ;
		
	if( polling_EN == Enabled)
	{
		while(!(SPI->SPSR & (1<<7)));
	}
	*PTXBuffer = SPI->SPDR ;
}



void MCAL_SPI_Set_Master_Pin( void )
{
	//PB4---> SS
	//PB5--->MOSI
	//PB6--->MISO
	//PB7--->SCK
	GPIO_PIN_CONFIG Pin_SPI_Conf ;

	//PB4---> SS
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_OUTPUT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN4 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
	//PB5--->MOSI
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_OUTPUT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN5 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
	//PB6--->MISO
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_INPUT_FLOAT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN6 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
	//PB7--->SCK
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_OUTPUT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN7 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
}



void MCAL_SPI_Set_Slave_Pin( void )
{
	GPIO_PIN_CONFIG Pin_SPI_Conf ;
		
	//PB4---> SS
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_INPUT_FLOAT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN4 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
	//PB5--->MOSI
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_INPUT_FLOAT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN5 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
	//PB6--->MISO
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_OUTPUT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN6 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
	//PB7--->SCK
	Pin_SPI_Conf.GPIO_Mode = GPIO_MODE_INPUT_FLOAT ;
	Pin_SPI_Conf.GPIO_Pin_Number = GPIO_PIN7 ;
	MCAL_GPIO_Init(GPIOB,&Pin_SPI_Conf);
}
//=================================================================================

/*
 * ===============================================================
 *
 *                      ISR Function Definitions
 *
 * ===============================================================
 */


void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	g_SPI_Config->P_IRQ_CALL() ;
}