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
//#define DEBUG
int l,m,ci;
map<string,int> mp;
char ss[20];
int vis[20];
int a[20];
void DFS(int k,int y)
{
	int i;
	if (k==l)
	{
		if (y%m==0 &&mp[ss]==0)
		{
			ci++;
			mp[ss]=1;
			//printf("%s\n",ss);
			return;
		}
	}
	for (i=0;i<l;i++)
	{
		if (k==0 && a[i]==0) continue;
		if (vis[i]==0)
		{
			int yy=y;
			y=y*10+a[i];
			y%=m;
			vis[i]=1;
			ss[k]=a[i]+'0';
			DFS(k+1,y);
			y=yy;
			vis[i]=0;
		}
	}
	return;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int i;
	char s[20];
	while (~scanf("%s %d",&s,&m))
	{
		l=strlen(s);
		mp.clear();
		memset(ss,0,sizeof(ss));
		memset(vis,0,sizeof(vis));
		for (i=0;i<l;i++)
			a[i]=s[i]-'0';
		ci=0;
		DFS(0,0);
		printf("%d\n",ci);
	}
	return 0;
}
