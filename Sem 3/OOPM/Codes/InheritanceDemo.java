//Inheritance

import java.util.*;

class A
{
	protected int i,j;
	
	void readij()
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter 2 values:= ");
		i = in.nextInt();
		j = in.nextInt();
	}	

	void displayij()
	{
		System.out.println("i = "+i+", j = "+j);
	}
}//class A ends 
//It has 4 members - 2 instance variables and 2 instance method

class B extends A
{
	private int k;

	void computek()
	{
		k = i+j;
	}
	void displayk()
	{
		System.out.println("Addition is "+k);
	}
}//class B ends
//It has 3 instance variable ( 1 its own and 2 inherited)
//and 4 instance methods( 2 its own and 2 inherited


public class InheritanceDemo
{
	public static void main(String [] args)
	{
		B ob = new B();
		ob.readij();
		ob.computek();
		ob.displayij();
		ob.displayk();
	}
}


--------------------------------------
class A
{
	protected int i,j;
	
	void readij()
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter 2 values:= ");
		i = in.nextInt();
		j = in.nextInt();
	}	

	void displayij()
	{
		System.out.println("i = "+i+", j = "+j);
	}
}//class A ends 
//It has 4 members - 2 instance variables and 2 instance method

class B extends A
{
	private int k;

	void computek()
	{
		readij();//one instance method can call other instance method 
		k = i+j;
	}
	void displayk()
	{
		displayij();
		System.out.println("Addition is "+k);
	}
}//class B ends
//It has 3 instance variable ( 1 its own and 2 inherited)
//and 4 instance methods( 2 its own and 2 inherited


public class InheritanceDemo
{
	public static void main(String [] args)
	{
		B ob = new B();
		//ob.readij();
		ob.computek();
		//ob.displayij();
		ob.displayk();
	}
}
