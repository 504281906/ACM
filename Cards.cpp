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
__int64 a,b;
void solve()
{
	__int64 i,j,x,y;
	__int64 k=0;
	__int64 ans=a*a-b*b;
	for (i=2;i<=b;i++)
	{
		if (i-1>a) continue;
		x=b%i;
		y=i-x;
		__int64 s=y*(b/i)*(b/i)+x*(b/i+1)*(b/i+1);
		s=i-s-2+(a-i+2)*(a-i+2);
		if (s>ans)
		{
			k=i;
			ans=s;
		}
	}
	printf("%I64d\n",ans);
	x=b%k;
	y=k-x;
	if (k==0)
	{
		for (i=0;i<a;i++)
			printf("o");
		for (i=0;i<b;i++)
			printf("x");
	}
	else
	{
		for (i=1;i<=k;i++)
		{
			if (i<=x)
				for (j=1;j<=b/k+1;j++)
					printf("x");
			else 
				for (j=1;j<=b/k;j++)
					printf("x");
			if (i+1<=k)
			if (i==1)
				for (j=1;j<=a-k+2;j++)
					printf("o");
			else printf("o");
		}
	}
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	while(~scanf("%I64d%I64d",&a,&b))
	{
		solve();
		printf("\n");
	}
	return 0;
}
