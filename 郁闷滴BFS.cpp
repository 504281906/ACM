#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
struct point 
{
	int x,y,t;
	bool operator<(point a) const
	{
		return t>a.t;
	}
}begin,a,b;
int n,m;
char map[210][210];
int xx[4]={-1,0,1,0};
int yy[4]={0,-1,0,1};
int BFS(point begin)
{
	int i;
	priority_queue <point> q;
	begin.t=0;
	map[begin.x][begin.y]='#';
	q.push(begin);
	while (!q.empty())
	{
		a=q.top();
		q.pop();
		for (i=0;i<4;i++)
		{
			b.x=a.x+xx[i];
			b.y=a.y+yy[i];
			if (map[b.x][b.y]=='r') return a.t+1;
			if (map[b.x][b.y]!='#' && b.x>0 && b.x<=n && b.y>0 && b.y<=m)
			{
				if (map[b.x][b.y]=='.')
				{
					map[b.x][b.y]='#';
					b.t=a.t+1;
					q.push(b);
				}
				else
				{
					map[b.x][b.y]='#';
					b.t=a.t+2;
					q.push(b);
				}
			}
		}
	}
	return -1;
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		int i,j;
		getchar();
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				scanf("%c",&map[i][j]);
				if (map[i][j]=='a')
				{
					begin.x=i;
					begin.y=j;
				}
			}
			getchar();
		}
		int f=BFS(begin);
		if (f>=0) printf("%d\n",f);
		else printf("Poor ANGEL has to stay in the prison all his life.\n"); 
	}
	return 0;
}
