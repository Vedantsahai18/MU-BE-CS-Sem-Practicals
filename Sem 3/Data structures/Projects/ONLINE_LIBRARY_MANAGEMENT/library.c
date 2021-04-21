//free online library
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define SIZE 100

long int lib_code=83678361;

struct book 
{
    struct book *next;
    int book_code,copies;
    char name_of_book[SIZE];
    char name_of_author[SIZE];
    char genre[20];
};
struct user_data 
{
    struct user_data *next;
    char username[SIZE],password[SIZE],first_name[SIZE],last_name[SIZE],gender;
    long int phone_number;
    int age;
    struct book *books;
};
struct Customer 
{
    struct user_data *start; 
};

struct Library {
    struct book *start;
};

void registration(struct Customer *users)
{
    struct user_data *new=(struct user_data *)malloc(sizeof(struct user_data));

    printf("\n\t**REGISTRATION FORM\n");
    printf("\nEnter your details here:-\n");

    printf("\nFirst Name:");
    scanf("%s",new->first_name);
    printf("Last Name:");
    scanf("%s",new->last_name);
    printf("Age:");
    scanf("%d",&new->age);
    printf("Gender(M or F):");
    scanf(" %c",&new->gender);
    printf("Phone number:");
    scanf("%ld",&new->phone_number);
    printf("Enter your username:");
    scanf("%s",new->username);
    printf("Enter your password:");
    scanf("%s",new->password);
    new->books=NULL;
    new->next=NULL;
    if(users->start==NULL)
    {
        users->start=new;
        printf("\n\n\t\tCongratulations!!\n\tYou are our first customer!!");
        Sleep(2);
    }
    else
    {
        struct user_data *p,*prev;
        p=users->start;
        while(p!=NULL)
        {
            prev=p;
            p=p->next;
        }
        prev->next=new;
    }
    printf("\n\tLogin to continue...\n\n");
}

struct user_data *login(struct Customer users)
{
    char username_check[SIZE], password_check[SIZE];

    printf("\nEnter your username:");
    scanf("%s",username_check);
    
    if(users.start!=NULL)
    {
        struct user_data *p;
        p=users.start;
        while(p!=NULL)
        {
            if((strcmp(p->username,username_check)==0))
                break;
            else
            {
                p=p->next;
            }
        }
        if(p==NULL)
        {
                printf("\n\t**User not found!!**\n\t  TRY AGAIN!!\n");
                sleep(1);
                return p;
        }
        else
        {
            printf("Password:");
            scanf("%s",password_check);

            if(strcmp(p->password,password_check)==0)
                {
                    if((p->gender=='M')||(p->gender=='m'))
                        printf("\n\tWelcome Mr. %s %s\n",p->first_name, p->last_name);
                    else
                        printf("\n\tWelcome Miss. %s %s\n",p->first_name, p->last_name);
                }
            else
                {
                    printf("\n\t**Wrong password!!**\n\t  TRY AGAIN!!\n");
                    sleep(1);
                    return NULL;
                }    

            return p;
        }
    }
}
    
void display_user_details(struct user_data p)
{
    printf("\n\t**User Details**\n");
    printf("\nUsername:%s",p.username);
    printf("\nName:%s %s",p.first_name, p.last_name);
    printf("\nGender:");
    if((p.gender=='M')||(p.gender=='m'))
        printf("Male\n");
    else
        printf("Female");

    printf("Age:%d",p.age);
    printf("\nPhone number:%ld",p.phone_number);
    printf("\nYour books:-\n");
    //display_user_books(p.books);
    
}

void change_password(struct user_data *p)
{
    char password_check[SIZE],new_password[SIZE];
    retry:
    printf("\nEnter your current password:");
    scanf("%s",password_check);
    if((strcmp(p->password,password_check)==0))
    {
        printf("\nEnter you New Password:");
        scanf("%s",new_password);
    }
    else
    {
        printf("\n\t**Wrong password!!**\n\t  TRY AGAIN!!\n");
        printf("\n\nPress any key to continue...\n");
        getch();
        goto retry;        
    }
    strcpy(p->password,new_password);
    printf("\n\t**Password Changed successfully**\n\t  Login to continue..\n");
}

void delete_account(struct Customer *users, int user_phone_number)
{
    struct user_data *p,*prev;
	p=users->start;
	prev=NULL;
	while(p->phone_number!=user_phone_number)
	{
		prev=p;
		p=p->next;
	}

	if(prev==NULL)			
	{
		users->start=p->next;
		free(p);
	}
	
	else
	{	
		prev->next=p->next;
		free(p);
	}
    printf("\n\t**Account Deleted**");
}

