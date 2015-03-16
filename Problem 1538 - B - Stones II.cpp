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
struct node 
{
	int a,b;
}f[1010];
int dp[1010][1010];
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int main()
{
	int n,i,j;
	while (~scanf("%d",&n) && n)
	{
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&f[i].a,&f[i].b);
		//	f[i].c=f[i].a/f[i].b;
		}
		sort(f+1,f+n+1,cmp);
		for (i=1;i<=n;i++)
			for (j=0;j<=n;j++)
				if (dp[i-1][j]>dp[i-1][j+1]+f[i].a-j*f[i].b)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i-1][j+1]+f[i].a-j*f[i].b;
		printf("%d\n",dp[n][0]);
	}
	return 0;
}
