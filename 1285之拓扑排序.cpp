#include <cstdio>
#include <cstring>
int vist[510],f[510][510],n,m;
void ff()
{
	int i=1,k=0;
	while (i<=n)
	{
		if (k==n) return;
		if (vist[i])
		{
			i++;
			continue;
		}
		int t=1;
		for (int j=1;j<=n;j++)
			if (f[j][i]==1)
			{
				t=0;
				i++;
				break;
			}
		if (t)
		{
			vist[i]=1;
			printf(k==0?"%d":" %d",i);
			for (int j=1;j<=n;j++)
				f[i][j]=0;
			k++;
			i=1;
		}
	}
}
int main()
{
	while (~scanf("%d%d",&n,&m))
	{
		memset(f,0,sizeof(f));
		memset(vist,0,sizeof(vist));
		for (int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			f[a][b]=1;
		}
		ff();
		printf("\n");
	}
	return 0;
} 
