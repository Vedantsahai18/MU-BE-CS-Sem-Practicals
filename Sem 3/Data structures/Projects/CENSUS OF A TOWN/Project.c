/*CODE AND OUTPUT*/
#include <stdio.h>
#include<stdlib.h>
struct node
{
  char name[50];
  char dob[10];
  char gender[5]; 
  float salary;
  int ID; 
  char disable[5];
  int mark;
  struct node *next;
  struct node *prev;  
};
struct node *start = NULL;
struct node *add (struct node *start);
void display(struct node *start);
struct node *del(struct node *start);
void display_fm(struct node *start);
void display_id(struct node *start); 
void total(struct node *start);
void dis_el(struct node *start);
void list_sal(struct node *start);
void display_list(struct node *start);
int count1=100;                                  //female
int count2=200;                                  //male
void main ()
{
    int opt;
    
    printf("================MENU==============\n");
    printf("1)Add details of a person to the list\n");              
    printf("2)Display the list of all people\n");                    
    printf("3)Delete details of a person from the list\n");         
    printf("4)Display a list of male and female\n");                
    printf("5)To find details of a person with their id no\n");     
    printf("6)To find the total no of people present in a town\n");
    printf("7)To verify if a person is eligible \n");   
    printf("8)To find the list of people above a paticular salary amount\n");
    printf("9)To display the list of disabled people\n");
    printf("========================================\n");no
    scanf("%d",&opt);

    do
    {
       switch(opt)
       {
        case 1:
        printf ("=============ENROLLMENT FORM==============\n");
        printf("          (NOTE:ENTER VALID DETAILS)          \n");
        start = add (start);
        printf("***********************************************\n");
        break;
        case 2:
        display(start);
        break;
        case 3:
        start=del(start);
        break;
        case 4:
        display_fm(start);
        break;
        case 5:
        display_id(start);
        break;
        case 6:
        total(start);
        break;
        case 7:
        dis_el(start);
        break;
        case 8:
        list_sal(start);
        break;
        case 9:
        display_list(start);
        break;
       }
        printf("Enter no of the operation:");
        scanf("%d",&opt);

    }while(opt!=0);
}


struct node *add(struct node *start)
{
    struct node *new_node,*ptr,*temp;
    int gen,dis;
    float sa;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("NAME:");
    scanf( " %s",new_node->name);
    printf("DATE OF BIRTH:");
    scanf(" %s",new_node->dob);
    printf("(Enter M:Male F:Female)\n");
    printf("GENDER:");
    scanf(" %s",new_node->gender);
    
    
    if(new_node->gender[0]=='F'||new_node->gender[0]=='f')         
    {
        count1++;
        new_node->ID=count1;
    }
    else
    {
        count2++;
        new_node->ID=count2;
    }
    printf("MONTHLY INCOME:");
    scanf("%f",&sa);
    new_node->salary=sa;
    
    printf("DISABLE:");
    scanf("%s",new_node->disable);
    if(new_node->disable[0]=='y'|| new_node->disable[0]=='Y')
    {
        new_node->mark=1;
    }
    else
    {
        new_node->mark=0;
    }
    
    if(start==NULL)
    {
        new_node->prev=NULL;
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node->next=NULL;
    }
    
    return start;
}


void display(struct node *start)
{
   
    struct node *ptr;
    
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        
        printf("===============LIST OF PEOPLE=================\n");
        ptr=start;
        
        while(ptr!=NULL)
        {  
            printf("ID:%d\t",ptr->ID);
            printf("NAME:%s\t",ptr->name);
            printf("DATE OF BIRTH:%s\t",ptr->dob);
            printf("GENDER:%s\t",ptr->gender);
            printf("MONTHLY INCOME:%f\t",ptr->salary);
           // printf("DISABLE:%s\t",ptr->dis);
            printf("\n");
            ptr=ptr->next;
        }
      
        printf("\n");
        
    }
}

struct node *del(struct node *start)
{
    /*
        when only one person is present *
        when list is empty *
        when you have to delete the first person *
        when you have to delete the last person  *
        when delete it the middle  *
        id not found *
    */
    
    int id;
    struct node *ptr,*temp1,*temp2;
    
    
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    
    else
    {
        printf("Enter the id no that you want to delete from the list:");
        scanf("%d",&id);
        if(start->next==NULL &&start->ID==id)
        {
            ptr=start;
            free(ptr);
            start=NULL;
            
        }
        else if(start->ID==id)
        {
            ptr=start;
            start=start->next;
            free(ptr);
            
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL && ptr->ID!=id)
            {
                ptr=ptr->next;
            }
            if(ptr->next==NULL && ptr->ID==id)
            {
                temp1=ptr->prev;   
                temp1->next=NULL;
                free(ptr);
            }
            else if(ptr->next==NULL && ptr->ID!=id)
            {
                printf("INVALID ID\n");
            }
            else
            {
                temp1=ptr->prev;
                temp1->next=ptr->next;
                temp2=ptr->next;
                temp2->prev=temp1;
            }
        }    
        
    }
    return start;
}


