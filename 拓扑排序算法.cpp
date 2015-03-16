#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int head[10010];
int d[10010],a[10010],vis[10010];
struct node
{
	int u,v,next;
}e[10010];
queue<int>q;
void add(int u,int v,int k)
{
	e[k].u=u;
	e[k].v=v;
	e[k].next=head[u];
	head[u]=k;
}
int main()
{
	int n,m,i,j,u,v;
	while (scanf("%d%d",&n,&m)) //n个顶点，m条有向边
	{
		memset(head,-1,sizeof(head));
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			d[v]++;
			add(u,v,i);
		}
		int k=0;
		for (i=0;i<n;i++)
			if (d[i]==0)
			{
				k++;
				a[k]=i;
				q.push(i);
				vis[i]=1;
			}
		while (!q.empty())
		{
			u=q.front();
			q.pop();
			for (i=head[u];i!=-1;i=e[i].next)
			{
				v=e[i].v;
				if (!vis[v])
				{
					d[v]--;
					if (d[v]==0)
					{
						q.push(v);
						k++;
						a[k]=v;
						vis[v]=1;
					}
				}
			}
		}
		if (k==n) 
			for (i=1;i<=k;i++)
				printf("%d ",a[i]);
		else 
			printf("No!");
		cout<<endl;
	} 
}
