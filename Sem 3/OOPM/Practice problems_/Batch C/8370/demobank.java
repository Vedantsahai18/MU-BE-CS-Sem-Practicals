import java.util.*;
abstract class Account{
    long id;
    int pin;
    String acc_handler;
    double bal;
    Account(long id,int pin,String acc_handler,double bal){
        this.id=id;
        this.pin=pin;
        this.acc_handler=acc_handler;
        this.bal=bal;
    }
    abstract public void display();
    abstract public void enter();
}
class Saving extends Account{
    int transactions;
    Saving(long id,int pin,String acc_handler,double bal,int transactions){
        super(id,pin,acc_handler,bal);
        this.transactions=transactions;
    }
    public void enter(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter ID:-");
        id=sc.nextLong();
        System.out.println("Enter pin:-");
        pin=sc.nextInt();
        System.out.println("Enter Account handler's name:-");
        acc_handler=sc.next();
        System.out.println("Enter Balance:-");
        bal=sc.nextDouble();
        System.out.println("Enter Transactions:-");
        transactions=sc.nextInt();
    }
    public void display(){
        System.out.println("ID      Account Handler     Balance     Transactions");
        System.out.println(id+"     "+acc_handler+"          "+bal+"          "+transactions);
    }
}
class Current extends Account{
    double min_bal;
    Current(long id,int pin,String acc_handler,double bal,double min_bal){
        super(id,pin,acc_handler,bal);
        this.min_bal=min_bal;
    }
    public void enter()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter ID:-");
        id=sc.nextLong();
        System.out.println("Enter pin:-");
        pin=sc.nextInt();
        System.out.println("Enter Account handler's name:-");
        acc_handler=sc.next();
        System.out.println("Enter Balance:-");
        bal=sc.nextDouble();
        System.out.println("Enter minimum balance:-");
        min_bal=sc.nextDouble();

    }
    public void display(){
        System.out.println("ID      Account Handler     Balance     Minimum Balance");
        System.out.println(id+"     "+acc_handler+"             "+bal+"          "+min_bal);
    }
}
class ECSpayment{

    void trans_current_to_current(Current c1,Current c2,double val){
        if(c1.bal<c1.min_bal)
        {
            //Considering an extra fee of 50 Rs per transaction.
            c1.bal=c1.bal-val-50;
            c2.bal=c2.bal+val;
        }
        else
        {
            c1.bal=c1.bal-val;
            c2.bal=c2.bal+val;
        }
        c1.display();
        c2.display();
    }
    void trans_current_to_saving(Current c,Saving s,double val){
        if(c.bal<c.min_bal)
        {
            //Considering an extra fee of 50 Rs per transaction.
            c.bal=c.bal-val-50;
            s.bal=s.bal+val;
        }
        else
        {
            c.bal=c.bal-val;
            s.bal=s.bal+val;
        }
        c.display();
        s.display();
    }
    void trans_saving_to_saving(Saving s1,Saving s2,double val){
        s1.transactions++;
        if(s1.transactions<=6)
        {
            s1.bal=s1.bal-val;
            s2.bal=s2.bal+val;

        }
        else
        {
            int perc=5;
            double extra;
            extra=0.05*val;
            s1.bal=s1.bal-val-extra;
            s2.bal=s2.bal+val;
        }
        s1.display();
        s2.display();
    }
    void trans_saving_to_current(Current c,Saving s,double val){
        s.transactions++;
        if(s.transactions<=6)
        {
            s.bal=s.bal-val;
            c.bal=c.bal+val;

        }
        else
        {
            int perc=5;
            double extra;
            extra=0.05*val;
            s.bal=s.bal-val-extra;
            c.bal=c.bal+val;
        }
        s.display();
        c.display();
    }
}
class demobank{
    private final static ArrayList<Current> C=new ArrayList();
    private final static ArrayList<Saving> S=new ArrayList();
    public static void main(String[] args){
        int choice;
        boolean flag=true,found=false;
        long id1,id2;
        while(flag){
            System.out.println("1. To add a saving account");
            System.out.println("2. To add a current account");
            System.out.println("3. To make a transaction from current account to current account");
            System.out.println("4. To make a transaction from savings account to saving account account");
            System.out.println("5. To make a transaction from current account to saving account");
            System.out.println("6. To make a transaction from savings account to current account");
            System.out.println("7. To Exit");
            Scanner sc=new Scanner(System.in);
            choice=sc.nextInt();
            switch(choice){
                case 1:
                    Saving s=new Saving(1,0000,"ABC",100000.0,0);
                    s.enter();
                    S.add(s);
                    break;
                case 2:
                    Current c=new Current(1,0000,"ABC",100000.0,1000.0);
                    c.enter();
                    C.add(c);
                    break;
                case 3:

                        System.out.println("Enter ID of the sender:-");
                        id1=sc.nextLong();
                        System.out.println("Enter ID of the receiver:-");
                        id2=sc.nextLong();
                        for(Current C1:C)
                        {
                            for(Current C2:C)
                            if(C1.id==id1){
                                if(C2.id==id2){
                                    double i;
                                    System.out.println("Enter Amount to be transferred :-");
                                    i=sc.nextDouble();
                                    ECSpayment E=new ECSpayment();
                                    E.trans_current_to_current(C1,C2,i);
                                    found=true;
                                }

                            }
                        }
                        break;
                case 4:
                    System.out.println("Enter ID of the sender:-");
                    id1=sc.nextLong();
                    System.out.println("Enter ID of the receiver:-");
                    id2=sc.nextLong();
                    for(Saving s1:S) {
                        for (Saving s2 : S) {
                            if (s1.id == id1) {
                                if (s2.id == id2) {
                                    double i;
                                    System.out.println("Enter Amount to be transferred :-");
                                    i = sc.nextDouble();
                                    ECSpayment E = new ECSpayment();
                                    E.trans_saving_to_saving(s1, s2, i);
                                    found = true;
                                    break;
                                }
                            }
                        }
                        if(found==true)
                            break;
                    }
                    break;
                case 5:
                    System.out.println("Enter ID of the sender:-");
                    id1=sc.nextLong();
                    System.out.println("Enter ID of the receiver:-");
                    id2=sc.nextLong();
                    for(Current c1:C)
                    {
                        for(Saving s1:S)
                        {
                            if(c1.id==id1)
                            {
                                if(s1.id==id2)
                                {
                                    double i;
                                    System.out.println("Enter Amount to be transferred :-");
                                    i=sc.nextDouble();
                                    ECSpayment E=new ECSpayment();
                                    E.trans_current_to_saving(c1,s1,i);
                                    found=true;
                                    break;
                                }

                            }
                        }
                        if(found==true)
                        {
                            break;
                        }
                    }
                    break;
                case 6:
                    System.out.println("Enter ID of the sender:-");
                    id1=sc.nextLong();
                    System.out.println("Enter ID of the receiver:-");
                    id2=sc.nextLong();
                    for(Saving s1:S)
                    {
                        for(Current c1:C)
                        {
                            if(s1.id==id1)
                            {
                                if(c1.id==id2)
                                {
                                    double i;
                                    System.out.println("Enter Amount to be transferred :-");
                                    i=sc.nextDouble();
                                    ECSpayment E=new ECSpayment();
                                    E.trans_saving_to_current(c1,s1,i);
                                    found=true;
                                    break;
                                }
                            }
                        }
                        if(found==true)
                        {
                            break;
                        }
                    }
                    break;
                case 7:
                    flag=false;
                    break;
                default:
                    System.out.println("Wrong Choice!!");
            }
        }
    }
}