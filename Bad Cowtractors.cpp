#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define M -1000000
int f[1100][1100],vis[1100];
int main()
{
	int n,m,t=0;
	while (~scanf("%d%d",&n,&m))
	{
		int i,j,s=0;
		memset(f,M,sizeof(f));
		memset(vis,0,sizeof(vis));
		for (i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (f[a][b]<c) 
				f[a][b]=f[b][a]=c;
		}
		vis[1]=1;
		bool flag=true;
		for (i=2;i<=n;i++)
		{
			int max=M,pos=0;
			for (j=1;j<=n;j++)
				if (!vis[j] && f[1][j]>max)
				{
					max=f[1][j];
					pos=j;
				}
			if (pos==0) 
			{
				flag=false;
				break;
			}
			s+=max;
			vis[pos]=1;
			for (j=1;j<=n;j++)
				if (!vis[j] && f[pos][j]>f[1][j])
					f[1][j]=f[pos][j];
		}
		if (flag) cout<<s<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
