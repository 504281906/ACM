#include <stdio.h>
long long f[1000010],s;
int main()
{ 
	long long n,i,j;
	f[3]=0;f[4]=1;f[5]=3;
	for (i=6;i<=1000000;i++)
	{
		s=0;
		if ((i-3) % 2!=0)
		{
			s=(i-3)/2+1;
			j=s-1;
		}
		else j=(i-3)/2;
		s+=(1+j)*j;
		f[i]=f[i-1]+s;
	}
	while (~scanf("%lld",&n)&& (n>=3))
		printf("%lld\n",f[n]); 
	return 0;
}
