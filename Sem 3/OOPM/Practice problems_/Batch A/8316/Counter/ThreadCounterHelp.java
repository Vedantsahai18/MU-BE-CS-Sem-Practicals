package Counter
public class ThreadCounterHelp implements Runnable {

	public void run()
	{
		for(int i=1;i<=50;i++)
		{
			if(i%2==1)
				System.out.println(i);
			try {
				Thread.sleep(1000);
			} catch (Exception e) {
				System.out.println(e);
			}
		}
		
	}
}


