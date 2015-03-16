#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define INF 0x3fffffff
int f[1010][1010],g[1010];
int main()
{
	queue<int> q;
	int n,m,l,md[1010];
	while (~scanf("%d%d%d",&n,&m,&l))
	{
		while (!q.empty())
		q.pop();
		for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000;j++)
			i==j?f[i][j]=0:f[i][j]=INF;
		for (int i=1;i<=1000;i++)
		g[i]=INF;
		for (int i=1;i<=n;i++)
		{
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			if (f[a][b]>t)
			f[b][a]=f[a][b]=t;
		}
		for (int i=1;i<=m;i++)
		{
			int a;
			scanf("%d",&a);
			g[a]=0;
			q.push(a);
		}
		for (int i=1;i<=l;i++)
		scanf("%d",&md[i]);
		while (!q.empty())
		{
			int now=q.front();
			q.pop();
			for (int i=1;i<=1000;i++)
			if (f[now][i]+g[now]<g[i])
			{
				g[i]=f[now][i]+g[now];
				q.push(i);
			}
		}
		int max=INF;
		for (int i=1;i<=l;i++)
		if (max>g[md[i]])
		max=g[md[i]];
		printf("%d\n",max);
	}
	return 0;
} 
