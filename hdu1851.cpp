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
int m,l,T,n;
int sg[25];
int mex(int x)
{
	int i;
	if (sg[x]!=-1) return sg[x];
	bool vis[22];
	memset(vis,0,sizeof(vis));
	for (i=1;i<=l;i++)
	{
		int t=x-i;
		if (t<0) break;
		sg[t]=mex(t);
		vis[sg[t]]=1;
	}
	for (i=0;;i++)
	if (!vis[i])
	{
		sg[x]=i;
		break;
	}
	return sg[x];
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(sg,0,sizeof(sg));
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			memset(sg,-1,sizeof(sg));
			scanf("%d%d",&m,&l);
			ans^=mex(m);
		}
		if (ans) puts("No");
		else puts("Yes");
	}
	return 0;
}

