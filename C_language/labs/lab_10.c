

#include <stdio.h>    
#include <stdlib.h>  
#include <stdint.h>
#include <string.h>

float * circle_calc(float num){
	static float calc [2];
	calc[0] = 3.14 * num * num;
	calc[1] = 2 * num *3.14;
	return calc;
}

int * op_array(int *number){
	static int op [2];
	int i,j,temp ;
	for(i=0 ; i<5 ; i++){
		for(j = i+1 ; j <5 ; j++){
			if(*(number+j) > *(number+i)){
				temp = *(number+j);
				*(number+j) = *(number+i);
				*(number+i) = temp;
			}
		}
	}
	op[0] = *number;
	op[1] = *(number+4);
	return op;
}

void main()
{
	int number[5] = {10,30,-5,11,2};
	int *op = op_array(number);
	printf("Max = %d \nMini = %d ",*op,*(op+1));
	
	/*
	float num,*calc;
	printf("Enter reduis : ");
	scanf("%f", &num);
	calc = circle_calc(num);
	printf("Area = %.2f \nCir = %.2f ",*calc,*(calc+1));
	*/
}