#include <stdio.h>
#include <math.h>
#define P 3.1415926
int main()
{
	int t,n;
	double E;
	E=exp(1.0);
	scanf("%d",&t);
	while (t--)
	{
		int m;
		scanf("%d",&n);
		m=(int)(log10(sqrt(2*P*n))+n*log10(n/E));
		printf("%d\n",m+1);
	}
	return 0;
}
