#include <stdio.h>
#include <string.h>
int f[110][110];
int main()
{
	int T,n,m,a,b,k;
	scanf("%d",&T);
	while (T--)
	{
		int s=0;
		scanf("%d%d%d",&n,&m,&k);
		memset(f,0,sizeof(f));
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			f[a][b]=f[b][a]=1;
		}
		while (1)
		{
			int t=0,num;
			for (int i=0;i<n;i++)
			{
				for (int j=i+1;j<n;j++)
				{
					num=0;
					if (!f[i][j])
					{
						for (int l=0;l<n;l++)
						{
							if (f[i][l] && f[j][l])
								num++;
						}
						if (num>=k)
						{
							t++;
							f[i][j]=f[j][i]=1;
						}
					}
				}
			}
			if (t)
				s+=t;
			else break;
		}
		printf("%d\n",s); 
	}
	return 0; 
} 
