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
#include <ctime>
#define LL __int64
#define EPS 1e-8
#define Pi acos(-1)
using namespace std;
struct node
{
	double x,h;
}a[100010];
struct node1
{
	double xx,ma,mb;
	int pos;
}b[100010];
int cmp(node a,node b)
{
	return a.h>b.h;
}
int cmp1(node1 a,node1 b)
{
	return a.xx<b.xx;
}
int cmp2(double a,double b)
{
	return a<b;
}
double c[100010];
int main()
{
	int T,i,j,n,q;
	scanf("%d",&T);
	int cas=1;
	while (T--)
	{
		printf("Case #%d:\n",cas++);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].h);
		sort(a+1,a+1+n,cmp);
		scanf("%d",&q);
		double xx;
		for (i=1;i<=q;i++)
		{
			scanf("%lf",&b[i].xx);
			b[i].ma=90.0,b[i].mb=90.0;
			b[i].pos=i;
			c[i]=b[i].xx;
		}
		sort(c+1,c+1+q,cmp2);
		sort(b+1,b+q+1,cmp1);
		for (i=1;i<=n;i++)
		{
			double d;
			int pos=lower_bound(c+1,c+1+q,a[i].x)-c;
			for (j=pos-1;j>=1;j--)
			{
				d=atan2((a[i].x-b[j].xx),a[i].h)*180/Pi;
				if (b[j].mb>=d)
					b[j].mb=d;
				else break;
			}
			for (j=pos;j<=q;j++)
			{
				d=atan2((b[j].xx-a[i].x),a[i].h)*180/Pi;
				if (b[j].ma>=d)
					b[j].ma=d;
				else break;
			}
		}
		for (i=1;i<=q;i++)
			printf("%.10lf\n",b[b[i].pos].ma+b[b[i].pos].mb);
	}
	return 0;
}
