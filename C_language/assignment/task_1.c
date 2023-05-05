#include <stdio.h>
void main(){
	char check;
	do{
		printf("\n- Chooes Task :\n1-Task 1.\n2-Task 2.\n\n\tYour task is : ");
		int task;
		scanf("%d",&task);
		
		switch(task){
			case 1:
				printf("----------Task 1----------\n\n");
				//write a prograam take 2 number from user and compare with ternary
				int num_1 , num_2;
				printf("Enter first number : ");
				scanf("%d",&num_1);
				printf("Enter second number : ");
				scanf("%d",&num_2);
				(num_1==num_2)?(printf("%d equal %d",num_1,num_2)):(num_1>num_2)?
				(printf("%d bigger than %d",num_1,num_2)):(printf("%d lower than %d",num_1,num_2));
			break;
			
			case 2 :
				printf("----------Task 2----------\n\n");
				//writet a program to check number even or odd (ternany only)
				int num ;
				printf("Enter a number : ");
				scanf("%d",&num);
				(num%2 == 0)?(printf("%d is even",num)):(printf("%d is odd",num));
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

