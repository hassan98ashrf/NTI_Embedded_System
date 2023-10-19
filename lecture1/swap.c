#include <stdio.h>

void swap_1(int*num1,int *num2)
{
	int temp = *num1;
	*num1= *num2;
	*num2 = temp;
}

void swap_2(int*num1,int *num2)
{
	*num1 = *num1 + *num2;
	*num2 = *num1 - *num2;
	*num1 = *num1 - *num2;
}

void swap_3(int*num1,int *num2)
{
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}
void main()
{
	int num1 = 5;
	int num2 = 10;
	swap_3(&num1,&num2);
	printf("%d\t%d",num1,num2);
}