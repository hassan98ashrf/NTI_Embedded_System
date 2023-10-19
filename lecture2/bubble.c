
			
#include <stdio.h>
#define SIZE 5
void swap(int *x , int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main(){
	
	int arr[] = {1,9,7,4,2};
	int i, j; 
	
	int S_arr = sizeof(arr)/sizeof(int);
    for (i = 0; i < S_arr - 1; i++)
	{ 
        for (j = 0; j < S_arr - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j],&arr[j + 1] );
		}
	}
	
	for(i=0 ; i<S_arr ; i++)
	{
		printf("%d\t",arr[i]);
	}
	
}