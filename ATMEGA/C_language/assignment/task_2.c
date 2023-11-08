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
				//write a progoram to take num and print even and print sum of even 
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
			
			case 2 :
				printf("\n\n====== task 2 ====== \n");
				// write a progoram to count digit of number
				
				float  x,y,z;
				printf("Enter x : ");
				scanf("%f",&x);
				printf("Enter y : ");
				scanf("%f",&y);
				printf("Enter z : ");
				scanf("%f",&z);
				
				float r_part, root1,root2,img;
				r_part=(y*y)-(4*x*z);
				
				if(r_part > 0){
					root1 = (-y + sqrt(r_part) / (2 * x));
					root2 = (-y - sqrt(r_part) / (2 * x));
					printf("\nRoot 1 = %.2f \nRoot 2 = %.2f", root1, root2);
				}
				else if(r_part < 0){
					root1 = root2 = -y / (2 * x);
					img = sqrt(-r_part) / (2 * x);
					printf("\nRoot 1 = %.2f + %.2f \nRoot 2 = %.2f - %.2f", root1, img, root2, img);
				}
				else{
					root1 = root2 = -y / (2 * x);
					printf("\nRoot 1 = %.2f \nRoot 2 = %.2f", root1, root2);
				}
					
			break;
			
			case 3 :
				printf("\n\n====== task 3 ====== \n");
				// write a progoram to get number of ady and print the day and repeat if ch=y
				int row;
				printf("Enter number of row : ");
				scanf("%d",&row);
				int i , j ;
				for(i=0 ; i < row ; i++){
					for(j=0 ; j < (row*2-1) ; j++){
						if(j<((row-1)-i) || j>((row-1)+i) ){
							printf(" ");
						}
						else{
							printf("*");
						}
					}
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
