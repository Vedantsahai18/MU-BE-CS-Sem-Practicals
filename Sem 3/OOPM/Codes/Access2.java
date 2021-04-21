//multilevel inheritance
class A
{
	private int x; //to remove error make x protected

	A()
	{
		x = 10;
	}
	
}

class B extends A
{
	private int y; //to remove error make y protected 
	B()
	{
		y = 20;
	}
}

class C extends B
{
	private int z;
	int getz()
	{
	
		z = x+y; //error 
		return z;
	}
}

public class Access2
{
	public static void main(String [] args)
	{
		C ob = new C();
		System.out.println(ob.getz());
	}
}