#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define max 1000000
int f[510][510],n,m,k;
void ff()
{
	int s=0,vis[510],i,d[515];
	for (i=1;i<=n;i++)
	{
		vis[i]=1;
		d[i]=f[1][i];
	}
	vis[1]=0;
	for (i=2;i<=n;i++)
	{
		int j,pos=0,mm=max;
		for (j=1;j<=n;j++)
		if (vis[j] && mm>d[j])
		{
			pos=j;
			mm=d[j];
		}
		s+=mm;
		vis[pos]=0;
		if (s>=max) break;
		for (j=1;j<=n;j++)
			if (vis[j] && f[pos][j]<d[j])
			d[j]=f[pos][j];
	}
	if (s>=max) printf("-1\n");
		else printf("%d\n",s);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int i;
		memset(f,max,sizeof(f));
		scanf("%d%d%d",&n,&m,&k);
		for (i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (c<f[a][b])
			f[a][b]=f[b][a]=c;
		}
		for (i=0;i<k;i++)
		{
			int j,t,a[505];
			scanf("%d",&t);
			for (j=0;j<t;j++)
			scanf("%d",&a[j]);
			for (j=0;j<t;j++)
				for (int j1=j+1;j1<t;j1++)
					f[a[j]][a[j1]]=f[a[j1]][a[j]]=0;
		}
		ff();
	}
	return 0;
}
