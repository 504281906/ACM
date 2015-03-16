#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
#define LL __int64
#define INF 0x7fffffff
#define min(a,b) a>b?b:a
int dis[20][20];
int dp[2050][20];
int main()
{
	int n,i,j,k,t;
	while (~scanf("%d",&n)&&n)
	{
		for (i=0;i<=n;i++)
			for (j=0;j<=n;j++)
				scanf("%d",&dis[i][j]);
		for (k=0;k<=n;k++)
			for (i=0;i<=n;i++)
				for (j=0;j<=n;j++)
					if (dis[i][k]+dis[k][j]<dis[i][j])
						dis[i][j]=dis[i][k]+dis[k][j];
		for (t=0;t<(1<<n);t++)
		{
			for (i=1;i<=n;i++)
			if (t & (1<<(i-1)))
				if (t==(1<<(i-1))) dp[t][i]=dis[0][i];
				else
				{
					dp[t][i]=INF;
					for (j=1;j<=n;j++)
						if((t &(1<<(j-1))) && (j!=i))
							dp[t][i]=min(dp[t][i],dp[(1<<(i-1))^t][j]+dis[j][i]);
				}
		}
		int ans=dp[(1<<n)-1][1]+dis[1][0];
		for (i=2;i<=n;i++)
			if (dp[(1<<n)-1][i]+dis[i][0]<ans)
				ans=dp[(1<<n)-1][i]+dis[i][0];
		printf("%d\n",ans);
	}
	return 0;
}
