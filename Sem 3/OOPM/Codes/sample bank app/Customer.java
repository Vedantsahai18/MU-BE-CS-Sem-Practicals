package bankdemoapp;
class Customer
{
    /* *** VARIABLES OF CUSTOMER *** */
    int custid;
    String custname;
    Account a;
    
    /* *** METHODS OF CUSTOMER *** */
    Customer(int custid, String custname)
    {
        this.custid=custid;
        this.custname=custname;
    }
    void setAccount(Account a)
    {
        this.a = a;
    }
    void operateAcc(String oper, float amt)
    {
        if(oper.equals("depo"))
            a.deposit(amt);
        if(oper.equals("wdm"))
            a.wdm(amt);
    }
    void operateAcc(String oper)
    {
        if(oper.equals("viewbal"))
            a.viewBal();
    }
    void displayCust()
    {
        System.out.println("CUST ID:" + custid + "  CUST NAME: " + custname + "ACC ID: " + a.accid);
    }
}
