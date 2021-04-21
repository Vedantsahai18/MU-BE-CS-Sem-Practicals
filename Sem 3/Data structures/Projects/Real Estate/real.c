#include<stdio.h>
#include<stdlib.h>

struct owner
{
	
	int RoomNumber;  //Flat number
	int size;        //in BHK's
	float area;     //sq.ft area of each flat
	float rate;     //price of the flat
	int floor;       //on which floor is the flat
	int status;		//0 for not booked and 1 for booked
	float balance;
	struct owner *next;
	struct owner *prev;
};
struct owner *start=NULL;

void create_owner()      //creating new flats
{
	struct owner *newnode, *ptr;
	int rn,size,floor;
	float area,rate;
	printf("Enter the Flat's Details:\n");
	
	printf("Enter the Room Number:\n");
	scanf("%d",&rn);
	
	printf("Enter the flat size in BHK:\n");
	scanf("%d",&size);

	printf("Enter the Floor:");
	scanf("%d",&floor);
	
	printf("Enter the area per sq.ft:");
	scanf("%f",&area);

	printf("Rate:");
	scanf("%f",&rate);
		
	newnode=(struct owner*)malloc(sizeof(struct owner));
	newnode->RoomNumber = rn;
	newnode->size = size;
	newnode->floor = floor;
	newnode->rate = rate;
	newnode->area = area;
	newnode->status = 0;
	newnode->balance=rate;
	
	if(start==NULL)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		start=newnode;
	}
	else
	{	
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next = newnode;
		newnode->next = NULL;
		newnode->prev = ptr;		
	}
}

void sort_rate()	//sort files accorinding to rate
{
	struct owner *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->rate > ptr2->rate)
			{
				temp=ptr1->rate;
				ptr1->rate = ptr2->rate;
				ptr2->rate=temp;
			} 
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	
}


void display_all()	//display details of all flats
{
	sort_rate();
	struct owner *ptr;
	ptr = start;
	while(ptr!=NULL)
	{	
 	    	printf("Room Number:%d\n", ptr->RoomNumber);
        	printf("Flat area per sq.feet: %f\n",ptr->area);
		printf("Flat Floor: %d\n",ptr->floor);
		printf("Flat size:%dBHK\n", ptr->size);
		printf("Rate:Rs %f\n",ptr->rate);
		if(ptr->status == 1)
		{	printf("Status : Booked\n");
			printf("Amount to be paid:%f\n",ptr->balance);
		}
		else
			printf("Status : Not Booked\n");
		
		ptr=ptr->next;
	}
	
}
void display1(struct owner *ptr)
{		
 	    printf("Room Number:%d\n", ptr->RoomNumber);
		printf("Flat size:%dBHK\n", ptr->size);
		printf("Flat area per sq.feet: %f\n",ptr->area);
		printf("Flat Floor: %d\n",ptr->floor);
		printf("Rate:Rs %f\n",ptr->rate);
		printf("Amount to be paid:%f\n",ptr->balance);
}

void display_available()
{
	struct owner *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->status == 0)
		{
			display1(ptr);
		}
		ptr=ptr->next;
	}
}

void change_status()
{	struct owner *ptr;
	int st,se,flag=0;
	printf("Enter the Room Number you want to change status:\n");
	scanf("%d",&st);
	ptr=start;
	while(ptr!=NULL)
	{	if(ptr->RoomNumber==st)
		{	printf("Is the Flat Book? If yes enter 1 else enter 0");
			scanf("%d",&se);
			ptr->status = se;
			flag=1;
			break;
		}	
		ptr = ptr->next;
	}
	if(flag==0)
		printf("Flat Not Found\n");
	
}

int display_floor(int ft)
{
	struct owner *ptr;
	int flag=0;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->status == 0)
		{
			if(ptr->floor == ft)
			{	flag=1;
				display1(ptr);
			}
		}
		ptr = ptr->next;
	}
	if(flag==0)
	{	printf("No flats found\n");
	}
	return flag;
}

int display_bhk(int ft,int bhk)
{
	struct owner *ptr;
	int flag=0;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->status == 0)
		{
			if(ptr->floor == ft)
			{
				if(ptr->size == bhk)
				{	flag=1;
					display1(ptr);
				}
			}
		}
		ptr = ptr->next;
	}
	if(flag==0)
	{	printf("No flats found\n");
	}
	return flag;	
}

int display_best_flat(int ft,int bhk,float us,float ms)
{
	struct owner *ptr;
	int flag=0;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->status == 0)
		{
			if(ptr->floor == ft)
			{
				if(ptr->size == bhk)
				{
					if((ptr->rate >ms) && (ptr->rate < us))
					{	flag=1;
						display1(ptr);
					}
				}
			}
		}
		ptr = ptr->next;
	}
	if(flag==0)
	{	printf("No flats found\n");
	}
	return flag;
	
}

void change_status_customer(int rns,float m)
{
	struct owner *ptr;
	ptr=start;
	while(ptr->RoomNumber != rns)
	{
		ptr=ptr->next;
	}
	ptr->status = 1;
	ptr->balance=ptr->balance-m;
	printf("Your Flat has been Booked\nDetails of your Flat are:\n");
	display1(ptr);
}
void sort_display_area()
{
	struct owner *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->area > ptr2->area)
			{
				temp=ptr1->area;
				ptr1->area = ptr2->area;
				ptr2->area=temp;
			} 
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
		if(start==NULL)
		printf("Empty");
		else
		{
			display_all();
		}
	
}

void main()
{
	struct owner *ptr;
	int n,i,op;
	char s[50];
	printf("Enter building name:\n");
	scanf("%s",&s);
	printf("Enter the number of Flats:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
					create_owner();
	printf("****FOR OFFICE USE****\n");
	
	do
	{
		printf("\n1: Add Flats to Database\n");
		printf("2: Change the status of a particular flat\n");
        	printf("3: Display all the Flats in the building\n");
		printf("4: EXIT\n");
		printf("Enter your option\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: create_owner();
					break;
			case 2: change_status();
					break;
			case 3: printf("%s\n",s);
					display_all();
                    		break;
            		case 4: break;
			default:printf("WRONG CHOICE");
				break;
		}
	}while(op!=4);

	printf("*******CUSTOMER*******\n");

	do
	{
		int ft,bhk,rns,in,f,b,d;
		float amt,us,ms,m;
		printf("Number of available Flats are as Following:\n");
		display_available();
		printf("\nFLats available according to Area:\n");
		sort_display_area();
		flat:
		printf("Enter the Floor on which you want the Flat:\n");
		scanf("%d",&ft);
		f=display_floor(ft);
		if(f==0)
			goto flat;
		bhk:
		printf("\nEnter the BHK's you want:\n");
		scanf("%d",&bhk);
		b=display_bhk(ft,bhk);
		if(b==0)
			goto bhk;
		money:
		printf("Enter the maximum you can spend:\n");
		scanf("%f",&us);
		printf("Enter the minimum amount:\n");
		scanf("%f",&ms);
		d=display_best_flat(ft,bhk,us,ms);
		if(d==0)
			goto money;
		printf("Enter the Room Number which you want to book:\n");
		scanf("%d",&rns);
		book:
		printf("Enter first installment to confirm booking\n");
		scanf("%f",&m);
		if(m>=ms)
			change_status_customer(rns,m);
		else
		{	printf("Insufficinet money\n");
			goto book;
		}
		printf("Enter 1 to EXIT or anything else to continue:\n ");
		scanf("%d",&in);
		if(in == 1)
			exit(1);
		else 
			continue;
	}while(1);
}