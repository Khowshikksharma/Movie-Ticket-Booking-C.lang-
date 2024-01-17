#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct movie
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;

int seat = 100 ;
void insert_details();
void viewAll();  
void book_ticket(); 
void cancel_ticket();
void old_record();

int password=9261;
void main()
{
	int ch;
 	do{	
 	printf("======================");
	printf("\n Moive Ticket booking ");
	printf("\n======================");
	printf("\nPress <1> Insert Movie");
   	printf("\nPress <2> View All Movies");
	printf("\nPress <3> Book Ticket");
	printf("\nPress <4> Cancel Ticket");
	printf("\nPress <5> View All Transactions");
   	printf("\nPress <0> Exit ");
	printf("\n===============================");
   	printf("\nEnter your Choice :: ");
   	scanf("%d",&ch); 	

   	switch (ch)
   	{
    	case 1 :
    	    {
    	        int p;
    	        printf("Enter the password :: ");
    	        scanf("%d",&p);
    	        if(p==password)
        		    insert_details();
        		else
        		    printf("Wrong password please try again\n");
   	    		break;
    	    }
		case 2:
    		viewAll();
   			break;
		case 3:
			book_ticket();
			break;
		case 4:
			cancel_ticket();
			break;
		case 5:
			old_record();
			break;
    	case 0:
    		exit(0);
    		break;
    	default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);
}


void insert_details()
{
	FILE *fp;
	struct movie b;
	printf("Enter movie code :- ");	
	scanf("%s",b.code);
	printf("Enter name :- ");	
	scanf("%s",b.name);
	printf("Enter Release Date:- ");	
	scanf("%s",b.date);
	printf("Enter Ticket Price:- ");	
	scanf("%d",&b.cost);
	fp=fopen("data.txt","a");
	if(fp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Record insert Successfull");
	}
	printf("\n");
	fclose(fp);
	printf("\n");
}


void viewAll()
{
	char ch;
	FILE *fp;
    
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);

	}
	else
	{	
	    printf("Code   Movie   ReleaseDate   Cost\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	printf("\n");
	printf("\n");
}


void book_ticket()
{
 struct movie b;
	FILE *fp;
	FILE *ufp;
	int total_seat,total_amount;
	char name[20];
	unsigned long long int mobile;
	char ch;
	char movie_code[20]; 
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);

	}
	else
	{	
	    printf("Code  Movie  ReleaseDate  Cost\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	printf("\n For Booking ticket Choose Movie(Enter Movie Code)\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{	
		while(fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost)!= EOF)
		{
			if(strcmp(b.code,movie_code) == 0)
			{	
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tMovie name ::%s",b.name);
				printf("\n\t\tDate ::%s",b.date);
				printf("\n\t\tPrice of ticket::%d",b.cost);
				break;
			}
		}
	}
	printf("\n* Fill Details  *");
	printf("\n Your name :");
	scanf("%s",name);
	printf("\n Mobile number :");
	scanf("%llu",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	total_amount = b.cost * total_seat;
	printf("\n ***** ENJOY MOVIE ****\n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %llu",mobile);
	printf("\n\t\tMovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tCost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	ufp=fopen("oldTransaction.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %llu %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record insert Successfull to the old record file");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);
	printf("\n");
	printf("\n");

}

void cancel_ticket()
{
    FILE *fp1,*fp2;
    fp1=fopen("oldTransaction.txt","r");
    fp2=fopen("temp.txt","a");
    if(fp1==NULL || fp2==NULL)
    {
        printf("File not found\n");
        exit(1);
    }
    else{
        char ch;
        int total_seat,total_amount,tcost;
	    char name[20];
	    long int mobile;
	    char movie_code[20],mname[20];
        while( ( ch = fgetc(fp1) ) != EOF )
      		printf("%c",ch);
        fclose(fp1);
        char moviename[20],personname[20];
        printf("Enter the movie name and your name");
        scanf("%s %s",moviename,personname);
        fp1=fopen("oldTransaction.txt","r");
        while(fscanf(fp1,"%s %llu %d %d %s %d",name,&mobile,&total_seat,&total_amount,mname,&tcost)!=EOF)
        {
            if(!(strcmp(moviename,mname)==0 && strcmp(personname,name)==0))
            {
                fprintf(fp2,"%s %llu %d %d %s %d \n",name,mobile,total_seat,total_amount,mname,tcost);
            }
        }
        fclose(fp1);
        fclose(fp2);
        remove("oldTransaction.txt");
        rename("temp.txt","oldTransaction.txt");
        printf("\n\n");
    }
    
}

void old_record()
{
	char ch;
	FILE *fp;
	fp = fopen("oldTransaction.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{	
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	printf("\n");
	printf("\n");
}
