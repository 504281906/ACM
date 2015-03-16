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
//#define DEBUG
#define max 200010
struct node
{
	int u,w,v,next;
}e[200100];
int head[200100],vis[200100],dis[200100]; 
void addeage(int u,int v,int w,int k)
{
	e[k].u=u;
	e[k].v=v;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
void SPFA()
{
	dis[1]=0;
	vis[1]=1;
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int u,v;
		u=q.front();
		q.pop();
		for (int i=head[u];i!=-1;i=e[i].next)
		{
			v=e[i].v;
			int f=0;
			if (dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				f=1;
			}
			if (f && !vis[v])
			{
				q.push(v);
				vis[v]=1;
			}
		}
	}
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int i,n,m;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		vis[i]=0;
		dis[i]=max;
		head[i]=-1;
	}
	for (i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addeage(u,v,w,i);
	}
	SPFA();
	for(i=2;i<=n;i++)
		printf("%d\n",dis[i]);
	return 0;
}
