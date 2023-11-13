/*
 * std.h
 *
 * Created: 11/12/2023 11:48:53 AM
 *  Author: Hassan
 */ 


#ifndef STD_H_
#define STD_H_



#define F_CPU    8000000
#include <util/delay.h>

#define  SET_BIT(reg,bit)     (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)     (reg=reg&~(1<<bit))
#define  TGL_BIT(reg,bit)     (reg=reg^(1<<bit))
#define  READ_BIT(reg,bit)    ((reg>>bit)&1)     //(reg &(1<<bit))


#endif /* STD_H_ */