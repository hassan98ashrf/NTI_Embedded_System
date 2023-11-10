/*
 * spi_slave.c
 *
 * Created: 10/30/2023 10:28:12 AM
 * Author : Hassan
 */ 

#include <avr/io.h>


#define F_CPU 1000000UL
#include <util/delay.h>
#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

void Spi_Slave_Init(void){
		//Bit 7 – SPIE: SPI Interrupt Enable
		//Bit 6 – SPE: SPI Enable
		/*Bit 5 – DORD: Data Order
		When the DORD bit is written to one, the LSB of the data word is transmitted first.
		When the DORD bit is written to zero, the MSB of the data word is transmitted first.
		Bit 4 – MSTR: Master/Slave Select
		This bit selects Master SPI mode when written to one, and Slave SPI mode when written logic zero.
		*/
		
		//// Set MOSI, SCK and SS as Output Pins
	DDRB = (1<<MISO);
	
		/* Set MOSI, SCK and SS input*/
		DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);
	// Enable SPI, Master mode, Shift Clock = CLK /16
	SPCR = (1<<SPE); 
}

unsigned char Spi_Slave_Recieve(unsigned char cdata){
	
	
	SPDR =cdata;	// Start transmission
	while(!(SPSR & (1<<SPIF)));	// Wait for transmission complete ..IF 0 Them still Transmit Data
	
	return SPDR;	// return the received data
}	
int main(void)
{
	Spi_Slave_Init();
	DDRA=0xFF;
	unsigned char data;
	
	for (data=255;data >=0;data--)
	{
		_delay_ms(1000);
		PORTA=Spi_Slave_Recieve(data);
	}
 
}


