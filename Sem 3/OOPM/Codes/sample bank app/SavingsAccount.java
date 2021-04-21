package bankdemoapp;
class SavingsAccount extends Account
{
    /* *** VARIABLES OF SAVINGS ACCOUNT *** */
    int roi;
        
    /* *** METHODS OF SAVINGS ACCOUNT *** */
    SavingsAccount(int accid, float amt, int roi)
    {
        super(accid, amt);
        this.roi = roi;
    }
    public boolean wdm(float amt) /* ***   OVERRIDDEN METHOD *** */ 
    {
        if((bal - amt)>0)
        {
                bal = bal-amt;
                return true;
        }
        else 
            return false;
    }
    public void updateBal()
    {
        bal = bal + (bal * roi)/100;
    }
    
}

