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
		}
		for (i=1;i<=n;i++)
		{
			LL max=1e9+10,pos=0;
			for (j=1;j<=n;j++)
				if (!vis[j] && a[j]<max && v[j].size())
				{	
					pos=j;
					max=a[j];
				}
			vis[pos]=1;
			int l=v[pos].size();
			for (j=0;j<l;j++)
			{
				k=max+a[v[pos][j].x];
				if (k<a[v[pos][j].y])
					a[v[pos][j].y]=k;
			}
		}
		printf("%I64d\n",a[1]);
		return 0;
}
