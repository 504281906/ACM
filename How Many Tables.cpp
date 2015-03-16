#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int f[1010],vis[1010];
int find(int x)
{
	if (x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		int i;
		for (i=1;i<=n;i++)
		{
			f[i]=i;
			vis[i]=1;
		}
		for (i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);		
			a=find(a);
			b=find(b); 
			if (a>b)
			{
				a=a+b;
				b=a-b;
				a=a-b;
			}
			f[b]=a;
		}
		int t=0;
		for (i=1;i<=n;i++)
		if (vis[find(i)])
		{
			t++;
			vis[i]=0;
		}
		printf("%d\n",t);
	}
	return 0;
}
