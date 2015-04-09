#include <cstdio>
#include <cstring>
#define INF 0x3fffffff
int f[510][510];
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		int s=0,vist[n+1];
		memset(vist,0,sizeof(vist));
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		f[i][j]=f[j][i]=INF;
		for (int i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			f[a][b]=f[b][a]=c;
		}
		for (int i=2;i<=n;i++)
		{
			int max=INF,pos;
			for (int j=1;j<=n;j++)
				if (max>f[1][j] && !vist[j])
				{
					pos=j;
					max=f[1][j];
				}
			vist[pos]=1;
			for (int j=1;j<=n;j++)
			if (f[1][j]>f[1][pos]+f[pos][j] &&	!vist[j])
			f[1][j]=f[1][pos]+f[pos][j];
		} 
		printf("%d\n",f[1][n]);
	}
	return 0;
}
