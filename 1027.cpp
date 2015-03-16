#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,y;
int vist[1010];
int a[1010];
int dfs(int x)
{
	if (y>m) return 0;
	if (x==n+1) 
	{
		y++;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (vist[i]==0)
		{
			a[x]=i;
			vist[i]=1;
			dfs(x+1);
			vist[i]=0;
		}
		if (y==m) 
		{
			for (int j=1;j<n;j++)
			printf("%d ",a[j]);
			printf("%d\n",a[n]);
			y++;
			return 0;
		}
	}
	return 0;
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		y=0;
		memset(vist,0,sizeof(vist));
		dfs(1);
	}
	return 0;
}
