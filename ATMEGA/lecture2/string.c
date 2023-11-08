#include <stdio.h>


void main(){
	
	char arr[] = "HASSAN";
	int count =0;
	for(int i =0 ; arr[i] != '\0';i++)
	{
		count++;
	}
	printf("size of string is %d",count);
	
}