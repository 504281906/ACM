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
#define LL __int64
#define EPS 1e-8
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int cmp1(int x,int y)
{
	return x>y;
}
int a[100010],b[100010];
int main()
{
	int n,m,i;
	while (~scanf("%d%d",&n,&m))
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (i=0;i<m;i++)
			scanf("%d",&b[i]);
		if (n==0) 
		{
			puts("1");
			continue;
		}
		sort(a,a+n,cmp);
		sort(b,b+m,cmp1);
		int a1=0,b1=0;
		int ans=1;
		while (1)
		{
			ans--;
			for (i=0;i<a[a1];i++)
			{
				ans+=b[b1];
				b1++;
				if (b1==m) break;
			}
			a1++;
			if (a1==n || b1==m) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
