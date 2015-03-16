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
struct node
{
	int x,y,c;
	bool operator ==(node a)
	{
		if (a.x==x && a.y==y) 	
			return 1;
		else return 0;
	}
}f[520][520],t[500*501];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
node find(int x,int y)
{
	if (x==f[x][y].x && y==f[x][y].y)
		return f[x][y];
	else return f[x][y]=find(f[x][y].x,f[x][y].y);
}
int main()
{
	int n,m,i,j,c,a,b;
	while (~scanf("%d%d",&n,&m))
	{
		for (i=0;i<=n+1;i++)
			for (j=0;j<=n+1;j++)
			{
				f[i][j].x=i;
				f[i][j].y=j;
				f[i][j].c=2;
			}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&c,&a,&b);
			t[i].x=a;
			t[i].y=b;
			f[a][b].x=a;
			f[a][b].y=b;
			f[a][b].c=c;
			for (j=0;j<4;j++)
			{
				if (f[a+dir[j][0]][b+dir[j][1]].c==f[a][b].c)
				{
					node k1=find(a+dir[j][0],b+dir[j][1]);
					node k2=find(a,b);
					f[k2.x][k2.y].x=k1.x;
					f[k2.x][k2.y].y=k1.y;
				}
			}
			int ans=0;
			for (j=1;j<=i;j++)
			{	
				node k1=find(t[j].x,t[j].y);
				if (k1==t[j])
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
