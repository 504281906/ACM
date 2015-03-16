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
int dis[15][15],kfc[60000][15],dp[60000][15];
int t,n,j,m,i,u,v,d;
int sta[12]={0,1,3,9,27,81,243,729,2187,6561,19683,59049};
#define INF 0x7fffff1f
#define min(a,b) a>b?b:a
int main()
{
	for (i=0;i<59049;i++)
	{
		t=i;
		for (j=1;j<=10;j++)
		{
			kfc[i][j]=t % 3;
			t/=3;
			if (t==0) break;
		}
	}
	while (2==scanf("%d%d",&n,&m))
	{
		for (i=1;i<60000;i++)
			for (j=1;j<=12;j++)
			{
				if (i<15)
					dis[i][j]=INF;
				dp[i][j]=INF;
			}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&d);
			dis[u][v]=dis[v][u]=min(dis[u][v],d);
		}
		for (i=1;i<=n;i++)
			dp[sta[i]][i]=0;
		int ans=INF;	
		for (t=0;t<sta[n+1];t++)
		{
			int find=1;
			for (i=1;i<=n;i++)
			{
				if (kfc[t][i]==0) find=0;
				if (dp[t][i]==INF) continue;
				for (j=1;j<=n;j++)
				{
					if (j==i || kfc[t][j]==2 || dis[i][j]==INF) continue;
					int newt=t+sta[j];
					dp[newt][j]=min(dp[newt][j],dp[t][i]+dis[i][j]);
				}
			}
			if (find)
				for (i=1;i<=n;i++)
					ans=min(ans,dp[t][i]);
		}
		if (ans==INF) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}
