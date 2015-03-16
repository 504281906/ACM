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
#define LL __int64
char s[55][55];
int sg[55][55];
int mex(int x,int y)
{
	int i,j,vis[660];
	memset(vis,0,sizeof(vis));
	for (i=0;i<x;i++)
	for (j=0;j<y;j++)
	vis[sg[i][y]^sg[x][j]]=1;
	for (i=0;;i++)
	if (!vis[i]) return i;
}
int main()
{
	int i,j,n,m;
	for (i=0;i<=50;i++)
	sg[i][0]=sg[0][i]=i;
	for (i=1;i<=50;i++)
	for (j=1;j<=50;j++)
		sg[i][j]=mex(i,j);
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		int ans=0;
		for (i=0;i<n;i++)
			scanf(" %s",&s[i]);
		for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		if (s[i][j]=='#')
			ans^=sg[i][j];
		if (ans) puts("John");
		else puts("Jack");
	}
	return 0;
}
