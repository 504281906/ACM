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
#define ll long long
//#define DEBUG
struct node
{
	ll x,y;
}p[100010];
struct node1
{
	ll z1,z2;
}a[100010];
ll dis(ll x,ll y,ll x1,ll y1)
{
	return (x1-x)*(x1-x)+(y1-y)*(y1-y);
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	ll x1,y1,x2,y2,r1,r2;
	while (~scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2))
	{
		int n,i,j,m;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
			a[i].z1=dis(p[i].x,p[i].y,x1,y1);
			a[i].z2=dis(p[i].x,p[i].y,x2,y2);
		}
		scanf("%d",&m);
		for (i=1;i<=m;i++)
		{
			int k=0;
			scanf("%lld%lld",&r1,&r2);
			r1=r1*r1;
			r2=r2*r2;
			for (j=1;j<=n;j++)
				if (a[j].z1>=r1 && a[j].z2>=r2)
					k++;
			printf("%d\n",k);
		}
	}
	return 0;
}
