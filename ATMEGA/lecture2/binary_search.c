#include <stdio.h>

void swap(int *x , int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main()
{
	//selection sort
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
	
	//binary search
	int low = 0 , high = S_arr-1 ;
	
	//choosen number 
	int x =7;
	
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == x)
		{
			printf("The Element number is : %d",mid); //1 2 4 7 9 
		}
		if (arr[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
  }
  
  
}