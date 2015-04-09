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
//#define DEBUG
long long ab(long long a,long long b)
{
	return a*b*(a-1)*(b-1)/4;
}
long long br(long long b,long long r)
{
	return b*r*(r-1)/2;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if (n>m)
		{
			int t=n;
			n=m;
			m=t;
		}
		long long a,b,max=0;
		int j=ceil(sqrt((double)k));
		if (j>n) j=n;
		for (a=2;a<=j;a++)
		{
			long long r=k % a;
			b=(k-r)/a;
			if (b>m) continue;
			long long s=ab(a,b);
			if (r>=2)
			{
				int t=b;
				if ((b==m && a<n) || (a<n && a>b && r<b))
					t=a;
				s+=br(t,r);
			}
			if (max<s) max=s;
		}
		printf("Case #%d: %lld\n", cas, max);
	}
	return 0;
}
