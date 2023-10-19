/*
 * utils.h
 *
 * Created: 10/17/2023 2:32:10 PM
 *  Author: amlta
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SETBIT(reg,bit)				reg = reg |  (1<<bit)
#define CLEARBIT(reg,bit)			reg = reg &~ (1<<bit)
#define TOGGLEBIT(reg,bit)			reg = reg ^  (1<<bit)
#define READBIT(reg,bit)			((reg>>bit)&1)

#define SETREG(reg) 				reg = 0xff
#define CLEARREG(reg)  				reg = 0x00
#define TOGGLEREG(reg) 				reg^= 0xff
#define AssignReg(reg,value)   		reg = value

#endif /* UTILS_H_ */