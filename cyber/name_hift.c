#include <stdio.h>
#include <string.h>


void main(){
	
	printf("Enter your name : ");
	char name[200];
	gets(name);
	printf("Enter shift : ");
	int shtf;
	scanf("%d",&shtf);
	while(shtf >=26){
		shtf = shtf -26;
	}
	
	
	printf("choose dec or inc \ndec = 0\tinc = 1\nYour choice : ");
	int chs;
	scanf("%d",&chs);
	
	switch(chs){
		case 0:
			for(int i=0 ; name[i]!='\0' ; i++){
				if(name[i]>96 && name[i]!=' '){
					name[i] = name[i] - shtf;
					if(name[i]<97){
						name[i]=97-name[i];
						name[i] = 123-name[i];
					}
				}
				else if(name[i]<=96 && name[i]!=' ') {
					name[i] = name[i] - shtf;
					if(name[i]<65){
						name[i]=65-name[i];
						name[i] = 91-name[i];
					}
				}
				
			}
			break;
		case 1:
			for(int i=0 ; name[i]!='\0' ; i++){
				if(name[i]>96 && name[i]!=' '){
					name[i] = name[i] + shtf;
					if(name[i]>122){
						name[i]=name[i]-123;
						name[i] = name[i] +97;
					}
				}
				else if(name[i]<=96 && name[i]!=' ') {
					name[i] = name[i] + shtf;
					if(name[i]>90){
						name[i]=name[i]-91;
						name[i] = name[i] +65;
					}
				}
			}
			break;	
	}
	
	printf("%s",name);
	
}