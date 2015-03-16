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
#define eps 1e-8
#define pi acos(-1)
#define M 1000000007
using namespace std;
int dp[5100][4100];
int main(){
	int T,a,b,i,j,cas=1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d-%d",&a,&b);
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for (i=2;i<=a+b;i++)
			for (j=0;j<=a;j++){
				if (i-j<j){
					if (i-1-j<j)
						dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
					if (i-j<j-1)
						dp[i][j]=(dp[i][j]+dp[i-1][j-1])%M;
				}
			}
		printf("Case #%d: %d ",cas++,dp[a+b][a]);
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for (i=2;i<=b*2;i++)
			for (j=0;j<=b;j++){
				if (i-j<j){
					if (i-1-j<j)
						dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
					if (i-j<j-1)
						dp[i][j]=(dp[i][j]+dp[i-1][j-1])%M;
				}
			}
		LL ans=0;
		for (i=b;i<=b*2-1;i++)
			ans=(ans+dp[i][b])%M;
		cout<<ans<<endl;	
	}
	return 0;
}

