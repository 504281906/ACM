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
#define eps 1e-8
using namespace std;
LL p[110];
struct node
{
	LL k,c;
}f[110];
int cmp(node a,node b)
{
	return a.c<b.c;
}
int main()
{
	int n,i,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%I64d%I64d",&f[i].k,&f[i].c);
	sort(f+1,f+1+n,cmp);
	scanf("%d",&m);
	for (i=1;i<=m;i++)
		scanf("%I64d",&p[i]);
	LL k=1;
	LL d=0;
	int t=1;
	LL ans=0;
	for (i=1;i<=n;i++)
	{
		LL r=f[i].k;
		while (d+r>p[t] && t<=m)
		{
			ans+=(p[t]-d)*k*f[i].c;
			r=r-(p[t]-d);
			k++;
			d=p[t];
			t++;
		}
		if (r)
		{
			ans+=r*k*f[i].c;
			d+=r;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
