#include <stdio.h>
#include <math.h>
int main()
{
	long s;
	int t,n,i;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);s=0;
		for (i=2;i<=sqrt(n);i++)
		{
		 if (n%i==0) 
		  if (i-n/i*1.0==0) s+=i;
		  else s+=i+n/i;
	    }
		printf("%ld\n",s+1);
	}
	return 0;
}
