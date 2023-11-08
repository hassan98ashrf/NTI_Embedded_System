#include <stdio.h>
#define SET(reg,bit) 		reg |= (1<<bit)
#define CLEAR(reg,bit) 		reg &= ~(1<<bit)
#define TOGGLE(reg,bit) 	reg ^= (1<<bit)

void main(){
	
	int reg = 0b0101;
	TOGGLE(reg,2); 
	printf("%d",reg);
	
}