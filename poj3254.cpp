#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;    //1表示有牛，0表示没牛 
const int mod=100000000;
int n,m,l;
int sta[1<<15];
int dp[1<<15][15];      //dp[i][j]第i个状态第j行有多少种 
int cas[15];
int ok(int x)
{
	if (x & (x<<1)) return 0;  //判断当前x状态是否满足相邻是否有为1。 
	return 1;
}
void cls()
{
	l=0;
	for (int i=0;i<1<<m;i++)
		if (ok(i)) sta[++l]=i;
}
int pd(int x,int k)
{
	if(x & cas[k]) return 0;
	return 1;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	cls();
	for (i=1;i<=n;i++)
	{
		cas[i]=0;     //表示第i行第哪些位置不能放(牛) 
		for (j=1;j<=m;j++)
		{
			scanf("%d",&k);
			if (k==0) cas[i]+=1<<(m-j);
		}
	}
	memset(dp,0,sizeof(dp));
	for (i=1;i<=l;i++)         //l表示可行的状态总数(也就是说没有相邻的牛)
		if (pd(sta[i],1))
			dp[i][1]=1;
	for (i=2;i<=n;i++)
		for (j=1;j<=l;j++)    //表示第i行第j个状态 
		{
			if (!pd(sta[j],i)) continue;
			for (k=1;k<=l;k++)  //表示第i-1行第k个状态 
			{
				if (!pd(sta[k],i-1)) continue;
				if (sta[j] & sta[k]) continue;
				dp[j][i]=(dp[j][i]+dp[k][i-1]) % mod;
			}
		}
	int ans=0;
	for (i=1;i<=l;i++)
		ans=(ans+dp[i][n]) % mod;
	cout<<ans<<endl;
}
