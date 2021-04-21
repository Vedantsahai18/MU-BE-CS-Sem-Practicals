import java.util.Scanner;

public class Frequency {
	public static void main(String[] args) {
		
	
		Scanner in = new Scanner(System.in);
		String st;
		int k=0;
	
		System.out.println("Enter the string:\n");
		st=in.nextLine();
		char[] ch= st.toCharArray();
		char[] check=new char[st.length()];
		
		for(int i=0;i<st.length();i++)
		{	int flag=0;
			int flag1=0;
			int count=1;
			char c=ch[i];
			
			
			for(int m=0;m<k;m++)
			{	
				if(ch[i]==check[m])
				{
					
					flag=1;
					break;
				}
			}
			
			if(flag==0) {
			for(int j=i+1;j<st.length();j++)
			{			
				if(flag==0 && c==ch[j] )
				{
					count++;	
				}
			}

			System.out.println("Frequency of "+c+" is "+count);
			
			check[k]=ch[i];
			k++;
			}
		}
	}
}
