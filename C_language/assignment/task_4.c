#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void half_speed(){
	printf("Half speed\n");
}
void full_speed(){
	printf("Full speed\n");
}
void stop(){
	printf("Stop\n");
}


int *func(int*arr,int size){
	int i ,count_ones=0 ,count_negative=0;
	static int result[2];
	for(i=0 ; i < size ; i++){
		if(arr[i] == 1){
			count_ones++;
		}
		if(arr[i] < 0){
			count_negative++;
		}
	}
	result[0]=count_ones;
	result[1]=count_negative;
	return result;
}

void main(){
	
	char check;
	do{
		printf("\n\n- Chooes task :\n1-task 1.\n2-task 2.\n\n\tYour task is : ");
		int task;
		scanf("%d",&task);
		
		switch(task){
			case 1:
				printf("\n====== task 1 ====== \n");
				//Write a C program to implement this state machines of a DC motor. Each state can be 
				//represented using a function and a printf statement.
				char input;
				int count = 0;
				while(1){
					scanf(" %c",&input);
					if(input == 'c'){
						count++ ;
						switch(count){
							case 1 :
								half_speed();
								break;
							case 2 :
								stop();
								break;
							case 3 :
								full_speed();
								break;
							case 4 :
								stop();
								count=0;
								break;
						}
					}
					else{
						printf("ERROR TRY AGAIN\n");
					}
				}
			break;
			
			case 2 :
				printf("\n\n====== task 2 ====== \n");
				//Write a C function that takes a 1D array of integers and return 
				//the count of ones and negative numbers in the array using call by reference.
				int arr[10]={1,-5,-6,1,0,8,0,1,-8,-4};
				int *res;
				res = func(arr,10);
				printf("Number of ones = %d\n",*(res+0));
				printf("Number of negative = %d",*(res+1));
			break;
			
			default:
				printf("Wrong number!!! \nplease try again \n");
			break;
				}
			printf("\n\nIf you want try again enter [Y]\nor click any button to exit !!!\n\tChoice is : ");
			scanf(" %c", &check);
		}
		
	
	while(check == 'Y');
}
