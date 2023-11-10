/*
 * USART.h
 *
 * Created: 10/29/2023 7:33:19 PM
 *  Author: Hassan
 */ 


#ifndef USART_H_
#define USART_H_


#include "ATmega32.h"
#include "UTILS.h"

void Uart_init(void);
void Uart_Send(uint8_t Data);
uint8_t Uart_Recieve(void);
void Uart_Send32(uint32_t Num);
uint32_t Uart_Recieve32(void);
void UART_Send_String (uint8_t* str);
char* UART_Receive_String (void);


#endif /* USART_H_ */