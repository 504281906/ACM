#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
int ans[100010];
long long b[100010];
int c[100010];
long long x1,x2,y1,y2;
int n,m,i,j;
struct node
{
	long long x,y;
}p[100010];
struct node1
{
	long long x,y,z;
}q[100010];
int low(int x)
{
	return x & (-x);
}
void add(int x)
{
	while (x<=n)
	{
		c[x]++;
		x+=low(x);
	}
}
int sum(int x)
{
	int s=0;
	while (x>0)
	{
		s+=c[x];
		x-=low(x);
	}
	return s;
}
int cmp1(node a,node b)
{
	return a.x>b.x;
}
int cmp2(node1 a,node1 b)
{
	return a.x>b.x;
}
int main()
{
	while (scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2)==4)
	{
		scanf("%d",&n);
		int t=0;
		memset(c,0,sizeof(c));
		for (i=0;i<n;i++)
		{
			long long x3,y3;
			scanf("%lld%lld",&x3,&y3);
			p[i].x=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
			p[i].y=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
			b[++t]=p[i].y;
		}
		sort(p,p+n,cmp1);
		sort(b+1,b+n+1);
		int h=unique(b+1,b+t+1)-b-1;
		scanf("%d",&m);
		for (i=0;i<m;i++)
		{
			long long r1,r2;
			scanf("%lld%lld",&r1,&r2);
			q[i].x=r1*r1;
			q[i].y=r2*r2;
			q[i].z=i;
		}
		sort(q,q+m,cmp2);
		t=0;
		for (i=0;i<m;i++)
		{
			while (t<n && p[t].x>=q[i].x)
			{
				int k=lower_bound(b+1,b+h+1,p[t].y)-b;
				add(k);
				t++;
			}
			int k=lower_bound(b+1,b+h+1,q[i].y)-b;
			ans[q[i].z]=sum(n)-sum(k-1);
		}
		for (i=0;i<m;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
