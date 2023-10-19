/*
 * DIO.c
 *
 * Created: 10/17/2023 2:51:29 PM
 *  Author: amlta
 */ 

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//============== Includes ==============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "DIO.h"
#include "Atmega32.h"


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//========== APIs Supported by " MCAL GPIO DRIVER " ===========
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void MCAL_DIO_INIT_PIN( DIO_t * PORTx ,  DIO_CFG_t * PIN){
	
	if(PIN->DIO_Mode == DIO_Mode_INPUT){
		PORTx->DDR = (PORTx->DDR & ~(1 << PIN->DIO_PinNumber)) | (PIN->DIO_Mode << PIN->DIO_PinNumber);
		PORTx->PORT &= 1 << PIN->DIO_PinNumber;
	}
	else if(PIN->DIO_Mode == DIO_Mode_INPUT_FLO){
		PORTx->DDR &= ~(1 << PIN->DIO_PinNumber);
		PORTx->PORT &= ~(1 << PIN->DIO_PinNumber);
	}
	else{
		PORTx->DDR = (PORTx->DDR & ~(1 << PIN->DIO_PinNumber)) | (PIN->DIO_Mode << PIN->DIO_PinNumber);
	}
}


void MCAL_GPIO_RESET( DIO_t* PORTx_RESET){
	PORTx_RESET->DDR = 0;
	PORTx_RESET->PIN = 0;
	PORTx_RESET->PORT = 0;
}

unsigned char MCAL_DIO_READ_PIN( DIO_t* PORTx , unsigned char PIN_NUMBER){
	return (PORTx->PIN >> PIN_NUMBER & 1);
}

unsigned char MCAL_DIO_READ_PORT( DIO_t * PORTx){
	return PORTx->PIN;
}


void MCAL_DIO_WRITE_PIN( DIO_t * PORTx , unsigned char PIN_NUMBER , unsigned char VAL){
	PORTx->PORT = (PORTx->PORT & ~(1 << PIN_NUMBER)) | (VAL << PIN_NUMBER);
}


void MCAL_DIO_WRITE_PORT( DIO_t* PORTx , unsigned char VAL){
	PORTx->PORT = VAL;
}

void MCAL_DIO_tOGGLE_PIN( DIO_t* PORTx , unsigned char PIN_NUMBER){
	PORTx->PORT ^= (1 << PIN_NUMBER);
}

void MCAL_DIO_tOGGLE_PORT( DIO_t* PORTx ){
	PORTx->PORT ^= 0xff;
	
}