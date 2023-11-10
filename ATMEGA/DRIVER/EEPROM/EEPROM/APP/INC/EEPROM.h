/*
 * EEPROM.h
 *
 * Created: 11/3/2023 9:59:30 AM
 *  Author: Hassan
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "stdint.h"
#include "LCD.h"


#define DEVICE_ADDRESS      0x50


#define  u16ADDRESS_00		0xA000
#define  u16ADDRESS_01		0xA001
#define  u16ADDRESS_02		0xA002
#define  u16ADDRESS_03		0xA003
#define  u16ADDRESS_04		0xA004
void EEPROM_Init(void);
void EEPROM_SaveData( uint8_t pageNum, uint8_t byte_address, uint8_t data);
uint8_t EEPROM_ReadData(uint8_t pageNumber, uint8_t byte_address);

#endif /* EEPROM_H_ */