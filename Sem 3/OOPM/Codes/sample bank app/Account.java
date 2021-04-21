package bankdemoapp;


abstract class Account
{
    /* *** VARIABLES OF ACCOUNT *** */
    int accid;
    float bal;
    Customer c;
    
    /* *** METHODS OF CUSTOMER *** */
    Account(int accid, float bal)
    {
        this.accid=accid;
        this.bal=bal;
    }
    void setCustomer(Customer c)
    {
        this.c = c;
    }
    void deposit(float amt)
    {
        bal = bal + amt;
    }
    void viewBal()
    {
        System.out.println("BALANCE : " + bal);
    }
    void displayAcc()
    {
        System.out.println("ACC ID:" + accid + "  BAL: " + bal + "CUST ID: " + c.custid);
    }
    /* *** ABSTRACT METHOD IMPLEMENTED BY CURRENT AND SAVING ACCOUNT *** */
    abstract boolean wdm(float amt);  
}

