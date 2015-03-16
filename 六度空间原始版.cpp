#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,a,b;
	int f[210][210];
	while (~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			f[a][b]=f[b][a]=1;
			for (int j=0;j<n;j++)
			{
				if (j!=a && j!=b)
				{
				if ( (f[j][a]==0 || f[j][a]!=0 && f[j][a]>f[j][b]+1)&& f[j][b]!=0)
					f[a][j]=f[j][a]=f[j][b]+1;
				if ( (f[j][b]==0 || f[j][b]!=0 && f[j][b]>f[j][a]+1)&& f[j][a]!=0)
					f[b][j]=f[j][b]=f[j][a]+1;
				}
			}
		}
			int kk=1;
			for (int i=0;i<n;i++)
			{
				if (kk) 
				for (int j=i+1;j<n;j++)
					if (f[i][j]==0 || f[i][j]>7) 
					{
						printf("No\n");
						kk=0;
						break;
					}
			}
			if (kk) printf("Yes\n");
	}
	return 0;
}
