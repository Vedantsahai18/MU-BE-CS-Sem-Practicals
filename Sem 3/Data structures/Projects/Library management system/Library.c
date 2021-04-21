#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//**********************************structures**********************************
 
typedef struct Admin //Librarian
{
    char usernm[15];
    char pswd[15];
}adm;
 
typedef struct Book
{
    int id;
    int temp; //to store original number of copies added by Librarian
    int taken; //number of copies (keeps on varying depending on how many books available to borrow/return)
    char title[50];
    char author[50]; 
    char category[100];
    char description[10000];
    struct Book *next;
} Book;
 
Book *startBook = NULL;
 
typedef struct Student //Student
{
    char name[15];
    int rn;
    struct Student *next;
    struct fine //Nested structure for issue and return date 
    {
        int borrow;
        int Idate,Imonth,Rdate,Rmonth;
    }fine[50];
}std;
 
std *startStudent=NULL;
 
//**********************************structures**********************************
 
//*************************Functions for Librarian**********************************



void addBook() //Adding books to the database
{
    char temp[100];
    int i,count;
    count=0;
    Book *newBook,*ptr,*preptr;
    newBook = (Book*)malloc(sizeof(Book));
    newBook->next=NULL;
    if(startBook==NULL)
    {
        startBook=newBook;
        count=1;
    }
    loop3:
    ptr=startBook;
    printf("Enter the unique book ID \n");
    scanf("%d",&i);
    while(ptr!=NULL) //Same Book ID condition
    {
        if(ptr->id==i)
        {
            printf("Invalid book ID\n");
            goto loop3;
        }
        else
            ptr=ptr->next;
    }
    newBook->id=i;
    if(count==0)
    {
        preptr=startBook;
        ptr=startBook;
        while(ptr!=NULL && newBook->id>ptr->id)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr!=NULL)
        {
            preptr->next=newBook;
            newBook->next=ptr;
        }
        else
        {
            preptr->next=newBook;
        } 
    }
    printf("Enter book title \n");
    scanf(" %[^\t\n]s",&temp);
    strcpy(newBook->title,temp);
    printf("Enter author name\n");
    scanf(" %[^\t\n]s",&temp);
    strcpy(newBook->author,temp);
    printf("Enter Category \n");
    scanf(" %[^\t\n]s",&temp);
    strcpy(newBook->category,temp);
    printf("Enter Description\n");
    scanf(" %[^\t\n]s",&temp);
    strcpy(newBook->description,temp);
    printf("Enter number of copies to be added \n");
    scanf("%d",&newBook->taken);
    newBook->temp=newBook->taken;
    printf(" %d copies of %s successfully added to library \n",newBook->taken,newBook->title);
    return;
}
 
void removeBook(int bid) //Removing specific book from the database
{
    Book *ptr, *preptr;
    ptr=startBook;
    if(startBook==NULL)
    {
        printf("Library empty \n");
        return;
    }
    else if(startBook->id==bid)
    {
        printf("Deleted Book = %s\n", startBook->title);
        startBook=startBook->next;
        free(ptr);
    }
    else
    {
        while(ptr->id!=bid && ptr!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->id!=bid)
        {
            printf("Book not found\n");
            return;
        }
        else
        {
            preptr->next=ptr->next;
            printf("Deleted Book = %s\n", ptr->title);
            free(ptr);
        }
        
    }
}
 
//*************************Functions for Librarian**********************************
 
//*************************Functions for Student**********************************
 
void studentList() //Dynamic addition of students to the database
{
    int temp,count;
    count=0;
    std *s;
    s=(std *)malloc(sizeof(std)); //Student
    printf("Enter Name\n");
    scanf("%s",s->name);
    s->next=NULL;
    std *ptr,*preptr;
    if(startStudent==NULL)
    {
        startStudent=s;
        count=1;
    }
    loop3:
    ptr=startStudent;
    printf("Enter Roll Number\n");
    scanf("%d",&temp);
    while(ptr!=NULL) //Same roll number condition
    {
        if(ptr->rn==temp)
        {
            printf("Invalid roll number\n");
            goto loop3;
        }
        else
            ptr=ptr->next;
    }
    s->rn=temp;
    if(count==0)
    {
        preptr=startStudent;
        ptr=startStudent;
        while(ptr!=NULL && s->rn>ptr->rn)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr!=NULL)
        {
            preptr->next=s;
            s->next=ptr;
        }
        else
        {
            preptr->next=s;
        } 
    }
    printf("Student successfully added to database \n");
    return;
}
 
