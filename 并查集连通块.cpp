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
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int a[520][520],f[501*501];
int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main()
{
	int n,m,i,c,x,y,j;
	while (~scanf("%d%d",&n,&m))
	{
		for (i=0;i<=250010;i++)
			f[i]=i;
		int ans=0;
		memset(a,-1,sizeof(a));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&c,&x,&y);
			a[x][y]=c;
			ans++;
			for (j=0;j<4;j++)
			{
				int x1=x+dir[j][0];
				int y1=y+dir[j][1];
				if (x1>0 && x1<=n && y1>0 && y1<=n && a[x][y]==a[x1][y1])
				{
					int k1=find((x-1)*n+y);
					int k2=find((x1-1)*n+y1);
					if (k1!=k2)
					{
						ans--;
						f[k1]=k2;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
