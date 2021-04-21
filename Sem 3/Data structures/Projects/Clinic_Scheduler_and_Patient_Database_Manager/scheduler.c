//Header files
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<malloc.h>
#include<time.h>

// SOME Function declarations
struct node *insert(struct node *start,char dummy[100]);
void display(struct node *start);
void insert_pat(struct node *start,char dummy[100]);
int checkdupes(char name[100]);
void returnfunc(void);

struct time_tt
{
    int hr;
    int min;
};

struct node
{
    char name[100];
    int age;
    struct time_tt tt;
    struct node *next;
};

struct patientnode
{
    char name[100];
    int age;
    char prescription[20][100];
    int prescount;
    struct patientnode *next;

}*pat_start=NULL;

 void printrec(struct node *ptr)
 {
        printf("NAME: %s\n",ptr->name);
        printf(" AGE: %d\n",ptr->age);
        printf("TIME: %d : %d\n",ptr->tt.hr,ptr->tt.min);
 }
 void printpatrec(struct patientnode *ptr)
 {
     int i =0;
    printf("NAME:         %s\n",ptr->name);
    printf("AGE:          %d\n",ptr->age);
    while(i<ptr->prescount)
     {
        printf("PRESCRIPTION: %s\n",ptr->prescription[i]);
        i++;
    }   
 } 
