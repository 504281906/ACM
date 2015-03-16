#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
char mp[10][10];
int n,m,T,ans;
int dis(int x,int y,int x1,int y1)
{
	return (fabs(x1-x)+fabs(y1-y));
}
void DFS(int x,int y,int t)
{
	if (ans==1) return;
	for (int i=0;i<4;i++)
	{
		int x1=x+xx[i];
		int y1=y+yy[i];
		if (mp[x1][y1]=='D' && t+1==T)
		{
			ans=1;
			return;
		}
		if (mp[x1][y1]=='.' && (x1>=0) && (x1<n) && (y1>=0) && (y1<m))
		{
			mp[x1][y1]='X';
			DFS(x1,y1,t+1);
			mp[x1][y1]='.';
			if (ans==1) return;
		}
	}
}
int main()
{
	while (~scanf("%d%d%d",&n,&m,&T) && (n+m+T))
	{
		int x,y,x1,y1;
		getchar();
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				scanf("%c",&mp[i][j]);
				if (mp[i][j]=='S')
				{
					x=i;
					y=j;
				}
				if (mp[i][j]=='D')
				{
					x1=i;
					y1=j;
				}
			}
			getchar();
		}
		int t=dis(x,y,x1,y1);
		if (t>T) puts("NO");
		else
		{
			ans=0;
			mp[x][y]=='X';
			DFS(x,y,0);
			if (ans) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
