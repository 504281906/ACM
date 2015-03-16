#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
struct node
{
	int x,y,t;
}begin;
int n,m;
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};
char map[202][202];
int BFS(node k)
{
	queue <node> q;
	q.push(k);
	node a,b;
	while (!q.empty())
	{
		a=q.front();
		q.pop();
		for (int i=0;i<4;i++)
		{
			b.x=a.x+xx[i];
			b.y=a.y+yy[i];
			if (map[b.x][b.y]=='r') {return a.t+1;}
			if (b.x>0 && b.x<=n && b.y>0 && b.y<=m && map[b.x][b.y]!='#')
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
					map[i][j]='#';
					begin.t=0;
				}
			}
			getchar();
		}
		int f=BFS(begin);
		if (f) cout<<f<<endl;
		else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}
