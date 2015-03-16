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
#define ling 0.0000001
struct node
{
	double s;
	int p;
}f[100010];
int cmp(node a,node b)
{
	return a.s>b.s;
}
double dis(LL x1,LL y1,LL x2,LL y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
LL b,xx,yy,x,y,s;
int main()
{
	double ans;
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%I64d",&b);
		scanf("%I64d%I64d",&xx,&yy);
		ans=0;
		for (i=0;i<n;i++)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&s);
			f[i].s=s/dis(xx,yy,x,y);
			f[i].p=i+1;
			ans+=f[i].s;
		}
		sort(f,f+n,cmp);
		double max=6*(b+ans-f[0].s);
		if ((f[0].s-max>ling))
			printf("%d\n",f[0].p);
		else puts("NOISE");
	}
	return 0;
}
