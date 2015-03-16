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
#define LL __int64
#define EPS 1e-8
using namespace std;
int dp[1<<10+1],a[20][20],n,i,j,k,t;
int main()
{
	while (~scanf("%d",&n) && n)
	{
		memset(dp,0,sizeof(dp));
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		k=(1<<n);
		for (t=0;t<k;t++)
		{
			for (i=0;i<n;i++)
			{
				if (t & (1<<i)) continue;
				for (j=0;j<n;j++)
				{
					if (i==j || (t & (1<<j))) continue;
					int m=t+(1<<j);
					dp[m]=max(dp[m],dp[t]+a[i][j]);
				}
			}
		}
		int ans=0;
		for (i=0;i<n;i++)
			ans=max(ans,dp[(k-1)^(1<<i)]);
		cout<<ans<<endl;
	}
	return 0;
}
