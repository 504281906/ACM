#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
long long extgcd(long long a, long long b, long long &x, long long &y)
{
	long long d, t;
	if (b == 0) { x = 1; y = 0;	return a; }
	d = extgcd(b, a % b, x, y);
	t = x - a / b * y; x = y; y = t;
	return d;
}

int main()
{
	long long a,b,c,k;
	int i;
	long long s[35];
	s[0]=1;
	for (i=1;i<33;i++)
		s[i]=s[i-1]*2;
	while (~scanf("%lld%lld%lld%lld",&a,&b,&c,&k) && (a+b+c+k))
	{
		long long X,Y;
		long long d = extgcd(c,  s[k], X, Y); long long r = s[k] / d;
		if ((b-a) % d) printf("FOREVER\n");
		else cout << ((b-a) / d * X % r + r) % r << endl;
	}
	return 0;
}
