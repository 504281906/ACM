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
LL dp[30][5];
LL f[30];
void INIT()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1;i<=20;i++)
	{
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];	//dp[i][0]代表长度为i不含49的方案数 
		dp[i][1]=dp[i-1][0];				//dp[i][1]代表长度为i高位为9的方案数 
		dp[i][2]=dp[i-1][1]+dp[i-1][2]*10;	//dp[i][2]代表长度为i含49的方案数 
	}
}
int main()
{
	int T,i;
	LL n;
	INIT();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&n);
		n++;
		memset(f,0,sizeof(f));
		int t=0;
		while (n)
		{
			f[++t]=n%10;
			n/=10;
		}
		f[t+1]=0;
		LL ans=0;
		int flag=0;
		for (i=t;i>=1;i--)
		{
			ans+=f[i]*dp[i-1][2];
			if (flag)
				ans+=f[i]*dp[i-1][0];
			else
			if (f[i]>4)
				ans+=dp[i-1][1];
			if (flag==0 && f[i+1]==4 && f[i]==9)
			{
				flag=1;
			//	ans+=1;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
