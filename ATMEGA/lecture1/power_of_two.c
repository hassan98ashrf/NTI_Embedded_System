#include <stdio.h>
int check_power(int *num)
{
	
	if(*num &(*num-1)!= 0 )
		return 1;
	return 0;
}
void main(){
	int num = 15;
	int count = check_power(&num);
	count == 0 ? printf("right"): printf("wrong");
}