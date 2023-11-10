/*
 * I2C.h
 *
 * Created: 11/3/2023 9:58:23 AM
 *  Author: Hassan
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "stdint.h"

#define TWCR        (*((volatile uint8_t* )0x56))
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

#define TWDR        (*((volatile uint8_t* )0x23))


/* TWAR */
#define TWAR        (*((volatile uint8_t* )0x22))
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define    TWSR     (*((volatile uint8_t* )0x21))
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0

#define    TWBR     (*((volatile uint8_t* )0x20))



/*Options */
#define SLAVE_MODE              0
#define MASTER_MODE             1
#define SCL_CLK_OPTION_ONE      100000UL
#define SCL_CLK_OPTION_THREE    400000UL

/*availabel prescalars 1, 4, 16, 64 */
#define SCL_PRESCALAR_01        0x01
#define SCL_PRESCALAR_4         0x04
#define SCL_PRESCALAR_16        0x10
#define SCL_PRESCALAR_64        0x40

/***Configurations */
#define MODE            MASTER_MODE
#define SCL_Clock       SCL_CLK_OPTION_THREE
#define SCL_PRESCALAR   SCL_PRESCALAR_16

#define I2C_READ            0x01
#define I2C_WRITE           0x00

void TWI_INIT(void);
void TWI_WriteStartCond(void);
void TWI_WriteRepStartCond(void);
void TWI_WriteStopCond(void);

void TWI_WriteSlaveAdd_With_Op(uint8_t SLA_Add, uint8_t Operation);
void TWI_WriteData(uint8_t Data);
uint8_t  TWI_ReadData_Write_NACK(void);
uint8_t  TWI_ReadData_Write_ACK(void);

void TWI_WriteMultiData(uint8_t* Data, uint8_t Data_Size);
void TWI_WriteString(uint8_t* Data, uint8_t Data_Size);
void TWI_ReadMultiData(uint8_t* Data, uint8_t Data_Size);


#endif /* I2C_H_ */