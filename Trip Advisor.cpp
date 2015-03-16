#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int ff,n,m;
int vis[100010],g[100010];
map<int,vector<int> >f;
int find(int n)
{
	if (n!=g[n]) g[n]=find(g[n]);
	return g[n];
}
int fff(int a,int b)
{
	int i;
	if (a==b) return 0;
	if (a>b)
	{
		a=a+b;			
		b=a-b;
		a=a-b;
	}
	for (i=1;i<=f[a].size();i++)
		if (b==f[a][i-1]) return 1;
	return 0;
}
int DFS(int a,int b,int c)
{
	int i;
	if (a==b) 
		if (vis[c]==1) return 1;
		else return 0;
	for (i=1;i<=n;i++)
	{
		if (ff) return ff;
		if (vis[i]==0 && fff(a,i))
		{
			vis[i]=1;
			ff=DFS(i,b,c);
			vis[i]=0;
		}
	}
	return ff;
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		f.clear();
		while (m--)
		{
			int x,y,a,b,i;
			scanf("%d%d",&a,&b);
			if (a==b) continue;
			if (a>b)
			{
				a=a+b;
				b=a-b;
				a=a-b;
			}
			x=find(a);
			y=find(b);
			g[x]=y;
			for (i=1;i<=f[a].size();i++)
				if (b==f[a][i-1]) break;
			if (i-1==f[a].size() || f[a].size()==0) 
				f[a].push_back(b);
		}
		int q;
		scanf("%d",&q);
		while (q--)
		{
			int a,b,c,x,y,z;
			ff=0;
			scanf("%d%d%d",&a,&b,&c);
			for (int i=1;i<=n;i++)
				vis[i]=0;
			vis[a]=1;
			x=find(a);
			y=find(b);
			z=find(c);
			if ((x==y) && (y==z) && DFS(a,b,c)) printf("Yes\n");
			else printf("No\n");
		}
	} 
	return 0;
}
