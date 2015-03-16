import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;
import java.io.*;

puplic class Main 
{
	puplic static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int m;
		m  = input.nextInt();
		while (m > 0)
		{
			m--;
			long n;
			n = input.nextLong();
			BigInteger ans = new BigInteger("1");
			BigInteger a = new BigInteger("1");
			for (long i = 1; i <= n; i++)
				a = a.multiply( BigInteger.valueOf(i));
			a = a.divide(BigInteger.valueOf(1024));
			ans = ans.add(a);
			ans = ans.add(b);
			System.out.println(ans);
		}
	}
}
