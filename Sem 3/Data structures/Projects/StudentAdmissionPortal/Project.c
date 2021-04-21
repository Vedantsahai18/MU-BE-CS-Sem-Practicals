#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 60
//Project to carry out admission of students in college
struct student
{
    char name[MAX];
    int marks;
    struct student *next;
    int pri;//0 for general, 1 for reserved
};
struct student *start=NULL;//master linkedlist
struct student *start2=NULL;//sorted master linked list by marks
struct student *start3=NULL;//list contaning sorted reserved students only
struct student *start4=NULL;//list contaning sorted general students only
struct student *startf=NULL;//final list of students to get admission
void add_student()
{
    struct student *newstudent,*ptr;
    char n[MAX];int b,temp;b=0;
    ptr=start;
    newstudent=(struct student *)malloc(sizeof(struct student));
    printf("Enter first name and marks for student. Enter 0 if general, 1 if reserved after \n");
    scanf("%s",n);
    scanf("%d",&b);
    scanf("%d",&newstudent->pri);
    if(b<0 || b>100)
    {
    	printf("invalid marks, please enter again between 0 and 100 \n");
    	scanf("%d",&temp);
    	b=temp;
    }
    strcpy(newstudent->name,n);//copying string from variable to node
    newstudent->marks=b;
    if (start==NULL)
    {
        newstudent->next=NULL;
        start=newstudent;
        return;
    }
    else
    {
        while(ptr->next!=NULL)
        {
        ptr=ptr->next;
        }
        newstudent->next=NULL;
        ptr->next=newstudent;
        return;
    }
}
void display(struct student *n)
{
    struct student *ptr;
    ptr=n;
    while(ptr!=NULL)
    {
                printf("%d \t %s \t %d",ptr->pri,ptr->name,ptr->marks);
                printf("\n");
                ptr=ptr->next;
    }
        return;

}
void sort(struct student *n)
{
    //printf("in sort\n");
    struct student *ptr1,*preptr,*ptr,*temp; int f=0;
    ptr1=start;
    while(ptr1!=NULL)
    {
        //printf("in while\n");
        temp=(struct student *)malloc(sizeof(struct student));
        strcpy(temp->name,ptr1->name);
        temp->marks=ptr1->marks;
        temp->pri=ptr1->pri;
        temp->next=NULL;
        if(start2==NULL)
        {
            //printf("in if\n");
            start2=temp;
        }
        else if(start2->marks < temp->marks)
        {
        	temp->next=start2;
        	start2=temp;
        }
        else
        {
            ptr=start2;
            while(ptr->next!=NULL && temp->marks<=ptr->next->marks)
            {	
                ptr=ptr->next;
            }
            temp->next=ptr->next;
            ptr->next=temp;
        }
        ptr1=ptr1->next;
    }
    //printf("end of sort\n");
}
void reservedfilter()
{
	struct student *ptr,*ptr1,*temp;
	ptr1=start2;
	ptr=start3;
	while(ptr1!=NULL)
	{
		if(ptr1->pri==1)
		{
		temp=(struct student *)malloc(sizeof(struct student));
       		strcpy(temp->name,ptr1->name);
        	temp->marks=ptr1->marks;
        	temp->pri=ptr1->pri;
        	temp->next=NULL;
		if(start3==NULL)
			ptr=start3=temp;
		else
		{
			ptr->next=temp;
			ptr=ptr->next;
		}
		}
		ptr1=ptr1->next;
	}
}
void genlist()
{
	struct student *ptr,*ptr1,*temp;
	ptr1=start2;
	ptr=start4;
	while(ptr1!=NULL)
	{
		if(ptr1->pri==0)
		{
		temp=(struct student *)malloc(sizeof(struct student));
       		strcpy(temp->name,ptr1->name);
        	temp->marks=ptr1->marks;
        	temp->pri=ptr1->pri;
        	temp->next=NULL;
		if(start4==NULL)
			ptr=start4=temp;
		else
		{
			ptr->next=temp;
			ptr=ptr->next;
		}
		}
		ptr1=ptr1->next;
	}
}
void finallist()
{
	//printf("in finallist func\n");
	int i,j;
	struct student *ptr,*ptr1,*ptr2,*temp;
	i=j=0;
	ptr1=start3;
	ptr2=start4;
	while(ptr1!=NULL && i<=10)
	{	
		//printf("In while 1");
		temp=(struct student *)malloc(sizeof(struct student));
       		strcpy(temp->name,ptr1->name);
        	temp->marks=ptr1->marks;
        	temp->pri=ptr1->pri;
        	temp->next=NULL;
		if(startf==NULL)
			ptr=startf=temp;
		else
		{
			ptr->next=temp;
			ptr=ptr->next;
		}
		i++;
		ptr1=ptr1->next;
		//printf("EoWhile1");
	}
	while(ptr2!=NULL && j<=10)
	{	
		//printf("In while 1");
		temp=(struct student *)malloc(sizeof(struct student));
       		strcpy(temp->name,ptr2->name);
        	temp->marks=ptr2->marks;
        	temp->pri=ptr2->pri;
        	temp->next=NULL;
		if(startf==NULL)
			ptr=startf=temp;
		else
		{
			ptr->next=temp;
			ptr=ptr->next;
		}
		j++;
		ptr2=ptr2->next;
	}
	/*while(ptr2!=NULL && i<=60)
	{
		if(ptr2->pri==0)
		{
		printf("In while 2");
		while(ptr!=NULL)
			ptr=ptr->next;
		temp=(struct student *)malloc(sizeof(struct student));
       		strcpy(temp->name,ptr2->name);
        	temp->marks=ptr2->marks;
        	temp->pri=ptr2->pri;
        	temp->next=NULL;
			ptr->next=temp;
			ptr=ptr->next;
		i++;
		ptr2=ptr2->next;
		}
		else
			ptr2=ptr2->next;
	}*/
}
void search()
{
	char name1[MAX];int flag;
	struct student *ptr;
	ptr=startf;
	flag=0;
	printf("Enter name to be searched in final list\n");
	scanf("%s",name1);
	while(ptr!=NULL)
	{
		if(ptr->name==name1)
		{
			flag=1;
			printf("Record found \n");
			return;
		}
		else
			ptr=ptr->next;
	}
	if(flag==0)
		printf("Sorry! Admission not secured. \n");
}
void makefile()
{
	FILE *fp;struct student *ptr;
	ptr=startf;
	fp=fopen("studentlist.txt","w");
	while(ptr!=NULL)
	{
		fprintf(fp, "%s, \t %d, \t %d \n",ptr->name,ptr->marks,ptr->pri);
		ptr=ptr->next;
	}
	fclose(fp);
}
int main()
{	
    int ch,i;
    printf("***Welcome to admission portal of 'The Crazy Genius School'*** \n");
    printf("Here are your choices: \n");
    do
    {
    printf("1.Enter student data for admission process \n");
    printf("2.Display final admission list \n");
    printf("3.Search if your sweet kid has secured admission? \n");
    printf("4.Make a file of students securing admission \n");
    printf("5.Exit \n");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    	add_student();
    	break;
    	case 2:
    	sort(start);
    	reservedfilter();
    	genlist();
    	finallist();
    	display(startf);
    	break;
    	case 3:
    	search();
    	break;
    	case 4:
    	makefile();
    	return;
    	case 5:
    	return;
    	default:
    	printf("Invalid choice");
    	break;
    }
    
    }while(1);
    
    printf("**Thank you for using our services. Have a nice day!** \n");
}
