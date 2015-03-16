#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	int l,w;
}a[5010];
bool cmp(node a,node b)
{
	if (a.l!=b.l) return a.l<b.l;
	else return a.w<b.w;
}
int vis[5010];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d%d",&a[i].l,&a[i].w);
		sort(a,a+n,cmp);
		int t=0;
		memset(vis,0,sizeof(vis));
		for (i=0;i<n;i++)
		if (vis[i]==0)
		{
			int k=i;
			//printf("%d %d\n",a[i].l,a[i].w);
			vis[i]=1;
			for (j=i+1;j<n;j++)
				if (vis[j]==0 && a[j].l>=a[k].l && a[j].w>=a[k].w)
				{
					vis[j]=1;
					k=j;
				}
			t++;
		}
		printf("%d\n",t);
	} 
	return 0;
}