void studentDisplay() //Displaying student database
{
    int i,j;
    j=1;
    std *ptr;
    Book *bk;
    bk=startBook;
    ptr=startStudent;
    while(ptr!=NULL)
    {
        printf("Name: %s\n",ptr->name);
        printf("Roll  number: %d\n",ptr->rn);
        printf("Books borrowed:\n");
        for(i=0;i<50;i++)
        {
            if(ptr->fine[i].borrow==1)
            {
                printf("Book ID=  %d\n",i);
                while(bk!=NULL && bk->id!=i)
                {
                    bk=bk->next;
                }
                if(bk->id==i)
                {
                    printf("   Book name:  %s\n",bk->title);
                    printf("   Book author:  %s\n",bk->author);
                    printf("   Book return date:  %d/%d\n",ptr->fine[i].Rdate,ptr->fine[i].Rmonth);
                }
            }
        }
        if(j==1)
        {
            printf(" None\n");
        }
        printf("**************************************************\n");
        ptr=ptr->next;
    }
}
 
int displayBook() //Displaying book database
{
    int flag=0;
    Book *ptr;
    if(startBook==NULL)
    {
        printf("List empty\n");
        flag=1;
        return flag;
    }
    else
    {
        printf("***************************************\n");
        ptr=startBook;
        while(ptr!=NULL)
        {
            printf("Book ID: %d\n",ptr->id);
            printf("   Title: %s\n",ptr->title);
            printf("   Author: %s\n",ptr->author);
            printf("   Category: %s\n",ptr->category);
            printf("   Description: %s\n",ptr->description);
            printf("   Nummber of copies: %d\n",ptr->taken);
            printf("***************************************\n");
            ptr=ptr->next;
        }
        return flag;
    }
}
 
int checkDate(int d, int m) // to check if entered date is valid or not
{
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        if(d>=1 && d<=31)
            return 1;
        else
        {
            printf("Invalid day \n");
            return 0;
        }
    
    }
    else if(m==4 || m==6 || m==9 || m==11)
    {
        if(d>=1 && d<=30)
            return 1;
        else
        {
            printf("Invalid day \n");
            return 0;
        }
    }
     else if(m==2)
    {
        if(d>=1 && d<=28)
           return 1;
        else
        {
            printf("Invalid day \n");
            return 0;
        }
    }
    else
    {
        printf("Invalid month \n");
        return 0;
    }
    return 1;
 
}
 
int retBook(std *ptr,int ID,int d,int m) //Calculate return date for book
{
    int df,mf;
 
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        if(d>=1 && d<=17)
        {
            df=d+14;
            mf=m;
        }
        else
        {
            df=1+(d-18);
            if(mf==12)
            {
                mf=1;
            }
            else
            {
                mf=m+1;
            }
        }
        ptr->fine[ID].Rdate=df;
        ptr->fine[ID].Rmonth=mf;
        printf("Return book by %d/%d\n",df,mf);
    }
 
    else if(m==4 || m==6 || m==9 || m==11)
    {
        if(d>=1 && d<=16)
        {
            df=d+14;
            mf=m;
        }
        else
        {
            df=1+(d-17);
            mf=m+1;
        }
        ptr->fine[ID].Rdate=df;
        ptr->fine[ID].Rmonth=mf;
        printf("Return book by %d/%d\n",df,mf);
    }
 
    else
    {
        if(d>=1 && d<=14)
        {
            df=d+14;
            mf=m;
        }
        else
        {
            df=1+(d-15);
            mf=m+1;
        }
        ptr->fine[ID].Rdate=df;
        ptr->fine[ID].Rmonth=mf;
        printf("Return book by %d/%d\n",df,mf);
    }
}
 
int checkLate(std *ptr,int ID,int d,int m) //Checking for late return
{
    int fine,df,mf;
    df=ptr->fine[ID].Rdate;
    mf=ptr->fine[ID].Rmonth;
    if((d>df && m==mf) || (d>df && m==mf+1))
    {
        fine=(d-df)*10;
    }
    else if((d==df && m==mf) || (d<df && m==mf) || (d<df && m==mf+1))
    {
        fine=1;
    }
    else
    {
        fine=500;
    }
    return fine;
}
 
