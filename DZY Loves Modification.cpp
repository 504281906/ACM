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
#include <limits>
using namespace std;
#define Max(a,b) a>b?a:b
struct node
{
	__int64 v;
};
__int64 r[1000010],w[1000010];
int main()
{
	__int64 n,m,k,p;
	priority_queue <__int64> q;
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&p);
	__int64 i,j,t;
	memset(r,0,sizeof(r));
	memset(w,0,sizeof(w));
	for (i=1;i<=n;i++) //w代表列，r代表行 
	{
		for (j=1;j<=m;j++)
		{
			scanf("%I64d",&t);
			r[i]+=t;
			w[j]+=t;
		}
	}
	while (!q.empty()) q.pop();
	for (i=1;i<=n;i++)
	{
		q.push(r[i]);
		r[i]=0;
	}
	for (i=1;i<=k;i++)
	{
		__int64 h=q.top();
		q.pop();
		r[i]=r[i-1]+h;
		h-=p*m;
		q.push(h);
	}
	while (!q.empty())q.pop();
	for (i=1;i<=m;i++)
	{
		q.push(w[i]);
		w[i]=0;
	}
	for (i=1;i<=k;i++)
	{
		__int64 h=q.top();
		q.pop();
		w[i]=w[i-1]+h;
		h-=p*n;
		q.push(h);
	}
	__int64 ans=-1e18;
	for (i=0;i<=k;i++)
	{
		ans=Max(ans,r[i]+w[k-i]-(__int64)(i*(k-i)*p));
	}
	printf("%I64d\n",ans);
	return 0;
}
