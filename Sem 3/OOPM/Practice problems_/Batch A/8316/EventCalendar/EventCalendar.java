import java.util.Scanner;

public class EventCalendar extends AllEvents{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num =1;
		System.out.println("***********EVENT CONTROLLER**********");
		while(num==1)
		{
			System.out.println("1:Add Event\n2:Delete Event\n3:Display Total Budget\n4:EXIT");
			int n=in.nextInt();
			
			switch(n)
			{
			case 1: addEvent();
					break;
					
			case 2: deleteEvent();
					break;
					
			case 3: getBudget();
					break;
					
			case 4: num=0;
					break;
			}
		}
	}
}
