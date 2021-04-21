//flight booking
#include<stdio.h>
#include<stdlib.h>
int count[3]={0,0,0};
typedef struct Node
{
	int bid,noofpass;
	char pname[20]; 
	float fees;
	struct Node *next;
}node;

typedef struct  //creating a linked list
{
	int fno;
	int totalseats;
	node* f;
	node* r;
}ll;

void setfno(ll *l,int ch)
{
	if (ch==1)
	{
		l->fno=101;
		l->totalseats=300;
	}
	else if(ch==2)
	{
		l->fno=102;
		l->totalseats=250;
	}
	else if(ch==3)
	{
		l->fno=103;
		l->totalseats=350;
	}
	else
		printf("wrong option enetered");
}
float getamount(int fno)
{
	if(fno==101)
		return 3000;
	else if(fno==102)
		return 6000;
	else if(fno==103)
		return 4000;
}

float pay(int noofpass,ll *f)
{
	float charges=getamount(f->fno);
	float amount=charges*noofpass;
	return amount;
}

float enqueue(ll* l,int c)       //creating a node
{
	ll *k=l;
	if(c<=l->totalseats)
	{
		
		node *p=(node*)malloc(sizeof(node));
		printf("\nEnter passenger name: ");
		scanf("%s",p->pname);
		printf("\nEnter no. of passengers: ");
		scanf("%d",&p->noofpass);
		p->fees=pay(p->noofpass,k);
		p->bid=c+1001;
		printf("\nPassenger id: %d",p->bid);
		c+=p->noofpass;
		p->next=NULL;
		if(l->r==NULL)	
		{
			l->r=p;
			l->f=p;
		}
		else
		{
			l->r->next=p;
			l->r=p;
		}
		return p->fees;
	}
	else
		printf("\nFlight not available: No seats left");
}

void delete(ll*l,int cid,int c)    //deleting a node
{
	int x;
	node *p,*prev;
	if(l->f!=NULL)
	{
		
		p=l->f; prev=NULL;
		while(p->next!=NULL)
		{	
			if(p->bid==cid)
				break;
			else
			{
				prev=p;
				p=p->next;
			}	
		}
		if(p==l->f)
			l->f=p->next;
		else if(p==l->r)
			l->r=prev;
		else	
			prev->next=p->next;		
		c-=p->noofpass;
		free(p);
		if(l->f==NULL)
		{
			l->r=NULL;
		}
     	}
}

void display(ll l,int id)         //displaying queue
{ 
	node *p; int flag=0;
	if(l.f!=NULL)
	{
		
		p=l.f;
		while(p->next!=NULL)
		{
			if(p->bid==id)
			{
				flag=1;
				break;
			}
			else
				p=p->next;
		}
		if(flag==1)
			printf("\nPassenger name: %s\nNo. of Passengers: %d\tAmount paid: %f",p->pname,p->noofpass,p->fees);
		else
			printf("\nPassenger  not found!");
	}
	else
		printf("Passenger not found");
}

int main()
{
	int n,s,cid,fid,i,flag=0;
	ll l[3]; 
	float amount;
	for(i=0;i<3;i++)
	{
		l[i].f=NULL;
		l[i].r=NULL;
	}
	char ch;
	do
	{
		printf("choose an option\n 1)Make a reservation \n 2)Delete a reservation\n 3)view a reservation\n");  
		//choose an operation
		scanf("%d",&n);
		if (n==1)
		{
			printf("choose flight\n 1)Mumbai to Delhi\n 2)Delhi to Mumbai\n 3)Kolkata to Mumbai");
			scanf("%d",&s);			
			switch(s)
			{
				case 1: setfno(&l[0],s);
					printf("\n\nFLIGHT: from BOM to DLH\nFlight id: %d",l[0].fno);
					amount=enqueue(&l[0],count[0]);
					printf("\nAmount to be payed: %f",amount);
					
					break;
				case 2: setfno(&l[1],s);
					printf("\n\nFLIGHT: from DLH to BOM\nFlight id: %d",l[1].fno);
					amount=enqueue(&l[1],count[1]);
					printf("\nAmount to be payed: %f",amount);
					
					break;
				case 3: setfno(&l[2],s);
					printf("\n\nFLIGHT: from KLT to BOM\nFlight id: %d",l[2].fno);
					amount=enqueue(&l[2],count[2]);
					printf("\nAmount to be payed: %f",amount);
					
					break;
				default: printf("\nNo such flight available");
			}		
			
		}
		else if(n==2||n==3)
		{
			printf("\nEnter flight id:");
			scanf("%d",&fid);
			printf("\nEnter passenger no.");
			scanf("%d",&cid);
			if(n==2)
			{
				for(i=0;i<3;i++)
				{
					if(l[i].fno==fid)
					{	
						delete(&l[i],cid,count[i]);
						flag=1;
					}
				}
				if(flag==1)
					printf("\nReservation cancelled");
				else
					printf("\nCould not find flight or passenger"); 
			}
			else
			{
				for(i=0;i<3;i++)
				{
					if(l[i].fno==fid)
					{
						display(l[i],cid);
						flag=1;
					}
				}
				if(flag==0)
					printf("\nCould not find flight"); 
			}
		}
		else
			printf("Incorrect option entered");
		printf("\nDo you want to continue?(y/n)");
		scanf(" %c",&ch);	
	}while(ch=='y'||ch=='Y');
	return 0;
} 	

