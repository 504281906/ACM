#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 10000000
int f[M+10],g[M+10];
int find(int n)
{
	if (n!=f[n]) f[n]=find(f[n]);
	return f[n];
}
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int i,max=1;
		for (i=1;i<=M;i++)
		{
			f[i]=i;
			g[i]=1;
		}
		for (i=1;i<=n;i++)
		{
			int x,y,a,b;
			scanf("%d%d",&a,&b);
			x=find(a);
			y=find(b);
			if (x!=y)
			{
				f[y]=x;
				g[x]+=g[y];
				if (max<g[x]) max=g[x];
				g[y]=0;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
