import java.util.*;
class Point
{
	private int x;
	private int y;

	Point()
	{}
	Point(int x,int y)
	{
		this.x = x; //instance variable = local variable
		this.y = y; 
	}

	public String toString()
	{
		return "["+x+","+y+"]";
	}
}

class Student
{
	int rollno;
	String name;
	Student()
	{}
	Student(int r, String n)
	{
		rollno = r;
		name = n;
	}
}
class VectorMain
{
	public static void main(String [] args)
	{
		Vector v = new Vector();

		v.add(new Integer(10));
		v.add(new Float(10.5f));
		v.add("SE Computer");
		v.add(new Point(2,3)); //add userdefined class objec
		v.add(1,new Student(10,"AAkash")); //at index 1 student object is inserted

		for(int i=0; i < v.size(); i++)
		{
			System.out.println((i+1)+" element is "+v.get(i));
		}
	}
}