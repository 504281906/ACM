#include <stdio.h>
int main()
{
	long long n,m;
	while (~scanf("%lld%lld",&n,&m) && (n+m))
	{
		if (n<m) 
		{
			long long t=n;
			n=m;
			m=t;
		}
		long long t=n-m+1; 
		long long s=m*(m-1)*n+n*(n-1)*m+2*t*m*(m-1);//横纵加上斜多的 
		for (long long i=2;i<m;i++)
		s+=4*i*(i-1);
		printf("%lld\n",s); 
	} 
	return 0;
}
