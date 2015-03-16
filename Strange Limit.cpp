#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[15];
int main()
{
	a[0]=1;
	int p,m,i;
	for (i=1;i<=12;i++)
		a[i]=a[i-1]*i;
	while (~scanf("%d%d",&p,&m))
	{
		long long s=p;
		int f=1;
		while (s<a[m] && f)
		{
			long long s1=s;
			s=p;
			for (i=1;i<=p;i++)
			{
				s*=s1;
				if (s>=a[m])
				{
					s=s % a[m];
					f=0;
				}
			}
		}
		printf("%lld\n",s % a[m]);
	}
	return 0;
} 
