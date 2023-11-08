/*
 * STD.h
 *
 * Created: 11/2/2023 11:37:54 AM
 *  Author: hassa
 */ 


#ifndef STD_H_
#define STD_H_

#define READ_BIT(reg,bit)    ((reg>>bit)&(1U))
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    (reg|=(1<<bit) )
#define CLR_BIT(reg,bit)    (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)        (reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num)))



#endif /* STD_H_ */