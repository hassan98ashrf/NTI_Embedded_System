/*
 * UTILS.h
 *
 * Created: 10/28/2023 11:49:22 AM
 *  Author: Hassan
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(PORT,Bit)       PORT |=  (1<<Bit)		// Set pin
#define Reset_Bit(PORT,Bit)     PORT &= ~(1<<Bit)		// Reset pin
#define Toggle_Bit(PORT,Bit)    PORT ^=  (1<<Bit)		// Toggle pin
#define Read_Bit(PORT,Bit)      ((PORT >> Bit) & 1)		// Read from pin



#endif /* UTILS_H_ */