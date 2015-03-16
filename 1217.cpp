#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
int n;
double a[35][35];
int ff(int x)
{
	int vist[35];
	double g[35];
	memset(vist,0,sizeof(vist));
	memset(g,0,sizeof(g));
	queue<int>q;
	while (!q.empty())
		q.pop();
	q.push(x);
	vist[x]=1;
	g[x]=1.0;
	while (!q.empty())
	{
		int x1=q.front();
		q.pop();
		vist[x1]=0;
		for (int i=1;i<=n;i++)
			if (g[x1]*a[x1][i]>g[i])
			{
				g[i]=g[x1]*a[x1][i];
				if (g[x]>1.0)
				return 1;
				if (!vist[i])
				{
					vist[i]=1;
					q.push(i);
				}
			}
	}
	return 0;
}
int main()
{
	map<string,int>mp;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		if (i==j)
		a[i][j]=1.0;
		else 
		a[i][j]=0;
	}
	int c=1;
	while (~scanf("%d",&n)&& n)
	{
		mp.clear();
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
		{
			char s[100];
			scanf("%s",s);
			mp[s]=i;
		}
		int m;
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			char s[100],s1[100];
			double f;
			scanf("%s%lf%s",&s,&f,&s1);
			a[mp[s]][mp[s1]]=f*1.0;
		}
		bool b=true; 
		for (int i=1;i<=n;i++)
			if (ff(i))
			{
				printf("Case %d: Yes\n",c++);
				b=false;
				break;
			}
		if (b) printf("Case %d: No\n",c++);
	}
	return 0;
}
