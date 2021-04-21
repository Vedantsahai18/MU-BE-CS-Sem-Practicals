import java.util.*;

class MyStack
{
  	int [] a;//a is reference variable to array(container) of integers
  	int top;
	
	MyStack()
	{
  		a=new int[5];
  		top=-1;
	}
	MyStack(int n)
	{
  		a=new int [n];
  		top=-1;
	}
	void push(int ele)
  	{
		if(top==a.length-1)
		{
			System.out.println("stack is full");
		}
		else
			a[++top]=ele;
  	}
	int pop()
	{
		if(isEmpty()) // pop() method call isEmpty() method
		{		//i.e one instance method call other instance method
			System.out.println("Stack is empty");
			return -1;
		}
		else
			return a[top--];
	}
	boolean isEmpty()
	{
		return (top==-1); //return true if top is equal to -1
	}
	int peek()
	{
		if(isEmpty)
		{
			System.out.println("Stack is empty");
			return -1;
		}
		else
		return a[top];
	}

	void display()
	{
		for(int i=top;i>=0;i--)
		{
			System.out.println(a[i]);
		}
	}
}//class stack ends

public class MyStackDemo
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		MyStack s = MyStack(); //stack object is initiated and pointed by reference variable s
		System.out.println("1.PUSH,2.POP,3.Peek,4.Display,5.Exit");
		while(true)
		{
			System.out.println("Enter the choice");
			int n=in.nextInt();
			switch(n)
			{
				case 1:
					System.out.println("enter the element to be inserted");
					int b=in.nextInt();
					s.push(b);
				break;
				case 2:
					int a=s.pop();
					System.out.println("Popped element is"+a);
				break;
				case 3:
					//complete the code
			}//switch ends
		}//while ends
	}//main ends
}//MyStackDemo ends