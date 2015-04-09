#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 0x7fffffff
int f[110][110],vis[110];
int main()
{
	int n,i,j,l;
	while (~scanf("%d",&n) && n>0)
	{
		memset(vis,1,sizeof(vis));
		int l=n*(n-1)/2;
		for (i=1;i<=l;i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if (d==1) c=0;
			f[b][a]=f[a][b]=c;
		}
		vis[1]=0;
		int s=0;
		for (i=2;i<=n;i++)
		{
			int m=M,pos=0;
			for (j=1;j<=n;j++)
			if (vis[j] && f[1][j]<m)
			{
				m=f[1][j];
				pos=j;
			}
			s+=m;
			vis[pos]=0;
			for (j=1;j<=n;j++)
				if (vis[j] && f[pos][j]<f[1][j])
					f[1][j]=f[pos][j];
		}
		cout<<s<<endl;
	}
	return 0;
}
