#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long oula(long long n)
{
	int i;
	long long ans=1;
	for (i=2;i*i<=n;i++)
	{
		if (n % i==0)
		{
			ans*=i-1;
			n/=i;
			while (n % i==0)
			{
				n/=i;
				ans*=i;
			}
		}
	}
	if (n>1) ans*=n-1;
	return ans;
}
int main()
{
	long long n;
	while (~scanf("%lld",&n) && n)
	{
		printf("%lld\n",oula(n));
	} 
	return 0;
}

