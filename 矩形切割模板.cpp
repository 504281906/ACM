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
#define LL __int64
using namespace std;
struct node
{
	int lx,ly,rx,ry,cl;
}f[1010];
int ans[10010];
void DFS(int lx,int ly,int rx,int ry,int t)
{
	if (t==0) return;
	if (f[t].lx>=rx || f[t].rx<=lx || f[t].ly>=ry || f[t].ry<=ly )
		DFS(lx,ly,rx,ry,t-1);
	else
	{
		int k1=max(lx,f[t].lx);
		int k2=min(rx,f[t].rx);
		if (lx<k1)
			DFS(lx,ly,k1,ry,t-1);
		if (rx>k2)
			DFS(k2,ly,rx,ry,t-1);
		int k3=max(ly,f[t].ly);
		int k4=min(ry,f[t].ry);
		if (ly<k3)
			DFS(k1,ly,k2,k3,t-1);
		if (ry>k4)
			DFS(k1,k4,k2,ry,t-1);
		ans[f[t].cl]+=abs(k2-k1)*abs(k4-k3);
		ans[1]-=abs(k2-k1)*abs(k4-k3);
	}
}
int main()
{
	int n,m,k,i;
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=k;i++)
		scanf("%d%d%d%d%d",&f[i].lx,&f[i].ly,&f[i].rx,&f[i].ry,&f[i].cl);
	memset(ans,0,sizeof(ans));
	ans[1]=n*m;
	DFS(0,0,n,m,k);
	for (i=1;i<=n;i++)
		if (ans[i])
			printf("%d %d\n",i,ans[i]);
	return 0;
}

