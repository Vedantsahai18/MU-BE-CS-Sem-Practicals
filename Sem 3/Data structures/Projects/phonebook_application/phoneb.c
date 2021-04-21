#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct person
{
    char name[35];
    char mobno[15];
    char landline[13];
    char email[100];
    struct person *prev,*next;
};


struct phonebook
{
	struct person *start;
};

 
void addcontact(struct phonebook *pb,char n[],char m[],char l[],char e[],int no)
{
	struct person *newc,*ptr,*temp,*current;
	newc=(struct person *)malloc(sizeof(struct person));
	strcpy(newc->name,n);
	strcpy(newc->mobno,m);
	strcpy(newc->landline,l);
	strcpy(newc->email,e);
	newc->prev=NULL;
	newc->next=NULL;
	
	if(pb->start==NULL)
	{
		pb->start=newc;
		newc->prev=pb->start;
	}
	else
	{	
		temp=pb->start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newc;
		newc->prev=temp;
	}
}


void display(struct phonebook *pb)
{
	struct person *i;
	i=pb->start;
	
	while(i!=NULL)
	{
		printf("\nName: %s\nMobile no.: %s\nLandline no.: %s\nEmail: %s\n",i->name,i->mobno,i->landline,i->email);
		i=i->next;
	}
}


void displaycontact(struct person *p)
{
	printf("\nName: %s\nMobile no.: %s\nLandline no.: %s\nEmail: %s\n",p->name,p->mobno,p->landline,p->email);
}


void searchcontact(struct phonebook *pb,char find[100])
{
	struct person *i,*j;
	int flag=0;
	i=pb->start;
	
	while(i!=NULL)
	{
		if(strcmp(i->name,find)==0)
		{
			printf("Displaying contact!\n");
			displaycontact(i);
			flag=1;
			break;
		}
		else
		{
			i=i->next;
		}
	}
	
	if(flag==0)
	{
		printf("Contact not found!\n");
	}
}


