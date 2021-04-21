//Programme to execute two sides of a movie booking process
//From both user and administrative point of view
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct movieinfo	//movie details and user viewing details
{							//will be entered here
	int code;
	char name[20];
	char date[20];
	int cost;
	char time[10];
}info;
typedef struct seat			//user seating arrangement will be 
{							//managed over here
	char code[2];
	int confirm;
	struct seat *next;
}seat;
seat *header;

void insert_details();//for inserting movie details (admin privelege)
void viewAll(); // for viewing all data 
info find(); // for finding data
void book_ticket(); //for booking tickets
void old_record(); //for view old records of users,booked tickets(admin privelege)
void constructScreen();
void insertseat(char ch[2],int flag);
void print();


int login()
{
	int a=0,i=0,data,flag=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
	FILE *fp;
	system("cls");
	printf("\n\n+++++++++++++++Are you a new user or do you have an existing account++++++++++\n\n ");
	printf("\t\t\t1.New User\n\n\t\t\t2.Existing Account\n\n");
	printf("\t\t\tEnter desired code\t");
	scanf("%d",&data);
	if(data==1)
		{
			fp=fopen("password.txt","a");
			system("cls");
			printf("\n\n\t\tPlease enter your account details");
			printf(" \n\n                  ENTER USERNAME:-");
			scanf("%s", &uname);
			fprintf(fp,"\t%s\t",uname);
			printf(" \n\n                  ENTER PASSWORD:-");
			scanf("%s",&pword);
			fprintf(fp,"%s",pword);
			fprintf(fp,"\n");
			fclose(fp);
		}
    do
	{
		
		fp=fopen("password.txt","r");
		system("cls");
		printf("\n  ++++++++++++++++++++++++++++++  LOGIN  ++++++++++++++++++++++++++++++  ");
		printf(" \n\n                  ENTER USERNAME:-");
		scanf("%s", &uname); 
		printf(" \n\n                  ENTER PASSWORD:-");
		while(i<10)
		{
			pword[i]=getch();
			c=pword[i];
			if(c==13) break;
			else printf("*");
			i++;
		}
		pword[i]='\0';
		i=0;
		if(strcmp(uname,"user")==0 && strcmp(pword,"password")==0)
			{
				flag=2;
				break;
			}
		while(getc(fp) != EOF)
		{
			fscanf(fp,"\t%s\t",&user);
			fscanf(fp,"%s",&pass);
			if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1 || flag==2)
		{
			printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();//holds the screen
			break;
		}else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;
			getch();//holds the screen
		}
		
	}while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		exit(0);
		
	}
		system("cls");
		return flag;
		
}
void main()
{
    int flag=login();
	int ch;
	info b;
 	do{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");	
	printf("\t Movie Ticket booking ");
	printf("\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	if(flag==1)
	{
		printf("\nEnter >1< To View All Movie");
		printf("\nEnter >2< To Find Movie ");
		printf("\nEnter >3< To Book Tickets");
		printf("\nEnter >0< To Exit ");
		printf("\nEnter your Choice :: ");
		scanf("%d",&ch); 
		
	switch (ch)
   	{
		case 1:
    		viewAll();
   		break;
    		
		case 2:
    		b=find();
   		break;

		case 3:
		book_ticket();
		break;
		
		case 0:
    	exit(0);
    	break;

    	default:
		printf("Wrong choice !");
    	break;
   	}
	}
	else{
		
	printf("\nEnter >1< To Insert Movie");
   	printf("\nEnter >2< To View All Movie");
	printf("\nEnter >3< To Find Movie ");
	printf("\nEnter >4< To Book Tickets");
	printf("\nEnter >5< To View All Transactions");
   	printf("\nEnter >0< To Exit ");

   	printf("\nEnter your Choice :: ");
   	scanf("%d",&ch); 
	system("cls");	

   	switch (ch)
   	{
    	case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;
    		
		case 3:
    		b=find();
   		break;

		case 4:
		book_ticket();
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
	}
 }while(ch!=0);
}


void insert_details()
{
	
	FILE *fp;		//file pointer
	info b;char ch;			
	printf("Enter movie code :- ");		//movie details are entered over here
	scanf("%d",&b.code);
	printf("Enter  name :- ");	
	scanf("%s",&b.name);
	printf("Enter Release Date:- ");	
	scanf("%s",&b.date);
	printf("Enter Release Timing:- ");	
	scanf("%s",&b.time);
	printf("Enter Ticket Price:- ");	
	scanf("%d",&b.cost);
	
	fp=fopen("data.txt","a");	//file writing in append mode
	
	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%d\t %s\t %s\t %s\t %d \n",b.code,b.name,b.date,b.time,b.cost);
		
		printf("Recorded Successfully");
	}
		printf("\n");
	fclose(fp);
	system("cls");
}
info find() //find details
{

	FILE *fp;
	int ch;info b;
	printf("Enter movie code :");
	scanf("%d",&ch);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{	
		do
		{
			fscanf(fp,"%d %s %s %s %d",&b.code,&b.name,&b.date,&b.time,&b.cost);
			if(b.code==ch)
			{	
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%d",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tmovie time ::%s",b.time);
				printf("\n\t\tprice of ticket ::%d",b.cost);
			}
		}while(b.code!=ch);
		return b;
		
	}

	fclose(fp);
	//system("cls");
}
void viewAll()
{
	
	char ch;
	FILE *fp,*fp1;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file is not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);

}
//for ticket booking 
void book_ticket()
{
	info b;
	seat s1;
	FILE *fp,*ufp;
	int total_seat=1,total_amount,i,j,rcode,ccode,a[5][5],flag=0;
	char name[20],mobile[10];
	char ch[3]; 		//used in display all movies
	char movie_code[20]; //for searching// display all moives by default for movie code
	viewAll();
	printf("\n Book your Tickets Here\n");
	b=find();
	constructScreen();
	fp=fopen("status.txt","r");
	ch[2]='\0';
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			fscanf(fp,"%d",&a[i][j]);
			printf("%d[%d,%d]\n",a[i][j],i,j);
		
			if(a[i][j]==1)
			{
				switch(j)
				{
					case 0:ch[1]='1';break;
					case 1:ch[1]='2';break;
					case 2:ch[1]='3';break;
					case 3:ch[1]='4';break;
					case 4:ch[1]='5';break;
				}
				if(i==0)
				{
					ch[0]='a';
					insertseat(ch,0);
					
				}
				if(i==1)
				{
					ch[0]='b';
					insertseat(ch,0);
					
				}
				if(i==2)
				{
					ch[0]='c';
					insertseat(ch,0);
					
				}
				if(i==3)
				{
					ch[0]='d';
					insertseat(ch,0);
					
				}
				if(i==4)
				{
					ch[0]='e';
					insertseat(ch,0);
					
				}
			}
				
		}
	}
	fclose(fp);
	printf("Enter code of your seat\n");
	scanf("%s",ch);
	insertseat(ch,1);
	switch(ch[0])
	{
		case 'a':i=0;
				break;
		case 'b':i=1;
				break;
		case 'c':i=2;
				break;
		case 'd':i=3;
				break;
		case 'e':i=4;
				break;
	}
	switch(ch[1])
	{
		case '1':j=0;
				break;
		case '2':j=1;
				break;
		case '3':j=2;
				break;
		case '4':j=3;
				break;
		case '5':j=4;
				break;
	}
	a[i][j]=1;
	fp=fopen("status.txt","w");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]==1)
				fprintf(fp,"%d\t",a[i][j]);
			else
				fprintf(fp,"%d\t",a[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	//system("cls");
	printf("\n* Fill Details  *");
	printf("\n your name : ");
	scanf("%s",&name);
	printf("\n mobile number :");
	if(isdigit(getch()))
		scanf("%s",&mobile);
	
	total_amount = b.cost;
	
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %s",mobile);
	printf("\n\t\tmovie name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tcost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	
	
	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s\t %s\t %s\t %s\t %s\t %s\t %d\t \n",name,mobile,b.name,b.date,b.time,ch,total_amount);
		printf("\n Record insert Sucessfull to the old record file");
		fclose(ufp);
	}
	printf("\n");
	exit(0);
}
//for view all user transections
void old_record()
{
	char ch;
	FILE *fp;

	//system("clear");
	
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
}
void constructScreen()
{
	int i,j,k,a[5][5];
	FILE *fp;
	char ch='a';
	fp=fopen("status.txt","r");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	
	printf("                                         <================================>\n");
	printf("                                              ALL EYES THIS WAY PLEASE");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	for(k=0;k<5;k++)
	{
		for(i=0;i<32;i++)
		printf(" ");
		printf("%c",ch);
		ch++;
		printf("  ");
		for(i=0;i<5;i++)
		{	
				printf("|");
				printf(" ");
				printf(" ");
				if(a[k][i]==1)
					printf("X");
				else
					printf("%d",i+1);
				printf(" ");
				printf(" ");
				printf("|");
				printf("   ");
		}
		printf("\n");
		for(i=0;i<36;i++)
		printf(" ");
		for(j=0;j<5;j++)
		{
				for(i=0;i<5;i++)
				{
				
					printf("_");
				}
			printf("     ");
		}
		printf("\n");
		printf("\n");
	}
}
void insertseat(char ch[2],int flag)
{
	seat *ptr,*preptr;
	FILE *fp;
	int i,j,k,a[5][5];
	seat *s1=(seat *)malloc(sizeof(seat));
	s1->confirm=1;s1->next=NULL;
	strcpy(s1->code,ch);
	printf("%s\n ",s1->code);
	ptr=header,preptr=header;
	if(header==NULL || strcmp(header->code,s1->code)>0)
	{
		s1->next=header;
		header=s1;
		printf("Successfull\n");
		print();
	}
	
	else 
	{
		while(ptr->next!=NULL && strcmp(ptr->code,s1->code)<0 || strcmp(ptr->code,s1->code)==0 )
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		printf("a=%d %s %s\n",strcmp(ptr->code,s1->code),ptr->code,s1->code);
		if(strcmp(preptr->code,s1->code)==0)
		{
			printf("Seat already occupied\n");
			exit(0);
		}
		else if(strcmp(ptr->code,s1->code)<0)
		{
			s1->next=ptr->next;
			ptr->next=s1;
			printf("Succesful2\n");
			print();	
		}
		else{
			s1->next=ptr;
			preptr->next=s1;
			print();
		}
			
	}
}


void print()
{
	seat *ptr=header;
	while(ptr!=NULL)
	{
		printf("%s\t",ptr->code);
		ptr=ptr->next;
	}
	printf("\n");
}
	


	
			
		