void borrowBook(int ID,char n[15]) //Borrowing book
{
    std *sptr;
    sptr=startStudent;
    int checkB=0;
    Book *ptr;
    ptr=startBook;
    while(ptr!=NULL)
    {
        if(ptr->id==ID)
        {
            checkB=1;
            break;
        }
        else
            ptr=ptr->next;
    }
    if(ptr->taken==0)
    {
        printf("Specified book is not available now\n");
        return;
    }
    else if(checkB==0)
    {
        printf("Invalid book ID\n");
        return;
    }
    else
    {
        while(strcmp(sptr->name,n)!=0 && sptr!=NULL)
        {
            sptr=sptr->next;
        }
        if(strcmp(sptr->name,n)==0)
        {
            int d,m;
            sptr->fine[ID].borrow=1;
            printf("Enter issue date\n");
            scanf("%d",&d);
            printf("Enter issue month\n");
            scanf("%d",&m);
            loop1:
            sptr->fine[ID].Idate=d;
            sptr->fine[ID].Imonth=m;
            if(checkDate(d,m)==1)
            {
                retBook(sptr,ID,d,m);
            }
            else
                goto loop1;
            ptr->taken--;
            printf("Book succesfully borrowed\n");
        }
    }
}
 
void returnBook(int ID,char n[15]) //Returning book
{
    std *sptr;
    sptr=startStudent;
    int checkR=0;
    Book *ptr;
    ptr=startBook;
    while(ptr!=NULL)
    {
        if(ptr->id==ID)
        {
            checkR=1;
            break;
        }
        else
            ptr=ptr->next;
    }
    if(checkR==0)
    {
        printf("Invalid book ID\n");
        return;
    }
    else if(ptr->taken==ptr->temp) //if number of copies available is equal to original number of copies
    {
        printf("Book has never been borrowed\n");
        return;
    }
    else
    {
        while(strcmp(sptr->name,n)!=0 && sptr!=NULL)
        {
            sptr=sptr->next;
        }
        if(strcmp(sptr->name,n)==0)
        { 
            int d,m,fine;
            sptr->fine[ID].borrow=0;
            ptr->taken++;
            loop2:
            printf("Enter return date\n");
            scanf("%d",&d);
            printf("Enter return month\n");
            scanf("%d",&m);
            if(checkDate(d,m)==1)
            {
                fine=checkLate(sptr,ID,d,m);
            }
            else
                goto loop2;
            if(fine==1)
            {
                printf("Book successfully returned before deadline \n");
            }
            else
            {
                printf("Your return date was %d/%d\n",sptr->fine[ID].Rdate,sptr->fine[ID].Rmonth);
                printf("Fine to  be paid : %d\n",fine);
            }
        }
    }
}
 
//*************************Functions for Student**********************************
 
