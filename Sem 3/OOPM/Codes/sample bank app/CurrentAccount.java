package bankdemoapp;
public class CurrentAccount extends Account
{
    /* *** VARIABLES OF CURRENT ACCOUNT *** */
    int minbal;
    int penaulty;
    
    /* *** METHODS OF CURRENT ACCOUNT *** */
    CurrentAccount(int accid, float amt, int minbal, int penaulty)
    {
        super(accid, amt);
        this.minbal = minbal;
        this.penaulty = penaulty;
    }
    public boolean wdm(float amt) /* ***   OVERRIDDEN METHOD *** */ 
    {
        if((bal - amt)>0)
        {
            if((bal-amt)>=minbal)
            {
                bal = bal-amt;
                return true;
            }
            else if(bal-amt-penaulty>0)
            {
                bal = bal-amt-penaulty;
                return true;
            }
            else
                return false;
        }
        else 
            return false;
    }
    
}
