//singlelevel inheritance, constructor calls
class A
{
	protected int x;
	A()
	{
		//super();
		x = 10;
		System.out.println("This is default constructor of A class");
	}

	A(int x)
	{
		//super();
		this.x = x;
		System.out.println("This is parameterized constructor of A class");
	}

	public String toString() //overriding toString method of object class
	{
		return ( new Integer(x).toString()); //return x+" ";
	}
}

class B extends A
{
	private int y;
	//inherited member x is present

	B()
	{
		//super()
		y = 5;
		System.out.println("This is default constructor of B class");
	}

	B(int x, int y) 
	{
		//super(x);//parameterized constructor of A class invoked, when you uncomment this stmt.
		this.y = y;
		System.out.println("This is 2 arguments paramterized construtor of B class");
	}

	public String toString() //overriding toString method of A class
	{
		return x+","+y;//return x,y
	}
}

public class Inheritance2
{
	public static void main(String [] args)
	{
		A ob1 = new A(25);

		System.out.println(ob1); //System.out.println(ob1.toString());

		System.out.println("--------------------------------------");
		B ob2 = new B(23,46);
		System. out.println(ob2);		
	}
}