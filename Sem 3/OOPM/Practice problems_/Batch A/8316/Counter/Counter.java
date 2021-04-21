package Counter;
public class Counter {
public static void main(String[] args) {
	

	ThreadCounterHelp n1 = new ThreadCounterHelp();
	ThreadCounterHelp2 n2 = new ThreadCounterHelp2();
	
	Thread t1 = new Thread(n1,"Thread 1");
	Thread t2 = new Thread(n2,"Thread 2");
	
	t1.start();
	t2.start();
	
	
	try {
		t2.join();
		t1.join();
		
	}
	catch(Exception e)
	{
		System.out.println(e);
	}
	System.out.println("*****DONE****");
}
}
