#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
long long gcd(long long a,long long b)
{
	if (b==0) return a;
		else return gcd(b,a % b);
}
int main()
{
	long long k,x,y,m,n,l;
	while (~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l))
	{
		map<long long ,long long>mp;
		mp.clear();
		if (x>y)
		{
			long long t=x;
			x=y;
			y=x;
			t=m;
			m=n;
			n=t;
		}
		if (m%l==n%l)
		{
			printf("Impossible\n");
			continue;
		}
		if (m>n)
			k=y-x;
		else if (m<n)
			k=l-y+x;
		/*if (( (n+y) % 2 != (x+m)%2) && l % 2==0) 
		{
			printf("Impossible\n");
			continue;
		}*/
		long long t=0;int ff=0;
		do
		{
			mp[x]=y;
			x=(x+m)%l+1;
			y=(y+n)%l+1;
			if (mp[x]==y) 
			{
				ff=1;
				break;
			}
			t++;
		}while (x!=y);
		if (ff) printf("Impossible\n");
		else 
		printf("%lld\n",t);
	}
	return 0;
}
