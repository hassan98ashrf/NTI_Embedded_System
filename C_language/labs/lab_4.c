#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3. \n4-lab 4.\n5-lab 5.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//write a progoram to take id and print the name of this id
				
				int id;
				printf("Enter your ID : ");
				scanf("%d",&id);
	
				//check if 123
				switch(id){
					case 1234:
						printf("Amr's ID : %d " , id);
						break;
					case 5678:
						printf("Maha's ID : %d " , id);
						break;
					case 9101:
						printf("Ahmed's ID : %d " , id);
						break;
					default:
						printf("INVALDE" );
						break;
				}
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to calaculate the salary depending on state (single 0%	married without kids 1%	married with kids 2% )
				
				int state;
				printf("chooes your state :\n1- single\n2- married without kids\n3- married with kids\nYour choice is : ");
				scanf("%d",&state);
		
				float salary;
				printf("Enter your salary : ");
				scanf("%f",&salary);
	
				//check state
				switch(state){
				case 1:
					printf("Your state is single\nYour salary : %.2f " , salary);
					break;
				case 3:
					printf("Your state is  married with kids\nYour salary : %.2f " , salary+(salary*0.02));
					break;
				case 2:
					printf("Your state is married without kids\nYour salary : %.2f" , salary+(salary*0.01));
					break;
		
				default:
					printf("INVALDE" );
					break;
				}
				
			break;
			
			case 3 :
				printf("\n\n====== lab 3 ====== \n");
				// write a progoram to check number is positive or negative or zero
				
				signed char num;
				printf("Enter number : ");
				scanf("%d",&num);
	
				switch(num){
					case 0:
						printf("Your number is %d ",num);
						break;
				default:
					char check = (num >> 7)&1;
					switch(check){
						case 1 :
							printf("Your number %d is negative",num);
							break;
					default:
						printf("Your number %d is positive",num);
						break;
					}
					break;
				}	
			break;
			
			case 4 :
				printf("\n\n====== lab 4 ====== \n");
				// write a progoram to get number of ady and print the day
				
			int day;
			printf("Enter number of day : ");
			scanf("%d",&day);
			char week[7][20]={"Saturday" , "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday"};
	
			switch(day){
				case 1:
					printf("your day is %s",week[0]);
					break;
				case 2:
					printf("your day is %s",week[1]);
					break;
				case 3:
					printf("your day is %s",week[2]);
					break;
				case 4:
					printf("your day is %s",week[3]);
					break;
				case 5:
					printf("your day is %s",week[4]);
					break;
				case 6:
					printf("your day is %s",week[5]);
					break;
				case 7:
					printf("your day is %s",week[6]);
					break;
				default:
					printf("INVALDE" );
					break;
			}
			break;
			
			case 5 :
				printf("\n\n====== lab 5 ====== \n");
				// write a progoram to get root from quadratic equation 
				
				float  a,b,c;
				printf("Enter a : ");
				scanf("%f",&a);
				printf("Enter b : ");
				scanf("%f",&b);
				printf("Enter c : ");
				scanf("%f",&c);
				
				float right_part, root_1,root_2,imag;
				right_part=(b*b)-(4*a*c);
					switch(right_part > 0){
						case 1:
							root_1 = (-b + sqrt(right_part) / (2 * a));
							root_2 = (-b - sqrt(right_part) / (2 * a));
							printf("\nRoot 1 = %.2f \nRoot 2 = %.2f", root_1, root_2);
							break;
						case 0:
							switch(right_part < 0){
								case 1: //True
									root_1 = root_2 = -b / (2 * a);
									imag = sqrt(-right_part) / (2 * a);
									printf("\nRoot 1 = %.2f + %.2f \nRoot 2 = %.2f - %.2f", root_1, imag, root_2, imag);
									break;
								case 0: // False (right_part = 0)
								root_1 = root_2 = -b / (2 * a);
								printf("\nRoot 1 = %.2f \nRoot 2 = %.2f", root_1, root_2);
								break;
							}
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
