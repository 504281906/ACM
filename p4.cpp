#include <stdio.h>
#include <string.h>
long max(long x,long y) 
{ 
long z; 
while(x%y!=0) 
{ 
   z=x%y; 
   x=y; 
   y=z; 
} 
return(y); 
}
int main()
{
	long max(long x,long y);
	char s[20];
	long t,a,b,l,f,i,k1,j,k;
	scanf("%ld",&t);
	while (t--)
	{
		scanf( "%s", s );
		a=0;b=0;k=0;k1=0;
		l=strlen(s);
		for (i=2;i<l;i++)
		  if (s[i]!='(')
		   {
				a=a*10+s[i]-'0';
				k++;
		   }
		  else 
		   {
				for (j=i+1;j<l-1;j++)
				  {
						b=b*10+s[j]-'0';
						k1++;
			      }
				  break;
		   }
		if (k==0) 
		{
			a=0;
			for (i=1;i<=k1;i++)
			  a=a*10+9;
			f=max(a,b);
			printf("%ld/%ld\n",b/f,a/f);
	    }
	    else if (k1==0)
	    {
			b=1;
			for (i=1;i<=k;i++)
			 b*=10;
			f=max(a,b);
			printf("%ld/%ld\n",a/f,b/f);
		}
		else 
		{
			long x=1,x1=1,x2;
			for (i=1;i<=k1;i++)
			 x*=10;
			for (i=1;i<=k;i++)
			 x1*=10;
			 b=x*a+b;
			 x2=x*x1;			
			f=max(x2-x1,b-a);
			printf("%ld/%ld\n",(b-a)/f,(x2-x1)/f);
		}
	}
	return 0;
}
