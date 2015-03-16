#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int vis[105][105];
char mp[105][105];
struct node
{
	int x,y,z;
	node(int x,int y,int z)  
    {  
        this->x=x;  
        this->y=y;  
        this->z=z;
    }  
};
queue<node>q;
int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};
int pd(int a,int b)
{
	if (a<0 || a>=n || b<0 || b>=m || mp[a][b]=='-' || vis[a][b])
		return 0;
	else return 1;
}
void BFS()
{
	while (!q.empty())
	{
		node k=q.front();
		q.pop();
		if (k.z==0)
			vis[k.x][k.y]=1;
		else vis[k.x][k.y]=2;
		int f=(k.z+1)%2;
		for (int i=0;i<4;i++)
		{
			int x1=k.x+xx[i];
			int y1=k.y+yy[i];
			if (pd(x1,y1))
				q.push(node(x1,y1,f));
		}
	}
}
int main()
{
	int i,j;
	while (scanf("%d%d",&n,&m)==2)
	{
		getchar();
		for (i=0;i<n;i++)
			scanf("%s",mp[i]);
		memset(vis,0,sizeof(0));
		while (!q.empty()) q.pop();
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
			{
				if (!vis[i][j] && mp[i][j]=='.')
				{
					q.push(node(i,j,0));
					BFS();
				}
			}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (vis[i][j]==0)
					printf("-");
				else if (vis[i][j]==1)
					printf("B");
				else printf("W");
			}
			printf("\n");
		}
	}
	return 0;
}
