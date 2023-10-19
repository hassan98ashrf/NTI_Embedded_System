
			
#include <stdio.h>

void swap(int *x , int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main(){
	
	int arr[] = {1,9,7,4,2};
	int i, j; 
	
	int S_arr = sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < S_arr - 1; i++)
	{ 
        int min = i;
		for (j = i+1; j < S_arr ; j++) 
		{
            if (arr[j] < arr[min]) 
				min = j;
		}
		swap(&arr[min],&arr[i] );
	}
	
	for(i=0 ; i<S_arr ; i++)
	{
		printf("%d\t",arr[i]);
	}
	
}