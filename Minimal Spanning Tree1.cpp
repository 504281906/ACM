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
const LL M=2333333;
const LL INF=0x7fffffff;
#define max(a,b) a>b?a:b
struct node 
{
	int x,y; 
	node (int a,int b):x(a),y(b){}
	bool operator <(const node a) const
	{
		return x<a.x;
	}
};
int vis[10000010];
LL n,m,i,j;
int cmp(node a,node b)
{
	return a.x<b.x;
}
priority_queue<node>q[10000010];
int main()
{
	while(~scanf("%I64d%I64d",&n,&m))
	{
		LL x=m;
		for (i=1;i<=n;i++)
		{
			while (!q[i].empty()) q[i].pop();
			vis[i]=0;
		}
		for (i=2;i<=n;i++)
		{
			x=(x * 907) %M;
			LL t=x;
			for (j=max(1,i-5);j<=i-1;j++)
			{
				x=(x * 907) %M;
				LL w=x ^ t;
				q[i].push(node(w,j));
				q[j].push(node(w,i));
			}
		}
		LL ans=0,t=0,k;
		/*vis[1]=1;
		while (t<n)
		{
			t++;
			while (vis[q[k].top().y]) q[k].pop();
			node h=q[k].top();
			k=h.y;
			if (vis[k]==0)
			{
				vis[k]=1;
				t++;
			}
			ans+=h.x;
		}*/
		for (i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			vis[i]=1;
			while (!q[i].empty() && vis[q[i].top().y]) q[i].pop();
			if (q[i].empty()) continue;
			node h=q[i].top();
			k=h.y;
			vis[k]=1;
			ans+=h.x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
