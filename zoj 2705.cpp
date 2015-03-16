#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	long long n,m;
	int i;
	int f[50];
	f[1]=1;f[2]=2;
	for (i=3;i<=45;i++)
		f[i]=f[i-1]+f[i-2];
	while (~scanf("%lld%lld",&n,&m))
	{
		long long s;
		for (i=45;i>=1;i--)
		{
			if (n % f[i]==0 || m % f[i]==0)
			{
				s=f[i];
				break;
			}
		}
		printf("%lld\n\n",m*n-m*n/s);
	}
	return 0;
}
