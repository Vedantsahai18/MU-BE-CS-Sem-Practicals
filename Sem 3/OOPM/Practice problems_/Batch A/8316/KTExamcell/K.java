package KTExamcell; 
import java.util.Scanner;

public class K extends KTStudent{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num =1;
		
		while(num==1)
		{
			System.out.println("1:Add Student\n2:Students in a particular Subject\n3:EXIT");
			int ch =in.nextInt();
			switch(ch)
			{
			case 1: addStudent();
					break;
					
			case 2: studentMarks();
					break;
					
			case 3: num=0;
					break;
					
			default: System.out.println("Wrong Choice");
					 break;
			}
		}
	}
}
