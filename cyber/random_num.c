#include <stdio.h>
#include <stdlib.h>

#include <string.h>


void main(){
	long long arr[256];
    for(int z=0;z<256;z++){
		arr[z]=rand()%100;   
	}
	
	for(int j = 1 ; j <=16 ; j++){	
		
		for(int i=0 ; i<16 ; i++){
			arr[i] = arr[i] + arr[(j*16)+i];
		}
	}
	
	for(int x = 0 ; x<16 ; x++){
		printf("%d   ",arr[x]);
	}
}