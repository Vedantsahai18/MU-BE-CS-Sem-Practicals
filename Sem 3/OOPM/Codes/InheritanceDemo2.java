//Single level inheritance

import java.util.*;

class Rectangle
{
	protected int length;
	protected int breadth;

	void read()
	{
		
		Scanner in = new Scanner(System.in);
		length = in.nextInt();
		breadth = in.nextInt();
	}

	double getArea()
	{
		return length*breadth;
	}

	public String toString()
	{
		return "Length "+length+"\tBreadth "+breadth;
	}
}


class Box
{
	private int depth;
	
	void read() //function overriding
	{
		
		Scanner in = new Scanner(System.in);
		super.read();
		depth = in.nextInt();
	}
	
	double getVolume()
	{
		return super.getArea()*depth;
	}

	double getArea()
	{
		return 2*((length*breadth)+(breadth*height)+(height*length));
	}
}
	
public class InheritanceDemo2
{
	public static void main(String [] args)
	{
		Box b = new Box();
		System.out.println("Enter all sides of box: =");
		b.read();
		System.out.println("Area of Box "+b.getArea());
		System.out.println("Volume of Box "+b.getVolume());	
	}
}