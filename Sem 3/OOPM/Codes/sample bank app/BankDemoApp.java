package bankdemoapp;
public class BankDemoApp {
    public static void main(String[] args) {
        Bank b = new Bank("XYZ BANK LTD", "BANDRA-W");
        b.createCust(1, "CUST1", 1, 25000, 'C');
        b.createCust(2, "CUST2", 2, 55000, 'S');
        
        System.out.println("*** FIRST CUSTOMER CURRENT ACCOUNT WITH 25000***");
        b.cust[0].operateAcc("viewbal");
        System.out.println("*** DEPOSIT 30000***");
        b.cust[0].operateAcc("depo", 30000);
        b.cust[0].operateAcc("viewbal");
        System.out.println("*** WITHDRAW MONEY 10000***");
        b.cust[0].operateAcc("wdm", 10000);
        b.cust[0].operateAcc("viewbal");
        b.displayAllCust();
        
    }
    
}
