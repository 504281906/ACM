#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
#define N 30010
using namespace std;
stack <int> st;
int instack[N];
int t,tot,n,m;
struct node
{
	int from,to,next;
}eage[2*N];
int head[N],dnf[N],low[N],belong[N],in[N],out[N]; 
void add(int a,int b)
{
	eage[tot].from=a;
	eage[tot].to=b;
	eage[tot].next=head[a];
	head[a]=tot++;
}
void getmap()
{
	memset(head,-1,sizeof(head));
	tot=0;
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
}
void tarjan(int k)
{
	st.push(k);
	dnf[k]=low[k]=++t;
	instack[k]=1;
	int i,v;
	for (i=head[k];i!=-1;i=eage[i].next)
	{
		v=eage[i].to;
		if (instack[v])
			low[k]=low[k]>dnf[v]?dnf[v]:low[k];
		else if (dnf[v]==0)
		{
			tarjan(v);
			low[k]=low[k]>low[v]?low[v]:low[k];
		}
	}
	if (dnf[k]==low[k])
	{
		do
		{
			i=st.top();
			st.pop();
			belong[i]=k;
			instack[i]=0;
		}while (i!=k);
	}
}
void getdegree()
{
	int i;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for (i=0;i<tot;i++)
	{
		if (belong[eage[i].from]==belong[eage[i].to]) continue;
		in[belong[eage[i].to]]++;
		out[belong[eage[i].from]]++;
	}
}
int main()
{
	int i,temp,t1,t2;
	while (~scanf("%d%d",&n,&m))
	{
		t=0;
		getmap(); 
		memset(dnf,0,sizeof(dnf));
		memset(low,0,sizeof(low));
		memset(instack,0,sizeof(instack));
		for (i=1;i<=n;i++)
			if (dnf[i]==0) tarjan(i);
		getdegree();
		temp=t1=t2=0;
		for (i=1;i<=n;i++)
		{
			if (belong[i]!=i) continue;
			temp++;
			if (in[i]==0) t1++;
			if (out[i]==0) t2++;
		}
		int ans=t1>t2?t1:t2;
		if (n<1 || temp==1) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
