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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};
struct node
{
	int x,y;
	node (){};
	node (int x,int y):x(x),y(y){};
};
node st[10];
int T,ans,sum,n,m,maxx,rres;
int vis[20][20];
char mp[20][20];
int d[10];
queue<node> q;
int BFS(int gg)
{
	int s=0;
	vis[q.front().x][q.front().y]=gg;
	while (!q.empty())
	{
		node k=q.front();
		q.pop();
		for (int i=0;i<4;i++)
		{
			int va=k.x+xx[i];
			int vb=k.y+yy[i];
			if (vis[va][vb]) continue;
			if (mp[va][vb]=='.' || mp[va][vb]=='C')
			{
				//if (vis[va][vb]==0)
				vis[va][vb]=gg;
				q.push(node(va,vb));
				if(mp[va][vb]=='C')
					s++;
			}
		}
	}
	return s;
}
void back(int x,int y,int gg)
{
	vis[x][y]=0;
    for (int i=0;i<4;i++)
	{
        int sx=x+xx[i];
        int sy=y+yy[i];
        if (sx<1 || sy<1 || sx>n || sy>m) continue;
        if (vis[sx][sy]!=gg) continue;
        back(sx,sy,gg);
    }
}
void go(int num) //第几个石头 
{
	if (num>=sum) return;
	for (int i=0;i<sum;i++)
	{
		if (d[i]) continue;
		d[i]=1;
		int x=st[i].x;
		int y=st[i].y;
		for (int j=0;j<4;j++)
		{
			int sx=x-xx[j];
			int sy=y-yy[j];
			if (sx<1 || sx>n || sy<1 || sy>m) continue;
			if (!vis[sx][sy]) continue;
			
			int tx=x+xx[j];
			int ty=y+yy[j];
			if (tx<1 || tx>n || ty<1 || ty>m) continue;
			if (mp[tx][ty]!='.' && !vis[tx][ty]) continue;
			
			char c=mp[tx][ty];
			mp[tx][ty]='O';
			mp[x][y]='.';
			q.push(node(x,y));
			rres=0;
			int res=BFS(i+2);
			maxx+=res;
			ans=max(maxx,ans);
			go(num+1);
			back(x,y,i+2);
			maxx-=res;
			mp[x][y]='O';
			mp[tx][ty]=c;
		}
		go(num+1);
		d[i]=0;
	}
}
int main()
{
	int i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		sum=0;
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		while (!q.empty()) q.pop();
		//getchar();
		for (i=1;i<=n;i++)
		{
			//getchar();
			//scanf("%s",&mp[i]+1);
			cin>>mp[i]+1;
			for (j=1;j<=m;j++)
			{
				if (mp[i][j]=='S')
				{
					q.push(node(i,j));
					vis[i][j]=1;
					mp[i][j]='.';
				}
				if (mp[i][j]=='O')
				{
					st[sum].x=i;
					st[sum].y=j;
					sum++;			
				}
			}
		}
		/*for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			cout<<mp[i][j];
			cout<<endl;
		}*/
		memset(d,0,sizeof(d));
		rres=0;
		int f1=BFS(1);
		maxx=0;ans=0;
		go(0);
		ans+=f1;
		cout<<ans<<endl;
	}
	return 0;
}
/*
6
3 4
S.OC
..O.
.XCX
4 6
S.X.CC
..XOCC
...O.C
....XC
4 4
.SXC
OO.C
..XX
.CCC
4 7
S.XX..X
..XC.CX
...XOOC
.......
4 4
SCXC
.CXC
.OCC
CCX.
*/
