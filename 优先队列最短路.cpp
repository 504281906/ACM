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
#define max 20005
int a[20010];
struct node 
{
	int u,v,l;
	node (int a,int b,int c):u(a),v(b),l(c){}
	bool operator <(const node a) const
	{
		if (u==a.u) 
			return v>a.v;
		return u>a.u;
	}
};
int main()
{
	int n,m,i,j,u,v,l;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
			a[i]=max;
	a[1]=0;
	priority_queue<node>que[50010];
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&l);
		que[0].push(node(u,v,l));
	}
	int t=0;
	while (1)
	{
		int f=1;
		while (!que[t].empty())
		{
			node k=que[t].top();
			que[t+1].push(k);
			//printf("%d %d %d\n",k.u,k.v,k.l);
			que[t].pop();
			if (a[k.v]>a[k.u]+k.l || a[k.v]==max)
			{
				a[k.v]=a[k.u]+k.l;
				/*k.u=a[k.v];
				k.v=k.v;
				que[t+1].push(k);*/
				f=0;
			}
		}
		t++;
		if (f) break;
	}
	for (i=2;i<=n;i++)
		printf("%d\n",a[i]);
	return 0;
}
