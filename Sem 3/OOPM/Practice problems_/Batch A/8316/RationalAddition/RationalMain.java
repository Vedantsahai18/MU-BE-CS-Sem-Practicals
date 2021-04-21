package RationalAddition;
import java.util.Scanner;

public class RationalMain {
	public static void main(String[] args) {
		Rational r = new Rational(0,0);
		Scanner in =new Scanner(System.in);
		System.out.println("Enter The numerator and the denominator of the first Rational number: ");
		int num1= in.nextInt();
		int deno1 = in.nextInt();
		System.out.println("Enter The numerator and the denominator of the second Rational number: ");
		int num2 = in.nextInt();
		int deno2 = in.nextInt();
		
		Rational r1 = new Rational(num1,deno1);
		Rational r2 =new Rational(num2,deno2);
		
		r.addRational(r1, r2);
		
		System.out.println("Addition = "+r);
	}
}
