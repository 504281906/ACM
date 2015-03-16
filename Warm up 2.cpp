#include <cstdio>
#include <cstring>
int dp[1010][1010],h[1010][1010],s[1010][1010];
int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		int x=0,y=0,a,b;
		memset(s,0,sizeof(s));
		memset(h,0,sizeof(h)); 
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			h[a][b]=1;
			if (x<a) x=a;
			if (y<b) y=b;
		}
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			s[a][b]=1;
			if (x<a) x=a;
			if (y<b) y=b;	
		}
		memset(dp,0,sizeof(dp));
		for (int i=0;i<=y+1;i++)
			for (int j=1;j<=x+1;j++)
			{
				if(dp[j][i]<dp[j-1][i]+h[j-1][i])
					dp[j][i]=dp[j-1][i]+h[j-1][i];
				if (dp[j][i]<dp[j][i-1]+s[j][i-1])
					dp[j][i]=dp[j][i-1]+s[j][i-1];
			}
		printf("%d\n",dp[x+1][y+1]);
	}
	return 0;
} 
