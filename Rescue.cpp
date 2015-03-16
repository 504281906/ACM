#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
char map[1010][1010];
int vis[1010][1010];
int f,x2,y2,n,m;
struct node
{
	int x,y,t;
	node (int a,int b,int c):x(a),y(b),t(c){}
	bool operator <(const node b) const
	{
		return t>b.t;
	}
};
priority_queue<node>q;
int BFS(int x,int y,int t)
{
	int i,j,x1,y1,t1;
	if (map[x][y]=='r' && t<f)
	{
		x2=x;
		y2=y;
		f=t;
		return f;
	}
	q.pop();
	for (i=0;i<4;i++)
	{
		x1=x+xx[i];
		y1=y+yy[i];
		if ((!vis[x1][y1]) && (map[x1][y1]!='#') && x1>0 && x1<=n && y1>0 && y1<=m)
		{
			vis[x1][y1]=1;
			if (map[x1][y1]=='x')
				q.push(node(x1,y1,t+2));
			else q.push(node(x1,y1,t+1));
		}
	}
	x1=q.top().x;
	y1=q.top().y;
	t1=q.top().t;
	BFS(x1,y1,t1);
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		int i,j,x,y;
		q.empty();
		getchar();
		memset(vis,0,sizeof(vis));
		for (i=1;i<=n;i++)
		{	
			for (j=1;j<=m;j++)
			{
				scanf("%c",&map[i][j]);
				if (map[i][j]=='a')
				{
					q.push(node(i,j,0));
					vis[i][j]=1;
				}
			}
			getchar();
		}
		f=0x7fffffff;
		BFS(q.top().x,q.top().y,0);
		cout<<f<<endl;
		cout<<x2<<" "<<y2<<endl;
	}
}
