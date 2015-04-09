#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL long long
class SquareDivisor
{
	public:
		long long biggest(long long x)
		{
			long long ans=1;
			for (long long i=2;i<=100000 && i<=x;i++)
			{
				LL k=i*i;
				while (x % k==0)
				{
					x/=k;
					ans*=k;
				}
				if (x % i==0) x/=i;
			}
			LL r=sqrt(double(x));
			if (r*r==x) ans*=x;
			return ans;
		}
}m;
//LL SquareDivisor::biggest();

int main()
{
	LL n;
	scanf("%lld",&n);
	cout<<m.biggest(n)<<endl;
	return 0;
}
