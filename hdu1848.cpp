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
int f[20],l,sg[1010];
int mex(int x)
{
	if (sg[x]!=-1) return sg[x];
	bool vis[1011];
	memset(vis,0,sizeof(vis));
	for (int i=1;i<l;i++)
	{
		int t=x-f[i];
		if (t<0) break;
		sg[t]=mex(t);
		vis[sg[t]]=1;
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
	f[1]=1;
	f[2]=2;
	for (l=3;f[l-1]<=1000;l++)
		f[l]=f[l-1]+f[l-2];
	l--;
	int i,a,b,c;
	memset(sg,-1,sizeof(sg));
	mex(1000);
	while (~scanf("%d%d%d",&a,&b,&c) && (a+b+c))
	{
		int k=sg[a]^sg[b]^sg[c];
		if (k) puts("Fibo");
		else puts("Nacci");
	}
	return 0;
}