struct node *insert(struct node *start, char dummy[100])
{
    system("cls");
    int hr,min;
    struct node *ptr,*p;
    ptr=(struct node *)malloc (sizeof(struct node));
    ptr->next=NULL;
    printf("ENTER THE NAME OF  THE PATIENT\n");
    scanf("%s",ptr->name);
    strcpy(dummy,ptr->name);
    printf("ENTER THE AGE OF THE PATIENT\n");
    scanf("%d",&ptr->age);
    printf("ENTER TIME FOR AN APPOINTMENT IN HRS AND MINS [24 HR FORMAT]\n");
    scanf("%d %d",&hr,&min);
    if(hr<0 || hr>24)
    {
        printf("Invalid time\n");
        returnfunc();
        return start;
    }
    if(min<0 || min>60)
    {
        printf("Invalid time\n");
        returnfunc();
        return start;
    }
    ptr->tt.hr=hr;
    ptr->tt.min=min;
    if(start==NULL)
    {
        start=ptr;
    }
    else if(hr<=start->tt.hr)
    {
        if(hr==start->tt.hr)
        {
            if(min==start->tt.min)
            {
                printf("THERE IS ALREADY AN APPOINTMENT AT THIS TIME\n");
                returnfunc();
                return start;
            }
            else if(min<start->tt.min)
            {
                ptr->next=start;
                start=ptr;
            }
            else
            {
                ptr->next=start->next;
                start->next=ptr;
            }
        }
        else
        {
            ptr->next=start;
            start=ptr;
        }
    }
    else
    {
        p=start;
        while(p->next!=NULL && p->next->tt.hr<=hr)
           {
               if(p->next->tt.hr==hr)
               {
                   while(p->next!=NULL && p->next->tt.min<=min)
                   {
                       if(p->next->tt.min==min)
                       {
                           printf("THERE IS ALREADY AN APPOINTMENT AT THIS TIME\n");
                           returnfunc();
                           return start;
                       }
                    p=p->next;
                   }
                 ptr->next=p->next;
                 p->next=ptr;
                 printf("APPOINTMENT ADDED!\n");
                 returnfunc();
                 return start;
               }
               else
                p=p->next;
           }
         ptr->next=p->next;
         p->next=ptr;
    }
    printf("APPOINTMENT ADDED!\n");
    returnfunc();
    return start;
}
void insert_pat(struct node *start,char dummy[100])
{   
    if(start==NULL)
    {
        return;
    }
    struct patientnode *pat_ptr,*traverser;
    struct node *ptr;
    pat_ptr=(struct patientnode *)malloc (sizeof(struct patientnode));
    pat_ptr->next=NULL;
    ptr=start;
    while((ptr!=NULL)&&(strcmp(ptr->name,dummy)!=0))
    {
        ptr=ptr->next;
    }
	if(pat_start==NULL)
	{
		pat_ptr->next=pat_start;
		pat_start=pat_ptr;
        strcpy(pat_ptr->name,ptr->name);
        pat_ptr->age=ptr->age;
        return;
	}
	traverser=pat_start;
	while(traverser->next!=NULL)
	{
		traverser=traverser->next;
	}
    if(checkdupes(ptr->name)==1)
    {
        free(pat_ptr);
        return;
    }
    traverser->next=pat_ptr;
    strcpy(pat_ptr->name,ptr->name);
    pat_ptr->age=ptr->age;
    return;
}
void display(struct node *start)
 {
        system("cls");   
        struct node *ptr;
        ptr=start;
        if(start==NULL)
            {
                printf("NO APPOINTMENT IN THE LIST\n");
                returnfunc();
            }
        else
        {
          printf("\t\tLIST OF APPOINTMENTS\n");
          printf("*********************************************\n");
          while(ptr!=NULL)
          {
              printrec(ptr);
              printf("------------------------------------------\n");
              ptr=ptr->next;
          }
        }
            returnfunc();
            return;
 }
 void display_db()
 {
     system("cls");
     struct patientnode *pat_ptr;
     int i=0;
     pat_ptr=pat_start;
     if(pat_start==NULL)
     {
            printf("NO PATIENTS IN THE LIST\n");
            returnfunc();
     }
    else
    {
        printf("\t\tLIST OF PATIENTS\n");
        printf("*********************************************\n");
        while(pat_ptr!=NULL)
        {
            printpatrec(pat_ptr);
            printf("------------------------------------------\n");
            pat_ptr=pat_ptr->next;
        }
    }
    returnfunc();
    return;
 }
 struct node *take_app(struct node *start)
 {
     system("cls");
     int i=0;
     struct node *ptr;
     struct patientnode *trav;
     if(start==NULL)
     {

         printf("NO APPOINTMENT IN THE LIST\n");
         returnfunc();
         return start;
     }
    else
    {
        trav=pat_start;
        ptr=start;
        while(trav!=NULL && strcmp(ptr->name,trav->name)!=0)
        {
            trav=trav->next;
        }
        printf("CURRENT APPOINTMENT IS\n");
        printrec(ptr);
        while(i<20)
        {
            printf("ENTER THE MEDICINES PRESCRIBED [MAX 20]\n");
            scanf("%s",trav->prescription[i]);
            i++;
            printf("Enter another medicine? [y/n]\n");
            if(_getch()=='n')
                break;
        }
        trav->prescount=i;
        start=start->next;
        free(ptr);
    }
    returnfunc();
    return start;
 }
 struct node *delete_app(struct node *start)
 {
    int choice;
    struct node *ptr,*preptr;
    char name[50];
    system("cls");
     if(start==NULL)
     {

         printf("NO APPOINTMENT IN THE LIST\n");
         returnfunc();
         return start;
     }
    
        printf("ENTER THE NAME OF THE PATIENT\n");
        scanf("%s",name);
        if(strcmp(start->name,name)==0)
        {
            ptr=start;
            free(ptr);
            start=start->next;
            printf("APPOINTMENT CANCELLED!\n");
            returnfunc();
            return start;
        }
        ptr=start;
        while((ptr!=NULL)&&(strcmp(ptr->name,name)!=0))
	    {
		    preptr=ptr;
		    ptr=ptr->next;
	    }
        if(ptr == NULL)
	    {
		    printf("PATIENT NOT FOUND\n");
            returnfunc();
		    return start;
	    }
	    else
	    {
		     strcpy(ptr->name,name);
	         preptr->next=ptr->next;
		     free(ptr);
	    }
    printf("APPOINTMENT CANCELLED!\n");
    returnfunc();
    return start;
 }
 void check_app(struct node *start)
 {
     if(start==NULL)
     {

         printf("NO APPOINTMENT IN THE LIST\n");
         returnfunc();
         return;
     }
    else
    {
        printf("CURRENT APPOINTMENT IS:\n");
      printrec(start);
    }
    returnfunc();
    return;
 }
 int checkdupes(char name[100])
 {
     struct patientnode *ptr;
    if(pat_start==NULL)
    {
        return 0;
    }
    if(strcmp(pat_start->name,name)==0)
    {
        return 1;
    }
     ptr=pat_start;
    while((ptr!=NULL)&&(strcmp(ptr->name,name)!=0))
	{
		ptr=ptr->next;
	}
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
    }
 }
 void checktime(struct node *start)
 {
     system("cls");
     struct node *ptr,*p;
     int hr,min;
     printf("ENTER THE TIME IN HRS AND MIN [24 HR FORMAT]\n");
     scanf("%d %d",&hr,&min);
     if(hr<0 || hr>24)
    {
        printf("Invalid time\n");
        returnfunc();
        return;
    }
    if(min<0 || min>60)
    {
        printf("Invalid time\n");
        returnfunc();
        return;
    }
     if(start==NULL)
    {
        printf("ALL SLOTS AVAILABLE\n");
        returnfunc();
        return;
    }
    else if(hr<=start->tt.hr)
    {
        if(hr==start->tt.hr)
        {
            if(min==start->tt.min)
            {
                printf("THERE IS ALREADY AN APPOINTMENT AT THIS TIME\n");
                returnfunc();
                return;
            }
            else
            {
                printf("SLOT IS AVAILABLE!\n");
                returnfunc();
                return;
            }
        }
        else
        {
             printf("SLOT IS AVAILABLE!\n");
             returnfunc();
             return;
        }
    }
    else
    {
        p=start;
        while(p->next!=NULL && p->next->tt.hr<=hr)
           {
               if(p->next->tt.hr==hr)
               {
                   while(p->next!=NULL && p->next->tt.min<=min)
                   {
                       if(p->next->tt.min==min)
                       {
                           printf("THERE IS ALREADY AN APPOINTMENT AT THIS TIME\n");
                           returnfunc();
                           return;
                       }
                    p=p->next;
                   }
                 printf("SLOT IS AVAILABLE!\n");
                 returnfunc();
                 return;
               }
               else
                p=p->next;
           }
         printf("SLOT IS AVAILABLE!\n");
         returnfunc();
         return;
    }
 }
 void modify()
 {
     system("cls");
     if(pat_start==NULL)
     {
         printf("EMPTY DB!!!\n");
         returnfunc();
         return;
     }
     struct patientnode *ptr;
     char name[100];
     int age,i=0,choice;
     printf("ENTER THE NAME OF THE PATIENT\n");
     scanf("%s",name);
     ptr=pat_start;
    while((ptr!=NULL)&&(strcmp(ptr->name,name)!=0))
	{
		ptr=ptr->next;
	}
	if(ptr == NULL)
	{
		printf("RECORD NOT FOUND\n");
        returnfunc();
        return;
	}
     printf("WHICH PARAMETER DO YOU WISH TO MODIFY?\n");
     printf("1.NAME\n");
     printf("2.AGE\n");
     printf("3.PRESCRIPTION\n");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:
             printf("ENTER THE NEW NAME\n");
            scanf("%s",name);
            strcpy(ptr->name,name);
            returnfunc();
            return;
         case 2:
            printf("ENTER THE NEW AGE\n");
            scanf("%d",&age);
            ptr->age=age;
            returnfunc();
            return;
         case 3:
             while(i<20)
            {
                printf("ENTER THE MEDICINES PRESCRIBED [MAX 20]\n");
                scanf("%s",ptr->prescription[i]);
                i++;
                printf("Enter another medicine? [y/n]\n");
                if(_getch()=='n')
                    break;
            }
            ptr->prescount=i;
            returnfunc();
            return;
     }
 }
 void searchname()
 {
     if(pat_start==NULL)
     {
         printf("EMPTY DATABASE\n");
         returnfunc();
         return;
     }
     struct patientnode *ptr;
     char name[100];
     printf("ENTER THE NAME OF THE PATIENT TO BE SEARCHED\n");
     scanf("%s",name);
     ptr=pat_start;
     while(ptr!=NULL && strcmp(ptr->name,name)!=0)
     {
         ptr=ptr->next;
     }
     if(ptr==NULL)
     {
         printf("RECORD NOT FOUND\n");
         returnfunc();
         return;
     }
        printpatrec(ptr);
        returnfunc();
        return;
 }
   
