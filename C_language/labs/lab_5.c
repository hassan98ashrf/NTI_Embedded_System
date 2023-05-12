#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3. \n4-lab 4.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//write a progoram to take num and print even and print sum of even 
				
				int even_num,sum=0;
				printf("Enter start number : ");
				scanf("%d",&even_num);
				if(even_num%2!=0){
						
						even_num++;
					}
				while(even_num < 99){
					sum = sum + even_num;
					printf("%d\t",even_num);
					even_num+=2;
				}
				printf("\nsum of even = %d\t",sum);
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to get number and print itts factorial
				
				unsigned long long numbe,facto=1;
				printf("Enter intrger number : ");
				scanf("%d",&numbe);;
				int ii = numbe;
				while(ii>0){
					facto = facto * ii;
					ii--;
				}
				printf("number is = %d\tFactorial is = %llu",numbe,facto);
		
	
			break;
			
			case 3 :
				printf("\n\n====== lab 3 ====== \n");
				// write a progoram to print multiblication table of get number
				
				int num;
				printf("Enter number : ");
				scanf("%d",&num);
				int i;
				for(i = num ; i>0 ; i--){
					printf("%d * %d = %d\t",num,i,i*num);	
				}
			break;
			
			case 4 :
				printf("\n\n====== lab 4 ====== \n");
				// write a progoram to get number of ady and print the day and repeat if ch=y
			int day;
			char ch;
			do{
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
				printf("\n\nIf you want try again enter [y]\nor click any button to exit !!!\n\tChoice is : ");
				scanf(" %c", &ch);
				} while(ch == 'y');
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
