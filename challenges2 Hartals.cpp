#include <cstdio>
#include <cstring>
int vist[3700]; 
int main()
{
	int T,a,n,m;
	scanf("%d",&T);
	while (T--)
	{
		int t=0;
		memset(vist,0,sizeof(vist));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&a);
			for (int j=a;j<=n;j+=a)
			{
				if (!vist[j] && (j % 7!=0) && (j % 7!=6))
				{
					vist[j]=1;
					t++;
				}	
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
