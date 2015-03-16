#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 1000000
int f[155][155];
int vis[155];
int main()
{
	int p,i,j,n;
	while (~scanf("%d",&p) && p)
	{
		scanf("%d",&n);
		memset(vis,1,sizeof(vis));
		memset(f,M,sizeof(f));
		for (i=1;i<=n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (c<f[a][b])
				f[a][b]=f[b][a]=c;
		}
		vis[1]=0;
		int s=0;
		for (i=2;i<=p;i++)
		{
			int m=M,pos=0;
			for (j=1;j<=p;j++)
				if (vis[j] && f[1][j]<m)
				{
					m=f[1][j];
					pos=j;
				}
			if (m!=M) s+=m;
			vis[pos]=0;
			for (j=1;j<=p;j++)
				if (vis[j]&& f[pos][j]<f[1][j])
					f[1][j]=f[pos][j];
		}
		cout<<s<<endl;
	}
	return 0;
}
