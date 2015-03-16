#include <bits/stdc++.h>
using namespace std;
#define min(a,b) a>b?b:a
int dp[5010][2];
int a[5010];
int main()
{
	int n,i;
	scanf("%d",&n);
	a[0]=0;
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,0,sizeof(dp));
	for (i=1;i<=n;i++)
	{
		if (a[i]>a[i-1])
		{
			dp[i][0]=min(dp[i-1][0]+a[i]-a[i-1],dp[i-1][1]+a[i]);
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
		}
		else
		{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1]+a[i]);
			dp[i][1]=min(dp[i-1][0],dp[i-1][1]+1);
		}
	}
	printf("%d\n",min(dp[n][0],dp[n][1]));
	return 0;
}
