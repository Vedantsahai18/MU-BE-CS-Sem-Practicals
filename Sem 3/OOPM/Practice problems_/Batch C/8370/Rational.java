import java.util.Scanner;

public class Rational {
    int m,n;
    Rational(int m,int n)
    {
        this.m=m;
        this.n=n;
    }
    //Arithmetic Operation of Addition
    void add(Rational R) {
        Rational res = new Rational(0, 0);
        res.m = (this.m * R.n + R.m * this.n);
        res.n = this.n * this.n;
        System.out.println("The sum of two Rational no.s:-");
        if(res.m%res.n==0)
        {
            int re=res.m/res.n;
            System.out.println(this.m + "/" + this.n + " + " + R.m + "/" + R.n + "="+re);
        }
        else
        {
            res.check();
            System.out.println(this.m + "/" + this.n + " + " + R.m + "/" + R.n + "=" + res.m + "/" + res.n);
        }
    }
    void check()
    {
        int i,flag=0;
        for(i=this.n-1;i>=1;i--)
        {
            if(this.m%i==0&&this.n%i==0) {
                flag = 1;
                break;
            }
        }
        if(flag==1)
        {
            this.m=this.m/i;
            this.n=this.n/i;
        }
    }
}
class demo
{
    public static void main(String[] args)
    {
        int a,b;
        System.out.println("Enter values of Rational no 1:");
        Scanner sc=new Scanner(System.in);
        a=sc.nextInt();
        b=sc.nextInt();
        if(a%b==0)
        {
            System.out.println("Not a rational no.");
            a=sc.nextInt();
            b=sc.nextInt();

        }
        Rational R1=new Rational(a,b);
        System.out.println("Enter values of Rational no 1:");
        a=sc.nextInt();
        b=sc.nextInt();
        Rational R2=new Rational(a,b);
        if(a%b==0)
        {
            System.out.println("Not a rational no.");
            a=sc.nextInt();
            b=sc.nextInt();
        }
        R1.add(R2);

    }
}
