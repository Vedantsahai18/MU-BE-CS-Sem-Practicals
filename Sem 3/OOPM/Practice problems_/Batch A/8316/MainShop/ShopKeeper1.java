package MainShop;
import java.util.Scanner;

public class ShopKeeper1 extends Shop1{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num =1;
		
		while(num==1)
		{
			System.out.println("1:Add Customer Details\n2:Number of customers who purchased 'Samsung' Product\n3:Details of all the Products Purchased\n4:EXIT");
			int ch=in.nextInt();
			
			switch(ch)
			{
			case 1: addCustomer();
					break;
					
			case 2: findProduct();
					break;
					
			case 3: allDetails();
					break;
					
			case 4: System.out.println("THANK YOU");
					num=0;
					break;
			}
		}
	}
}
