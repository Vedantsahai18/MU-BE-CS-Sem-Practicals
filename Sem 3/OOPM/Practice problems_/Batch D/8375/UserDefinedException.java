import java.util.*;

class UserDefinedException
{ 
 public static void main(String args[])
 { Scanner sc=new Scanner(System.in);
 int no;
  System.out.println("Enter the no\n");
  no=sc.nextInt();
  
  try
  {
  getMarks(no);
  }
  catch(IllegalNumException ime)
  {
   System.out.println(ime);
  }
 
 }
 
 public static void getMarks(int no)throws IllegalNumException
 {
  if(no%2!=0)
  {
   IllegalNumException ime=new IllegalNumException(no);
   throw ime;
  }
 
 }
 

}

class IllegalNumException extends Exception
{   int no;
	IllegalNumException()
	{}
	IllegalNumException(int no)
	{
		this.no=no;
	}
	
 public String toString()
 {return("InValid Number");
 }
}