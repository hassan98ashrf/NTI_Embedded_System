#include <stdio.h>

#define MAX(a,b) (a>b)?a:b

void most_occur(int *arr,int S_arr){
		
	int i,j,count[10],max=0,max_num=0;
	for(i=0 ; i<S_arr; i++){
		count[arr[i]]++;
		/*if(count>=max){
			max=MAX(max,count);
			max_num=arr[i];
		}
		count =1;*/
	}
	printf("%d is the most occurrence element\nIt occure : %d time",max_num,max);
}
void main(){
	
	int arr[] = {1,0,4,5,8,3,3,3,3,1,3,7,4,2};
	
	int S_arr = sizeof(arr)/sizeof(arr[0]);
	most_occur(arr,S_arr);
	
}