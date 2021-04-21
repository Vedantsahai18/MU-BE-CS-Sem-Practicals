package KTExamcell;
import java.util.LinkedList;
import java.util.Scanner;

public class KTStudent {
	public static LinkedList<double[]> examCell = new LinkedList<double[]>();
	
	static void addStudent()
	{
		Scanner in = new Scanner(System.in);
		double[] s = new double[11];
		System.out.println("Enter the Roll Number:");
		s[0] = in.nextDouble();
		System.out.println("KT in maths?1:yes 2:no");
		s[1] = in.nextDouble();
		if(s[1]==1)
		{
			System.out.println("ENter marks in maths paper:");
			s[6]= in.nextDouble();
		}
		else {
			s[6]=0;
		}
		System.out.println("KT in OOPM?1:yes 2:no");
		s[2] = in.nextDouble();
		if(s[2]==1)
		{
			System.out.println("ENter marks in OOPM paper:");
			s[7]= in.nextDouble();
		}
		else {
			s[7]=0;
		}
		System.out.println("KT in CO?1:yes 2:no");
		s[3] = in.nextDouble();
		if(s[3]==1)
		{
			System.out.println("ENter marks in CO paper:");
			s[8]= in.nextDouble();
		}
		else {
			s[8]=0;
		}
		System.out.println("KT in DLDA?1:yes 2:no");
		s[4] = in.nextDouble();
		if(s[4]==1)
		{
			System.out.println("ENter marks in DLDA paper:");
			s[9]= in.nextDouble();
		}
		else {
			s[9]=0;
		}
		System.out.println("KT in ECCF?1:yes 2:no");
		s[5] = in.nextDouble();
		if(s[5]==1)
		{
			System.out.println("ENter marks in ECCF paper:");
			s[10]= in.nextDouble();
		}
		else {
			s[10]=0;
		}
		
		examCell.add(s);
	}
	
	static void studentMarks()
	{
		Scanner in =new Scanner(System.in);
		System.out.println("Which Subject Details you Want to enquire about?");
		System.out.println("1:Maths 2:OOPM 3:CO 4:DLDA 5:ECCF");
		int n=in.nextInt();
		int count=0;
		switch(n)
		{
		case 1: for(int i=0;i<examCell.size();i++)
				{
					double[] d=examCell.get(i);
					if(d[1]==1)
					{
						count++;
						System.out.println("ROLL NUMBER: "+d[0]+" MATHS MARKS: "+d[6]);
					}
				}
				System.out.println("Number of students appeared for this Paper: "+count);
				break;
		case 2:  for(int i=0;i<examCell.size();i++)
				{
					double[] d=examCell.get(i);
					if(d[2]==1)
					{
						count++;
						System.out.println("ROLL NUMBER: "+d[0]+" MATHS MARKS: "+d[7]);
					}
				}
		System.out.println("Number of students appeared for this Paper: "+count);
				break;
		
		case 3:  for(int i=0;i<examCell.size();i++)
				{
					double[] d=examCell.get(i);
					if(d[3]==1)
					{
						count++;
						System.out.println("ROLL NUMBER: "+d[0]+" MATHS MARKS: "+d[8]);
					}
				}
		System.out.println("Number of students appeared for this Paper: "+count);
				break;
				
		case 4: for(int i=0;i<examCell.size();i++)
				{
					double[] d=examCell.get(i);
					if(d[4]==1)
					{
						count++;
						System.out.println("ROLL NUMBER: "+d[0]+" MATHS MARKS: "+d[9]);
					}
				}
		System.out.println("Number of students appeared for this Paper: "+count);
				break;
				
		case 5:  for(int i=0;i<examCell.size();i++)
				{
					double[] d=examCell.get(i);
					if(d[5]==1)
					{
						count++;
						System.out.println("ROLL NUMBER: "+d[0]+" MATHS MARKS: "+d[10]);
					}
				}
		System.out.println("Number of students appeared for this Paper: "+count);
				break;
				
		default: System.out.println("Wrong Choice");
					break;
		}
	}
}
