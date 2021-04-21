import java.util.Scanner;
import java.io.*;
import java.util.*;

class Product
{
public int id;
public String name;
public double price;

  Product(int id,String name,double price)
 {
   this.id=id;
   this.name=name;
   this.price=price;
 }
 
} 
 

class Samsung
{
  public static void main(String args[])
  { 
   int id,count=0;
  double price,sprice=0;
  String name;
  String s1;
  String s2=new String("Samsung");
  int n,i,j,m;
   Product [][]a;
   Scanner sc=new Scanner(System.in);
   
   System.out.println("Enter the no of costumers");
   n=sc.nextInt();
   a=new Product[n][];
   
   for(i=0;i<a.length;i++)
   {
    System.out.println("Welcome costumer no:"+(i+1));
	System.out.println("Enter the no of products u want to buy");
	m=sc.nextInt();
	a[i]=new Product[m];
	for(j=0;j<a[i].length;j++)
	{
	 System.out.println("Enter the product id,product price,product name");
	 id=sc.nextInt();
	 price=sc.nextDouble();
	name=sc.next();
	a[i][j]=new Product(id,name,price);
	}
    
   }
   for(i=0;i<a.length;i++)
   {
	   for(j=0;j<a[i].length;j++)
	   {
		  System.out.println("id is "+a[i][j].id+"price is "+a[i][j].price+"name is "+a[i][j].name);
	   }
   }   
   
   for(i=0;i<a.length;i++)
   {
	   for(j=0;j<a[i].length;j++)
	   {
		if(s2.equals(a[i][j].name))
		{count++;
         sprice+=a[i][j].price;		
	   }
	   }
   }
   System.out.println("The details of the products sold today are\n:");
  System.out.println("the no of products of Samsung sold today is "+count);
  System.out.println("The earning from the Samsung product is "+sprice);  

  }
} 