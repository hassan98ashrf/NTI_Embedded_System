#include <stdio.h>

void main(){
	
	char check;
	do{
		printf("\n- Chooes Task :\n1-Task 1,2.\n2-Task 3.\n3-Task 4.\n\n\tYour task is : ");
		int task;
		scanf("%d",&task);
		
		switch(task){
			case 1:
				printf("----------Task 1----------\n\n");
				//print and scanf every data type and size of its variable
				char x ;
				printf("Enter a char : ");
				scanf(" %c",&x);
				printf("Size of char : %d \n\n" ,sizeof(char));
				
				short y ;
				printf("Enter a short : ");
				scanf("%d",&y);
				printf("Size of short : %d \n\n" ,sizeof(short));
				
				int z ;
				printf("Enter a int : ");
				scanf("%d",&z);
				printf("Size of int : %d \n\n" ,sizeof(int));
				
				float a ;
				printf("Enter a float : ");
				scanf("%f",&a);
				printf("Size of float : %d \n\n" ,sizeof(float));
				
				double b ;
				printf("Enter a double : ");
				scanf("%lf",&b);
				printf("Size of double : %d \n\n" ,sizeof(double));
				
				long double c ;
				printf("Enter a long double : ");
				scanf("%lf",&c);
				printf("Size of long double : %d \n\n" ,sizeof(long double));
			break;
			
			case 2 :
				printf("----------Task 2----------\n\n");
				//scan number and print its hexa and octal
				int num ;
				printf("Enter a number : ");
				scanf("%d",&num);
				printf("Octal = %o \n Hexa = %x \n" ,num,num);
			break;
			
			case 3 :
				printf("----------Task 3----------\n\n");
				//scan char and print its value and ASCII
				char symble ;
				printf("Enter a charachter : ");
				scanf(" %c",&symble);
				printf("value = %c \nASCII = %d \n" ,symble,symble);
			break;
			
			default:
				printf("Wrong number!!! \nplease try again \n");
			break;
		}
		printf("\nIf you want try again enter [Y]\nor click any button to exit !!!\n\tChoice is : ");
		scanf(" %c", &check);
	}
	while(check == 'Y');
}

