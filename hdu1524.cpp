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
vector <int>vt[1010];
int sg[1100];
int mex(int x)
{
	if (sg[x]!=-1) return sg[x];
	if (vt[x].size()==0) return 0;
	int vis[1010];
	memset(vis,0,sizeof(vis));
	for (int i=0;i<vt[x].size();i++)
	{
		if (sg[vt[x][i]]==-1)
			sg[vt[x][i]]=mex(vt[x][i]);
		vis[sg[vt[x][i]]]=1;
	}
	for (int i=0;;i++)
	if (!vis[i])
	{
		sg[x]=i;
		break;
	}
	return sg[x];
}
int main()
{
	int n,m,k,i,x;
	while (~scanf("%d",&n))
	{
		memset(sg,-1,sizeof(sg));
		for (i=0;i<n;i++)
		{
			vt[i].clear();
			scanf("%d",&m);
			while (m--)
			{
				scanf("%d",&k);
				vt[i].push_back(k);
			}
		}
		while (~scanf("%d",&m) && m)
		{
			int ans=0;
			k=m;
			while (k--)
			{
				scanf("%d",&x);
				if (sg[x]==-1)
					sg[x]=mex(x);
				ans^=sg[x];
			}
			if (ans) puts("WIN");
			else puts("LOSE");
		}
	}
	return 0;
}
