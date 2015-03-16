#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> path[10010];
vector <int> cost[10010]; 
int dis[10010];
int vis[10010];
void BFS(int k)
{
	int i,j,t;
	vis[k]=1;
	t=path[k].size();
	for (i=0;i<t;i++)
	{
		j=path[k][i];
		if (!vis[j])
		{
			dis[j]=dis[k]+cost[k][i];
			BFS(j);
		}
	}
	return;
}
int main()
{
	int n,i,v,u,c;
	while (~scanf("%d",&n))
	{
		for (i=1;i<n;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			path[u].push_back(v);
			cost[u].push_back(c);
			path[v].push_back(u);
			cost[v].push_back(c);
		}
		memset(vis,0,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		dis[1]=0;
		BFS(1);
		int start,max=-1;
		for (i=1;i<=n;i++)
			if (max<dis[i])
			{
				start=i;
				max=dis[i];
			}
		memset(vis,0,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		dis[start]=0;
		BFS(start);
		max=-1;
		for (i=1;i<=n;i++)
			if (max<dis[i])
				max=dis[i];
		printf("%d\n",max*10+(max+1)*max/2);
	}
}
