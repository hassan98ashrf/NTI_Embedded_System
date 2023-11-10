/*
 * I2C.c
 *
 * Created: 11/3/2023 10:07:22 AM
 *  Author: Hassan
 */ 
#define F_CPU       16000000UL
#include "STD_macro.h"
#include "I2C.h"


void TWI_INIT(void)
{
	TWBR= (uint8_t) (((F_CPU/SCL_Clock)-16)/(2*SCL_PRESCALAR));
	#if (SCL_PRESCALAR == SCL_PRESCALAR_01)
	TWSR = 0x00;
	#elif (SCL_PRESCALAR == SCL_PRESCALAR_04)
	TWSR = 0x01;
	#elif (SCL_PRESCALAR == SCL_PRESCALAR_16)
	TWSR = 0x02;
	#elif   (SCL_PRESCALAR == SCL_PRESCALAR_64)
	TWSR = 0x03;
	#endif
}
void TWI_WriteStartCond(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	// start condition has been transmitted
	//while ((TWSR & 0XF8) != 0x08);
}


void TWI_WriteRepStartCond(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	//wait to finish
	while(READ_BIT(TWCR,TWINT)==0);
	// repeated start condition has been transmitted
	while ((TWSR & 0XF8) != 0x10);
}


void TWI_WriteStopCond(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void TWI_WriteData(uint8_t Data)
{
	TWDR = Data;
	TWCR = ((1<<TWINT) | (1<<TWEN) );
	while(READ_BIT(TWCR,TWINT)==0);
	//check data has been transmitted and ACK has been received
	//while ((TWSR & 0xf8) != 0x28);
}

uint8_t  TWI_ReadData_Write_NACK(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0);
	// data byte has been received and Not ACK has been returned
	//while ((TWSR & 0XF8) != 0x58);
	return TWDR ;
}


uint8_t  TWI_ReadData_Write_ACK(void)
{
	/*Enable Acknowledgement TWEA */
	TWCR=(1<<TWINT)|(1<<TWEN) |(1<<TWEA);
	while(READ_BIT(TWCR,TWINT)==0);
	// data byte has been received and Not ACK has been returned
	while ((TWSR & 0XF8) !=0x50 );
	return TWDR ;
}


void TWI_WriteSlaveAdd_With_Op(uint8_t SLA_Add, uint8_t Operation)
{

	TWDR=SLA_Add<<1;
	if(Operation == I2C_READ)
	{
		/* Copy data in TWI data register */
		TWDR |= 0x01;
	}
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(READ_BIT(TWCR,TWINT)==0); //wait to finish
	if(Operation == I2C_WRITE)
	{
		// SLA+write has been transmitted and ACK has been received
		while ((TWSR & 0XF8) != 0x18);
	}
	else if(Operation == I2C_READ)
	{
		// SLA+read has been transmitted and ACK has been received
		while ((TWSR & 0XF8) != 0x40);
	}
}
