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
struct node
{
	int x,y;
	node(LL a,LL b):x(a),y(b){}
};
LL a[100010];
int vis[100010];
vector <node>v[10010];
int n,m,i,j,k,x,y;
queue<int>q;
int main()
{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			vis[i]=0;
		}
		if (m==0)
		{
			printf("%I64d\n",a[1]);
			return 0;
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&k,&x,&y);
			v[x].push_back(node(y,k));
			v[y].push_back(node(x,k));
			if (!vis[x])
			{
				vis[x]=1;
				q.push(x);
			}
			if (!vis[y])
			{
				vis[y]=1;
				q.push(y);
			}
		}
		while (!q.empty())
		{
			k=q.front();
			vis[k]=0;
			q.pop();
			int l=v[k].size();
			for (i=0;i<l;i++)
			{
				if (a[k]+a[v[k][i].x]<a[v[k][i].y])
				{
					a[v[k][i].y]=a[k]+a[v[k][i].x];
					if (!vis[v[k][i].y])
					{
						q.push(v[k][i].y);
						vis[v[k][i].y]=1;
					}
				}
			}
		}
		printf("%I64d\n",a[1]);
		return 0;
}