void main()
{
    char username[15],password[15];
    int loginL=0,loginS=0; // Login Flags to check first time sign up
    int st=0,admOption=0,stdOption=0,st1=0; // switch case options
    int iday,imonth,iyear; // for issue date to pass into date function
    int rday,rmonth,ryear; // for return date to pass into date function
    int dateFlag;
    adm adm;
    SIGNUP:
    printf("LOGIN\n");
    printf("1: Librarian \n2: Student\n3: Exit\n");
    scanf("%d",&st);
    switch(st)
    {
        case 1: //Librarian
        {
            if(loginL==0)
            {
                printf("Provide Username and Password for Librarian Setup \n");
                printf("Enter a Valid Username\n");
                scanf("%s",adm.usernm);
                printf("Enter a Valid Password\n");
                scanf("%s",adm.pswd);
                loginL=1;
                goto SIGNUP; 
            }
            else
            {
                LOGINadmin:
                printf("Enter username\n");
                scanf("%s",username);
                printf("Enter password\n");
                scanf("%s",password);
                if(strcmp(username,adm.usernm)==0 && strcmp(password,adm.pswd)==0)
                {
                    printf("Login successful\n");
                    bookFunctn:
                    printf("Select action \n1: Add new Book\n2: Delete Books\n3: Display Books\n4: Student database\n5: Back\n");
                    scanf("%d",&admOption);
                    switch(admOption)
                    {
                        case 1: 
                        {
                            addBook();
                            goto bookFunctn;
                        }
 
                        case 2: 
                        {
                            displayBook();
                            printf("Enter book ID to be deleted \n");
                            int bookID;
                            scanf("%d",&bookID);
                            removeBook(bookID);
                            goto bookFunctn;
                        }
 
                        case 3:
                        {
                            displayBook();
                            goto bookFunctn;
                        }
                        
                        case 4:
                        {
                            studentDisplay();
                            goto bookFunctn;
                        }
                        case 5:
                        {
                            goto SIGNUP;
                        }
            
                    }
                }
                else
                {
                    printf("Invalid username and password\n");
                    goto LOGINadmin;
                }
                    
            }
        }
        case 2: //Student
        {
            Book *bk;
            bk=startBook;
            int check1=0;
            char name[15];
            int rn=0;
            int x; //book ID to be borrowed and returned
            std *ptr;
            stSignUp:
            if(loginS==0)
            {
                printf("Provide Name and Roll Number for Setup \n");
                studentList();
                loginS=1;
                goto stSignUp;
            }
            else
            {
                printf("1: Login\n2:Signup\n3:Back\n");
                scanf("%d",&stdOption);
                switch(stdOption)
                {
                    case 1:
                    {
                        LOGINstudent:
                        printf("Enter Name\n");
                        scanf("%s",name);
                        printf("Enter Roll number\n");
                        scanf("%d",&rn);
                        ptr=startStudent;
                        while(ptr!=NULL)
                        {
                            if(strcmp(ptr->name,name)==0 && ptr->rn==rn)
                            {
                                printf("Login successful\n");
                                check1=1;
                                loop:
                                printf("Select action \n1: Borrow a book\n2: Return a book\n3:My profile\n4:Back\n");
                                scanf("%d",&st1);
                                switch(st1)
                                {
                                    case 1:
                                    {
                                        int a;
                                        a=displayBook();
                                        if(a==0)
                                        {
                                            printf("Enter ID of the book to be borrowed\n");
                                            scanf("%d",&x);
                                            borrowBook(x,name);
                                            goto loop;
                                            break;
                                        }
                                    }
                                    case 2: 
                                    {
                                        printf("Enter ID of the book to be returned\n");
                                        scanf("%d",&x);
                                        returnBook(x,name);
                                        goto loop;
                                        break;
                                    }
 
                                    case 3:
                                    {
                                        bk=startBook;
                                        int i,ct,j;
                                        ct=0;j=1;
                                        printf("Name: %s\n Roll number: %d\n",ptr->name,ptr->rn);
                                        printf(" Books borrowed:\n");
                                        for(i=0;i<50;i++)
                                        {
                                            if(ptr->fine[i].borrow==1)
                                            {
                                                printf("%d)   Book ID=  %d\n",j,i);
                                                while(bk!=NULL && bk->id!=i)
                                                {
                                                    bk=bk->next;
                                                }
                                                if(bk->id==i)
                                                {
                                                    printf("   Book name:  %s\n",bk->title);
                                                    printf("   Book author:  %s\n",bk->author);
                                                    printf("   Book return date:  %d/%d\n",ptr->fine[i].Rdate,ptr->fine[i].Rmonth);
                                                }
                                                j++;
                                            }
                                        }
                                        if(j==1)
                                        {
                                            printf(" None\n");
                                        }
                                        goto loop;
                                    }
                                    
                                    case 4:
                                    {
                                        goto stSignUp;
                                    }
                                }
                            }
                            else
                            {
                                ptr=ptr->next;
                            }
                        }
                        if(check1==0)
                        {
                            printf("Invalid name or roll number\n");
                            goto LOGINstudent;
                        }
                        break;
                    }
 
                    case 2:
                    {
                        printf("Provide Name and Roll Number for Setup \n");
                        studentList();
                        goto stSignUp;
                        break;
                    }
 
                    case 3:
                    {
                        goto SIGNUP;
                    }
                }
            }
        }
        case 3: 
        {
            printf("******************************************Thank you for visiting************************************************\n");
            break;
        }
    }
}
 

