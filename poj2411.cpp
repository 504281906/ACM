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
LL dp[1<<11][12];
bool sta[1<<11];
int t,n,m,i,j;
bool pd(int x)
{
	int k=0;
	while (x)
	{
		if (x & 1) k++;
		else
		{
			if (k & 1) return 0;
			else k=0;
		}
		x>>=1;
	}
	if (k & 1) return 0;
	else return 1;
}
int check(int x,int y)
{
	if ((x | y)!=t-1) return 0;
	return sta[x & y];
}
int main()
{
	memset(sta,0,sizeof(sta));
	t=1<<11;
	for (i=0;i<t;i++)
		if (pd(i))
			sta[i]=1;
	while (~scanf("%d%d",&n,&m) && (n+m))
	{
		memset(dp,0,sizeof(dp));
		t=1<<m;
		for (i=0;i<t;i++)
			if (sta[i])
				dp[i][0]=1;
		for (int l=1;l<n;l++)
		{
			for (i=0;i<t;i++)
			for (j=0;j<t;j++)
			{
				if (!check(i,j)) continue;
				dp[i][l]+=dp[j][l-1];
			}
		}
		cout<<dp[t-1][n-1]<<endl;
	}
	return 0;
}
