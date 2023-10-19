
#ifndef INC_ATMEGA32_H_
#define INC_ATMEGA32_H_

#define Read_Bit(reg,bit) 				(reg &(1<<bit))>>bit
#define Clear_Bit(reg,bit)   			reg &= ~(1<<bit)
#define Set_Bit(reg,bit)  				reg |=  (1<<bit)
#define Assign_Bit(reg,bit,value)		reg  =  (reg & (~(1<<bit)))|(value<<bit)
#define Toggele_bit(reg,bit) 			reg ^=  (1<<bit)

#define Set_reg(reg) 					reg = 0xff
#define Clear_reg(reg)  				reg = 0x00
#define Toggele_reg(reg) 				reg^= 0xff
#define Assign_Reg(reg,value)   		reg = value




#endif