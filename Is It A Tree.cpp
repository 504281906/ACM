#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int f[100010],g[100010],vis[100010];
int find(int n)
{
	if (n!=f[n]) f[n]=find(f[n]);
	return f[n];
}
int main()
{
	int i,a,b,t=1;
	bool flag=true;
	memset(vis,0,sizeof(vis));
	memset(g,0,sizeof(g));
	for (i=1;i<=100000;i++)
		f[i]=i;
	while (~scanf("%d%d",&a,&b) && (a+b)>=0)
	{
		if (a==0 && b==0)
		{
			int k=0;
			for (i=1;i<=100000;i++)
			if ((vis[i]) && (i==find(i)))
				k++;
			if (k>1) flag=false;
			if (flag) printf("Case %d is a tree.\n",t++);
			else printf("Case %d is not a tree.\n",t++);
			memset(vis,0,sizeof(vis));
			memset(g,0,sizeof(g));
			for (i=1;i<=100000;i++)
				f[i]=i;
			flag=true;
		}
		else
		{
			if (!flag) continue;
			int x,y;
			x=find(a);
			y=find(b);
			vis[a]=1;
			vis[b]=1;
			if (x==y || y!=b) flag=false;
			if (g[x]>=g[y])
			{
				g[x]++;
				f[y]=x;
			}
			else flag=false;
		}
	}
	return 0;
}
