#include <cstdio>
#include <queue>
using namespace std;
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};
char map[201][201];
struct node
{
	int x,y,t;
}begin;
int n,m;
int BFS(node k)
{
	queue<node> q;
	int i;
	q.push(k);
	node now,h;
	while (!q.empty())
	{
		h=q.front();
		q.pop();
		for (i=0;i<4;i++)
		{
			now.x=h.x+xx[i];
			now.y=h.y+yy[i];
			if (map[now.x][now.y]=='r') 
			{return h.t+1;}
			if (now.x>0 && now.x<=n && now.y>0 && now.y<=m && map[now.x][now.y]!='#')
			{
				if (map[now.x][now.y]=='.')
				{
					map[now.x][now.y]=='#';
					now.t=h.t+1;
					q.push(now);
				}
				else 
				{
					map[now.x][now.y]=='#';
					now.t=h.t+2;
					q.push(now);
				}
			}
		}
	}
	return 0;
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		int i,j;
		char c;	
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
					begin.t=0;
					map[i][j]='#';
				}
			}
			getchar();
		}
		int f=BFS(begin);
		if (f) printf("%d\n",f);
			else printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}
