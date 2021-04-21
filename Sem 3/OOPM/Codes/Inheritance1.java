//single level inheritance, constructor calls
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

	public String toString() //overriding toString method of A class
	{
		return x+","+y;//return x,y 

		//here x can get accessed since x is protected member, inherited in B as protected member
	}
}

public class Inheritance1
{
	public static void main(String [] args)
	{
		A ob1 = new A();

		System.out.println(ob1); //System.out.println(ob1.toString());

		System.out.println("--------------------------------------");
		B ob2 = new B();
		System. out.println(ob2);		
	}
}