
#include <stdio.h>    
#include <stdlib.h>  
#include <stdint.h>
#include <string.h>


void main()    
{   
	
	/*
	///////////////lab 1
	
	int  i_1,j_1;
	int arr_1[3][4] ;	
	//store
	for(i_1=0 ; i_1<3 ; i_1++){
		for(j_1=0 ; j_1<4 ; j_1++){
				scanf("%d",&arr_1[i_1][j_1]);
		}
	}
	//print
	for(i_1=0 ; i_1<3 ; i_1++){
		for(j_1=0 ; j_1<4 ; j_1++){
			printf("%d ",arr_1[i_1][j_1]);
		}
		printf("\n");
		}
	*/
		
	/*
	///////////////lab 2
	printf("\n\n====== lab 2 ====== \n");
	//add two array
	int arr_2[3][4]={5,6,4,7,2,3,4,5,7,9,1,0};
	int arr_2_add[3][4]={3,2,4,1,6,5,4,3,1,0,7,0};
	int i_2,j_2;
	//store
	for(i_2=0 ; i_2<3 ; i_2++){
		for(j_2=0 ; j_2<4 ; j_2++){
			arr_2_add[i_2][j_2] += arr_2[i_2][j_2];
		}
	}
	//print
	for(i_2=0 ; i_2<3 ; i_2++){
		for(j_2=0 ; j_2<4 ; j_2++){
			printf("%d ",arr_2_add[i_2][j_2]);
		}
		printf("\n");
	}
	
	
	*/
	
	/*
	///////////////lab 3
	printf("\n\n====== lab 3 ====== \n");
	//add two array
	int arr_3[3][4]={5,6,4,7,2,0,4,5,7,9,1,2};
	int i_3,j_3;
	int max = arr_3[0][0];
	int min = arr_3[0][0];
	//store
	for(i_3=0 ; i_3<3 ; i_3++){
		for(j_3=0 ; j_3<4 ; j_3++){
			if(arr_3[i_3][j_3] > max){
				max = arr_3[i_3][j_3];
			}
			if(arr_3[i_3][j_3] < min){
				min = arr_3[i_3][j_3];
			}
		}
	}
	//print	
	printf("The biggest element is : %d\nThe smallest element is : %d",max,min);
	*/
	
	/*
	///////////////lab 4
	printf("\n\n====== lab 4 ====== \n");
	//add two array
	int arr_4[3][4]={5,6,4,7,2,0,4,5,7,9,1,2};
	//int arr_4_c[3][4]={5,6,4,7,2,0,4,5,7,9,1,2};
	int arr_4_c[3][4]={4,99,4,7,8,7,4,5,7,9,1,2};
	
	int i_4,j_4,flag=0;
	
	//store
	for(i_4=0 ; i_4<3 ; i_4++){
		for(j_4=0 ; j_4<4 ; j_4++){
			if(arr_4[i_4][j_4] != arr_4_c[i_4][j_4]){
				flag=1;
				break;
			}
		}
	}
	//print	
	switch(flag){
		case 1:
			printf("The marix is different");
			break;
		default:
			printf("The marix is same");
			break;
		
	}
	*/
	
	/*
	///////////////lab 5
	printf("\n\n====== lab 5 ====== \n");
	//add two array
	int arr_5[3][4]={5,6,4,7,2,1,4,5,7,9,1,2};
	int arr_5_c[3][4]={4,10,4,7,8,7,4,5,7,9,1,2};
	
	int i_5,j_5,flag=0;
	
	//store
	for(i_5=0 ; i_5<3 ; i_5++){
		for(j_5=0 ; j_5<4 ; j_5++){
			arr_5_c[i_5][j_5] *= arr_5[i_5][j_5];
			}
		}
	
	//print	
	for(i_5=0 ; i_5<3 ; i_5++){
		for(j_5=0 ; j_5<4 ; j_5++){
			printf("%d ",arr_5_c[i_5][j_5]);
			}
		printf("\n");
	}
		*/






}

