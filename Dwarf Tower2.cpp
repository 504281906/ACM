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
#define min(a,b) a>b?b:a
struct node
{
	int x,y;
};
vector<node>ans[10010];
LL a[10010];
int vis[10010];
LL DFS(int k)
{
	LL l=ans[k].size();
	if (l==0) return a[k];
	else
	{
		for (LL i=0;i<l;i++)
		{
			int ax,ay;
			int x=ans[k][i].x;
			int y=ans[k][i].y;
			if (vis[x]) ax=a[x];
			else
			{
				vis[x]=1;
				ax=DFS(x);
				vis[x]=0;
			}
			if (vis[y]) ay=a[y];
			else
			{
				vis[y]=1;
				ay=DFS(y);
				vis[y]=0;
			}
			a[k]=min(a[k],(ax+ay));
		}
		return a[k];
	}
}
int main()
{
	int n,m;
scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			ans[i].clear();
			vis[i]=0;
		}
		vis[1]=1;
		for (int i=1;i<=m;i++)
		{
			LL k,x,y;
			scanf("%d%d%d",&k,&x,&y);
			node t;
			t.x=x;
			t.y=y;
			ans[k].push_back(t);
		}
		printf("%I64d\n",DFS(1));
	return 0;
}
