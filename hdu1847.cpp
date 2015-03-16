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
int sg[1010];
int a[20];
int mex(int x)
{
	if (sg[x]!=-1) 
		return sg[x];
	bool vis[1010];
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=10;i++)
	{
		int t=x-a[i];
		if (t<0) break;
		sg[t]=mex(t);
		vis[sg[t]]=true;
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
	memset(sg,-1,sizeof(sg));
	a[1]=1;
	for (int i=2;i<=10;i++)
		a[i]=a[i-1]*2;
	mex(1000);
	int n;
	while (~scanf("%d",&n))
	{
		if (sg[n]) printf("Kiki\n");
		else printf("Cici\n");
	}
	return 0;
}
