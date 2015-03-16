#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 0x7fffffff
int f[2010][2010];
int vis[2010];
int main()
{
	int T,i,j,n,mm;
	while(~scanf("%d%d",&n,&mm))
	{
		for (i=1;i<=n;i++)
		{
			vis[i]=1;
			for (j=i+1;j<=n;j++)
				f[i][j]=f[j][i]=M;
		}
		for (i=1;i<=mm;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (c<f[a][b])
				f[a][b]=f[b][a]=c;
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
			if (s<m && pos!=0) s=m;
			vis[pos]=0;
			for (j=1;j<=n;j++)
				if (vis[j] && f[pos][j]<f[1][j])
					f[1][j]=f[pos][j];
		}
		cout<<s<<endl;
	}
	return 0;
}
