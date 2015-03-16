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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
struct node
{
	int u,v,next;
}f[200010];
int T,n,i,k,u,v,j;
int head[200010];
void add(int u,int v)
{
	f[u].u=u;
	f[u].v=v;
	head[++k]=u;
	f[u].next=head[k];
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		k=0;
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		memset(f,-1,sizeof(f));
		while (n--)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		for (i=1;i<=n;i++)
		{
			for (j=f[i].v;j!=-1;j=f[i].next)
				cout<<j<<endl;
			cout<<endl;
		}
	}
	return 0;
}
