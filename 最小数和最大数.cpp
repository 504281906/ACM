#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long a[110];
int main()
{
	long n,i,k,s=0;
	while (~scanf("%lld",&n))
	{
		s=0;
		for (int i=0;i<n;i++)
		{
			scanf("%lld",&k);
			s+=k;
		}
			sort(a,a+n);
		printf("%lld\n",s);
	}
	return 0;
}