/* function to swap data of two nodes a and b*/
void swap(struct patientnode *a, struct patientnode *b) 
{ 
    char ntemp[100];
    int atemp;
    int preslen,diff,flag=0;
    int i;
    //swapping age
    atemp = a->age; 
    a->age = b->age; 
    b->age = atemp; 
    //swapping name
    strcpy(ntemp,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,ntemp);
    //swapping prescription
    if(a->prescount>b->prescount)
        {
            preslen=b->prescount;
            diff = a->prescount-preslen;
            b->prescount=a->prescount;
            a->prescount=preslen;
            flag=1;
        }

    else
        {
            preslen=a->prescount;
            diff = b->prescount-preslen;
            a->prescount=b->prescount;
            b->prescount=preslen;
            flag=2;
        }
    
    while(i<preslen)
     {
        strcpy(ntemp,a->prescription[i]);
        strcpy(a->prescription[i],b->prescription[i]);
        strcpy(b->prescription[i],ntemp);
        i++;
    }
    if(diff!=0) 
    {
        if(flag==1)
        {
            while(diff!=0)
            {
                strcpy(b->prescription[i],a->prescription[i]);
                i++;
                diff--;
            }
        }
        if(flag==2)
        {
            while(diff!=0)
            {
                strcpy(a->prescription[i],b->prescription[i]);
                i++;
                diff--;
            }
        }
    }  

} 
 void returnfunc(void)
 {
	{
		printf(" Press ENTER to continue...\n ");
        while(_getch()!=13)
        {}
        return;
	}
}
void bubbleSort() 
{ 
    int swapped, i; 
    struct patientnode *ptr1; 
    struct patientnode *lptr = NULL; 
  
    /* Checking for empty list */
    if (pat_start == NULL)
    {
        printf("EMPTY DB!!\n");
        returnfunc(); 
        return; 
    }
    do
    { 
        swapped = 0; 
        ptr1 = pat_start; 
        while (ptr1->next!= lptr) 
        { 
            if (strcmp(ptr1->name,ptr1->next->name)>0) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

int main()
{
struct node *start=NULL;
struct node *p;
char dummy[100];
int choice;
do
	{
        time_t t;
        time(&t);
        system("cls");
        
        printf("CURRENT DATE AND TIME IS %s\n\n",ctime(&t));
        
		printf("Enter the function you wish to perform\n\n");
        printf("****************************************************\n");
		printf("1:INSERT APPOINTMENT\n");
		printf("2:TAKE APPOINTMENT\n");
        printf("3.CANCEL APPOINTMENT\n");
        printf("4.CHECK CURRENT APPOINTMENT\n");
        printf("5.CHECK TIMESLOT AVAILIBILITY\n");
		printf("6:DISPLAY APPOINTMENTS\n");
        printf("7.DISPLAY PATIENT DATABASE\n");
        printf("8.MODIFY PATIENT RECORD\n");
        printf("9.SEARCH THE DATABASE [by name]\n");
        printf("10.SORT DATABASE BY NAME\n");
		printf("11:EXIT\n");
        printf("****************************************************\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=insert(start,dummy);
                insert_pat(start,dummy);
				break;
			case 2:
				start=take_app(start);
				break;
            case 3:
                start=delete_app(start);
                break;
            case 4:
                check_app(start);
                break;
            case 5:
                checktime(start);
                break;
			case 6:
				display(start);
				break;
            case 7:
                display_db();
                break;
            case 8:
                modify();
                break;
            case 9:
                searchname(start);
                break;
            case 10:
                bubbleSort();
                display_db();
                break;
			case 11:
                system("cls");
                printf("\n\n");
				printf("\tExiting");
                //for aesthetic purposes
                int i;
                for(i=0;i<3;i++)
                {   Sleep(250);
                    printf(". ");
                }
                printf("\n");
				break;
			default:
				printf("Invalid choice!!!\n");
				break;
		}
	}while(choice!=11);
}