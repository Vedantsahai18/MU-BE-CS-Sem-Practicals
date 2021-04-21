package bankdemoapp;

class Bank {
    /* *** VARIABLES OF BANK *** */
    String bankname;
    String branch;
    Customer[] cust;  /* *** ARRAY OF OBJECTS *** */
    static int count=0;
    
    /* *** METHODS OF BANK *** */
    Bank(String bankname, String branch)
    {
        this.bankname = bankname;
        this.branch = branch;
        cust = new Customer[10];
    }
    
    public Customer createCust( int custid, String custname, int accid, float amt, char acctype)
    {
        Account a;
        if(acctype == 'C')
            a = new CurrentAccount(accid, amt, 10000, 1000);
        else
            a = new SavingsAccount(accid, amt, 5);
        
        Customer c = new Customer(custid, custname);
        c.setAccount(a); /***  CUSTOMER'S ACCOUNT ASSOCIATION ***/
        a.setCustomer(c); /*** ACCOUNT'S CUSTOMER ASSOCIATION ***/
        
        cust[count++]=c;  /*** AGGREGATION WITH ARRAY OF OBJECTS ***/
                        /*** ONE CUSTOMER IS CREATED FOR THE BANK ***/
        return c;
    }
    
    public void displayAllCust()
    {
        for(int i=0; i<cust.length;i++)
            if(cust[i] != null)
                cust[i].displayCust();
    }
}

