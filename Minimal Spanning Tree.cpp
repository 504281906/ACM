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
const LL M=2333333;
const LL INF=0x7fffffff;
#define max(a,b) a>b?a:b
struct node
{
	LL x,y;
}a[10000010];
int vis[10000010];
LL n,m,i,j;
int cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	while(~scanf("%I64d%I64d",&n,&m))
	{
		LL x=m;
		for (i=1;i<=n;i++)
		{
			vis[i]=0;
			a[i].x=INF;
			a[i].y=0;
		}
		for (i=2;i<=n;i++)
		{
			x=(x * 907) %M;
			LL t=x;
			for (j=max(1,i-5);j<=i-1;j++)
			{
				x=(x * 907) %M;
				LL w=x ^ t;
				if (a[i].x>w)
				{
					a[i].x=w;
					a[i].y=j;
				}
				if (a[j].x>w)
				{
					a[j].x=w;
					a[j].y=i;
				}
			}
		}
		LL ans=0;
		sort(a+1,a+1+n,cmp);
		for (i=1;i<=n;i++)
			if (!vis[i])
			{
				vis[a[i].y]=1;
				ans+=a[i].x;
			}
		cout<<ans<<endl;
	}
	return 0;
}
