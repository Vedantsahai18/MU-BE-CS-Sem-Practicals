import java.util.LinkedList;
import java.util.Scanner;

public class AllEvents {
	public static LinkedList<String[]> event = new LinkedList<String[]>();
	

	
	
	static void addEvent()
	{
		String[] s = new String[5];
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the Date of the Event:");
		String dd = in.nextLine();
		System.out.println("Enter the Month of the Event:");
		String mm = in.nextLine();
		System.out.println("Énter the year of the Event:");
		String yy = in.nextLine();
		System.out.println("Enter the budget of the Event:");
		String budget = in.nextLine();
		System.out.println("Enter the place the Evemt is to be held:");
		String place = in.nextLine();
		
		s[0]= dd;
		s[1]= mm;
		s[2]= yy;
		s[3]= budget;
		s[4]= place;
		
		event.add(s);
		
	}
	
	static void deleteEvent()
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the date and the place of the event you want to delete:");
		String dd = in.nextLine();
		String place = in.nextLine();
		int n=event.size();
		for(int i=0;i<n;i++)
		{
			String[] s=event.get(i);
			if(s[0].equals(dd) && s[4].equals(place))
			{
				event.remove(i);
			}
		}
	}
	
	static void getBudget()
	{
		double total=0;
		int n=event.size();
		for(int i=0;i<n;i++)
		{
			String[] s = event.get(i);
			System.out.println("DATE: "+s[0]+"/"+s[1]+"/"+s[2]);
			System.out.println("DESTINATION: "+s[4]);
			System.out.println("BUDGET: "+s[3]);
			System.out.println("**********************");
		}
		
		for(int i=0;i<n;i++)
		{
			String[] s = event.get(i);
			total = total + Double.parseDouble(s[3]);	
		}
		System.out.println("The total Budget of all the events is:"+total);
	}
	
}
