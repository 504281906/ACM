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
int bag[50],a[50],d[50],c[50][50];
int dp[2100000];
#define max(a,b) a>b?a:b
int main()
{
	int g,b,s,i,j,k,n,m;
	while (~scanf("%d%d%d",&g,&b,&s) && (g + b +s))
	{
		memset(c,0,sizeof(c));
		for (i=1;i<=b;i++)
		{
			scanf("%d",&n);
			for (j=1;j<=n;j++)
			{
				scanf("%d",&m);
				c[i][m]++;
			}
		}
		n=1<<b;
		for (i=1;i<n;i++)
		{
			dp[i]=-10000;
			for (j=1;j<=g;j++)
				a[j]=0;
			for (j=1;j<=b;j++)
			{
				if ((i & (1<<(j-1)))==0)
				{
					for (k=1;k<=g;k++)
					{
						a[k]+=c[j][k];
						while (a[k]>=s)
							a[k]-=s;
					}
				}
			}
			for (j=1;j<=b;j++)
			{
				int ss=0;
				if (i & (1<<(j-1)))
				{
					for (k=1;k<=g;k++)
						d[k]=a[k];
					for (k=1;k<=g;k++)
					{
						d[k]+=c[j][k];
						if (d[k]>=s)
							ss=ss+d[k]/s;
					}
					if (ss>0) dp[i]=max(dp[i],ss+dp[i^(1<<(j-1))]);
					else dp[i]=max(dp[i],ss-dp[i^(1<<(j-1))]);
				}
				
			}
		}
		printf("%d\n",dp[n-1]);
	}
	return 0;
}

