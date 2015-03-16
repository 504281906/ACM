#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define M 0x7fffffff
int f[510][510];
int vis[510];
int main()
{
	int T,i,j,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			vis[i]=1;
			for (j=1;j<=n;j++)
				scanf("%d",&f[i][j]);
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
