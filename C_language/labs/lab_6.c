#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3. \n4-lab 4.\n5-lab 5.\n6-lab 6.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//write a progoram to print all num except(*3,*5) 
				
				int n;
				printf("Enter start number : ");
				scanf("%d",&n);
		
				for( ;n <=100;n++){
					if(n%3==0 && n%5==0){
						printf("FIZZBUZZ\t");
					}
					else if(n%3==0 ){
						printf("FIZZ\t");
					}
					else if(n%5==0 ){
						printf("BUZZ\t");
					}
					else{
					printf("%d\t",n);
					}
				}	
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to print multiblication table of get number
				
				int num;
				printf("Enter number : ");
				scanf("%d",&num);
				int i , j;
				for(i = 1 ; i<=num ; i++){
					for(j = i ; j<=num ; j++){
						printf("%d * %d = %d\t",i,j,i*j);	
					}
					printf("\n");
				}
		
	
			break;
			
			case 3 :
				printf("\n\n====== lab 3 ====== \n");
				// write a progoram to count digit of number
				int digit_num;
				printf("Enter number : ");
				scanf("%d",&digit_num);
				int init,sum=0;
				for(init=digit_num ; init>0 ;init=init/10){
					sum +=  (init%10);
				}
				printf("sum is %d\t",sum);	
				
			break;
			
			case 4 :
				printf("\n\n====== lab 4 ====== \n");
				/*
				1 2 3 4
				1 2 3
				1 2
				1
				*/
				int number_get;
				printf("Enter number of row : ");
				scanf("%d",&number_get);
				int z , f;
				for(z = number_get ; z>0 ; z--){
					for(f = 1 ; f<=z ; f++){
						printf("%d ",f);	
					}
					printf("\n");
				}
			break;
			
			case 5 :
				printf("\n\n====== lab 5 ====== \n");
				/*
				1
				2 3
				4 5 6
				7 8 9 10
				*/
				int number;
				printf("Enter number of row : ");
				scanf("%d",&number);
				int l , m,u=1;
				for(l=0 ; l < number ; l++){
					for(m=0 ; m <=l ; m++){
						printf("%d ",u);
						u++;
					}
					printf("\n");
				}
			break;
			
			case 6 :
				printf("\n\n====== lab 6 ====== \n");
				/*
				1
				2 2
				3 3 3
				4 4 4 4
				*/ 
				int inumber;
				printf("Enter number of row : ");
				scanf("%d",&inumber);
				int ll , mm,uu=1;
				for(ll=0 ; ll < inumber ; ll++){
					for(mm=0 ; mm <=ll ; mm++){
						printf("%d ",uu);
					}
					uu++;
					printf("\n");
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
