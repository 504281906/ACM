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
#define LL __int64
int main()
{
	LL n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if ((n-1)*(m-1)<k) printf("-1\n");
	else
	{
		if (n>m) 
		{
			n=n+m;
			m=n-m;
			n=n-m;
		}
		LL l=0,r=(n-1);
		if (r>k) r=k;
		LL max=0;
		if (max<n*(m/(k+1)) && (m-1>=k))
			max=n*(m/(k+1));
		while (l<r)
		{
			LL mid=(l+r)/2;
			LL mid1=(mid+r)/2; 
		/*	if (m-1<k-mid)
			{
				l=mid;
				continue;
			}*/
			LL h=0,h1=0;
			h=(n/(mid+1))*(m/(k-mid+1));
			h1=(n/(mid1+1))*(m/(k-mid1+1));
			if (h>=h1)
			{
				if (max<h)
					max=h;
				r=mid1;
			}
			else
			{
				if (max<h1)
					max=h1;
				l=mid;
			}
		}
		if (max==0) printf("-1\n");
		else
		printf("%I64d\n",max);
	}
	return 0;
}
