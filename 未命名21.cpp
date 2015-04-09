#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5*10010;
int A[N],n;
int t[N],ranks[N];
int dp[N];
int vis[N];
vector<int> v;
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++){
            scanf("%d",&A[i]);
            t[i]=A[i];
            dp[i]=1<<30;
            vis[i]=0;
        }
        sort(t+1,t+1+n);
        int m=1,k=1;
        ranks[0]=0;
        for (int i=2;i<=n;i++){
            if (t[i]!=t[i-1]){
                t[++m]=t[i];
            }
            if (A[i]!=A[i-1]){
                A[++k]=A[i];
                ranks[k-1]=i-k+1;
            }
        }
        ranks[k]=n-k+1;
        for (int i=1;i<=k;i++)
		{
            int pos=lower_bound(t+1,t+1+m,A[i])-t;
            A[i]=pos;
        }
        
        dp[0]=0;
        dp[k]=k;
        
		for (int i=0;i<k;i++)
		{
            int cnt=0;
            if (dp[i]>=dp[i+1]) continue;
            for (int j=i+1;j<=k;j++)
			{
                if (!vis[A[j]])
				{
                    cnt++;
                    v.push_back(A[j]);
                }
                vis[A[j]]++;
                if (dp[i]+cnt*cnt>=dp[k]) break;
                dp[j]=min(dp[j],dp[i]+cnt*cnt);
            }
            for (int j=0;j<v.size();j++)
			{
                vis[v[j]]=0;
            }
            v.clear();
        }
        printf("%d\n",dp[k]);

    }
}
/*
10
3 4 2 4 4 2 4 3 2 2
*/
