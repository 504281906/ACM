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
int n,i,j,k,t;
int dp[1<<10+1],a[10][10];
int main()
{
	while (1==scanf("%d",&n) && n) 
	{
		memset(dp,0,sizeof(dp));
		for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		for (t=0;t<(1<<n);t++)
		{
			for (i=0;i<n;i++)
			{
				if (t & (1<<i)) continue;
				for (j=0;j<n;j++)
				{
					if ((i==j) || (t & (1<<j))) continue;
					int newt=t+(1<<j);
					dp[newt]=max(dp[newt],dp[t]+a[i][j]);
				}
			}
		}
		int ans=0;
		for (i=0;i<n;i++)
			ans=max(ans,dp[((1<<n)-1) ^ (1<<i)]);
		cout<<ans<<endl;
	}
	return 0;
}
