#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct node
{
struct node *next;
int data,data1,data2,data3;
char name[200],crime[200],location[200];
};
struct node *start=NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_bef(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_bef(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *search(struct node *);

void main()
{
int option;
do
{
printf("\t\t\t\tMain Menu\n\n");
printf("--------------------------------------------------------------------------------");
printf("\n 1.Enter 1 to create a list \n 2.Enter 2 to display \n 3.Enter 3 to insert begin \n 4.Enter 4 to insert end \n 5.Enter 5 to insert before \n 6.Enter 6 to insert after \n 7.Enter 7 to delete beg  \n 8.Enter 8 to delete end \n 9.Enter 9 to delete before \n 10.Enter 10 to delete after \n 11.Enter 11 to delete list \n 12.Enter 12 to search\n 13.Enter 13 to stop\n  ");
scanf("%d",&option);
switch(option)
{
case 1:
start=create_cll(start);
break;

case 2:
start=display(start);
break;

case 3:
start=insert_beg(start);
break;

case 4:
start=insert_end(start);
break;

case 5:
start=insert_bef(start);
break;

case 6:
start=insert_after(start);
break;

case 7:
start=delete_beg(start);
break;

case 8:
start=delete_end(start);
break;

case 9:
start=delete_bef(start);
break;

case 10:
start=delete_after(start);
break;


case 11:
start=delete_list(start);
break;
case 12:
    start=search(start);
    break;

}
}
while(option!=13);
}


struct node *create_cll(struct node *start)//Create a circular linked list
{
struct node *ptr,*new_node;
int id_no,killed,injured,year;
char nav[200],cri[200],loc[200];
char a;
printf("Enter -1 to stop\n\n");
printf("Enter the id no if the criminal\n");
scanf("%d",&id_no);
printf("Enter the no of killed people\n");
scanf("%d",&killed);
printf("Enter the no of injured people\n");
scanf("%d",&injured);
printf("Enter the year in which in crime was performed\n");
scanf("%d",&year);
scanf("%c",&a);
printf("Enter the name of the criminal\n");
gets(nav);
printf("Enter the crime performed\n");
gets(cri);
printf("Enter the location\n");
gets(loc);

while(id_no != -1)
{
new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=id_no;
new_node->data1=killed;
new_node->data2=injured;
new_node->data3=year;
strcpy(new_node->name,nav);
strcpy(new_node->crime,cri);
strcpy(new_node->location,loc);
if(start==NULL)
{
new_node->next=new_node;
start=new_node;
}

else
{
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=start;
}
printf("Enter the id no if the criminal\n");
scanf("%d",&id_no);
if(id_no==-1)
    break;
printf("Enter the no of killed people\n");
scanf("%d",&killed);
printf("Enter the no of injured people\n");
scanf("%d",&injured);
printf("Enter the year in which in crime was performed\n");
scanf("%d",&year);
scanf("%c",&a);
printf("Enter the name of the criminal\n");
gets(nav);
printf("Enter the crime performed\n");
gets(cri);
printf("Enter the location\n");
gets(loc);
}
return start;

}

struct node *display(struct node *start)
{
struct node *ptr;

ptr=start;
if(start==NULL)
    printf("List is Empty");
else
    {
printf("****************************CRIMINAL  RECORD*************************************");
while(ptr->next!=start)
{
printf("\nthe id_no is %d\n",ptr->data);
printf("the no of killed people is %d\n",ptr->data1);
printf("the no of injured people is %d\n",ptr->data2);
printf("the year in which the crime was performed is %d\n\n",ptr->data3);
printf("the Name of the criminal %s\n",ptr->name);
printf("the crime performed is %s\n",ptr->crime);
printf("the location is %s\n",ptr->location);
printf("---------------------------------------------------------------------------------------");

 ptr=ptr->next;
}
printf("the id_no is %d\n",ptr->data);
printf("the no of killed people is%d\n",ptr->data1);
printf("the no of injured people is %d\n",ptr->data2);
printf("the year in which the crime was performd is%d\n",ptr->data3);
printf("the Name of the criminal %s\n",ptr->name);
printf("the crime performed is %s\n",ptr->crime);
printf("the location is %s\n",ptr->location);
printf("********************************************************************************");
    }
return (start);
}

struct node *insert_beg(struct node *start)//insert at the beginning of the linked list
{
struct node *ptr,*new_node;
int id_no,killed,injured,year;
char nav[100],cri[200],loc[200];
char a;
printf("enter the id no if the criminal\n");
scanf("%d",&id_no);
printf("Enter the no of killed people\n");
scanf("%d",&killed);
printf("Enter the no of injured people\n");
scanf("%d",&injured);
printf("Enter the year in which in crime was performed\n");
scanf("%d",&year);
scanf("%c",&a);
printf("Enter the name of the criminal \n");
gets(nav);
printf("Enter the crime performed \n");
gets(cri);
printf("Enter the location \n");
gets(loc);
new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=id_no;
new_node->data1=killed;
new_node->data2=injured;
new_node->data3=year;
strcpy(new_node->name,nav);
strcpy(new_node->crime,cri);
strcpy(new_node->location,loc);
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=start;
start=new_node;

return start;
}

struct node *insert_end(struct node *start)
{
struct node *ptr,*new_node;
int id_no,killed,injured,year;
char nav[200],cri[200],loc[200];
char a;
printf("enter the id no if the criminal\n");
scanf("%d",&id_no);
printf("enter the no of killed people\n");
scanf("%d",&killed);
printf("enter the no of injured people\n");
scanf("%d",&injured);
printf("enter the year in which in crime was performed\n");
scanf("%d",&year);
scanf("%c",&a);
printf("Enter the name of the criminal \n");
gets(nav);
printf("Enter the crime performed \n");
gets(cri);
printf("Enter the location \n");
gets(loc);


new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=id_no;
new_node->data1=killed;
new_node->data2=injured;
new_node->data3=year;
strcpy(new_node->name,nav);
strcpy(new_node->crime,cri);
strcpy(new_node->location,loc);
ptr=start;
while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=start;
return start;
}

struct node *insert_bef(struct node *start)
{

struct node *ptr,*pre_ptr,*new_node;
char nav[200],cri[200],loc[200];
char a;
int num;
int id_no,killed,injured,year;
printf("entre the id no before which which you want to insert \n");
scanf("%d",&num);

printf("enter the id no if the criminal\n");
scanf("%d",&id_no);
printf("enter the no of killed people\n");
scanf("%d",&killed);
printf("enter the no of injured people\n");
scanf("%d",&injured);
printf("enter the year in which in crime was performed\n");
scanf("%d",&year);
scanf("%c",&a);
printf("Enter the name of the criminal \n");
gets(nav);
printf("Enter the crime performed \n");
gets(cri);
printf("Enter the location \n");
gets(loc);

new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=id_no;
new_node->data1=killed;
new_node->data2=injured;
new_node->data3=year;
strcpy(new_node->name,nav);
strcpy(new_node->crime,cri);
strcpy(new_node->location,loc);
ptr=start;

while(ptr->data!=num)
{
pre_ptr=ptr;
ptr=ptr->next;
}
pre_ptr->next=new_node;
new_node->next=ptr;

return start;

}
 struct node *insert_after(struct node *start)
{
struct node *new_node,*ptr,*pre_ptr;
char nav[200],cri[200],loc[200];
char a;
 int num;
int id_no,killed,injured,year;
printf("\n\nenter the id no if the criminal\n");
scanf("%d",&id_no);
printf("enter the no of killed people\n");
scanf("%d",&killed);
printf("enter the no of injured people\n");
scanf("%d",&injured);
printf("enter the year in which in crime was performed\n");
scanf("%d",&year);
scanf("%c",&a);
printf("Enter the name of the criminal \n");
gets(nav);
printf("Enter the crime performed \n");
gets(cri);
printf("Enter the location \n");
gets(loc);

printf("Enter the num after which you want to insert the no\n");
scanf("%d",&num);

new_node=(struct node *)malloc(sizeof(struct node));
new_node->data=id_no;
new_node->data1=killed;
new_node->data2=injured;
new_node->data3=year;
strcpy(new_node->name,nav);
strcpy(new_node->crime,cri);
strcpy(new_node->location,loc);
ptr=start;
while(pre_ptr->data!=num)
{

pre_ptr=ptr;
ptr=ptr->next;
}

pre_ptr->next=new_node;
new_node->next=ptr;

return start;

}

struct node *delete_beg(struct node *start)
{
struct node *ptr;

ptr=start;

while(ptr->next!=start)
{
ptr=ptr->next;
}
ptr->next=start->next;
free(start);
start=ptr->next;

return start;

}

struct node *delete_end(struct node *start)
{

struct node *ptr,*pre_ptr;

ptr=start;

while(ptr->next!=start)
{
pre_ptr=ptr;
ptr=ptr->next;

}
pre_ptr->next=ptr->next;
free(ptr);

return start;

}

struct node *delete_bef(struct node *start)
{

struct node *p,*ptr,*pre_ptr;
int val;

printf("enter the id no before which you want to delete\n");
scanf("%d",&val);
ptr=start;
pre_ptr=NULL;
while(ptr->data!=val)
{
p=pre_ptr;
pre_ptr=ptr;
ptr=ptr->next;
}
p->next=pre_ptr->next;
free(pre_ptr);

return(start);

}


struct node *delete_after(struct node *start)
{

struct node *ptr,*pre_ptr;
int val;

printf("enter the id no  after which you want to delete\n");
scanf("%d",&val);
ptr=start;

while(pre_ptr->data!=val)
{
pre_ptr=ptr;
ptr=ptr->next;
}
pre_ptr->next=ptr->next;
free(ptr);

return(start);

}

struct node *delete_list(struct node *start)//To delete an entire list
{
struct node *ptr;
ptr=start;
if(start==NULL)
    printf("No such list to delete");
else
{
while(ptr->next!=start)

start=delete_end(start);
free(start);
}
start=NULL;

return (start);

}
struct node *search(struct node *start)//To search for a particular record by ID no or crime name or year in which it was performed
{
   struct node *ptr ,*preptr;
   int value;

   printf("enter 1 if you want to search by id_no \n\nEnter 2 if you wish to search by year\n\nEnter 3 if you want to search by name\n");
   scanf("%d",&value);

   if(value==1)
  {
      int a;
      printf("Enter the id_no by which you want to search\n");
      scanf("%d",&a);
      ptr=start;
   while(ptr->data!=a)
   ptr=ptr->next;
 
   }
   else if(value==2)
       {
       int b;
      printf("Enter the year by which you want to search\n");
      scanf("%d",&b);
      printf("------------------------------------------------------------------------------");
      ptr=start;
   while(preptr->next!=start)
   {
       
       if(b==ptr->data3)
       	{
       	  printf("\nThe id_no is %d\n",ptr->data);
			printf("The no of killed people is%d\n",ptr->data1);
			printf("The no of injured people is %d\n",ptr->data2);
			printf("The year in which the crime was performd is%d\n",ptr->data3);
			printf("The criminal name is %s\n",ptr->name);
			printf("The crime performed\n%s",ptr->crime);
			printf("The location is\n%s",ptr->location);
			printf("\n_________________________________________________________________________________");
			preptr=ptr;
			ptr=ptr->next;

   }
   }
	exit(0);       }
   else
    if(value==3)
   {
       char n[100];
       printf("Enter the name of the crime \n");
       scanf("%s",&n);
       ptr=start;
   while(preptr->next!=start)
   
  {
  
       
       printf("%d",strcmp(ptr->crime,n));
       if(strcmp(ptr->crime,n)==0)
       {
       	 printf("\nThe id_no is %d\n",ptr->data);
			printf("The no of killed people is%d\n",ptr->data1);
			printf("The no of injured people is %d\n",ptr->data2);
			printf("The year in which the crime was performd is%d\n",ptr->data3);
			printf("The criminal name is %s\n",ptr->name);
			printf("The crime performed\n%s",ptr->crime);
			printf("The location is\n%s",ptr->location);
			printf("\n_________________________________________________________________________________");
			preptr=ptr;
			ptr=ptr->next;
}
       
   }
exit(0);

   }
   
   printf("\nThe id_no is %d\n",ptr->data);
printf("The no of killed people is%d\n",ptr->data1);
printf("The no of injured people is %d\n",ptr->data2);
printf("The year in which the crime was performd is%d\n",ptr->data3);
printf("The criminal name is %s\n",ptr->name);
printf("The crime performed\n%s",ptr->crime);
printf("The location is\n%s",ptr->location);
printf("\n_________________________________________________________________________________");

  
return start;

}
/*OUTPUT
                                Main Menu

--------------------------------------------------------------------------------

 1.Enter 1 to create a list
 2.Enter 2 to display
 3.Enter 3 to insert begin
 4.Enter 4 to insert end
 5.Enter 5 to insert before
 6.Enter 6 to insert after
 7.Enter 7 to delete beg
 8.Enter 8 to delete end
 9.Enter 9 to delete before
 10.Enter 10 to delete after
 11.Enter 11 to delete list
 12.Enter 12 to search
 13.Enter 13 to stop
  1
Enter -1 to stop

Enter the id no if the criminal
3
Enter the no of killed people
2
Enter the no of injured people
4
Enter the year in which in crime was performed
2008
Enter the name of the criminal
Akshay
Enter the crime performed
Murder
Enter the location
Bandra
Enter the id no if the criminal
4
Enter the no of killed people
3
Enter the no of injured people
5
Enter the year in which in crime was performed
2008
Enter the name of the criminal
Manas
Enter the crime performed
Robbery
Enter the location
Santacruz
Enter the id no if the criminal
-1
                                Main Menu

--------------------------------------------------------------------------------

 1.Enter 1 to create a list
 2.Enter 2 to display
 3.Enter 3 to insert begin
 4.Enter 4 to insert end
 5.Enter 5 to insert before
 6.Enter 6 to insert after
 7.Enter 7 to delete beg
 8.Enter 8 to delete end
 9.Enter 9 to delete before
 10.Enter 10 to delete after
 11.Enter 11 to delete list
 12.Enter 12 to search
 13.Enter 13 to stop
  4
enter the id no if the criminal
6
enter the no of killed people
45
enter the no of injured people
120
enter the year in which in crime was performed
2012
Enter the name of the criminal
Azad
Enter the crime performed
Terrorist Attack
Enter the location
Vashi
                                Main Menu

--------------------------------------------------------------------------------

 1.Enter 1 to create a list
 2.Enter 2 to display
 3.Enter 3 to insert begin
 4.Enter 4 to insert end
 5.Enter 5 to insert before
 6.Enter 6 to insert after
 7.Enter 7 to delete beg
 8.Enter 8 to delete end
 9.Enter 9 to delete before
 10.Enter 10 to delete after
 11.Enter 11 to delete list
 12.Enter 12 to search
 13.Enter 13 to stop
  12
enter 1 if you want to search by id_no

Enter 2 if you wish to search by year

Enter 3 if you want to search by name
2
Enter the year by which you want to search
2008
------------------------------------------------------------------------------
The id_no is 3
The no of killed people is2
The no of injured people is 4
The year in which the crime was performd is2008
The criminal name is Akshay
The crime performed
MurderThe location is
Bandra
________________________________________________________________________________
_
The id_no is 4
The no of killed people is3
The no of injured people is 5
The year in which the crime was performd is2008
The criminal name is Manas
The crime performed
RobberyThe location is
Santacruz
________________________________________________________________________________
_
