#include<stdio.h>
#include<math.h>
int main()
{
	long m,i,j,a[10000],n,c;
	while(scanf("%ld",&n)>0)
	{
		a[0]=1;
		m=0;
		for(i=1;i<=n;i++)
		{
			c=0;
			for(j=0;j<=m;j++)
			{
				a[j]=a[j]*i+c;
				c=a[j]/10000;
				a[j]%=10000;
			}
			if(c>0)
			{
				m++;
				a[m]=c;
			}
		}
		printf("%ld",a[m]);
		for(i=m-1;i>=0;i--)
			printf("%4.4ld",a[i]);
		printf("\n");
	}
	return 0;
}
