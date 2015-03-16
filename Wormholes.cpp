#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	int from,to,w,next;
}d[2100];
int flag,vis[2100],v[2100],head[2100],h[2100][2100];
void dfs(int k)
{
	int i;
	if (flag) return;
	for (i=head[k];i!=-1;i=d[i].next)
	{
		int go=d[i].to;
		if ( vis[go]==0 )
		{
			vis[go]=1;
			v[go]=v[d[i].from]+d[i].w;
		//	cout<<go<<":"<<v[go]<<endl;
			dfs(go);
		}
		else
		if (v[go]>v[d[i].from]+d[i].w)
		{
			//printf("%d\n",go);
			flag=1;
		}
	}
	return ;
}
int main()
{
	int T,i,n,m;
	scanf("%d",&T);
	while (T--)
	{
		memset(head,-1,sizeof(head));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		int t=0;
		for (i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			d[t].from=a;
			d[t].to=b;
			d[t].w=c;
			d[t].next=head[a];
			head[a]=t++;
		}
		vis[0]=1;
		flag=0;
		dfs(0);
		if (flag) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}
