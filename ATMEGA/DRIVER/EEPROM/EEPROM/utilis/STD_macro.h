/*
 * STD_macro.h
 *
 * Created: 11/3/2023 10:03:07 AM
 *  Author: Hassan
 */ 


#ifndef STD_MACRO_H_
#define STD_MACRO_H_


#define READ_BIT(reg,bit)    ((reg>>bit)&(1U))
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    (reg|=(1<<bit) )
#define CLR_BIT(reg,bit)    (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)        (reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num)))


#endif /* STD_MACRO_H_ */