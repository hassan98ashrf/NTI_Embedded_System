#include <stdio.h>

void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3. \n4-lab 4.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//write a progoram to print sum of 2 int (if difeerence)and sum of 3 int (if smiller)
				
				//get data from user
				int num_1,num_2;
				printf("Enter first number : ");
				scanf("%d",&num_1);
				printf("Enter second number : ");
				scanf("%d",&num_2);
				
				//check if numbers are equal
				if(num_1 != num_2){
					printf("numbers are not equal\nResult is : %d",num_1+num_2);
				}
				else{
					printf("numbers are equal\nResult for sum : %d\n Result for trible sum : %d", num_1+num_2 , (num_1+num_2)*3 );
				}
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to take 2 number from user and make all calculatio algoritm(calculator)
				
				//get data from user
				int number;
				printf("Enter  number : ");
				scanf("%d",&number);
				
				//check if int >51 
				if(number<51){
					printf("%d is smaller than 51\nResult is : %d",number,51-number);
				}
				else if(number>51) {
					printf("%d is bigger than 51\nResult is : %d",number,(number-51)*3);
				}
				else{
					printf("number is %d. so the difference is 0",number);
				}
			break;
			
			case 3 :
				printf("\n\n====== lab 3 ====== \n");
				// write a progoram to check multiplle number of 3 or 7
				
				//get data from user
				int fnum;
				printf("Enter first number : ");
				scanf("%d",&fnum);
				
				//check if mod 3 orr 7
				if(fnum%3==0 && fnum%7==0){
					printf("%d is multiple of 3 and 7",fnum);
				}
				else if(fnum%3==0) {
					printf("%d is multiple of 3 ",fnum);
				}
				else if(fnum%7==0) {
					printf("%d is multiple of 7 ",fnum);
				}
				else{
					printf("%d is not multiple of 3 or 7 ",fnum);
				}
			break;
			
			case 4 :
				printf("\n\n====== lab 4 ====== \n");
				// write a progoram to check nears number to 100
				
				//get data from user
				int num1,num2,div_1,div_2;
				printf("Enter first number : ");
				scanf("%d",&num1);
				printf("Enter second number : ");
				scanf("%d",&num2);
				
				div_1 = num1-100;
				div_2 = num2-100;
				
				//turn negative to positive
				div_1 = (div_1 > 0)? (div_1=div_1):(div_1 = -1*div_1);
				div_2 = (div_2 > 0)? (div_2=div_2):(div_2 = -1*div_2);
	
				if(div_1 == div_2){
					printf("Two number has the samee distance to 100");
				}
	
				else if(div_1 > div_2){
					printf("The nearst distance is %d for number %d ",div_2,num2);
				}
				else{
					printf("The nearst distance is %d for number %d ",div_1,num1);
				}
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
