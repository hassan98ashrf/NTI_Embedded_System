
			
#include <stdio.h>

int add (int x, int y)
{
	return x+y;
}


int sub (int x, int y)
{
	return x-y;
}
void main(){
	
	//int (*fun)(int,int) = &add; 
	int (*fun)(int,int) = &sub; 
	printf("%d\t",(*fun)(4,2));
	
	
	
}