#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
#define M 50050
int vis[M],head[M],dfn[M],low[M],belong[M],in[M],out[M];
stack <int> st;
struct node
{
	int from,to;
	int next;
}e[M];
int t,tt;
int add(int a,int b)
{
	e[t].from=a;
	e[t].to=b;
	e[t].next=head[a];
	head[a]=t++;
}
void tarjan(int k)
{
	st.push(k);
	dfn[k]=low[k]=tt++;
	vis[k]=1;
	int i,v;
	for (i=head[k];i!=-1;i=e[i].next)
	{
		v=e[i].to;
		if (vis[v])
			low[k]=low[k]>dfn[v]?dfn[v]:low[k];
		else if (dfn[v]==0)
		{
			tarjan(v);
			low[k]=low[k]>low[v]?low[v]:low[k];
		}
	}
	if (dfn[k]==low[k])
	{
		do
		{
			i=st.top();
			st.pop();
			belong[i]=k;
			vis[i]=0;
		}while (i!=k);
	}
}
void getdegree()
{
	int i;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for (i=0;i<t;i++)
	{
		if (belong[e[i].from]==belong[e[i].to]) continue;
		in[belong[e[i].to]]++;
		out[belong[e[i].from]]++;
	}
}
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		t=0;
		memset(head,-1,sizeof(head));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		for (int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		tt=1;
		for (int i=1;i<=n;i++)
			if (dfn[i]==0) tarjan(i);
		getdegree();
		int ttt=0,t1=0,t2=0;
		for (int i=1;i<=n;i++)
		{
			if (belong[i]!=i) continue;
			ttt++;
			if (in[i]==0) t1++;
			if (out[i]==0) t2++;
		}
		int ans=t1>t2?t1:t2;
		if (ttt==1 || n < 1) ans=0;
		cout<<ans<<endl;
	} 
	return 0;
}
