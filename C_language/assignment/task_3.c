#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	
	char check;
	do{
		printf("\n\n- Chooes task :\n1-task 1.\n2-task 2.\n3-task 3. \n\n\tYour task is : ");
		int task;
		scanf("%d",&task);
		
		switch(task){
			case 1:
				printf("\n====== task 1 ====== \n");
				int ii, number, sum = 0;
				// take info from user
				printf("Enter number : ");
				scanf("%d", &number);

				for(ii = 1; ii <= number / 2; ii++){
					if(number%ii == 0){
						sum += ii;
					}
				}
				// Check  
				if(sum == number && number > 0){
					printf("%d is perfect number", number);
				}
				else{
					printf("%d is not perfect number", number);
				}
			break;
			
			case 2 :
				printf("\n\n====== task 2 ====== \n");
				// write a progoram to count digit of number
				int num, digit_num, rem, n = 0;
				float result = 0.0;
				printf("Enter a number : ");
				scanf("%d", &num);
				digit_num = num;
				for (digit_num = num; digit_num != 0; ++n) {
					digit_num /= 10;
				}
				for (digit_num = num; digit_num != 0; digit_num /= 10) {
					rem = digit_num % 10;
					result += pow(rem, n);
				}
				if ((int)result == num)
					printf("%d is an Armstrong number.", num);
				else
					printf("%d is not an Armstrong number.", num);
			break;
			
			case 3 :
				printf("\n\n====== task 3 ====== \n");
				// write a progoram to get number of ady and print the day and repeat if ch=y
				int arr[20], i, j, size, count = 0;
				printf("\n Please Enter Number of elements in an array  :   ");
				scanf("%d", &size);
	
				printf("\n Please Enter %d elements of an Array  :  ", size);
				for (i = 0; i < size; i++){
					scanf("%d", &arr[i]);
				}     
 
				for (i = 0; i < size; i++){
					for(j = i + 1; j < size; j++){
						if(arr[i] == arr[j]){
							count++;
							break;
						}
					}
				}
				printf("\n Total Number of Duplicate Elements  =  %d ", count);
				
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
