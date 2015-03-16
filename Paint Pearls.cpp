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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int a[50010];
int b[50010];
int vis[50010];
int dp[50010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while (scanf("%d",&n)!=EOF)
	{
		int t=1,k;
		LL h=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			dp[i]=i;
			if (k==a[t-1]) continue;
			a[t++]=k;
			b[t-1]=k;
		}
		n=t-1;
		sort(b+1,b+n+1);
		k=1;
		for (i=1;i<=n;i++)
			if (b[i]!=b[i-1])
				b[k++]=b[i];
		k--;
		for (i=1;i<=n;i++)
		{
			int pos=lower_bound(b+1,b+1+k,a[i])-b;
			a[i]=pos;
		}
		int ans=0;
		vector <int> vt;
		memset(vis,0,sizeof(vis));
		dp[0]=0;
		dp[n]=n;
		for (i=0;i<n;i++)
		{
            int cnt=0;
            if (dp[i]>=dp[i+1]) continue;
            for (int j=i+1;j<=n;j++)
			{
                if (!vis[a[j]])
				{
                    cnt++;
                    vt.push_back(a[j]);
                }
                vis[a[j]]++;
                if (dp[i]+cnt*cnt>=dp[n]) break;
                dp[j]=min(dp[j],dp[i]+cnt*cnt);
            }
            for (int j=0;j<vt.size();j++)
			{
                vis[vt[j]]=0;
            }
            vt.clear();
        }
        printf("%d\n",dp[n]);

	}
	return 0;
}
