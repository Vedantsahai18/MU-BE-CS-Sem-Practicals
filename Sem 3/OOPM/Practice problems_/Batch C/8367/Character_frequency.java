import java.util.*;


public class Character_frequency {

	int i=0,count=0;
	char ch;
	String test;
	
	Character_frequency(String test,char ch){
		this.ch=ch;
		this.test=test;
	}
	
	int count_iterations(){
		while(i<test.length()){
			if(ch==test.charAt(i))
				count++;
			i++;
		}
		return count;
	}
	
	void Display(int x){
		if(x==0)
			System.out.println("The character is not present in the string!");
		else
			System.out.println("The frequency of " + ch + " is:" + x);
	}
	
}

class Demo{
	public static void main(String[] args){
		String test;
		char ch;
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter any String: ");
		test=sc.nextLine();
		System.out.print("Enter the character of your choice:");
		ch=sc.next().charAt(0);
		
		Character_frequency c=new Character_frequency(test,ch);
		
		c.Display(c.count_iterations());
		
	}
}