class A
{
	private int x;//private members are accessed using non-private methods

	A()
	{
		x = 10;			
	}
	int getx() //default access (package level access)
	{
		return x;
	}
}

public class Access1
{
	public static void main(String [] args)
	{
		A ob = new A();
		System.out.println(ob.x); //error
		System.out.println("Value of x is:"+x.getx());
	}
}