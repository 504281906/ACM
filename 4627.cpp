#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
__int64 gcd(__int64 a,__int64 b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	__int64 T,n,i;
	scanf("%I64d",&T);
	while (T--)
	{
		scanf("%I64d",&n);
		__int64 ans=0;
		for (i=n/2;i>0;i--)
		{
			__int64 j=n-i;
			if (ans>i/gcd(i,j)*j) break;
			ans=i/gcd(i,j)*j;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
