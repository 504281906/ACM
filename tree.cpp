#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int x,y,z,n,m;
int map[100005][100];
int a[100005],b[100005],vis[100005];
int BFS()
{
	queue<int> q;
	int i,f=0;
	q.push(1);
	vis[1]=1;
	while (!q.empty())
	{
		int k=q.front();
		q.pop();
		for (i=1;i<=map[k][0];i++)
		{
			if (vis[map[k][i]]==0)
			{
				q.push(map[k][i]);
				b[map[k][i]]=k;
				vis[map[k][i]]=1;
			}
			/*if (map[k][i]==y)
			{
				f=1;
				b[y]=k;
			}
		}
		if (f==1) return 1;*/
	}}
	return 1;
}
int main()
{
	int i;
	while (~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			map[v][0]++;
			map[v][map[v][0]]=u;
			map[u][0]++;
			map[u][map[u][0]]=v;
		}
		BFS();
		for (i=1;i<=m;i++)
		{
		scanf("%d%d%d",&x,&y,&z);
		int s=z^a[y];
		while (b[y]!=x)
		{
			if (s<(z^a[b[y]]))
				s=(z^a[b[y]]);
			y=b[y];
		}
		if (s<(z^a[x])) 
			s=(z^a[x]);
		printf("%d\n",s);
	}
	}
	return 0;
}
