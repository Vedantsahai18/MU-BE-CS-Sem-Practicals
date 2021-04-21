import java.util.ArrayList;
import java.util.Scanner;

public class Shop {
    String brand;
    int id;
    static int unid=1;
    String product;
    double cost;
    Shop(String brand,String product,double cost)
    {
        this.brand=brand;
        this.product=product;
        this.cost=cost;
        id=unid;
        unid++;
    }
    void enter()
    {
        System.out.println("Enter Brand Name:-");
        Scanner sc=new Scanner(System.in);
        brand=sc.next();
        System.out.println("Enter Product:-");
        product=sc.next();
        System.out.println("Enter Cost:-");
        cost=sc.nextDouble();
    }
    void display()
    {
        System.out.println("ID:-"+this.id);
        System.out.println("Brand:-"+this.brand);
        System.out.println("Product:-"+this.product);
        System.out.println("Cost:-"+this.cost);

    }
}
class demoShop
{
    private final static ArrayList<Shop>prod=new ArrayList<>();
    public static void main(String[] args)
    {
        int choice;
        boolean flag=true;
        int no=0;
        Scanner sc=new Scanner(System.in);
        while(flag) {
            System.out.println("1. To add a product");
            System.out.println("2. To display all product with brand Samsung");
            System.out.println("3. To Exit");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    Shop s = new Shop("Samsung", "TV", 1000.0);
                    s.enter();
                    prod.add(s);
                    break;
                case 2:
                    for (Shop p : prod) {
                        if (p.brand.equalsIgnoreCase("Samsung")) {
                            p.display();
                            no++;
                        }
                    }

                    System.out.println("The Number of Samsung products sold:-"+no);
                    no=0;
                    break;
                case 3:
                    flag=false;
                    break;
                default:
                    System.out.println("Wrong Choice!!");

            }
        }
    }
}
