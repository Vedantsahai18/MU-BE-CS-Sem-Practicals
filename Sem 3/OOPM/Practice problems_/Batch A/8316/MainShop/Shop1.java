package MainShop;
import java.util.LinkedList;
import java.util.Scanner;

public class Shop1 {
	public static LinkedList<String[]> customer = new LinkedList<String[]>();
	
	static void addCustomer()
	{
		
		Scanner in= new Scanner(System.in);
		String[] s = new String[3];
		System.out.println("Enter the product:");
		String p = in.nextLine();
		System.out.println("Enter the Brand Name:");
		String pb = in.nextLine();
		System.out.println("Enter the cost");
		String pc = in.nextLine();
		
		s[0]=p;
		s[1]=pb;
		s[2]=pc;
		
		customer.add(s);
		
	}
	
	static void findProduct()
	{
		System.out.println("**********SAMSUNG**********");
		int count=0;
		for(int i=0;i<customer.size();i++)
		{
			String[] s = new String[3];
			s= customer.get(i);
			if(s[1].equalsIgnoreCase("Samsung"))
			{
				count++;
			}
		}
		System.out.println("The number of Samsung Products purchased are : "+count);
	}
	
	static void allDetails()
	{
		double total=0;
		System.out.println("**********ALL DETAILS**********");
		for(int i=0;i<customer.size();i++)
		{
			String[] s = new String[3];
			s= customer.get(i);
			total = total + Double.parseDouble(s[2]);
			System.out.println("Product: "+s[0]+" Product Brand:"+s[1]+" Product Cost: RS "+s[2]);
		}
		System.out.println("TOtal Cost of Products sold: "+total+"\n");
		
	}
}
