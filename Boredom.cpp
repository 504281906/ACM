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
LL dp[100010],f[100010],a[100010];
int main()
{
	int n,i;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	int max=0;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[a[i]]++;
		if (max<a[i]) max=a[i];
	}
	for (i=1;i<=max;i++)
	{
	if (f[i])
	{
		if (dp[i-2]+f[i]*i>dp[i-1])
			dp[i]=dp[i-2]+f[i]*i;
		else 
			dp[i]=dp[i-1];
	}
	else dp[i]=dp[i-1];
	}
	cout<<dp[max]<<endl;
	return 0;
}
