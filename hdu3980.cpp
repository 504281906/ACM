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
int n,m,sg[2048];
int mex(int x)
{
	int i;
	bool vis[2048];
	memset(vis,0,sizeof(vis));
	if (x-m<0) return sg[x]=0;
	if (sg[x]!=-1) return sg[x];
	for (i=0;i<=x-m;i++)
	{
		if (sg[i]==-1)
			sg[i]=mex(i);
		if (sg[x-i-m]==-1)
			sg[x-i-m]=mex(x-i-m);
		vis[sg[i] ^ sg[x-i-m]]=1; 
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
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case #%d: ",cas);
		scanf("%d%d",&n,&m);
		if (m>n)
		{
			puts("abcdxyzk");
			continue;
		}
		n-=m;
		memset(sg,-1,sizeof(sg));
		mex(n);
		if (sg[n]==0) puts("aekdycoin");
			else puts("abcdxyzk");
	}
	return 0;
}
