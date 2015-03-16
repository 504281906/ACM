import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;
import java.io.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		long t;
		t=input.nextInt();
		while (t>0)
		{
			t--;
			long n,i;
			n=input.nextInt();
			BigInteger s=new BigInteger("1");
			BigInteger a=new BigInteger("1");
			BigInteger b=new BigInteger("1");
			for (i=n-3;i<=n;i++)
				a=a.multiply(BigInteger.valueOf(i));
			a=a.divide(BigInteger.valueOf(24));
			for (i=n-1;i<=n;i++)
				b=b.multiply(BigInteger.valueOf(i));
			b=b.divide(BigInteger.valueOf(2));
			s=s.add(a);
			s=s.add(b);
			System.out.println(s);
		}
	}
}
