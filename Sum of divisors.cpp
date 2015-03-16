#include <stdio.h>
#include <math.h>
int main()
{
	int n,m,a[100];
	while (~scanf("%d%d",&n,&m))
	{
		int s=0;
		for (int i=1;i<=sqrt(n);i++)
		{
			if (n % i ==0)
			{
				int k=i;
				while (k)
				{
					s+=((k % m)*(k % m));
					k/=m;
				}
				if (i*i!=n)
				{ 
					k=n / i;
					while (k)
					{
						s+=((k % m)*(k % m));
						k/=m;
					}
				}
			}
		}
		int t=0;
		while (s)
		{
			a[t++]=s % m;
			s/=m;
		}
		t--;
		for (int i=t;i>=0;i--)
		if (a[i]>9) printf("%c",a[i]-10+'A');
			else printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
