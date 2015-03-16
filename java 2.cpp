import java.util.Scanner;  
import java.math.*;  
   
public class Main  
{  
    static final int N=2010;  
    static Scanner cin=new Scanner(System.in);  
    static BigInteger one=BigInteger.ONE,zero=BigInteger.valueOf(0);  
       
    static BigInteger xiaohao(BigInteger n,BigInteger m)  
    {  
        BigInteger t;  
        while(m.compareTo(zero)!=0)  
        {  
            t=n.mod(m);  
            n=m;  
            m=t;  
        }  
        return n;  
    }  
       
    public static void main(String[] args)  
    {  
        int T;  
        int n;  
        BigInteger m,gcd;  
        T=cin.nextInt();  
        while(T!=0)  
        {  
            m=cin.nextBigInteger();  
            n=cin.nextInt();  
            BigInteger xh=one;  
            for(int i=1;i<n;i++)  
                xh=xh.multiply(m);  
            gcd=xiaohao(xh,BigInteger.valueOf(n));  
            xh=xh.divide(gcd);  
            m=BigInteger.valueOf(n).divide(gcd);  
            System.out.println(m+"/"+xh);  
            T--;  
        }  
    }  
   
}
