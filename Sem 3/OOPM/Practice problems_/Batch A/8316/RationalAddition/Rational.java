package RationalAddition;
public class Rational {
	public int num;
	public int deno;

	Rational(int num,int deno)
	{
		 this.num=num;
		 this.deno=deno;
	}
	
	void addRational(Rational r1,Rational r2)
	{
		num=(r1.num*r2.deno)+(r2.num*r1.deno);
		deno = r1.deno*r2.deno;
	}
	
	public String toString()
	{
		return num+"/"+deno;
		
	}
}
