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
#define Max 100005
#define INF 0x3fffffff
int dis[210][210];
int dir[Max],u[Max],v[Max],c[Max],f[Max];
int find(int x)
{
	if (f[x]!=x) return f[x]=find(f[x]);
	else return x;
}
void unit(int x,int y)
{
	int a=find(x);
	int b=find(y);
	if (a!=b) f[a]=b;
	return;
}
void floyd(int n)
{
	int i,j,k;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (dis[i][k]<INF && dis[j][k]<INF)
					if (dis[i][j]>dis[i][k]+dis[k][j])
						dis[i][j]=dis[i][k]+dis[k][j];
}
int main()
{	
	int n,m,i,j,x,y,a,b,q;
	while (~scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		for (i=0;i<Max;i++)
			f[i]=i;
		for (i=0;i<205;i++)
			for (j=0;j<205;j++)
				if (i==j) dis[i][j]=0;
				else dis[i][j]=dis[j][i]=INF;
		for (i=1;i<=m;i++)	
		{
			scanf("%d%d%d",&u[i],&v[i],&c[i]);
			if (c[i]==0) unit(u[i],v[i]);
		}
		int t=0;
		for (i=1;i<=n;i++)
			if (f[i]==i)
				dir[i]=t++;
		for (i=1;i<=n;i++)
			if (f[i]!=i)
			{
				x=find(i);
				dir[i]=dir[x];
			}
		for (i=1;i<=m;i++)
		{
			x=find(u[i]);
			y=find(v[i]);
			if (x!=y)
			{
				int a=dir[x];
				int b=dir[y];
				if (c[i]<dis[a][b])
					dis[a][b]=dis[b][a]=c[i];
			}
		}
		floyd(t);
		scanf("%d",&q);
		while (q--)
		{
			scanf("%d%d",&x,&y);
			a=find(x);
			b=find(y);
			if (a==b)
			{
				printf("0\n");
				continue;
			}
			a=dir[a];
			b=dir[b];
			if (dis[a][b]==INF) printf("-1\n");
			else printf("%d\n",dis[a][b]);
		}
	}
	return 0;
}
