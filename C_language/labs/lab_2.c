#include <stdio.h>
#define PI 3.14 
void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//write a progoram to calculate area and cicumferance of circle
				float r , area , c;
				printf("Enter redious = ");
				scanf("%f",&r);
				c = 2*PI*r;
				area = PI *r*r;
				printf("circular = %f \nArea = %f\n",c,area);
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to take 2 number from user and make all calculatio algoritm(calculator)
				float num_1 , num_2 ;
				printf("\nEnter first number = ");
				scanf("%f",&num_1);
				printf("Enter second number = ");
				scanf("%f",&num_2);
				
				printf("%.2f + %.2f = %.2f\n",num_1 , num_2 , num_1+num_2 );
				printf("%.2f - %.2f = %.2f\n",num_1 , num_2 , num_1-num_2 );
				printf("%.2f * %.2f = %.2f\n",num_1 , num_2 , num_1*num_2 );
				printf("%.2f / %.2f = %.2f\n",num_1 , num_2 , num_1/num_2 );
				printf("%.2f mod %.2f = %d\n",num_1 , num_2 , (int)num_1%(int)num_2 );
			break;
			
			case 3 :
				printf("\n\n====== lab 3 ====== \n");
				// write a progoram to make And , Or and TOGGLE operator
				int num1 = 6 , num2 = 2 , num3 = 5 , AND , OR , TOGGLE;
				OR = num1 | (1<<0);
				AND = num2 &~ (1<<1);
				TOGGLE = num3 ^ (1<<2);
				printf("\nOR = %d\n", OR );
				printf("AND = %d\n", AND);
				printf("TOGGLE = %d\n", TOGGLE );
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

