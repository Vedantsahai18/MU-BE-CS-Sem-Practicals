import java.util.*;

class ProductItem
{
	private int id;
	private double price;
	ProductItem(int id,double price)
	{
		this.id=id;
		this.price=price;
	}
	double getPrice()
	{
		return price; //private members are accessed using non-private method
	}
	public String toString()
	{
		return "ID : "+id+"Price : "+price; //string representation of Product Item
	}
}
class ShoppingCart
{
	int custid;
	Vector itemsv;

	ShoppingCart(int custid)
	{
		this.custid=custid;
		itemsv=new Vector();
	}
	public void addItem(ProductItem item)
	{
		itemsv.add(item);
	}
	public void removeItem(ProductItem item)
	{
		itemsv.remove(item);
	}
	public void showAllItem()
	{
		for(int i=0;i<itemsv.size();i++)
		{
			ProductItem temp=(ProductItem)itemsv.get(i);
			System.out.println(temp);
		}
	}
	public double calculateAmt()
	{
		double amt=0.0;
		for(int i=0;i<itemsv.size();i++)
		{
			ProductItem temp=(ProductItem)itemsv.get(i);
			amt=amt+temp.getPrice();
		}
		return amt;
	}
}
public class ShoppingCartSimulation
{
	public static void main(String[] args)
	{
		
		ProductItem [] p = new ProductItem[11];//there are total 10 items , p[1] is first item

		populateItems(p);
		
		ShoppingCart sc=new ShoppingCart(1); //first shopping cart

		Scanner in = new Scanner(System.in);
		do
		{
			System.out.println("1.Add item \n2. Remove item \n3. Make final Payment");
			System.out.print("Enter your option:= ");
			int option = in.nextInt();
			switch(option)
			{
				case 1:
					System.out.println("Which item put in bag:= ");
					int item_no1 = in.nextInt();

					sc.addItem(p[item_no1]);

				break;
				case 2:
					System.out.println("Which item to remove from bag:= ");
					int item_no2 = in.nextInt();

					sc.removeItem(p[item_no2]);
				break;
				case 3:
					System.out.println("Printed Bill");
					sc.showAllItem();
					System.out.println("You have to make payment of "+sc.calculateAmt());
				
					System.exit(0); //leave the shop
			}	
		}while(true);		
	}

	static void populateItems(ProductItem [] h)
	{
		Scanner in = new Scanner(System.in);
		for(int i = 1 ; i < h.length; i++)
		{
			System.out.println("Enter price of a product item "+(i+1)+":= ");
			double price = in.nextDouble();
			h[i] = new ProductItem(i+1,price);
		}
	}
} 

