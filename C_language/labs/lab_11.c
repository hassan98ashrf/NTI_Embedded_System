#include <stdio.h>    
#include <stdlib.h>  
#include <stdint.h>
#include <string.h>
/*
float add (float num_1 , float num_2){
	return (num_1+num_2);
}
float multi (float num_1 , float num_2){
	return (num_1*num_2);
}
float sub (float num_1 , float num_2){
	return (num_1-num_2);
}
float divid (float num_1 , float num_2){
	return (num_1/num_2);
}
void main(){
	printf("Enter first number : ");
	float num_1;
	scanf("%f",&num_1);
	printf("Enter operation : ");
	char op;
	scanf(" %c",&op);
	printf("Enter second number : ");
	float num_2;
	scanf("%f",&num_2);
	float (*ptr[4])(float , float)={add,multi,sub,divid};
	float result = 0;
	switch(op){
		case '+':
			result = ptr[0](num_1,num_2);
			printf("%.2f + %.2f = %.2f",num_1,num_2,result);
			break;
		case '*':
			result = ptr[1](num_1,num_2);
			printf("%.2f * %.2f = %.2f",num_1,num_2,result);
			break;
		case '-':
			result = ptr[2](num_1,num_2);
			printf("%.2f - %.2f = %.2f",num_1,num_2,result);
			break;
		case '/':
			result = ptr[3](num_1,num_2);
			printf("%.2f / %.2f = %.2f",num_1,num_2,result);
			break;
		
	}
}

*/

/*

void op ( int (*ptr)[3] , int row , int col ){
	int i , j,max=ptr[0][0],mini=ptr[0][0];
	float avg=0;
	for (i=0 ; i < row ; i++){
		for(j=0 ; j < col ; j++){
			printf("%d\t", ptr[i][j]);
			
			if(ptr[i][j]>max){
				max = ptr[i][j];
			}
			
			if(ptr[i][j]<mini){
				mini = ptr[i][j];
			}
			
			avg = avg + ptr[i][j];
		}
		printf("\n");
	}
	printf("max number is %d\n", max);
	printf("mini number is %d\n", mini);
	printf("avarage number is %.2f\n", avg / 6);
}

void main(){
	int arra[2][3] = {{1,2,3},{4,5,6}};
	op(arra , 2 ,3);	
}

*/

/*

int size_of_array(char *arr){
	int i ;
	for(i=0 ; i < 100 ; i++){
		if(arr[i] == '\0'){
			break;
		}
	}
	return i;
}

void main(){
	printf("Enter string : ");
	char arr[100];
	scanf("%s",arr);
	printf("size of string is : %d " , size_of_array(arr));
	
}
*/


void main(){
	short num = 0x1234;
	void *p;
	p=&num;
	if (*(char*)p == 0x12){
		printf("big endian");
	}
	else{
		printf("little endian ");
	}
	//12 big endian ----- 34 little endian 
}
