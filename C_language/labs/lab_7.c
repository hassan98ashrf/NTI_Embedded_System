#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///////////lab1
int even_odd_check(int n){
	if(n%2 == 0){
		return 1;			
	}
	else{
		return 0;	
	}
}
///////////lab2
int big_num_check(int n_1, int n_2, int n_3){
	if(n_1>n_2 && n_1>n_3){			//first number > second number or third number
		return n_1;			
	}
	else if (n_2>n_1 && n_2>n_3){	//second number > first number or third number
		return n_2;	
	}
	else if (n_3>n_1 && n_3>n_2){	//third number > first number or second number
		return n_3;	
	}
	else if (n_1>n_2 || n_1>n_3){  //first number = second number or third number
		return n_1;	
	}
	else if (n_2>n_1 || n_2>n_3){ //second number = first number or third number
		return n_2;	
	}
	else if (n_3>n_1 || n_3>n_2){ //third number = first number or second number
		return n_3;	
	}
	else{ //third number = first number = second number
		return n_1;
	}
}
///////////lab3
void multi_fun(long long int number){
	int i,j;
	long long int facto=1,result=0;
	for(i=0 ; i<number ; i++ ){
		for( j=i+1 ; j>0;j--){
			facto=facto*j;
		}
		result = result+(facto/(i+1));
		facto=1;
	}
	printf("The result is %lld",result);
}
///////////lab4
int check_prime(int p_num){
	int i,flag=1;
	if(p_num==0||p_num==1){ //as 0 and 1 not prime number
		flag=0;
	}
	for(i=2 ; i<p_num/2 ; i++ ){
		if(p_num%i ==0){
			flag=0;
			break;
		}	
	}
	
	
	return flag;
}
///////////lab5
void decimal_binary_converter(char d_num){
	char bin[8];
	int i;
	for(i=0 ; i<8 ; i++ ){//store binary
		bin[i] = (d_num>>i)&1;
	}
	
	for(i=7; i>=0 ; i-- ){
		printf("%d",bin[i]);
	}
}
///////////lab6
void check_num(int num){
	int i;
	for(i=1 ; i<=num ; i++ ){
		if(i%5==0 && i%3==0){
			printf("FIZZBUZZ");
		}
		else if(i%5==0){
			printf("BUZZ\t");
		}
		else if(i%3==0){
			printf("FIZZ\t");
		}
		else{
			printf("%d\t",i);
		}
	}
	
	
}


void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3. \n4-lab 4.\n5-lab 5.\n6-lab 6.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//take an inetegr and return 1 even 0 odd 
				
				int n;
				printf("Enter number : ");
				scanf("%d",&n);
		
				int check = even_odd_check(n);	
				if(check == 1){
					printf("%d is even",n);
				}
				else{
					printf("%d is odd",n);
				}
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to get bigeest number
				
				int n_1;
				printf("Enter first number : ");
				scanf("%d",&n_1);
				
				int n_2;
				printf("Enter seccond number : ");
				scanf("%d",&n_2);
				
				int n_3;
				printf("Enter third number : ");
				scanf("%d",&n_3);
		
				int check_big = big_num_check(n_1,n_2,n_3);
				printf("%d is the biggest number",check_big);
	
			break;
			
			case 3 :
				printf("\n\n====== lab 3 ====== \n");
				// write a progoram to count n!/n
				long long int number;
				printf("Enter number : ");
				scanf("%lld",&number);
				multi_fun(number);
			break;
			
			case 4 :
				printf("\n\n====== lab 4 ====== \n");
				// write a progoram to check prime
				int p_num;
				printf("Enter number : ");
				scanf("%d",&p_num);
				int flag =check_prime(p_num);
				if(flag==1){
					printf("%d is prime",p_num);
				}
				else{
					printf("%d is not prime",p_num);
				}
			break;
			
			case 5 :
				printf("\n\n====== lab 5 ====== \n");
				// write a convert decciaml to biinary
				char d_num;
				printf("Enter number : ");
				scanf("%d",&d_num);
				decimal_binary_converter(d_num);
			break;
			
			case 6 :
				printf("\n\n====== lab 6 ====== \n");
				// write a convert decciaml to biinary
				int num;
				printf("Enter number : ");
				scanf("%d",&num);
				check_num(num);
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