void display_fm(struct node *start)
{
    int in;
    struct node *ptr;
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        printf("Enter any one option:\n1:List of female\n2:List of male\n");
        scanf("%d",&in);
        ptr=start;
        
        if(in==2)
        {
            printf("==============LIST OF MEN=============\n");
            while(ptr!=NULL)
        {
            
            if(ptr->gender[0]=='M'||ptr->gender[0]=='m')
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s  \t",ptr->name);
                printf("DATE OF BIRTH:%s\t",ptr->dob);
                printf("\n\n");
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
          
        printf("***********************************************\n");
        }
    
        if(in==1)
        {
            printf("==============LIST OF WOMEN=============\n");
            while(ptr!=NULL)
        {
            
            if(ptr->gender[0]=='F'||ptr->gender[0]=='f')
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s  \t",ptr->name);
                printf("DATE OF BIRTH:%s\t",ptr->dob);
                printf("\n\n");
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        printf("***********************************************\n");

        }
    }
}

void display_id(struct node *start)
{
    
   /* if no entries are filled in
    if entires are present but id is wrong 
    if id is found display the details */
    
    int id;
    struct node *ptr;
    printf("Enter ID no:");
    scanf("%d",&id);
    
    
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        ptr=start;   
        while(ptr->next!=NULL && ptr->ID!=id)
        {
            ptr=ptr->next;
        }
        if(ptr->ID ==id &&ptr->next==NULL)                //if it is the last node
        {
            printf("              PERSONAL  INFORMATION            \n ");
            
            printf("NAME:%s\n",ptr->name);
            printf("DATE OF BIRTH:%s\n",ptr->dob);
            printf("GENDER:%s\n",ptr->gender);
            printf("MONTHLY INCOME:%f\n",ptr->salary);
            
        }
        else if (ptr->ID !=id &&ptr->next==NULL)
        {
            printf("INVALID ID\n");
        }
        else
        {
            printf("              PERSONAL  INFORMATION            \n ");
            
            printf("NAME:%s\n",ptr->name);
            printf("DATE OF BIRTH:%s\n",ptr->dob);
            printf("GENDER:%s\n",ptr->gender);
            printf("MONTHLY INCOME:%f\n",ptr->salary);
            
        }
        
    }
    
}


void total(struct node *start)
{
    struct node *ptr;
    int count=0;
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            count ++;
            ptr=ptr->next;
        }
    }
    printf("Total no of people present :%d\n",count);
}

/*void dis_el(struct node *start)
{
    int id;
    struct node *ptr;
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        ptr=start;
        printf("Enter the code no:");
        scanf("%d",&id);
        while(ptr->next!=NULL && ptr->ID!=id)
        {
            ptr=ptr->next;
        }
        if(ptr->next==NULL && ptr->ID==id)
        {
            if(ptr->mark==0)
            {
                printf("Person is eligibile\n");
            }
            else
            {
                printf("Person is not eligible\n");
            }
        }
        else if(ptr->next==NULL && ptr->ID!=id)
        {
            printf("Inavlid id\n");
        }
        else
        {
            if(ptr->mark==0)
            {
                printf("Person is eligibile\n");
            }
            else
            {
                printf("Person is not eligible\n");
            }
        }
    }
}
*/
void display_list(struct node *start)
{
    if(start==NULL)
    {
        printf("No entries present\n");
    }
    else
    {
        printf("**************LIST OF DISABLED PEOPLE*******************\n ");
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->mark==1)
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s\t",ptr->name);
                printf("DATE OF BIRTH:%s\t",ptr->dob);
                printf("GENDER:%s\t",ptr->gender);
                printf("MONTHLY INCOME:%f\t",ptr->salary);
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
    }
}

