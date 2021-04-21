import java.util.*;
import java.lang.*;

public class InvalidNumException extends Exception {
	int x;
	InvalidNumException(int x){
		this.x=x;
	}
	
	public String Error(){
		return "Entered value is not an even number!";
	}

}

class Demo{
public static void main(String[] args){
		
		try{
			getmarks();
		}
		
		catch(InvalidNumException e){
			System.out.println(e.Error());
		}
	}

		
static void getmarks() throws InvalidNumException {
			
			Scanner sc=new Scanner(System.in);
			System.out.print("Enter an even number:");
			int x=sc.nextInt();
			
			if(x%2!=0){
					InvalidNumException e=new InvalidNumException(x);
					throw e;
			}
			else
				System.out.println("Input is: "+x);
			
		}
}
