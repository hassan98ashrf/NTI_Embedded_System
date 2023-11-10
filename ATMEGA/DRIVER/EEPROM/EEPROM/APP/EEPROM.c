/*
 * EEPROM.c
 *
 * Created: 11/3/2023 10:15:21 AM
 *  Author: Hassan
 */ 
#define F_CPU		16000000UL
#include "util/delay.h"
#include "I2C.h"
#include "LCD.h"
#include "EEPROM.h"



void EEPROM_Init(void)
{
	TWI_INIT();
}

/* this will write the data to address 0*/
void EEPROM_SaveData(uint8_t pageNum, uint8_t byte_address, uint8_t data)
{
	TWI_INIT();
	_delay_ms(500);
	TWI_WriteStartCond(); // transmit start condition // 0x00a0
	uint8_t var = (DEVICE_ADDRESS | pageNum) & 0xFE;
	// transmit device address and Write
	TWI_WriteSlaveAdd_With_Op(var,I2C_WRITE);
	TWI_WriteData(byte_address); // transmit word address
	
	TWI_WriteData(data); // transmit data
	TWI_WriteStopCond(); // transmit stop condition
	_delay_ms(200);
}


uint8_t EEPROM_ReadData(uint8_t pageNumber, uint8_t byte_address)
{
	uint8_t data = 0;
	TWI_INIT();
	TWI_WriteStartCond(); // transmit start condition
	uint8_t var = (DEVICE_ADDRESS | pageNumber) & 0xFE;
	TWI_WriteSlaveAdd_With_Op(var,I2C_WRITE);// transmit device address and Write
	TWI_WriteData(byte_address); // transmit word address
	TWI_INIT();
	TWI_WriteRepStartCond(); // transmit repeated start condition
	TWI_WriteSlaveAdd_With_Op(var,I2C_READ); // transmit device address and read
	data=TWI_ReadData_Write_NACK();


	TWI_WriteStopCond();
	return data;
}