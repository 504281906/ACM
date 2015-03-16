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
int sg[10010],a[110],s[110],ans[110],k;
int mex(int x)
{
	int i;
	if (sg[x]!=-1) return sg[x];
	bool vis[110];
	memset(vis,0,sizeof(vis));
	for (i=0;i<k;i++)
	{
		int t=x-s[i];
		if (t<0) break;
		sg[t]=mex(t);
		vis[sg[t]]=1;
	}
	for (i=0;;i++)
		if (vis[i]==0)
		{
			sg[x]=i;
			break;
		}
	return sg[x];
}
int main()
{
	int i,n,m,j,h; 
	while (~scanf("%d",&k )&&k)
	{
		for (i=0;i<k;i++)
			scanf("%d",&s[i]);
		sort(s,s+k);
		scanf("%d",&n);
		memset(sg,-1,sizeof(sg));
		sg[0]=0;
		for (i=1;i<=n;i++)
		{
			ans[i]=0;
			scanf("%d",&m);
			for (j=1;j<=m;j++)
			{
				scanf("%d",&h);
				ans[i]^=mex(h);
			}
		}
		for (i=1;i<=n;i++)
			ans[i]==0?printf("L"):printf("W");
		cout<<endl;
	}
	return 0;
}

