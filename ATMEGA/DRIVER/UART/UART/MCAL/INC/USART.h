/*
 * USART.h
 *
 * Created: 10/29/2023 1:29:50 AM
 *  Author: Hassan
 */ 


#ifndef USART_H_
#define USART_H_


/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "ATmega32.h"
#include "Utils.h"

void	 UART_INIT(void);
void	 UART_Send(uint8_t data );
uint8_t  UART_Receive(void);

void     UART_SendNumberU32(uint32_t num);
uint32_t UART_ReceiveNumberU32(void);

void   UART_Send_String(char* str);
char*  UART_Receive_String(void);

/*Clock*/




#endif /* USART_H_ */