void add_userbook(struct Library *library, struct user_data *p)
{
    int add_bookcode;
    printf("\nEnter the book code of the book you want:");
    scanf("%d",&add_bookcode);
    struct book *ptr,*user_booklist;
    ptr=library->start;
    user_booklist=p->books;
    while(ptr!=NULL)
    {
        if(ptr->book_code==add_bookcode)
            break;
        else
        ptr=ptr->next;
    }
    if(ptr==NULL)
        printf("\n\t**NO SUCH BOOK!!**\nTRY AGAIN");
    else
    {
        struct book *new=(struct book *)malloc(sizeof(struct book));
        new->next=NULL;
        new->book_code=ptr->book_code;
        strcpy(new->genre,ptr->genre);
        strcpy(new->name_of_book,ptr->name_of_book);
        strcpy(new->name_of_author,ptr->name_of_author);
        new->copies=1;
        ptr->copies--;

        if(p->books==NULL)
        {
            p->books=new;
            printf("\n\t**BOOK ADDED**\n");
        }    
        else
        {
            while(user_booklist!=NULL)
            {
                user_booklist=user_booklist->next;
            }
            user_booklist=new;
            printf("\n\t**BOOK ADDED**\n");
        }
    }
}

void add_book(struct Library *library)
{
    struct book *new=(struct book *)malloc(sizeof(struct book));
    new->next=NULL;
    printf("\nEnter book code:");
    scanf("%d",&new->book_code);
    printf("Enter the genre of the book:");
    scanf("%s",new->genre);
    printf("Enter the book's name:");
    scanf("%s",new->name_of_book);
    printf("Enter the author's name:");
    scanf("%s",new->name_of_author);
    printf("Enter the number of copies to be added:");
    scanf("%d",&new->copies);
    if(library->start==NULL)
    {
        library->start=new;
        printf("\n\t**Book added!!**");
    }
    else
    {
        struct book *p;
        p=library->start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=new;
        printf("\n\t**Book added!!**");
    }
}

void remove_book(struct Library *library, int bookcode_remove)
{
    int copies_deleted;
    struct book *p,*prev;
	p=library->start;
	prev=NULL;
	while(p->book_code!=bookcode_remove)
	{
		prev=p;
		p=p->next;
	}

    printf("\nHow many copies of this book do you want to remove:");
    scanf("%d",&copies_deleted);
        if(copies_deleted>=p->copies)
        {
            if(prev==NULL)			//first element
	        {
    		    library->start=p->next;
		        free(p);
	        }
    	    else
	        {	
    		    prev->next=p->next;
		        free(p);
	        }
        }
        else
        {
            p->copies-=copies_deleted;
        }
    printf("\n\t**Book Removed**");
}

void display_all_books(struct Library library)
{
    struct book *ptr;
    if(library.start==NULL)
        printf("\n\t**BOOKS COMING SOON!!**");
    else
    {
        ptr=library.start;
        while(ptr!=NULL)
        {
            printf("\nGenre:%s",ptr->genre);
            printf("\nBook code:%d",ptr->book_code);
            printf("\tName:%s",ptr->name_of_book);
            printf("\tAuthor:%s",ptr->name_of_author);
            printf("\nCopies available:%d\n",ptr->copies);
            ptr=ptr->next;
        }
    } 
}


void displaybooks(struct user_data *p)
{
    struct book *ptr;
    if(p->books!=NULL)
    {
        ptr=p->books;
        while(ptr!=NULL)
        {
            printf("\n\tBook code:%d",ptr->book_code);
            printf("\nGenre:%s",ptr->genre);
            printf("\tName:%s",ptr->name_of_book);
            printf("\tAuthor:%s\n",ptr->name_of_author);
            ptr=ptr->next;
        }
    }
    else
        printf("\n");
}

void remove_userbook(struct user_data *ptr)
{
    struct book *p,*prev;
    int bookcode_to_delete;
    if(ptr->books==NULL)
    {
        printf("\n\t**NO BOOK ADDED YET**");
    }
    else
    {   
        printf("\nEnter the book code of the book you want to remove:");
        scanf("%d",&bookcode_to_delete); 
	    p=ptr->books;
	    prev=NULL;
	    while(p->book_code!=bookcode_to_delete)
	    {
		    prev=p;
		    p=p->next;
    	}
        if(prev==NULL)			//first element
	    {
    	    ptr->books=p->next;
	        free(p);
        }
        else
	    {	
    	    prev->next=p->next;
	        free(p);
        }
    }
}


