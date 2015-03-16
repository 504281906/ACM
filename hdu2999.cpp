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
int sg[1010],l,n,m,a[1010],k;
int mex(int x)
{
	if (sg[x]!=-1) return sg[x];
	bool vis[1010];
	memset(vis,0,sizeof(vis));
	for (int i=0;i<l;i++)
		for (int j=0;j<=(x-a[i]);j++)
		{
			if (sg[j]==-1)
				sg[j]=mex(j);
			if (sg[x-j-a[i]]==-1)
				sg[x-j-a[i]]=mex(x-j-a[i]);
			vis[sg[j] ^ sg[x-j-a[i]]]=1;
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
	while (~scanf("%d",&n))
	{
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		l=unique(a,a+n)-a;
		scanf("%d",&m);
		memset(sg,-1,sizeof(sg));
		while (m--)
		{
			scanf("%d",&k);
			if (sg[k]==-1)
				sg[k]=mex(k);
			if (sg[k]) puts("1");
			else puts("2");
		}
	}
	return 0;
}
