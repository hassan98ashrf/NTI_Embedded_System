
			
#include <stdio.h>
#include <string.h>


//User configuration
struct Sbook{
	char book_title[25];
	char author_name[25];
	int publication_year;
	int num_copy;
	int ID;
	float price;
	int status[10];
};
struct Sbook new_book[101];

int i = 0;
int check =1;
int counter = 0;

void delete_book(struct Sbook detail[]){
	int id_book;
	printf("------------------------------\n");
	printf("Enter ID book : ");
	scanf("%d",&id_book);
	
		
	for (int z = 0 ; z<=i && counter<100 ; z++){
		
		if(detail[z].ID == id_book){
			counter = counter - detail[z].num_copy;
			detail[z]= detail[100];
			printf("delete done\n\n ");	
			for(int x=z ; x<=i ; x++){
				detail[100] = detail[x];
				detail[x] = detail[x+1];
				detail[x+1] = detail[100];
			}
			i--;
			break;
		}
		if(z==i)
			printf("ID book not found\n\n ");	
	}
	printf("\n\n Number of copies = %d\n\n ",counter);
	printf("\n\n Number of i = %d\n\n ",i);
}



void borrow(struct Sbook detail[]){
	int id_book;
	printf("------------------------------\n");
	printf("Enter ID book : ");
	scanf("%d",&id_book);
	
		
	for (int z = 0 ; z<=i && counter<100; z++){
		
		
		if(detail[z].ID == id_book){
			printf("\nThe totla copy is %d\n\n",--(detail[z].num_copy));
			counter--;
			if(detail[z].num_copy == 0){
				detail[z]= detail[100];
				printf("delete done\n\n ");	
				for(int x=z ; x<=i && x<100 ; x++){
					detail[100] = detail[x];
					detail[x] = detail[x+1];
					detail[x+1] = detail[100];
				}
				i--;
			}
				
			break;
		}
		if(z==i)
			printf("ID book not found\n\n ");	
	}
	printf("\n\n Number of copies = %d\n\n ",counter);
	printf("\n\n Number of i = %d\n\n ",i);
}

void add_book(struct Sbook detail[] ){
	
	
	printf("------------------------------\n");
	printf("Add the book Details: \n");
	printf("------------------------------\n");
	
	if(counter >100){
		printf("\nERROR above 100 !!!!!!!!!!\n\n");
			
	}
	else{
		printf("Enter book title : ");
		scanf("%s",detail[i].book_title);
	
		printf("Enter author name: ");
		scanf("%s",detail[i].author_name);
	
		printf("Enter publication year : ");
		scanf("%d",&detail[i].publication_year);
	
		printf("Enter number of copies : ");
		scanf("%d",&detail[i].num_copy);
	
		printf("Enter ID : ");
		scanf("%d",&detail[i].ID);
	
		printf("Enter price : ");
		scanf("%f",&detail[i].price);
	
		printf("Enter status : ");
		scanf("%s",detail[i].status);
	
		counter = counter + detail[i].num_copy;
		if(counter > 100){
			printf("\nERROR above 100 !!!!!!!!!!\nWe cant add this book\n\n");
			counter = counter - detail[i].num_copy;
		}
		printf("\n\n Number of copies = %d\n\n ",counter);
		printf("\n\n Number of i = %d\n\n ",i);
		++i;
	}

}

void view_book (struct Sbook detail[]){
	
	for(int z=0 ; z<=i  ; z++){
		printf("-------------------------------\n");
		printf("\tbook title: %s\n",(detail[z].book_title));
		printf("\tauthor name: %s\n",(detail[z].author_name));
		printf("\tpublication year: %d\n",(detail[z].publication_year));
		printf("\tnumber of copies: %d\n",(detail[z].num_copy));
		printf("\tID: %d\n",(detail[z].ID));
		printf("\tprice: %f\n",(detail[z].price));
		printf("\tstatus: %s\n",(detail[z].status));
		printf("\n\n Number of copies = %d\n\n ",counter);
	}
}

void buy_book(struct Sbook detail[]){
	printf("------------------------------\n");
	printf("Add the book Details: \n");
	printf("------------------------------\n");
	printf("Enter ID : ");
	scanf("%d",&detail[i].ID);
	int flag=0;
	int z,x;
	for( z=0 ; z<i; z++){
		if(detail[z].ID == detail[i].ID){
			i--;
			printf("\nThe book was aleardy found!!!!!\n\n\n");
			printf("Enter number of copies : ");
			scanf("%d",&x);
			counter = counter + x ;
			detail[z].num_copy = detail[z].num_copy+x;
			if(counter >100){
				printf("\nERROR above 100 !!!!!!!!!!\n\n");
				counter = counter - x;
				flag = 100 - counter;
				counter = flag + counter;
				detail[z].num_copy = detail[z].num_copy+flag;
				flag=0;
			}
			printf("\n\n Number of copies = %d\n\n ",counter);
			printf("\n\n Number of i = %d\n\n ",i);
			i++;
			break;
		}
	}
	if(detail[z].ID != detail[i].ID){
		printf("Enter book title : ");
		scanf("%s",detail[i].book_title);
	
		printf("Enter author name: ");
		scanf("%s",detail[i].author_name);
	
		printf("Enter publication year : ");
		scanf("%d",&detail[i].publication_year);
	
		printf("Enter number of copies : ");
		scanf("%d",&detail[i].num_copy);
	
		printf("Enter price : ");
		scanf("%f",&detail[i].price);
	
		printf("Enter status : ");
		scanf("%s",detail[i].status);
	
		counter = counter + detail[i].num_copy;
		if(counter > 100){
			printf("\nERROR above 100 !!!!!!!!!!\nWe cant add this book\n\n");
			counter = counter - detail[i].num_copy;
		}
		printf("\n\n Number of copies = %d\n\n ",counter);
		printf("\n\n Number of i = %d\n\n ",i);
		i++;
		
	}	
	
	
}



void main(){
	
	int choice;
	do{
		printf("\t Choose on of the following options\n\n");
		printf("1: Add book Manually\n");
		printf("2: View book\n");
		printf("3: Borrow book\n");
		printf("4: delete_book\n");
		printf("5: buy book\n");		
		printf("\nYour option is : ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				add_book(new_book);
				break;
			case 2: 
				view_book(new_book);
				break;
			case 3:
				borrow(new_book);
				break;
			case 4:
				delete_book(new_book);
				break;
			case 5:
				buy_book(new_book);
				break;
			default :
				printf("\n========Your choice is invalid========\n");
				break;
		}
		printf("\n-------------------------------\n");
		printf("You want to continue ?\n");
		printf("1: Yes.\n");
		printf("2: No.\n");
		printf("-------------------------------\n");
		scanf("%d",&choice);
	}while(choice == 1);
	
	
}