//single level inheritance
package object;
public class Rectangle
{
	protected int length, breadth;

	public Rectangle()
	{}
 	public Rectangle(int length, int breadth)

 	{
		this.length = length; 
		this.breadth= breadth;
	}

 	public int getArea()

 	{
		return length*breadth;
	}

}	
//save the above code in file Rectangle.java
 
package object;
public class Box extends Rectangle
{
	private int depth;

	public Box()
	{}
 	public Box(int l, int b, int d)

 	{
		super(l, b); //call parameterized constructor of Rectangle
		depth = d; 
	}

 	public double getVolume()

 	{
		return area()*breadth;
	}

}

//save the above code in file Box.java

package client;
import object.*;
public class RectBox
{   
	public static void main(String[] args)

    	{
		Rectangle r = new Rectangle(10, 5);

     		System.out.println("Area of Rectangle is "+r.getArea());

     		Box b = new Box(4, 5, 6);

     		System.out.println("volume of box is "+b.getVolume());

    	}

}
//save the above code in file RectBox.java