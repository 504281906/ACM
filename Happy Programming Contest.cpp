#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
struct node
{
	int v,w;
}a[55];
int dp[55][1010],sum[55][1110],num[55][1110]; 
int cmp(const void *a,const void *b)
{
	if ((*(node *)a).v==(*(node *)b).v)
		return (*(node *)a).w>(*(node *)b).w;
	return (*(node *)a).v-(*(node *)b).v;
}
int main()
{
	int t,n,i,j,T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&t,&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i].v);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i].w); 
		qsort(a,n+1,sizeof(a[0]),cmp);
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		for (i=1;i<=n;i++)
		{
			for (j=0;j<=t;j++)
			{
				dp[i][j] = dp[i-1][j]; 
				num[i][j] = num[i-1][j];
                sum[i][j] = sum[i-1][j]; 
				if (j>=a[i].v)
				{
				if (dp[i][j]<=dp[i-1][j-a[i].v]+a[i].w)
				{
					if (dp[i][j]<dp[i-1][j-a[i].v]+a[i].w)
					{
						dp[i][j]=dp[i-1][j-a[i].v]+a[i].w;
						num[i][j]=num[i-1][j-a[i].v]+1;
						sum[i][j]=sum[i-1][j-a[i].v]+j;
					}
					else if (num[i][j]<=num[i-1][j-a[i].v]+1)
					{
						if (num[i][j]<num[i-1][j-a[i].v]+1)
						{
							num[i][j]=num[i-1][j-a[i].v]+1;
							sum[i][j]=sum[i-1][j-a[i].v]+j;
						}
						else if (sum[i][j]>sum[i-1][j-a[i].v]+j)
							sum[i][j]=sum[i-1][j-a[i].v]+j;
					} 
				}
				}	
			}
		}
		int max=0,sum1=0,num1=0;
		for(i = 0; i <= t; i++)
		{
            if( max < dp[n][i] )
			{
                max = dp[n][i];num1 = num[n][i];sum1 = sum[n][i];
            }    
            else if( max == dp[n][i] )
			{
                if( num1 < num[n][i] )
                {
                    num1 = num[n][i];
					sum1 = sum[n][i];    
				}
				else if( sum1 > sum[n][i] )
                    sum1 = sum[n][i];
            }        
        }
		printf("%d %d %d\n",max,num1,sum1);
	}
	return 0;
}