void sortcontact(struct phonebook *pb)
{
	struct person *temp=(struct person*)malloc(sizeof(struct person));
	struct person *ptr1;
	struct person *ptr2;
	ptr1=pb->start;
	
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
	
		while(ptr2!=NULL)
		{
			if(strcmp(ptr1->name,ptr2->name)>0)
			{
				strcpy(temp->name,ptr1->name);
				strcpy(temp->mobno,ptr1->mobno);
				strcpy(temp->landline,ptr1->landline);
				strcpy(temp->email,ptr1->email);
				strcpy(ptr1->name,ptr2->name);
				strcpy(ptr1->mobno,ptr2->mobno);
				strcpy(ptr1->landline,ptr2->landline);
				strcpy(ptr1->email,ptr2->email);
				strcpy(ptr2->name,temp->name);
				strcpy(ptr2->mobno,temp->mobno);
				strcpy(ptr2->landline,temp->landline);
				strcpy(ptr2->email,temp->email);
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}


void editcontact(struct phonebook *pb)
{
	struct person *ptr,*i;
	char find[50];
	char name[50],mobno[15],landline[13],email[50];
	int flag=0;
	printf("\nEnter the contact name to be edited: ");
	scanf("%s",find);
	ptr=pb->start;
	
	while(ptr!=NULL)
	{
		if(strcmp(ptr->name,find)==0)
		{
			flag=1;
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	
	if(flag==0)
	{
		printf("Contact not found!!!\n");
	}
	else
	{
		printf("\nEnter the contact name: ");
		scanf("%s",name);
		strcpy(ptr->name,name);
		printf("\nEnter the mobile no: ");
		scanf("%s",mobno);
		strcpy(ptr->mobno,mobno);
		printf("\nEnter landline no: ");
		scanf("%s",landline);
		strcpy(ptr->landline,landline);
		printf("\nEnter email: ");
		scanf("%s",email);
		strcpy(ptr->email,email);
	}
}


int deletecontact(struct phonebook *pb,char find[50])
{
	int flag=0;
	struct person *temp,*ptr;
	temp=pb->start;
	
	if(temp==NULL)
	{
		printf("Phonebook empty!!\n");
		return;
	}
	
	if(strcmp(temp->name,find)==0)
	{
			pb->start=temp->next;
			temp->next->prev=pb->start;
			free(temp);
			return;
	}
	
	while(temp!=NULL)
	{
	
		if(strcmp(temp->name,find)==0)
		{
			flag=1;
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	
	if(flag==0)
	{
		printf("Contact not found!!\n");
	}
	else
	{
	
		if(temp->next==NULL)
		{
			temp->prev->next=NULL;
			free(temp);
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				free(temp);
			}
		}
}

int main()
{
	struct phonebook pb;
	pb.start=NULL;
	int choice;
	int flag=1;
	char n[50],e[50],find[50];
	char l[13],m[15];
	int no;
	
	while(flag==1)
	{
		printf("\n***************Phonebook******************\n");
		printf("\n1.-----Add a contact-----");
		printf("\n2.-----Search a contact-----");
		printf("\n3.-----Edit a contact-----");
		printf("\n4.-----Delete a contact-----");
		printf("\n5.-----Display contact list-----\n");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1: printf("\nAdd contact");
					printf("\nName: ");
					scanf("%s",n);
					printf("\nMobile no.: ");
					scanf("%s",&m); 	
					printf("\nLandline: ");
					scanf("%s",&l);
					printf("\nEmail id: ");
					scanf("%s",e);
					addcontact(&pb,n,m,l,e,no);
					sortcontact(&pb);
					display(&pb);
					break;

			case 2: printf("\nEnter contact name to be searched: ");
					scanf("%s",find);
					searchcontact(&pb,find);
					break;

			case 3: editcontact(&pb);
					sortcontact(&pb);
					display(&pb);
					break;
					
			case 4: printf("\nEnter contact name to be Deleted: ");
    				scanf("%s",find);
					deletecontact(&pb,find);
            		break;
            
			case 5: printf("\nContact list displayed");
					display(&pb);
					break;		
			case 6: flag=0;
					break;

			default: printf("Invalid entry\n");
					 break;
		}
		printf("Enter 1:Continue 2:Exit\n");
		scanf("%d",&flag);
	}
	return 0;
}
/*

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
1

Add contact
Name: nolita

Mobile no.: +917715816259

Landline: 02226692327

Email id: nolitarego@gmail.com

Name: nolita
Mobile no.: +917715816259
Landline no.: 02226692327
Email: nolitarego@gmail.com
Enter 1:Continue 2:Exit
1

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
1

Add contact
Name: benita

Mobile no.: +919892938847

Landline: 02226698765

Email id: benitarego@yahoo.in

Name: benita
Mobile no.: +919892938847
Landline no.: 02226698765
Email: benitarego@yahoo.in

Name: nolita
Mobile no.: +917715816259
Landline no.: 02226692327
Email: nolitarego@gmail.com
Enter 1:Continue 2:Exit
1

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
1

Add contact
Name: carol

Mobile no.: +97123456789

Landline: 23345576897

Email id: carol123@yahoo.com

Name: benita
Mobile no.: +919892938847
Landline no.: 02226698765
Email: benitarego@yahoo.in

Name: carol
Mobile no.: +97123456789
Landline no.: 23345576897
Email: carol123@yahoo.com

Name: nolita
Mobile no.: +917715816259
Landline no.: 02226692327
Email: nolitarego@gmail.com
Enter 1:Continue 2:Exit
1

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
2

Enter contact name to be searched: carol
Displaying contact!

Name: carol
Mobile no.: +97123456789
Landline no.: 23345576897
Email: carol123@yahoo.com
Enter 1:Continue 2:Exit
1

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
3

Enter the contact name to be edited: benita

Enter the contact name: beni

Enter the mobile no: 9892385170

Enter landline no: 26692327

Enter email: regobenita26@gmail.com

Name: beni
Mobile no.: 9892385170
Landline no.: 26692327
Email: regobenita26@gmail.com

Name: carol
Mobile no.: +97123456789
Landline no.: 23345576897
Email: carol123@yahoo.com

Name: nolita
Mobile no.: +917715816259
Landline no.: 02226692327
Email: nolitarego@gmail.com
Enter 1:Continue 2:Exit
1

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
4

Enter contact name to be Deleted: nolita
Enter 1:Continue 2:Exit
1

***************Phonebook******************

1.-----Add a contact-----
2.-----Search a contact-----
3.-----Edit a contact-----
4.-----Delete a contact-----
5.-----Display contact list-----
5

Contact list displayed
Name: 1
Mobile no.: 2
Landline no.: 2
Email: 2

Name: beni
Mobile no.: 9892385170
Landline no.: 26692327
Email: regobenita26@gmail.com

Name: carol
Mobile no.: +97123456789
Landline no.: 23345576897
Email: carol123@yahoo.com
Enter 1:Continue 2:Exit
2

--------------------------------
Process exited after 509.5 seconds with return value 0
Press any key to continue . . .
*/