void list_sal(struct node *start)
{
    int amt;
    struct node *ptr;
    if(start==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter the amount :");            //amt above which list of people need to be displayed
        scanf("%d",&amt);
        ptr=start;
        
            while(ptr!=NULL)
            {
            
                if(ptr->salary>amt)
            {
                printf("ID:%d\t",ptr->ID);
                printf("NAME:%s  \t",ptr->name);
                printf("MONTHLY SALARY:%f\t",ptr->salary);
                printf("\n\n");
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
    }
}

/*
OUTPUT
================MENU==============                                                                                                     
1)Add details of a person to the list                                                                                                  
2)Display the list of all people                                                                                                       
3)Delete details of a person from the list                                                                                             
4)Display a list of male and female                                                                                                    
5)To find details of a person with their id no                                                                                         
6)To find the total no of people present in a town                                                                                     
7)To verify if a person is eligible                                                                                                    
8)To find the list of people above a paticular salary amount                                                                           
========================================                                                                                               
1                                                                                                                                      
=============ENROLLMENT FORM==============                                                                                             
          (NOTE:ENTER VALID DETAILS)                                                                                                   
NAME:eliza                                                                                                                             
DATE OF BIRTH:09/05/88                                                                                                                 
(Enter M:Male F:Female)                                                                                                                
GENDER:F                                                                                                                               
MONTHLY INCOME:5688                                                                                                                    
DISABLE:No                                                                                                                             
***********************************************                                                                                        
Enter no of the operation:1                                                                                                            
=============ENROLLMENT FORM==============                                                                                             
          (NOTE:ENTER VALID DETAILS)                                                                                                   
NAME:Harru                                                                                                                             
DATE OF BIRTH:07/08/98
(Enter M:Male F:Female)                                                                                                                
GENDER:M                                                                                                                               
MONTHLY INCOME:7899                                                                                                                    
DISABLE:Yes                                                                                                                            
***********************************************                                                                                        
Enter no of the operation:1                                                                                                            
=============ENROLLMENT FORM==============                                                                                             
          (NOTE:ENTER VALID DETAILS)                                                                                                   
NAME:Beatrice                                                                                                                          
DATE OF BIRTH:/31/09/78                                                                                                                
(Enter M:Male F:Female)                                                                                                                
GENDER:F                                                                                                                               
MONTHLY INCOME:4566                                                                                                                    
DISABLE:Yes                                                                                                                            
***********************************************                                                                                        
Enter no of the operation:1                                                                                                            
=============ENROLLMENT FORM==============                                                                                             
          (NOTE:ENTER VALID DETAILS)                                                                                                   
NAME:William                                                                                                                           
DATE OF BIRTH:14/09/78                                                                                                                 
(Enter M:Male F:Female)                                                                                                                
GENDER:M                                                                                                                               
MONTHLY INCOME:5677                                                                                                                    
DISABLE:No                                                                                                                             
***********************************************                                                                                        
Enter no of the operation:2                                                                                                            
===============LIST OF PEOPLE=================       
ID:101  NAME:eliza      DATE OF BIRTH:09/05/88  GENDER:F        MONTHLY INCOME:5688.000000                                             
ID:201  NAME:Harru      DATE OF BIRTH:07/08/98  GENDER:M        MONTHLY INCOME:7899.000000                                             
ID:102  NAME:Beatrice   DATE OF BIRTH:/31/09/78 GENDER:F        MONTHLY INCOME:4566.000000                                             
ID:202  NAME:William    DATE OF BIRTH:14/09/78  GENDER:M        MONTHLY INCOME:5677.000000                                             
                                                                                                                                       
Enter no of the operation:3                                                                                                            
Enter the id no that you want to delete from the list:105                                                                              
INVALID ID                                                                                                                             
Enter no of the operation:3                                                                                                            
Enter the id no that you want to delete from the list:101                                                                              
Enter no of the operation:2                                                                                                            
===============LIST OF PEOPLE=================                                                                                         
ID:201  NAME:Harru      DATE OF BIRTH:07/08/98  GENDER:M        MONTHLY INCOME:7899.000000                                             
ID:102  NAME:Beatrice   DATE OF BIRTH:/31/09/78 GENDER:F        MONTHLY INCOME:4566.000000                                             
ID:202  NAME:William    DATE OF BIRTH:14/09/78  GENDER:M        MONTHLY INCOME:5677.000000                                             
                                                                                                                                       
Enter no of the operation:4                                                                                                            
Enter any one option:                                                                                                                  
1:List of female                                                                                                                       
2:List of male                                                                                                                         
1                                                                                                                                      
==============LIST OF WOMEN=============                                                                                               
ID:102  NAME:Beatrice   DATE OF BIRTH:/31/09/78                                                                                        
                                                                                                                                       
***********************************************                                                                                        
Enter no of the operation:5                                                                                                            
Enter ID no:106                                                                                                                        
INVALID ID                                                                                                                             
Enter no of the operation:5                                                                                                            
Enter ID no:201                                                                                                                        
              PERSONAL  INFORMATION                                                                                                    
 NAME:Harru                                                                                                                            
DATE OF BIRTH:07/08/98                                                                                                                 
GENDER:M                                                                                                                               
MONTHLY INCOME:7899.000000                                                                                                             
Enter no of the operation:6                                                                                                            
Total no of people present :3                                                                                                          
Enter no of the operation:7                                                                                                            
Enter the code no:201                                                                                                                  
Person is not eligible                                                                                                                 
Enter no of the operation:7                                                                                                            
Enter the code no:202                                                                                                                  
Person is eligibile                                                                                                                    
Enter no of the operation:8                                                                                                            
Enter the amount :5000                                                                                                                 
ID:201  NAME:Harru      MONTHLY SALARY:7899.000000                                                                                     
                                                                                                                                       
ID:202  NAME:William    MONTHLY SALARY:5677.000000                                                                                     
                                                                                                                                       
Enter no of the operation:0         
*/   
