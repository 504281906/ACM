#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	long long a,b;
	while (~scanf("%lld%lld",&a,&b))
	{
		printf("%lld\n",gcd(a,b));
	}
	return 0;
}

