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
}a[100010],b[100010];
ll dis(ll x,ll y,ll x1,ll y1)
{
	return (x1-x)*(x1-x)+(y1-y)*(y1-y);
}
int cmp(node1 b1,node1 b)
{
	if (b1.z1<=b.z1)
		return 1;
	else return 0;
}
int cmp1(node1 b1,node1 b)
{
	if (b1.z2<=b.z2)
		return 1;
	else return 0;
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
			b[i].z1=a[i].z1;
			b[i].z2=a[i].z2;
		}
		sort(a+1,a+n,cmp);
		sort(b+1,b+n,cmp1);
		scanf("%d",&m);
		for (i=1;i<=m;i++)
		{
			int k=0;
			scanf("%lld%lld",&r1,&r2);
			r1=r1*r1;
			r2=r2*r2;
			int t=n/2;
			int l2=n,l1=1;
			int f=0;
			while (1)
			{
				if (a[t].z1<r1) 
				{
					l1=t;
					t=(t+l2)/2;
					if (!f) 
					{
						t+=1;
						f=0;
					}
					else f=1;
				}
				else
				if (a[t-1].z1<r1 && a[t].z1>=r1)
				{
					k=n-t+1;
					break;
				}
				else 
				{
					l2=t;
					t=(t+l1)/2;
				}
				if (t==n) break;
			}
			t=n/2;
			l1=1;l2=n;
			f=0;
			while (1)
			{
				if (b[t].z2<r2) 
				{
					l1=t;
					t=(t+l2)/2;
					if (!f) 
					{
						t+=1;
						f=0;
					}
					else f=1;
				}
				else
				if (b[t-1].z2<r2 && b[t].z2>=r2)
				{
					for (j=1;j<t;j++)
						if (b[j].z1>=r1) k--;
					break;
				}
				else 
				{
					l2=t;
					t=(t+l1)/2;
				}
				if (t==n) 
				{
					k=0;
					break;
				}
			}
			printf("%d\n",k);
		}
	}
	return 0;
}
