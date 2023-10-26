/*
 * project1.c
 *
 * Created: 10/26/2023 10:46:03 AM
 * Author : hassa
 */ 


#include "PING.h"


int main(void)
{
    Ping_Init();
    while (1) 
    {
		 Ping_Play();
    }
}

