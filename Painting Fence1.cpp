#include <bits/stdc++.h>
using namespace std;
__int64 a[5010],bb[5010],dp[5010][5010][2];
#define min(a,b) a>b?b:a
int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	memset(dp,0,sizeof(dp));
	dp[1][1][0]=1;
	dp[1][1][1]=1;
	for (i=1;i<=n;i++)
	{
		bb[i]=n;
		if (a[i]<bb[i]) bb[i]=a[i];
		int h=min(bb[i-1],bb[i]);
		for (j=1;j<=h;j++)
		{
			dp[i][j][0]=dp[i-1][bb[i-1]][0];
			dp[i][j][1]=dp[i-1][j][0]+1;
			//if (j<=min(a[i-1],a[i])) break;
		}
		if (bb[i]>=bb[i-1])
		{
			for (j=bb[i-1]+1;j<=bb[i];j++)
			{
				dp[i][j][0]=dp[i][j-1][0]+1;
				dp[i][j][1]=dp[i][bb[i-1]][0]+1;
			}
		}
		else
		{
			for (j=1;j<=bb[i];j++)
			{
				dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i][j][1]);
				//dp[i][j][0]=min(dp[i-1][bb[i-1]][1],dp[i][j][0]);
				dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+(bb[i-1]-1!=j));
			}
		}
	}
	ans=0x3fffffff;
	if (ans>dp[n][bb[n]][0]) ans=dp[n][bb[n]][0];
	if (ans>dp[n][bb[n]][1]) ans=dp[n][bb[n]][1];
	cout<<ans<<endl;
	return 	0;
}
