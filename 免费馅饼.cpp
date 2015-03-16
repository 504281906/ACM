#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[100010][20],n,pos,t;
int main()
{
	while (~scanf("%d",&n) && n)
	{
		int mt=0;
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&pos,&t);
			dp[t][pos]++;
			if (mt<t) mt=t;
		}
		int s=0;
		for (int i=1;i<=5;i++)
		{
			for (int j=0;j<5-i;j++) dp[i][j]=0;
			for (int j=i+5+1;j<=10;j++) dp[i][j]=0;
			for (int j=5-i;j<=5;j++)
				dp[i][j]+=max(dp[i-1][j+1],dp[i-1][j]);
			for (int j=6;j<=5+i;j++)
				dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
		}
		for (int i=6;i<=mt;i++)
		{
			for (int j=0;j<=10;j++)
			dp[i][j]+=max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]);
		}
		for (int i=0;i<=10;i++)
		if (s<dp[mt][i])
		{
			s=dp[mt][i];
			//pos=i;
		}
		printf("%d\n",s);
	}
	return 0;
}
