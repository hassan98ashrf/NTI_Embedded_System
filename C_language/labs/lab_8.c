#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main(){
	
	char check;
	do{
		printf("\n\n- Chooes lab :\n1-lab 1.\n2-lab 2.\n3-lab 3. \n4-lab 4.\n5-lab 5.\n6-lab 6.\n7-lab 7.\n8-lab 8.\n\n\tYour lab is : ");
		int lab;
		scanf("%d",&lab);
		
		switch(lab){
			case 1:
				printf("\n====== lab 1 ====== \n");
				//print all negative member
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				
				int arr_1[6]={1,-2,-3,5,7,-10};
				int  i_1 ;	
				for(i_1=0 ; i_1<6 ; i_1++){
					if(arr_1[i_1] < 0){
						printf("%d ",arr_1[i_1]);
					}
				}
			break;
			
			case 2 :
				printf("\n\n====== lab 2 ====== \n");
				// write a progoram to find max and mini element
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				
				int arr_2[6]={1,-2,-3,5,7,9};
				int check_2 , i_2,j_2 , temp ;	
				for(i_2=0 ; i_2<6 ; i_2++){
					for(j_2 = i_2+1 ; j_2 <6 ; j_2++){
						if(arr_2[j_2] > arr_2[i_2]){
							temp = arr_2[j_2];
							arr_2[j_2] = arr_2[i_2];
							arr_2[i_2] = temp;
						}
					}
				}
				printf("The max number is %d\nThe mini number is %d ",arr_2[0],arr_2[5]);
	
			break;
			
			case 3 :
				// write a progoram to find sum of elements
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				int arr_3[6]={1,-2,-3,5,7,9};
				int sum_3=0 , i_3;	
				for(i_3=0 ; i_3 < 6 ; i_3++){
					sum_3 += arr_3[i_3];
				}
				printf("The sum is %d ",sum_3);
				
			break;
			
			case 4 :
				printf("\n\n====== lab 4 ====== \n");
				// write a progoram to copy elementts from araay to another
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				int arr_4[6]={1,-2,-3,5,7,9};
				int arr_4_copy[6];
				int i_4;	
				for(i_4=0 ; i_4 < 6 ; i_4++){
					arr_4_copy[i_4] = arr_4[i_4];
					printf("%d ",arr_4_copy[i_4]);
				}
				
			break;
			
			case 5 :
				printf("\n\n====== lab 5 ====== \n");
				// write a convert decciaml to biinary
				//print all negative member
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				
				int arr_5[]={1,0,1,0,0,1};
				int  i_5,count_5=0 ;	
				for(i_5=0 ; i_5<6 ; i_5++){
					if(arr_5[i_5] == 1){
						count_5++;
					}
				}
				printf("%d ",count_5);
			break;
			
			case 6 :
				printf("\n\n====== lab 6 ====== \n");
				// write a convert decciaml to biinary
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				
				int arr_6[]={9,0,2,5,3,7,6,4};
				int size_arr_6 = sizeof(arr_6)/sizeof(arr_6[0]);
				int  i_6 = size_arr_6 ;	
				for( ; i_6 >0 ; i_6--){
					printf("%d ",arr_6[i_6-1]);
				}
				
			break;
			
			case 7 :
				printf("\n\n====== lab 7 ====== \n");
				// write a convert decciaml to biinary
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				int arr_7[6]={1,-2,-3,5,7,9};
				int check_7 , i_7,j_7 , temp_7 ;	
				for(i_7=0 ; i_7<6 ; i_7++){
					for(j_7 = i_7+1 ; j_7 <6 ; j_7++){
						if(arr_7[j_7] > arr_7[i_7]){
							temp_7 = arr_7[j_7];
							arr_7[j_7] = arr_7[i_7];
							arr_7[i_7] = temp_7;
						}
					}
				}
				printf("The second largest number is %d ",arr_7[1]);
				
			break;
			
			case 8:
				printf("\n====== lab 8 ====== \n");
				//print all negative member
				/* get data from user
				printf("Enter the number of array : ");
				int size_arr_1;
				scanf("%d",&size_arr_1);
				
				int arr[size_arr_1];
				for(i=0 ; i<size_arr_1 ; i++){
					printf("Enter element %d : ",i+1 );
					scanf("%d",&arr[i]);
				}
				*/
				
				int arr_8[100];
				printf("Entter number of array : ");
				int n;
				scanf("%d",&n);
				for(i_8=0 ; i_8<n ; i_8++){
					
				}
				int  i_8 ,count_even = 0 , count_odd = 0;	
				for(i_8=0 ; i_8<8 ; i_8++){
					if(arr_8[i_8] %2 == 0){
						count_even++;
					}
					else{
						count_odd++;
					}
				}
				printf("Sum of even = %d\nSum of odd = %d ",count_even,count_odd);
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
