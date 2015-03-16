#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
struct point 
{
	int x,y;
}begin,end;
int map[10][10];
int n,m,t,f;
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};
int dis(int a,int b)
{
	return abs(a-end.x)+abs(b-end.y);
}
int DFS(int x,int y,int T)
{
	int i,j,h;
	h = dis(x, y);
    if((h & 1) != ((t - T) & 1) || h > t - T) return 0;
	if (T==t && ((x!=end.x) || (y!=end.y))) return f;
	if ((x==end.x) && (y==end.y) && (T==t))
	{
		f=1;
		return f;
	}
	for (i=0;i<4;i++)
	{
		int x1=x+xx[i];
		int y1=y+yy[i];
		if ((!map[x1][y1]) && (x1>0) && (x1<=n) && (y1<=m) && (y1>0))
		{
			map[x1][y1]=1;
			T++;
			DFS(x1,y1,T);
			if (f) return 1;
			T--;
			map[x1][y1]=0;
		}
	}
}
int main()
{
	while (~scanf("%d%d%d",&n,&m,&t) && (n+m+t))
	{
		int i,j,tt=0;
		memset(map,0,sizeof(map));
		getchar();
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				char c;
				scanf("%c",&c);
				if (c=='S') 
				{
					begin.x=i;
					begin.y=j;
					map[i][j]=1;
				}
				else if (c=='D')
				{
					end.x=i;
					end.y=j;
				}
				else if (c=='X')
				{
					map[i][j]=1;
					tt++;
				}
			}
			getchar();
		}	
		if (t>n*m-tt) puts("NO");
			else
			{
				f=0;
				DFS(begin.x,begin.y,0);
				if (f==0) printf("NO\n");
				else printf("YES\n");
			}
	}
	return 0;
}
