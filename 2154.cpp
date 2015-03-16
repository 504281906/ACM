#include <stdio.h>
int main()
{
	int n,i;
	int a[1001],b[1001];
	while (scanf("%d",&n)!=EOF && n)
	{
		a[0]=1;
		for(i=1;i<=n;i++)
		{
			a[i]=(b[i-1]+b[i-1])%10000;
			b[i]=(a[i-1]+b[i-1])%10000;
		}
  		printf("%d\n",a[n]);
	}
	return 0;
}
