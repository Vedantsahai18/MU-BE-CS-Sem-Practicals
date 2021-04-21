import java.util.*;


	

class Sync{
	
	static String smessage;	
	public synchronized static void Sending(String message){
	
		System.out.println("Sending......"+message);		
	}

	public synchronized static void Receiving(){
	
		System.out.println("Receiving...."+smessage);
	}



	public static void main(String args[]){
	
		Thread p = new Thread(new Runnable(){
			
			public void run(){
				Scanner s= new Scanner(System.in);
				System.out.println("Enter message to send\n");
				smessage = s.next();
				Sending(smessage);
		}
		});
		Thread c = new Thread(new Runnable(){	
			public void run(){
			try{
				Thread.sleep(5000);
			}
			catch(InterruptedException e){
				e.printStackTrace();
			}
			Receiving();
		}
		});
		
		p.start();
		c.start();
		
	try{
		p.join();
		c.join();
		
	}
	catch(InterruptedException e){
		e.printStackTrace();
	}
	
	}
}

/*-----OUTPUT---------
Enter message to send
Aman
Sending......Aman
Receiving....Aman