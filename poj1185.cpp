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
#define max(a,b) a>b?a:b
int dp[110][100][100];
int sta[1100];
int cas[1100];
int pd(int x)
{
	if (x & (x<<1)) return 0;
	if (x & (x<<2)) return 0;
	return 1;
}
int js1(int x)
{
	int ans=0;
	while (x)
	{
		if (x&1==1) ans++;
		x>>=1;
	}
	return ans;
}
int num[1100];
int main()
{
	int n,m,i,j,k,l;
	scanf("%d%d",&n,&m);
	int t=0;
	for (i=0;i<1<<m;i++)
		if (pd(i))
		{
			sta[++t]=i;
			num[t]=js1(i);
		}
	for (i=1;i<=n;i++)
	{
		getchar();
		for (j=1;j<=m;j++)
		{
			char c;
			scanf("%c",&c);
			if (c=='H') cas[i]+=1<<(m-j);
		}
	}
	memset(dp,-1,sizeof(dp));
	for (i=1;i<=t;i++)
		if ((sta[i] & cas[1])==0)
			dp[1][1][i]=num[i];
	for (i=2;i<=n;i++)
		for (j=1;j<=t;j++)
		{
			if (sta[j] & cas[i]) continue;
			for (k=1;k<=t;k++)
			{
				if (sta[j] & sta[k]) continue;
				for (l=1;l<=t;l++)
				{
					if (sta[j] & sta[l]) continue;
					dp[i][k][j]=max(dp[i][k][j],dp[i-1][l][k]+num[j]);
				}
			}
		}
	int ans=-1;
	for (i=1;i<=n;i++)
	for (j=1;j<=t;j++)
	for (k=1;k<=t;k++)
		ans=max(ans,dp[i][j][k]);
	cout<<ans<<endl;
	return 0;
}
