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
int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};
int vis[520][520],mp[520][520],n,m,ans;
int check(int x,int y,int t)
{
	if (x<1 || x>n || y<1 || y>n || mp[x][y]!=t || vis[x][y]==1)
		return 0;
	return 1;
}
void DFS(int x,int y,int t,int cas)
{
	for (int i=0;i<4;i++)
	{
		int x1=x+xx[i];
		int y1=y+yy[i];
		if (check(x1,y1,t))
		{
			if (cas==1) ans--;
			int cass=cas;
			cas=2;
			vis[x1][y1]=1;
			DFS(x1,y1,t,cas);
			cas=cass;
		}
	}
}
struct node
{
	int x,y;
}h[501*501];
int main()
{
	int i,a,c,b,j,k;
	while (~scanf("%d%d",&n,&m))
	{
		int t=0; 
		memset(mp,0,sizeof(mp));
		ans=0;
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&c,&a,&b);
			ans++;
			if (c==1)
				mp[a][b]=1;
			if (c==0)
				mp[a][b]=2;
			memset(vis,0,sizeof(vis));
			vis[a][b]=1;
			DFS(a,b,mp[a][b],1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
