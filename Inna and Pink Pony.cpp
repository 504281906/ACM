#include <cstdio>
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
//#ifdef DEBUG

struct node
{
	int i,j;
	node(int a,int b):i(a),j(b){}
};
int t,n,m,i,j,a,b;
int mmap[10002][10002];
int panduan(node x)
{
	if (x.i==1 && x.j==m) return 1;
	if (x.i==1 && x.j==1) return 1;
	if (x.i==n && x.j==1) return 1;
	if (x.i==n && x.j==m) return 1;
	return 0;
}
int BFS()
{
	queue<node>q;
	q.push(node(i,j));
	while (!q.empty())
	{
		node x=q.front();
		q.pop();
		if (panduan(x)) return t;
		else 
		{
			node y=x;
			y.i=x.i-a;y.j=x.j-b;
			if (y.i>0 && y.j>0 && mmap[y.i][y.j]==0) 
				q.push(node(y.i,y.j));
			y.i=x.i-a;y.j=x.j+b;
			if (y.i>0 && y.j<=m && mmap[y.i][y.j]==0)
				q.push(node(y.i,y.j));
			y.i=x.i+a;y.j=x.j-b;
			if (y.i<=n && y.j>0 && mmap[y.i][y.j]==0) 
				q.push(node(y.i,y.j));
			y.i=x.i+a;y.j=x.j+b;
			if (y.i<=n && y.j<=m && mmap[y.i][y.j]==0) 
				q.push(node(y.i,y.j));
		}
		t++;
	}
	return 0;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	while (~scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b))
	{
		memset(mmap,0,sizeof(mmap));
		mmap[i][j]=1;
		t=0;
		int f=BFS();
		if (f==0) printf("Poor Inna and pony!\n");
		else printf("%d\n",f);
	}
	return 0;
}
