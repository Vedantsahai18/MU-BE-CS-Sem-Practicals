#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{ int id,price;
  struct node *next;
};


int a[10]={0};
int choose[10]={0};
int price[10]={5000,3200,6000,4000,4800,8000};
char brand[10][10]={"Samsung","Lenovo","Dell","Asus","Sony","Apple"};
struct node *start=NULL;

void create()
{ int n;
  struct node *newnode,*ptr,*preptr;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter your choice\n");
  scanf("%d",&n);
  newnode->id=n;
  a[n]=0;
  newnode->next=NULL;
  newnode->price=price[n];
  if(start==NULL)
  {start=newnode;
  }

  else
  { ptr=start;
    while(ptr->price<newnode->price)
    {
      preptr=ptr;
      ptr=ptr->next;
      if(ptr==NULL)
      break;
    }
    if(ptr==start)
    {
      newnode->next=start;
      start=newnode;
    }
    else{
    newnode->next=ptr;
    preptr->next=newnode;
  }
  }
 }

 void delete(int delid)
 {
   struct node *ptr,*preptr;
   ptr=start;
   if(start->id==delid)
   {
     start=start->next;
     a[delid]=1;
   }
   else
   {
     while(ptr->id!=delid)
     {
       preptr=ptr;
       ptr=ptr->next;
       if(ptr==NULL)
       break;
     }
     if(ptr!=NULL)
     {
       preptr->next=ptr->next;
       a[delid]=1;
     }
     else
     {
       printf("Sorry no such product id\n");
     }

   }

}

void main()
{  struct node *ptr;
  int total=0,price,delid,choice,id,i;
  char name[20],result1[10],result2[10],result3[10],array[200];
  FILE *fp,*fw,*fr;
 fp=fopen("data.txt","a");
 fr=fopen("f1.txt","r");

 for(i=0;i<=5;i++)
 {
   fgets(array,200,fr);
   id=atoi(array);
   a[id]=1;
 }

 fclose(fr);
 printf("Enter your name\n");
 scanf("%s",&name);
 fw=fopen("f1.txt","w");
do{
l1:  if(a[0]==1)
  printf("Enter 0:Samsung Laptop  Price:5000\n");
 if(a[1]==1)
  printf("Enter 1:Lenovo Laptop   Price:3200\n");
   if(a[2]==1)
  printf("Enter 2:Dell Laptop  Price:6000\n");
   if(a[3]==1)
  printf("Enter 3:Asus Laptop  Price:4000\n");
   if(a[4]==1)
  printf("Enter 4:Sony Laptop  Price:4800\n");
   if(a[5]==1)
  printf("Enter 5:Apple Laptop  Price:8000\n");
  printf("\n");
  create();
   printf("Enter 1:adding more products\nEnter 2:Deleting a particular product\nEnter 3:exit\n");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1:goto l1;
            break;
     case 2:del:printf("Enter the id of the product you want to remove from your cart\n");
            scanf("%d",&delid);
            delete(delid);
            printf("Enter 1:to add new products\t2:deleting more products\t3:exit");
            scanf("%d",&choice);
            if(choice==1)
            goto l1;
            else if(choice==2)
            goto del;
           else if(choice==3)
            goto out;
     case 3:goto out;
   }

} while(1);

out: ptr=start;
while(ptr!=NULL)
{
  total=total+ptr->price;
  ptr=ptr->next;
}
fputs("Name:",fp);
fputs(name,fp);
fputs("\n",fp);
ptr=start;
while(ptr!=NULL)
{
  fputs("Product ID:",fp);
  id=ptr->id;
  sprintf(result1,"%d",id);
  fputs(result1,fp);
  fputs("\n",fp);
  fputs("Product Brand:",fp);
  fputs(brand[ptr->id],fp);
  fputs("\n",fp);
  price=ptr->price;
  sprintf(result2,"%d",price);
  fputs("Price:",fp);
  fputs(result2,fp);
  fputs("\n",fp);
  ptr=ptr->next;
  fputs("\n\n",fp);


}
fputs("Total:",fp);
sprintf(result3,"%d",total);
fputs(result3,fp);
fputs("\n\n",fp);
ptr=start;
printf("The details are:\n");
while(ptr!=NULL)
{
  printf("Name:%s\n",name);
  printf("Product ID:%d\n",ptr->id);
  printf("Product Brand:%s\n",brand[ptr->id]);
  printf("Price::%d\n",ptr->price);
  printf("\n");
  ptr=ptr->next;
}
printf("\n");
printf("TOTAL PRICE:%d\n",total);
fclose(fp);// it starts from here
for(i=0;i<=5;i++)
{
  if(a[i]==1)
  {
    sprintf(result1,"%d",i);
    fputs(result1,fw);
    fputs("\t",fw);
    fputs(brand[i],fw);
    fputs("\t",fw);
    fputs("\n",fw);

  }
}
fclose(fw);
}
