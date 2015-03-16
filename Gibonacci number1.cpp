#include <stdio.h>
int main()
{
	int a[25],b[25];
	int t,i,j,k,s;
	scanf("%d",&t);
	a[1]=1;a[2]=1;
	for (i=3;i<=20;i++)
		a[i]=a[i-1]+a[i-2];
	b[1]=0;b[2]=1;
	for (i=3;i<=20;i++)
		b[i]=b[i-1]+b[i-2];
	while (t--)
	{
		scanf("%d%d%d",&k,&s,&j);
		double x=(s-b[k])*1.00/a[k];
		if (x>=1 && ((x-(int)x) < 1e-15 || (x-(int)x) > 0.999999999999999 )) 
		{
			long long max=a[j]*x+b[j]; 
			printf("%lld\n",max);
		}			
		else printf("-1\n");
	}
	return 0;
} 