int main()
{
    struct Library library;
    library.start=NULL;
    struct Customer users;
    users.start=NULL;
    int main_ch,ch;   
    
    main_menu:
    printf("\n\t***Welcome to Online Library Store***\n");
    printf("\n1.New Customer \n2.Old Customer \n3.Librarian(Admin)\n4.Exit\n\nEnter you choice:");
    scanf("%d",&main_ch);

    if(main_ch==1)                  //new user case
    {
        menu:
        printf("\n\n1.Yes \n2.No \nDo you want to register? :");
        scanf("%d",&ch);
        if(ch==1)
        {
            registration(&users);
            printf("\n\nPress any key to continue...\n");
            getch();
            goto log;
        }
        else if(ch==2)
        {
            printf("\nThank you!\n\n");
            printf("\n\nPress any key to continue...\n");
            getch();
            goto main_menu;
        }
        else
        {
            printf("\n\t**Wrong Input!!**\n\t  TRY AGAIN");
            printf("\n\nPress any key to continue...\n");
            getch();
            goto menu;
        }

    }

    else if(main_ch==2)                         //login 
    {
        struct user_data *this_user;
        log:
        if(users.start==NULL)
        {
            printf("\n\t**NO USER FOUND!!");
            printf("\n\nPress any key to continue...\n");
            getch();
            goto main_menu;
        }
        else
        {
            this_user=login(users);
            if(this_user==NULL)
                goto log; 
            else
            {
                menu_account:
                printf("\n1.Add new books \n2.Remove books \n3.Display your account details \n4.Change your password \n5.Delete your account \n6.Logout \n\nEnter your choice:");
                scanf("%d",&ch);

                if(ch==1)
                {
                    display_all_books(library);
                    add_userbook(&library,&(*this_user));
                    printf("\n\nPress any key to continue...\n");
                    getch();
                    goto menu_account;
                }

                else if(ch==2)
                {
                    displaybooks(this_user);
                    remove_userbook(&(*this_user));
                    printf("\n\nPress any key to continue...\n");
                    getch();
                    goto menu_account;
                }

                else if(ch==3)
                {
                    display_user_details(*this_user);
                    displaybooks(this_user);
                    printf("\n\nPress any key to continue...\n");
                    getch();
                    goto menu_account;
                }

                else if(ch==4)
                {
                    change_password(&(*this_user));
                    goto log;
                }

                else if(ch==5)
                {
                    delete_account(&users,this_user->phone_number);
                    printf("\n\nPress any key to continue...\n");
                    getch();
                    goto main_menu;
                }

                else if(ch==6)
                {
                    printf("\n\t**User logged out successfully**\n\n");
                    sleep(2);
                    goto main_menu;
                }
                else
                {
                    printf("\n\t**Wrong Input!!**\n\t  TRY AGAIN");
                    printf("\n\nPress any key to continue...\n");
                    getch();
                    goto menu_account;
                }
            }

        }
    }   

    else if(main_ch==3)
    {
        int check_lib_code;
        check:
        printf("\nEnter library code:");
        scanf("%d",&check_lib_code);
        if(check_lib_code==lib_code)
        {
            menu_librarian:

            printf("\n\t***Welcome Librarian***\n");
            printf("\n1.Add new books \n2.Remove a book \n3.Display all books \n4.Sign out \n\nEnter your choice:");
            scanf("%d",&ch);
            if(ch==1)
            {
                printf("\nEnter the details of the book:-\n");
                add_book(&library);
                printf("\n\nPress any key to continue...\n");
                getch();
                goto menu_librarian;
            }

            else if(ch==2)
            {
                int bookcode_remove;
                if(library.start==NULL)
                {
                    printf("\n\t**NO BOOK AVAILABLE**");
                }
                else
                {
                    display_all_books(library); 
                    printf("\n\nEnter the book code of the book you want to remove:");
                    scanf("%d",&bookcode_remove);
                    remove_book(&library,bookcode_remove);
                    printf("\n\nPress any key to continue...\n");
                    getch();
                    goto menu_librarian;
                }

                goto menu_librarian;    
            }

            else if(ch==3)
            {
                printf("\n\t**LIBRARY Database**\n");
                display_all_books(library);
                printf("\n\nPress any key to continue...\n");
                getch();
                goto menu_librarian;
            }

            else if(ch==4)
            {
                printf("\n\t**Signed Out successfully**\n\n");
                sleep(2);
                goto main_menu;       
            }

            else
            {
                printf("\n\t**Wrong Input!!**\n\t  TRY AGAIN");
                printf("\n\nPress any key to continue...\n");
                getch();
                goto menu_librarian;
            }
            
        }
        else
        {
            printf("\n\t**Wrong Library Code!!**\n");
            sleep(2);
            goto main_menu;
        }
    }

    else if(main_ch==4)                  //logout case
    {
        printf("\n\n\t**Thank You\n\t  VISIT AGAIN!!\n");
        sleep(2);
        exit(0);
    }

    else
    {
        printf("\n\t**Wrong Input!!**\n\t  TRY AGAIN\n");
        printf("\n\nPress any key to continue...\n");
        getch();
        goto main_menu;
    }
}