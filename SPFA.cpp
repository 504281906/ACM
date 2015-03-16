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
//#define DEBUG
const int max1=0x7fffffff;
struct node
{
	int u,v,w;
	int next;
}e[200010];
int head[200010],dis[200010],vis[200010],n,m;
void addeage(int u,int v,int w,int k)
{
	e[k].v=v;
	e[k].u=u;
	e[k].w=w;
	e[k].next=head[u];
	head[u]=k;
}
void SPFA()
{
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int i=head[u];i!=-1;i=e[i].next)
		{
			int f=0;
			int v=e[i].v;
			if (dis[v]>dis[u]+e[i].w)
			{
				f=1;
				dis[v]=dis[u]+e[i].w;
			}
			if (!vis[v] && f)
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return ;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		vis[i]=0;
		head[i]=-1;
		dis[i]=max1;
	} 
	dis[1]=0;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addeage(u,v,w,i);
	}
	SPFA();
	for (int i=2;i<=n;i++)
		printf("%d\n",dis[i]);
	return 0;
}
