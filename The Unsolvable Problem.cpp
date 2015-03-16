#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	return (b==0?a:gcd(b,a%b));
}
int main()
{
	int n,T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		__int64 k=n/2;
		__int64 s;
		while (gcd(k,(n-k))!=1) k--;
		s=k*(n-k);
		printf("%I64d\n",s);
	}
	return 0;
} 
