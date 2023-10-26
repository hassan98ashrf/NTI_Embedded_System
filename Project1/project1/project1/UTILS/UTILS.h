/*
 * UTILS.h
 *
 * Created: 10/26/2023 10:51:15 AM
 *  Author: hassa
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#include "MEMmap.h"
#include "stdint.h"
#define F_CPU 16000000
#include "util/delay.h"

#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define CLR_BIT(reg,bit) (reg=reg &(~(1<<bit)))
#define SET_BIT(reg,bit) (reg=reg |(1<<bit))
#define TGL_BIT(reg,bit) (reg=reg ^(1<<bit))




#endif /* UTILS_H_ */