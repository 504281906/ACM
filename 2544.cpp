#include <cstdio>
#include <cstring>
int f[110][110];
#define INF 0x3fffffff; 
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=INF;
		for (int i=1;i<=m;i++)
		{
			int a,b,s;
			scanf("%d%d%d",&a,&b,&s);
			f[b][a]=f[a][b]=s;
		} 
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (f[i][j]>f[i][k]+f[k][j])
						f[j][i]=f[i][j]=f[i][k]+f[k][j];
		printf("%d\n",f[1][n]);
	}
	return 0;
} 
