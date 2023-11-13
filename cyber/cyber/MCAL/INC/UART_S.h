/*
 * UART_S.h
 *
 * Created: 11/12/2023 3:10:26 PM
 *  Author: Hassan
 */ 


#ifndef UART_S_H_
#define UART_S_H_

#include "std.h"
#include "Types.h"
#include "MEM.h"
#include "UART.h"


void UART_SendString(u8 *pu8str);
void UART_SendNumber(u32 u32num);
void UART_ReceiveString(u8 *pu8str);
void UART_RecieveNumber(u32 *pu32num);
void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);



#endif /* UART_S_H_ */