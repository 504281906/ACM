#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,s;
	int t,k,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		s=n*log10(n*1.0);
		a=modf(s,&b);
		int k=pow(10.0,a);
		printf("%d\n",k);
	}
	return 0;
}
