package Counter;
public class ThreadCounterHelp2 implements Runnable{
	public void run()
	{	
		for(int i=1;i<=50;i++)
		{
			if(i%2==0)
				System.out.println(i);
				try {
					Thread.sleep(1000);
					
				} catch (Exception e) {
					System.out.println(e);
				}
				
		}
	}
}
