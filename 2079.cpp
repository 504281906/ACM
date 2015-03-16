#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[50];
int n,m,j,i,a,b,k;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			for (j=n;j>=a;j--)
			{
				for (k=1;k<=b;k++)
				{
					if (j-a*k>=0)
						dp[j]+=dp[j-a*k];
					else break;
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}

