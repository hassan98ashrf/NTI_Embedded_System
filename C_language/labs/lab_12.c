#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int *func(int size ){
	int * arr = (int*)malloc(size * sizeof(int));
	int i=0;
	for(;i<size;i++){
		scanf("%d",arr+i);
	}
	int start = 0 , end = size-1,temp;
	while(start<end){
		temp = arr[start];
		arr[start]= arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	return arr;
}	


typedef struct {
	int array[100];
	int count;
}data_t;
data_t func_2(int y){
	static data_t b;
	int start=0,end=1;
	int i=2;
	b.count=0;
	b.array[0]=0;
	b.array[1]=1;
	b.array[2] = start+end;
	while (b.array[i]<=y){
		start = end;
		end = b.array[i];
		b.array[i+1] = start + end;
		i++;
	}
	b.count = i;
	return b;	
}
void main(){
	data_t x;
	data_t y;
	int end;
	printf("Enter end of array: ");
	scanf("%d",&end);
	y.count = end;
	x = func_2(end);
	int i=0;
	printf("Fibonacci Series: ");
	for(;i<x.count;i++){
		printf("%d\t",x.array[i]);
	}
	
	
	
	
	
	/*
	int *p,size;
	printf("Enter number of array: ");
	scanf("%d",&size);
	p = func(size);
	int i=0;
	printf("Reverse array is : ");
	for(;i<size;i++)
	{
		printf("%d\t",*(p+i));
	}
	*/
	
	
}
