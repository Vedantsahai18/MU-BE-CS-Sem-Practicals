import java.util.Scanner;

class InvalidNumException extends Exception
{
	InvalidNumException()
	{}
	public String toString()
	{
		return "InValid Number";
	}
}
public class ExceptionNumber {
	public static void main(String[] args) {
		try
		{
			Scanner in =new Scanner(System.in);
		
			System.out.println("Enter an even number:\n");
			int n = in.nextInt();
			System.out.println();
			if(n%2!=0) throw new InvalidNumException();
			System.out.println("THANK YOU");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
