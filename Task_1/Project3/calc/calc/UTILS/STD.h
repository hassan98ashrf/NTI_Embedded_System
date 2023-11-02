/*
 * STD.h
 *
 * Created: 11/1/2023 5:59:11 PM
 *  Author: hassa
 */ 


#ifndef STD_H_
#define STD_H_


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)   ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)         reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num))
#define helper(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define conc_Bits(b7,b6,b5,b4,b3,b2,b1,b0)   helper(b7,b6,b5,b4,b3,b2,b1,b0)

//Pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//Ports
#define PA 0
#define PB 1
#define PC 2
#define PD 3

#define high 1
#define HIGH 1
#define low 1
#define LOW 1




#endif /* STD_H_ */