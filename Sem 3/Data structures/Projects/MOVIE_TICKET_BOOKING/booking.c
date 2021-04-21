#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct seat
{
    char name[15];
    int no,row;
    int booked;
    struct seat *next;
};

struct screen
{
    char name[20];
    int price;
    char time[5];
    struct seat *pointer;
};
void init(struct screen *t)
{
    t->pointer=NULL;
}
void theater(struct screen *t)
{
    struct seat *ptr;
    int i;
    char name[20]="";
    int j=1;
    for(i=1;i<=16;i++)
    {   
       
        struct seat *r = (struct seat*)malloc(sizeof(struct seat));
        r->next=NULL;
        r->no=i;
        strcmp(r->name, name);
        r->row=j;
        r->booked=0;
        if(i%4==0)
        {
            j++;
        }
        if(t->pointer==NULL)
        {
            t->pointer = r;
        }
        else
        {
            ptr = t->pointer;
            while(ptr->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = r;
        }
    }
}
void available_seats(struct screen *t,int row)
{
    struct seat *ptr;
    ptr = t->pointer;
    while(ptr->row < row)
    {
        ptr = ptr->next;
    }
    printf("Available seats no are\n");
    while(ptr->row==row)
    {
        if(ptr->booked==0)
        {
            printf("%d\t",ptr->no);
        }
        ptr=ptr->next;
    }
}
int tickets(struct screen *t,int row,char name[])
{
    int seat_no;
    struct seat *ptr;
    ptr = t->pointer;
    while(ptr->row < row )
    {
        ptr=ptr->next;
    }
    while( ptr->row==row && ptr->booked==1)
    {
        ptr=ptr->next;
    }
    if(ptr->row==row)
    {
    strcpy(ptr->name,name);
    seat_no = ptr->no;
    ptr->booked=1;
    return seat_no;
    }   
}

void book(struct screen *t,int code)
{
    int row,j=0,no,i,age,k;
    struct seat *ptr;
    char name[20],phone_no[11],date[10]="16/10/18";
    do
    {
        printf("Enter row no \n");
        scanf("%d",&row);
        if(row>4)
        {
            printf("Sorry only four rows are there\n");
        }
        else
        {
            available_seats(t,row);
        }
        printf("enter 1 to continue to booking or enter any key to enter again row no\n");
        scanf("%d",&j);
    }
    while(j!=1);
    printf("Enter your Name,Age and Moblie no\n");
    scanf("%s",name);
    scanf("%d",&age);
    scanf("%s",phone_no);
    printf("Enter no of seats\n");
    scanf("%d",&no);
    printf("                           TICKET                                     ");
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");	
    printf("SCREEN:\t%d\n",code);
    printf("MOVIE :\t");
    printf("%s",t->name);
    printf("\tTIME: %s",t->time);
    printf("\nNAME :\t");
    printf("%s",name);
    printf("\tAGE :\t%d",age);
    printf("\nMOBLIE NO :\t");
    printf("%s",phone_no);
    printf("%s",date);
    printf("\tPRICE :\t%d",(t->price)*no);
    printf("\nSeat no: ");
    for(i=1;i<=no;i++)
    {
       k = tickets(t,row,name);
       printf("%d\t",k);
    }
    printf("\nTotal Money:\t%d\n",(t->price)*no);
    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void booked(struct screen *t)
{
    int i,j=0;
        printf("No Of seats booked are\n");
        struct seat *ptr;
        ptr = t->pointer;
        for(i=1;i<=4;i++)
        {
            while(ptr->row!=i)
            {
                ptr = ptr->next;
            }
            printf("row %d :\t",i);
            while(ptr->row=i)
            {
                if(ptr->booked==1)
                {
                    printf("%d\t",ptr->no);
                    j++;
                }
            }
        }
    printf("\nMoney Collected in this Movie :\t",(t->price)*j);
    
}
void cancel(struct screen *t)
{
    struct seat *ptr;
    int i,no,x;
    char name[20];
    printf("CANCEL\n");
    ptr=t->pointer;
    printf("Enter your name\n");
    scanf("%s", name);
    while(strcmp(ptr->name, name) != 0)
    {
        ptr=ptr->next;
    }
    while(strcmp(ptr->name, name) == 0)
    {
        ptr->booked=0;
        ptr=ptr->next;
    }
    printf("your tickets has been cancel\n");
}

void main()
{
    int choice,ch,c,i=1,k,j,price,code,q,x, code2;
    struct screen t[5];
    char name[20], dummy[2];
    for(j=0;j<=4;j++)
    {
        init(&t[j]);
    }
    do
    {
        printf("\nEnter >1< For Administrator");
        printf("\nEnter >2< For Customer");
        printf("\nEnter >0< To Close The program\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                     do
                    {
                        printf("\nEnter >1< To Insert Movie");
                        printf("\nEnter >2< To View All Movies");
                        printf("\nEnter >3< To See No Of Seats Booked And Money Collected In Specific Movie");
                        printf("\nEnter >0< To Exit\n");
                        scanf("%d",&c);
                        switch(c)
                        {
                            case 1:
                                    printf("\nEnter Movie's Name,Price of Ticket And Time\n");
                                    scanf("%s",name);
                                    scanf("%d %s",&price, t[i].time);
                                    strcpy(t[i].name,name);
                                    t[i].price=price;
                                    theater(&t[i]);
                                    i++;
                                    break;
                            case 2:
                                    printf("                           MOVIES                                   \n");
                                    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                                    printf("Code\t\t Movie\t\t Time\n");
                                    for(k=1;k<=i;k++)
                                    {
                                        if(t[k].pointer!=NULL)
                                        {
                                            printf("%d\t\t %s\t %s\n",k,t[k].name,t[k].time);
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                     printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                                     break;
                            case 3:
                                {
                                    printf("Enter movie's name\n");
                                    scanf("%s",&name);
                                    for(k=1;k<i;k++)
                                    {
                                       q = strcmp(t[k].name,name);
                                        if(q==0)
                                        break;
                                    }
                                    if(t[k].pointer!=NULL)
                                    {
                                        booked(&t[k]);
                                    }
                                    else
                                    {
                                        printf("Movie doesn't exist");
                                    }

                                     break;
                                }
                            case 0:
                                    break;

                            default:
                                    printf("Wrong choice !");
                                    break;
                        }
                    }while(c!=0);
                    break;

            case 2:
                    
                        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
                        printf("\n");	
                        printf("\t Movie Ticket booking ");
                        printf("\n");
                        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            
                    do{ 
                        printf("\nEnter >1< To View All Movies");
                        printf("\nEnter >2< To Book Tickets");
                        printf("\nEnter >3< To Cancel Tickets");
                        printf("\nEnter >0< Back ");
                        printf("\nEnter your Choice :");
                        scanf("%d",&ch);

                        switch (ch)
                        {
                            case 1:
                                    printf("                           MOVIES                                   \n");
                                    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                                    printf("Code\t\t Movie\t\t Time\n");
                                    for(k=1;k<=i;k++)
                                    {
                                        if(t[k].pointer!=NULL)
                                        {
                                            printf("%d\t\t %s\t %s\n",k,t[k].name,t[k].time);
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                     printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
                                     break;
                            case 2:
                                    printf("Enter Movie Code\n");
                                    scanf("%d",&code);
                                    if(t[code].pointer!=NULL)
                                    {
                                        book(&t[code],code);
                                    }
                                    else
                                    {
                                        printf("Movie not avialable\n");
                                    }
                                    break;
                            case 3:
                                    printf("Enter movie code\n");
                                    scanf("%d", &code2);
                                    cancel(&t[code2]);
                                    break;
                            case 0:
                                    break;

                            default:
                                    printf("Wrong choice !");
                                    break;
                        }
                    }while(ch!=0);
                    break;

            case 0:
                    exit(0);
                    break;

            default:
                    printf("Wrong choice !");
                    break;
        }
    }
    while(choice!=0);
}